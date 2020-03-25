#include <8051.h>
#define led0 P2_0
#define led1 P2_1
#define led2 P2_2
#define led3 P2_3
#define led4 P2_4
#define led5 P2_5
#define led6 P2_6
#define led7 P2_7
void main(void)
{
	while(1)	
	{
		int i = 0;
		int j = 0;
		led7 = 1;
		led0 = 0;
		for(i=0; i<100; ++i)
			for(j=0; j<100; ++j);
		led0 = 1;
		led1 = 0;
		for(i=0; i<100; ++i)
			for(j=0; j<100; ++j);
		led1 = 1;
		led2 = 0;
		for(i=0; i<100; ++i)
			for(j=0; j<100; ++j);
		led2 = 1;
		led3 = 0;
		for(i=0; i<100; ++i)
			for(j=0; j<100; ++j);
		led3 = 1;
		led4 = 0;
		for(i=0; i<100; ++i)
			for(j=0; j<100; ++j);
		led4 = 1;
		led5 = 0;
		for(i=0; i<100; ++i)
			for(j=0; j<100; ++j);
		led5 = 1;
		led6 = 0;
		for(i=0; i<100; ++i)
			for(j=0; j<100; ++j);
		led6 = 1;
		led7 = 0;
		for(i=0; i<100; ++i)
			for(j=0; j<100; ++j);
	}
}
