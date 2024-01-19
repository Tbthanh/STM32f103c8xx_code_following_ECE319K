/*
 * PLL.c
 *
 *  Created on: Jan 10, 2024
 *      Author: TBTHANH
 *	 Reference: 
 *https://medium.com/@csrohit/clock-configuration-in-stm32-6a058da220e0 
 *
 * This file configures the system clock as follows:
 *=============================================================
 *=============================================================
 *        System Clock source				| PLL(HSE)
 *-------------------------------------------------------------
 *        SYSCLK(Hz)								| 48000000
 *-------------------------------------------------------------
 *        HCLK(Hz)									| 48000000
 *-------------------------------------------------------------
 *        AHB  Prescaler 						| 1
 *-------------------------------------------------------------
 *        APB1  Prescaler 					| /2
 *-------------------------------------------------------------
 *				APB2  Prescaler 					| 1
 *-------------------------------------------------------------
 *        HSE Frequency(Hz)					| 8000000
 *-------------------------------------------------------------
 *        PLLMUL										| 6
 *-------------------------------------------------------------
 *        PREDIV 										| 1
 *-------------------------------------------------------------
 *        Flash Latency(WS)					| 1
 *-------------------------------------------------------------
 *        Prefetch Buffer						| ON
 *-------------------------------------------------------------
  **************************************************************
 */
 
#include "PLL.h"

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
	RCC->CFGR |= RCC_CFGR_PLLXTPRE_HSE;
	
	// turn on HSE
	RCC->CR 	|= RCC_CR_HSEON;
	while (!(RCC->CR & RCC_CR_HSERDY))
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
