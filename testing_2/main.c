#include <stdint.h>
#include <stm32f10x.h>
#include <system_stm32f10x.h>

// initialize port B 4-9 and B 0-1
void portB_Init(void);

// initialize port A 0-2
void portA_Init(void);

// function for flashing walking light 4 times B0-1
void flashing(uint32_t time);

// Systick related function
void SysTick_Init(uint32_t ticks);
volatile static uint32_t TimeDelay;
void SysTick_Handler(void);
void Delay(uint32_t nTime);

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

// wait time (*10ns)
#define GreenTime	1000	//10s
#define WaitTime	200		//2s
#define RedTime		100		//1s
#define WalkGTime	800		//8s

// state Structure
struct State
{
	uint32_t Output;	// 6-bit output for port B for road light
	uint32_t Time;		// x10 ms
	uint8_t Next[8];	// depends on 3-bit input
};

// Blink of walk need to look into more!!
// FSM of states
typedef const struct State STyp;
static const STyp FSM[10]={
	// jSo : just South
	{0x0C0,GreenTime,{wSo,wSo,wSo,wSo,jSo,wSo,wSo,wSo}},
	// wSo : wait South
	{0x0A0,WaitTime,{rAl,rSo,rSo,rSo,rAl,rSo,rSo,rSo}},
	// rSo : red South
	{0x090,RedTime,{rAl,jWa,jWe,jWe,rAl,jWa,jWe,jWe}},
	// jWe : just West
	{0x210,GreenTime,{wWe,wWe,jWe,wWe,wWe,wWe,wWe,wWe}},
	// wWe : wait West
	{0x110,WaitTime,{rAl,rWe,rAl,rWe,rWe,rWe,rWe,rWe}},
	// rWe : red West
	{0x090,RedTime,{rAl,jWa,rAl,jWa,jSo,jSo,jSo,jWa}},
	// jWa : just Walk
	{0x090,WalkGTime,{wWa,jWa,wWa,wWa,wWa,wWa,wWa,wWa}},
	// wWa : wait Walk
	{0x090,WaitTime,{rAl,rAl,rWa,rWa,rWa,rWa,rWa,rWa}},
	// rWa : red Walk
	{0x090,RedTime,{rAl,rAl,jWe,jWe,jSo,jSo,jSo,jSo}},
	// rAl : red All
	{0x090,RedTime,{rAl,jWa,jWe,jWe,jSo,jSo,jSo,jSo}}
};

int main(void)
{
	// systick
	SysTick_Init(9000);

	// Enable RCC for GPIO
	RCC->APB2ENR |= 0x0C;

	// Give time to stabilize the clock
	while(!((RCC->APB2ENR) & 0x0C));

	// Initialize GPIOs
	portA_Init();
	portB_Init();
	
	// Input
	volatile uint32_t input = 0x00;
		
	for(;;)
	{
		GPIOB->ODR |= 0x000003F0\
		;
		Delay(100);
		GPIOB->ODR &= 0xFFFFFFFC;
		Delay(100);
	}
}

void portB_Init(void)
{
	// CRL for pin B 4-7 and 0-1
	GPIOB->CRL &= 0x0000FF00;
	GPIOB->CRL |= 0x66660066;
	// CLH for pin B 8-9
	GPIOB->CRH |= 0x00000022;
	// Cheking all the LED
	GPIOB->ODR |= 0x000003F3;
	Delay(100);
	GPIOB->ODR &= 0xFFFFFC0C;
}

void portA_Init(void)
{
	// CRL for pin A 0-2
	GPIOA->CRL |= (uint32_t)0x00000088;
	// Pull up pin A 0-2
	GPIOA->ODR |= (uint32_t)0x00000003;
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
		__asm("nop");		// busy wait
}

void SysTick_Init(uint32_t ticks)
{
	SysTick->CTRL = 0x00000000;	// SysTick_CTRL_DISABLE;
	SysTick->LOAD = ticks - 1;
	// set interupt piority of SysTick to least urgency
	NVIC_SetPriority (SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1);
	SysTick->VAL = 0;	// reset the value
	// select processor clock
	SysTick->CTRL |= 0x00000004;
	// enable systick interupt
	SysTick->CTRL |= SysTick_CTRL_ENABLE;
	// enable systick;
}
