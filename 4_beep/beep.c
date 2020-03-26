#include <8051.h>
#define BEEPER P1_5
int main(void) {
	BEEPER = 1;
	return 0;
}
