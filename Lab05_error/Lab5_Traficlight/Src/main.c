/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Tran Ba Thanh
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

/*Input:
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
 * 	B7: R South light
 * 	B8: Y South light
 * 	B9: G South light
 *
 *For more info, please visit: https://github.com/Tbthanh/STM32f103c8xx_code_following_ECE319K
 *FSM and the excel sheet can be found: STM32f103c8xx_code_following_ECE319K/lab05_trafic_light/00_Others/
**/

#include <stdint.h>
#include "PLL.h"
#include "SysTick.h"
#include "Register.h"

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
STyp FSM[10]={
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

// initialize port B 4-9 and B 0-1
void portB_Init(void)
{
	// CRL for pin B 4-7 and 0-1
	*(GPIOB->CRL) |= 0x11110011;
	// CLH for pin B 8-9
	*(GPIOB->CRH) |= 0x00000011;
	// Optional for clearing / setting the LED
}

// initialize port A 0-2
void portA_Init(void)
{
	// CRL for pin A 0-2
	*(GPIOA->CRL) |= (uint32_t)0x00000088;
	// Pull up pin A 0-2
	*(GPIOA->ODR) |= (uint32_t)0x00000003;
}

// function for flashing walking light 4 times B0-1
void flashing(uint32_t time)
{
	time /= 8;
	int8_t count = 5;
	while(count--)
	{
		*(GPIOB->ODR) |= 0x03;		// ensure the led on
		*(GPIOB->ODR) &= 0xFFFFFFFE;	// turn off white
		delay(time);
		*(GPIOB->ODR) |= 0x03;		// ensure the led on
		*(GPIOB->ODR) &= 0xFFFFFFFD;	// turn off red
		delay(time);
	}
}

int main(void)
{
	// initialize 48 MHz system clock
	SystemInit();

	// Enable RCC for GPIO
	*(RCC->APB2ENR) |= 0x0C;

	// Give time to stabilize the clock
	while(0 == (*(RCC->APB2ENR) & 0x0C)){}

	// Initialize GPIOs
	portA_Init();
	portB_Init();

	// Initial state: red All
	uint8_t state = rAl;

	// Input
	volatile uint32_t input = 0x00;

    /* Loop forever */
	for(;;)
	{
		// set the output to the current state
		*GPIOB->ODR = FSM[state].Output;

		// check if wWa
		if (state == wWa)
		{
			// flash white-red-off
			flashing(FSM[state].Time);
		}
		else
		{
			// delay 10ms * FSM[state].Time
			delay(FSM[state].Time);
		}

		// get new input
		input = *(GPIOA->IDR);
		//input = (*GPIO_A_IDR & 0x07);

		// go to next state
		state = FSM[state].Next[input];
	}
}