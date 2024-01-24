/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Tran Ba Thanh
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 *Input:
 * 	A0:Walk
 * 	A1:West
 * 	A2:South
 *
 *Input value:
 *	0x0 = 000 = no sensor
 *	0x1 = 001 = Walk sensor
 *	0x2 = 010 = West sensor
 *	0x3 = 011 = Walk and West sensor
 *	0x4 = 100 = South sensor
 *	0x5 = 101 = South and Walk sensor
 *	0x6 = 110 = South and West sensor
 *	0x7 = 111 = all three sensor
 *
 *Priority
 *	South > West > Walk
 *
 *Output:
 * 	B0: White Walk light
 * 	B1: Red Walk light
 * 	B4: R South light
 * 	B5: Y South light
 * 	B6: G South light
 * 	B7: R West light
 * 	B8: Y West light
 * 	B9: G West light
 *
 *For more info, please visit: https://github.com/Tbthanh/STM32f103c8xx_code_following_ECE319K
 *FSM and the excel sheet can be found: STM32f103c8xx_code_following_ECE319K/lab05_trafic_light/00_Others/
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stm32f10x.h>
#include <system_stm32f10x.h>
#include "fonts.h"
#include "ssd1306.h"

// initialize port B 4-9 and B 0-1
void portB_Init(void);

// initialize port A 0-2
void portA_Init(void);

// function for flashing walking light 4 times B0-1
void flashing(uint32_t time);

// Systick related function
void SysTick_Init(uint32_t ticks);
void SysTick_Handler(void);				//Delay 1ms
void Delay(uint32_t nTime);
volatile static uint32_t TimeDelay;

// function to set the sysclock to 48Mhz
void PLLInit(void);

// Interupt init for PA[0:2]
void Interupt_Init(void);

// external interupt handler function for PA0,1,2:
void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
static	volatile uint8_t input = 0x00; // Input (set using interupt)

// states
#define jSo		0
#define wSo		1
#define rSo		2
#define	jWe		3
#define wWe		4
#define rWe		5
#define jWa		6
#define wWa		7
#define rWa		8
#define rAl		9

// wait time (*1ms)
#define GreenTime	8000		// 8s
#define WaitTime	2000		// 2s
#define RedTime		1000		// 1s
#define WalkGTime	5000		// 5s

// state Structure
struct State
{
	uint32_t 	Output;	// 6-bit output for port B for road light
	uint32_t 	Time;		// x10 ms
	uint8_t 	Next[8];	// depends on 3-bit input
};

// Blink of walk need to look into more!!
// FSM of states
typedef const struct State STyp;
static const STyp FSM[10]={
	// jSo : just South
	{0x000000C2,GreenTime,{wSo,wSo,wSo,wSo,jSo,wSo,wSo,wSo}},
	// wSo : wait South
	{0x000000A2,WaitTime,{rAl,rSo,rSo,rSo,rAl,rSo,rSo,rSo}},
	// rSo : red South
	{0x00000092,RedTime,{rAl,jWa,jWe,jWe,rAl,jWa,jWe,jWe}},
	// jWe : just West
	{0x00000212,GreenTime,{wWe,wWe,jWe,wWe,wWe,wWe,wWe,wWe}},
	// wWe : wait West
	{0x00000112,WaitTime,{rAl,rWe,rAl,rWe,rWe,rWe,rWe,rWe}},
	// rWe : red West
	{0x00000092,RedTime,{rAl,jWa,rAl,jWa,jSo,jSo,jSo,jWa}},
	// jWa : just Walk
	{0x00000091,WalkGTime,{wWa,jWa,wWa,wWa,wWa,wWa,wWa,wWa}},
	// wWa : wait Walk
	{0x00000093,WaitTime,{rAl,rAl,rWa,rWa,rWa,rWa,rWa,rWa}},
	// rWa : red Walk
	{0x00000092,RedTime,{rAl,rAl,jWe,jWe,jSo,jSo,jSo,jSo}},
	// rAl : red All
	{0x00000092,RedTime,{rAl,jWa,jWe,jWe,jSo,jSo,jSo,jSo}}
};

/*************** MAIN ***************/
int main(void)
{
	// initialize 48 MHz system clock
	//PLLInit();
	
	// systick
	SysTick_Init(8000);

	// Enable RCC for GPIO
	RCC->APB2ENR |= 0x0000000C;

	// Give time to stabilize the clock
	while(!(RCC->APB2ENR & 0x0000000C));

	// Initialize GPIOs
	portA_Init();
	portB_Init();
	
	// Interupt for PA0, PA1 and PA2
	Interupt_Init();
	
	// Initial state: red All
	volatile uint8_t state = (uint8_t)rAl;
	
	// Input (for non interupt)
	// volatile uint32_t input = 0x00000000;
		
	for(;;)
	{
		// set the output to the current state
		GPIOB->ODR = FSM[state].Output;

		// check if wWa
		if (state == (uint8_t)wWa)
		{
			// flash white-red-off
			flashing(FSM[state].Time);
		}
		else
		{
			// delay 1ms * FSM[state].Time
			Delay(FSM[state].Time);
		}

		// get new input (when not using Interupt)
		//input = (GPIOA->IDR& 0x07);
		//input = (*GPIO_A_IDR & 0x07);

		// go to next state
		state = (uint8_t)(FSM[state].Next[input]);
	}
}
/********* END OF MAIN ***************/

void portB_Init(void)
{
	// CRL for pin B 4-7 and 0-1
	GPIOB->CRL &= 0x0000FF00;
	GPIOB->CRL |= 0x66660066;
	// CLH for pin B 8-9
	GPIOB->CRH |= 0x00000066;
	// Cheking all the LED
	GPIOB->ODR |= 0x000003F3;
	Delay(3000);
	GPIOB->ODR &= 0xFFFFFC0C;
	Delay(3000);
}

void portA_Init(void)
{
	// CRL for pin A 0-2
	GPIOA->CRL &= 0xFFFFF000;
	GPIOA->CRL |= 0x00000888;
	// Pull down pin A 0-2
	GPIOA->ODR &= 0xFFFFFFF8;
}

void flashing(uint32_t time)
{
	time /= 8;
	int8_t repeatTime = 5;
	while(repeatTime--)
	{
		GPIOB->ODR |= 0x03;		// ensure the led on
		GPIOB->ODR &= 0xFFFFFFFE;	// turn off white
		Delay(time);
		GPIOB->ODR |= 0x03;		// ensure the led on
		GPIOB->ODR &= 0xFFFFFFFD;	// turn off red
		Delay(time);
	}
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

void SysTick_Init(uint32_t ticks)
{
	SysTick->CTRL = 0x00000000;	// SysTick_CTRL_DISABLE;
	SysTick->LOAD = ticks - 1;
	// set interupt piority of SysTick to least urgency
	// Using NVIC_setPiority for convinience, to focus on peripheral interupt
	NVIC_SetPriority (SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL);
	SysTick->VAL = 0;	// reset the value
	// select processor clock
	SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                   SysTick_CTRL_TICKINT_Msk   |
                   SysTick_CTRL_ENABLE_Msk;  /* Enable SysTick IRQ and SysTick Timer */
	
}

// function to set the sysclock to 48Mhz
// for some reason my HSE cannot be ready so scrap this
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
	RCC->CFGR |= RCC_CFGR_PLLXTPRE_HSE;
	
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

void EXTI0_IRQHandler(void)
{
	if ((EXTI->PR & 0x00000001) !=0)	
	{
		if ((GPIOA->IDR& 0x00000001) != 0) // rising? 0x00000001
		{
			input &= 0xFE;	// clear bit 0
			input |= 0x01;	// set bit 0
		}
		else	// falling?
		{
			input &= 0xFE;	// clear bit 0
		}
		/* Clear the EXTI0 pending bit */
		EXTI->PR |= 0x00000001;
	}
}
void EXTI1_IRQHandler(void)
{
	if ((EXTI->PR & 0x00000002) !=0)	
	{
		if ((GPIOA->IDR& 0x00000002) != 0) // rising?
		{
			input &= 0xFD;	// clear bit 1
			input |= 0x02;	// set bit 1
		}
		else	// falling?
		{
			input &= 0xFD;	// clear bit 1
		}
		/* Clear the EXTI1 pending bit */
		EXTI->PR |= 0x00000002;
	}
}
void EXTI2_IRQHandler(void)
{
	if ((EXTI->PR & 0x00000004) !=0)	
	{
		if ((GPIOA->IDR& 0x00000004) != 0) // rising?
		{
			input &= 0xFB;	// clear bit 2
			input |= 0x04;	// set bit 2
		}
		else	// falling?
		{
			input &= 0xFB;	// clear bit 2
		}
		/* Clear the EXTI2 pending bit */
		EXTI->PR |= 0x00000004;
	}
}

void Interupt_Init(void)
{
	/* Interupt config for PA0, PA1 and PA2
	 *ref: the 1 st one is the most okay! 
			1) https://controllerstech.com/external-interrupt-using-registers/
			2) https://stackoverflow.com/questions/67140959/stm32f103-blue-pill-interrupts-from-scratch
			3) https://youtu.be/uKwD3JuRWeA?si=OXbISvS9MOoUbTvn
			
	 *define in stm32f10x.h for IRQn
			******  STM32 specific Interrupt Numbers ******
			EXTI0_IRQn                  = 6,       EXTI Line0 Interrupt                                 
			EXTI1_IRQn                  = 7,       EXTI Line1 Interrupt                                 
			EXTI2_IRQn                  = 8,       EXTI Line2 Interrupt
	*/
	// Enable AFIO (SYSCFG in stm32F4) to use interupt
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;			// (1 << 0)

	// AFIO_EXTICR1 for pin 0 - 2
	// RM008 9.4.3 External interrupt configuration register 1
	AFIO->EXTICR[0] &= 0xFFFFFFF0; 	// EXTIx[3:0] set to 0000:PA[x] pin
	AFIO->EXTICR[0] &= 0xFFFFFF0F;
	AFIO->EXTICR[0] &= 0xFFFFF0FF;       			

	// Set bit
	// rm0008 10.3.1 Interrupt mask register
	EXTI->IMR 	|= 0x00000007;				// unmask interrupt to enable interupt
	// rm0008 10.3.2 Event mask register
	// EXTI->EMR 	|= 0x00000007;				// unmask event = enable some how
	// rm0008 10.3.3 Rising trigger selection register
	EXTI->RTSR 	|= 0x00000007;				// set rising edge
	// rm0008 10.3.4 Falling trigger selection register
	EXTI->FTSR	|= 0x00000007;				// set falling edge

	// Set interupt piority
	//NVIC_SetPriority(EXTI0_IRQn, 1); // cmsis funct def in core_cm3.h ln1632 
	// PM0056 4.3.7 Interrupt priority registers
	NVIC->IPR[((uint32_t)EXTI0_IRQn)] = (uint8_t)((1 << (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL);
	NVIC->IPR[((uint32_t)EXTI1_IRQn)] = (uint8_t)((1 << (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL);
	NVIC->IPR[((uint32_t)EXTI2_IRQn)] = (uint8_t)((1 << (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL);
	// __NVIC_PRIO_BITS define in stm32f10x.h ln168
	/* Basicly, the code above is to set the interupt piority 1 (pretty high) to PA[0:2]
		 The reason we have to offset left 4U is becase:
			 "The processor implements only bits[7:4] of each field, 
			 bits[3:0] read as zero and ignore writes"*/

	// Enable Interupt for PA[0:2]
	//NVIC_EnableIRQ(EXTI0_IRQn); // Set interupt using cmsis
	// PM0056 4.3.2 Interrupt set-enable registers
	NVIC->ISER[EXTI0_IRQn >> 5UL] = (uint32_t)(1UL << (EXTI0_IRQn & 0x1FUL));
	NVIC->ISER[EXTI1_IRQn >> 5UL] = (uint32_t)(1UL << (EXTI1_IRQn & 0x1FUL));
	NVIC->ISER[EXTI2_IRQn >> 5UL] = (uint32_t)(1UL << (EXTI2_IRQn & 0x1FUL));
	// 
	/* End of interupt config */
}
