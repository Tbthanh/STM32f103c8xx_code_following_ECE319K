#include <stdio.h>
#include <stdint.h>
#include "stm32f10x.h"

static int count = 0;
void ISR(void)
{
	count ++;
	printf("count = %d\n", count);
}

int main()
{
	// install ISR
	ISR();
	
	// main code
	while(1)
	{
		if (count == 10)
		{
			printf("reset the counter");
			count -= 10;
		}
	}
}