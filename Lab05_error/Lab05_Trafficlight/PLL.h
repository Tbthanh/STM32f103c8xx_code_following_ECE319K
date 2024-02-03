/*
 * PLL.h
 *
 *  Created on: Jan 10, 2024
 *      Author: TBTHANH
 *
 * This file configures the system clock as follows:
 *=============================================================
 *=============================================================
 *        System Clock source				| PLL(HSE)
 *-------------------------------------------------------------
 *        SYSCLK(Hz)						| 48000000
 *-------------------------------------------------------------
 *        HCLK(Hz)							| 48000000
 *-------------------------------------------------------------
 *        AHB  Prescaler 					| 1
 *-------------------------------------------------------------
 *        APB  Prescaler 					| 1
 *-------------------------------------------------------------
 *        APB1 Prescaler 					| 0.5
 *-------------------------------------------------------------
 *        HSE Frequency(Hz)					| 8000000
 *-------------------------------------------------------------
 *        PLLMUL							| 6
 *-------------------------------------------------------------
 *        PREDIV 							| 1
 *-------------------------------------------------------------
 *        Flash Latency(WS)					| 1
 *-------------------------------------------------------------
 *        Prefetch Buffer					| ON
 *-------------------------------------------------------------
  **************************************************************
 */

#ifndef PLL_H_
#define PLL_H_

#include "Register.h"

extern uint32_t SystemCoreClock;          /*!< System Clock Frequency (Core Clock) */
extern const uint8_t  AHBPrescTable[16U];  /*!< AHB prescalers table values */
extern const uint8_t  APBPrescTable[8U];   /*!< APB prescalers table values */

extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);

#endif /* PLL_H_ */
