#include <8052.h>
#define bit0 P2_2
#define bit1 P2_3
#define bit2 P2_4

void select_nixie_tube(char num) {
	switch(num){
		case 0:
			bit0 = 0;
			bit1 = 0;
			bit2 = 0;
			break;
		case 1:
			bit0 = 1; 
			bit1 = 0; 
			bit2 = 0;
			break;
		case 2:
			bit0 = 0;
			bit1 = 1; 
			bit2 = 0;
			break;
		case 3:
			bit0 = 1; 
			bit1 = 1; 
			bit2 = 0; 
			break;
		case 4:
			bit0 = 0;
			bit1 = 0;
			bit2 = 1;
			break;
		case 5:
			bit0 = 1;
			bit1 = 0; 
			bit2 = 1;
			break;
		case 6:
			bit0 = 0; 
			bit1 = 1;
			bit2 = 1;
			break;
		case 7:
			bit0 = 1;
			bit1 = 1;
			bit2 = 1;
			break;
	}
}
//set and go light
#define tube_a 	P0_0
#define tube_b 	P0_1
#define tube_c 	P0_2
#define tube_d 	P0_3
#define tube_e 	P0_4
#define tube_f 	P0_5
#define tube_g 	P0_6
#define tube_dp P0_7
char alphabet[17] = {
	0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71, 0x80
};

void select_char(char number) {
	P0 = alphabet[number];
}
// delay
void delay(int n) {
	while(n--);
}

void main(void) {
	char tube_block = 0;
	while(1) {
		char num = tube_block%8;	
		select_char(num);
		select_nixie_tube(num);
		++tube_block;
		delay(100000);
	}
}
