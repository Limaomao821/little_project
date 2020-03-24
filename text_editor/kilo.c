#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <termios.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/ioctl.h>

// This mirrors what the Ctrl key does in the terminal: 
// it strips bits 5 and 6 from whatever key you press in combination with Ctrl, 
// and sends that.
# define CTRL_KEY(k) (k & 0x1f)
struct editorConfig {
    struct termios orig_termios;
    int screenrows;
    int screencols;
};
struct editorConfig E;

/*** terminal ***/

// Most C library functions that fail will set the global errno variable to indicate what the error was. 
// perror() looks at the global errno variable and prints a descriptive error message for it. 
// It also prints the string given to it before it prints the error message, 
// which is meant to provide context about what part of your code caused the error.
void die(const char *s) {
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);

    perror(s);
    exit(1);
}

void disableRawMode() {
    // online course use TCASFLUSH here
    // currently I cannot tell the difference here
    if(tcsetattr(STDIN_FILENO, TCSANOW, &E.orig_termios) == -1) {
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
    if(tcgetattr(STDIN_FILENO, &E.orig_termios) == -1) die("tcgetattr");

    struct termios raw = E.orig_termios;
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
int getCursorPosition(int *rows, int *cols) {
    if(write(STDOUT_FILENO, "\x1b[6n", 4) != 4) return -1;

    char store[32];
    int i;
    for(i=0; i<32; ++i) {
        if(read(STDIN_FILENO, store+i, 1) != 1) return -1;
        if(store[i] == 'R') break;
    }

    ++i;
    store[i] = '\0';

    if(store[0] != '\x1b'|| store[1] != '[') return -1;
    if(sscanf(&store[2], "%d;%d", rows, cols) != 2) return -1;

    return 1;
}
int getWindowSize(int *rows, int *cols) {
    struct winsize size;
    if(ioctl(STDIN_FILENO, TIOCGWINSZ, (char *) &size) == -1 || size.ws_row == 0) {
        if(write(STDOUT_FILENO, "\x1b[999C\x1b[999B", 12) != 12) return -1;
        return getCursorPosition(rows, cols);
    } else {
        *rows = size.ws_row;
        *cols = size.ws_col;    
        return 0;
    }
}

void editorDrawRows() {
    int col;
    for(col=0; col<E.screenrows-1; ++col) {
        write(STDOUT_FILENO, "~\r\n", 3);
    }
    write(STDOUT_FILENO, "~", 1);
}
void editorRefreshScreen() {
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);

    editorDrawRows();

    write(STDOUT_FILENO, "\x1b[H", 3);
}



void editorProcessKeypress() {
    char c = editorReadKey();

    switch (c)
    {
    case(CTRL_KEY('q')):
        write(STDOUT_FILENO, "\x1b[2J", 4);
        write(STDOUT_FILENO, "\x1b[H", 3);

        exit(0);
        break;
    
    default:
        break;
    }
}
/*** append buffer ***/
struct abuf {
    char *b;
    int len;
}
#define ABUF_INIT {NULL, 0}

void abAppend(struct abuf *ab, const char *s, int len) {
    char *new = realloc(ab->b, ab->len + len);

    if(new == NULL) return;
    memcpy(&new[ab->len], s, len);
    ab->b = new;
    ab->len += len;
}

void abFree(struct abuf *ab) {
    free(ab->b);
}

/*** init ***/
void initEditor() {
    if(getWindowSize(&E.screenrows, &E.screencols) == -1) die("getWindowSize");
}
int main(void){
    enableRawMode();
    initEditor();
    editorRefreshScreen();

    while (1) {
        editorProcessKeypress();
    }
    return 0;
}
