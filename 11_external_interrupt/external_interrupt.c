#include <8051.h>

#define led P2_0
#define key P3_2

void delay(int n) {
	while(n--);
}

void Int0Init() {
	IT0 = 1;
	EX0 = 1;
	EA = 1;
}

void main(void) {
	Int0Init();
	while(1);
}

void Int0() __interrupt (0) {
	delay(1000);
	if(key == 0) {
		led = !led;
	}
}
