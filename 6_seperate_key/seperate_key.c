#include <8051.h>
#define K1 		P3_1
#define led		P2_0
#define led2 	P2_1

void delay(int n) {
	while(n--);
}

int main(void) {
	led2 = 0;
	delay(100000);
	led2 = 1;
	delay(100000);
	return 0;
}
