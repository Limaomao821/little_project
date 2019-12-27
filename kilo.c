#include <unistd.h>
#include <termios.h>
#include <stdlib.h>

struct termios orig_termios;
void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
}

void enableRawMode() {
    struct termios raw;

    // I don't understand
    // i want to turn off echo of the screen, why read STDIN_FILENO
    tcgetattr(STDIN_FILENO, &raw);

    orig_termios = raw;
    atexit(disableRawMode);

    // ECHO is a bitflag, defined as 00000000000000000000000000001000 in binary. 
    // We use the bitwise-NOT operator (~) on this value to get 11111111111111111111111111110111. 
    // We then bitwise-AND this value with the flags field, 
    // which forces the fourth bit in the flags field to become 0, 
    // and causes every other bit to retain its current value. 
    // Flipping bits like this is common in C.
    raw.c_lflag &= ~(ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

int main(void){
    enableRawMode();

    char c;
    while(read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
    return 0;
}