#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <termios.h>
#include <errno.h>
#include <stdlib.h>

// This mirrors what the Ctrl key does in the terminal: 
// it strips bits 5 and 6 from whatever key you press in combination with Ctrl, 
// and sends that.
# define CTRL_KEY(k) (k & 0x1f)

struct termios orig_termios;

// Most C library functions that fail will set the global errno variable to indicate what the error was. 
// perror() looks at the global errno variable and prints a descriptive error message for it. 
// It also prints the string given to it before it prints the error message, 
// which is meant to provide context about what part of your code caused the error.
void die(const char *s) {
    perror(s);
    exit(1);
}

void disableRawMode() {
    // online course use TCASFLUSH here
    // currently I cannot tell the difference here
    if(tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios) == -1) {
        die("tcsetattr");
    }
     
}

void enableRawMode() {
    
    // i want to turn off echo of the screen, why read STDIN_FILENO
    // Explanation: echo is an attribute of the keyboard,
    //              because first keyboard send, then screen shows.
    ////////
    // QUESTION HERE!!!!!!
    // if we use pipe or file as the standard input here
    // tcgetattr would die, why
    if(tcgetattr(STDIN_FILENO, &orig_termios) == -1) die("tcgetattr");

    struct termios raw = orig_termios;
    atexit(disableRawMode);

    // Flipping bits like this is common in C.
    //
    // ECHO is a bitflag, defined as 0000010 in binary. 
    // We use the bitwise-NOT operator (~) on this value to get 1111101
    // We then bitwise-AND this value with the flags field, 
    // which forces the second bit in the flags field to become 0, 
    // and causes every other bit to retain its current value. 
    //
    // EXPANSION:
    // Turn on  echo:           raw.c_lflag |=  ECHO;
    // Turn off echo:           raw.c_lflag &= ~ECHO;
    // Test if  echo is open:   if(raw.c_lflag && ECHO)
    // Test if  echo is closed: if(!(raw.c_lflag && ECHO))
    //
    ////////
    // 
    // By flipping bits represent signal dealing with ctrl+z and ctrl+c
    // 
    raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);

    // distinguish between SIGNAL and SOFTWARE FLOW CONTROL
    // according to WIKI, software flow control includes 
    // XOFF(ASCII DC3: Ctrl + S) and XON(ASCII DC1: Ctrl + Q)
    //
    // actually, I find whether turn on or off software flow control
    // it seems that it doesn't matter
    // the only difference is that 
    // if IXON in not set, ctrl+s and ctrl+q will displat their ascii number
    //
    // ??????????????????????       QUESTION HERE
    // according to POSIX standard or POSIX program guide
    // I cannot tell the use of IXON bit very clearly
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);

    // ICRNL makes all "\r"(including ctrl+m and Enter) into "\n"
    // and then, "\n" are translated into "\r\n" by default
    /////////
    // in practice, the "\n" to "\r\n" translations
    // is likely the only output processing feature by default
    raw.c_oflag &= ~(OPOST);

    raw.c_cflag |= (CS8);

    // VMIN decides the minimum characters read must get before return
    // VTIME decides the minimum time before read return
    // when VMIN && VTIME is true, then read could return
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 10;

    // online course use TCASFLUSH here
    // currently i cannot tell the difference here
    if(tcsetattr(STDIN_FILENO, TCSANOW, &raw) == -1) die("tcsetattr");
}

void editorRefreshScreen() {
    write(STDOUT_FILENO, "\x1b[2J", 4);
}
char editorReadKey() {
    int nread;
    char c;

    // I am not very clear about the conditions here
    while((nread = read(STDIN_FILENO, &c, 1)) != 1) {
        // QUESTION HERE??????
        // I suppose EAGAIN could never occur in blocking IO
        // read() here is a blocking IO
        // why the need to check it
        if(nread == -1 && errno != EAGAIN) die("read");
    }
    return c;
}

void editorProcessKeypress() {
    char c = editorReadKey();

    switch (c)
    {
    case(CTRL_KEY('q')):
        exit(0);
        break;
    
    default:
        break;
    }
}
int main(void){
    enableRawMode();

    while (1) {
        editorRefreshScreen();
        editorProcessKeypress();
    }
    return 0;
}