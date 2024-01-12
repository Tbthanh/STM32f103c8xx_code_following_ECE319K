/*
 * SysTaoick.h
 *
 *  Created on: Jan 10, 2024
 *      Author: TBTHANH
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

volatile uint32_t msTicks = 0;

/**
 * @brief Interrupt handler function
 *
 */
void SysTick_Handler(void)
{
	msTicks++;
}

/**
 * @brief Add blocking delay
 *
 * @param ms delay in milliseconds
 */
void delay(int ms)
{
	uint32_t expected_ticks = msTicks + ms;
	while (msTicks < expected_ticks)
	{
		__asm("nop");
	}
}


#endif /* SYSTICK_H_ */
