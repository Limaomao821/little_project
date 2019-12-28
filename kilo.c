#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <termios.h>
#include <stdlib.h>

struct termios orig_termios;
void disableRawMode() {
    // online course use TCASFLUSH here
    // currently i cannot tell the difference here
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
}

void enableRawMode() {
    
    // i want to turn off echo of the screen, why read STDIN_FILENO
    // Explanation: echo is an attribute of the keyboard,
    //              because first keyboard send, then screen shows.
    tcgetattr(STDIN_FILENO, &orig_termios);

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
    raw.c_iflag &= ~(IXON | ICRNL);

    // ICRNL makes all "\r"(including ctrl+m and Enter) into "\n"
    // and then, "\n" are translated into "\r\n" by default
    /////////
    // in practice, the "\n" to "\r\n" translations
    // is likely the only output processing feature by default
    raw.c_oflag &= ~(OPOST);

    // online course use TCASFLUSH here
    // currently i cannot tell the difference here
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

int main(void){
    enableRawMode();

    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q') {
        if (iscntrl(c)) {
            printf("%d\r\n", c);
        } else {
            printf("%d ('%c')\r\n", c, c);
        }
    }
    return 0;
}