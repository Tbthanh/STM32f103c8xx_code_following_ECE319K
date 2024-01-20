#include <stdint.h>
#include <stm32f10x.h>
#include <system_stm32f10x.h>

void portB_Init(void);

// Systick related function
void SysTick_Init(uint32_t ticks);
volatile static uint32_t TimeDelay;
void SysTick_Handler(void);				//Delay 1ms
void Delay(uint32_t nTime);

// function to set the sysclock to 48Mhz
void PLLInit(void);

int main(void)
{
	// initialize 48 MHz system clock
	//PLLInit();
	
	// systick
	SysTick_Init(8000);
	
	// Enable RCC for GPIO
	RCC->APB2ENR |= 0x0C;

	// Give time to stabilize the clock
	while(0 == ((RCC->APB2ENR) & 0x0C)){}

	// Initialize GPIOs
	portB_Init();
		
	for(;;)
	{
		GPIOB->ODR |= 0x00000001;
		Delay(1000);
		GPIOB->ODR &= 0xFFFFFFFE;
		Delay(1000);
	}
}

void portB_Init(void)
{
	// CRL for pin 0
	GPIOB->CRL &= 0xFFFFFFF0;
	GPIOB->CRL |= 0x00000002;
}

// function to set the sysclock to 48Mhz
void PLLInit(void)
{
	/* this part follow the intruction of the following guide:
			https://medium.com/@csrohit/clock-configuration-in-stm32-6a058da220e0
	*/
	// Set flash latency
	// 48MHz = SYSCLK > 24MHz -> one wait state
	FLASH->ACR |= FLASH_ACR_LATENCY_2;
	
	// setting APB,AHB & HSE divisor
	// read stm32f10x.h and rm0008 103/1136 for more detail
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;
	RCC->CFGR &= 0xFFFDFFFF;	// (PLLXTPRE=0)
	
	// The HSE crystal of my board doesnt work so ...
	// turn on HSE
	RCC->CR 	|= RCC_CR_HSEON;
	while (!(RCC->CR & RCC_CR_HSERDY)) // code get stuck here
		;		// hse is ready
	
	// config PLL
	RCC->CFGR |= RCC_CFGR_PLLMULL6;
	RCC->CFGR |= RCC_CFGR_PLLSRC_HSE;
	RCC->CFGR |= RCC_CR_PLLON;
	while (!(RCC->CR & RCC_CR_PLLRDY))
		;		// pll is ready
	
	// sellect the pll for coreclock
	RCC->CFGR  |= RCC_CFGR_SW_PLL;	// 0X02
	while (!(RCC->CFGR & RCC_CFGR_SWS_PLL))
		;		// clock is ready 48Mhz
}

void SysTick_Init(uint32_t ticks)
{
	SysTick->CTRL = 0x00000000;	// SysTick_CTRL_DISABLE;
	SysTick->LOAD = ticks - 1;
	// set interupt piority of SysTick to least urgency
	NVIC_SetPriority (SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL);
	SysTick->VAL = 0;	// reset the value
	// select processor clock
	SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                   SysTick_CTRL_TICKINT_Msk   |
                   SysTick_CTRL_ENABLE_Msk;  /* Enable SysTick IRQ and SysTick Timer */
	
}

void SysTick_Handler(void)
{
	if(TimeDelay > 0)
		TimeDelay--;
}

void Delay(uint32_t nTime)
{
	// nTime: specifies the delay time length
	TimeDelay = nTime;
	while(TimeDelay != 0)
		;		// busy wait
}

