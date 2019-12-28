#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <gnu/libc-version.h>

int main(void){
    // struct termios now;
    // tcgetattr(STDIN_FILENO, &now);

    // if (now.c_lflag & ECHO) {
    //     printf("yes");
    // } else if (!(now.c_lflag & ECHO)){
    //     printf("no");
    // } else {
    //     printf("what is the problem?");
    // }

    printf("%s", gnu_get_libc_version());
    return 0;
}