#include <stdint.h>
#include <stm32f10x.h>
#include <system_stm32f10x.h>

void portB_Init(void);
void delay(void);

int main(void)
{
	// Enable RCC for GPIO
	RCC->APB2ENR |= 0x0C;

	// Give time to stabilize the clock
	while(0 == ((RCC->APB2ENR) & 0x0C)){}

	// Initialize GPIOs
	portB_Init();
		
	for(;;)
	{
		GPIOB->ODR |= 0x00000003;
		delay();
		GPIOB->ODR &= 0xFFFFFFFC;
		delay();
	}
}

void portB_Init(void)
{
	// CRL for pin B 4-7 and 0-1
	GPIOB->CRL &= 0x0000FF00;
	GPIOB->CRL |= 0x11110011;
	// CLH for pin B 8-9
	GPIOB->CRH |= 0x00000011;
	// Optional for clearing / setting the LED
}

void delay(void)
{
	for (uint32_t i = 0; i < 1000000; i++)
	{
		__asm("NOP");
	}
}
