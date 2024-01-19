/*
 * SysTick.c
 *
 *  Created on: Jan 19, 2024
 *      Author: TBTHANH
 *	 Reference: https://youtu.be/aLCUDv_fgoU?si=fMm2bMp-1QTNWgd8
 *							RM0056 150/156 also have listed the systick register
 */
#include "SysTick.h"

/* This function is using CMSIS interupt driver which is not allowed
 * in the Lab-5-Requirements-Tutorials-1.docx. So just to serve as 
 * something to test other code til impliment interupt myseft.
 */
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
