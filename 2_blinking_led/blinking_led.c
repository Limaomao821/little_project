#include <8051.h>
#define led P2_0
void main(void)
{
	while(1)	
	{
		int i = 0;
		int j = 0;
		led = 0;
		for(i=0; i<100; ++i)
			for(j=0; j<100; ++j)
			{}
		led = 1;
		for(i=0; i<100; ++i)
			for(j=0; j<100; ++j)
			{}
	}
}
