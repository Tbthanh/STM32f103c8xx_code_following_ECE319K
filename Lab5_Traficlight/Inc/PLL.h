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

#define RCC_CR_HSEON 	0x00010000
#define RCC_CR_HSERDY	0x00020083
#define RCC_CR_RESET	0x00000083	// NOT SURE!!
#define RCC_CFGR_HPRE_DIV1	0x0070	// HPRE[7:4] 0---
#define RCC_CFGR_PPRE_DIV1	0x0400	// PPRE2[13:11] 0xx PPRE1[10:8] 0xx
#define RCC_CR_PLLRDY 	0x02000083	// NOT SURE!!
#define HSE_STARTUP_TIMEOUT   ((uint16_t)0x5000) /*!< Time out for HSE start up */

/**
  * @brief  Configures the System clock frequency, AHB/APBx prescalers and Flash
  *         settings.
  * @note   This function should be called only once the RCC clock configuration
  *         is reset to the default reset state (done in SystemInit() function).
  *         Original code's link: https://github.com/Seeed-Studio/MotorBridgeCapeFirmwareSourceCode/blob/master/STM32F0xx_StdPeriph_Lib_V1.5.0/Projects/STM32F0xx_StdPeriph_Examples/RCC/RCC_Example/system_stm32f0xx.c
  * @param  None
  * @retval None
  */
static void SetSysClock(void)
{
	uint32_t StartUpCounter = 0, HSEStatus = 0;

	/******************************************************************************/
	/*            PLL (clocked by HSE) used as System clock source                */
	/******************************************************************************/

	/* SYSCLK, HCLK, PCLK configuration ----------------------------------------*/
	/* Enable HSE */
	*(RCC->CR) |= ((uint32_t)RCC_CR_HSEON);

	/* Wait till HSE is ready and if Time out is reached exit */
	do
	{
		HSEStatus = *(RCC->CR) & RCC_CR_HSERDY;
		StartUpCounter++;
	} while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));

	if ((*(RCC->CR) & RCC_CR_HSERDY) != RCC_CR_RESET)
	{
		HSEStatus = (uint32_t)0x01;
	}
	else
	{
		HSEStatus = (uint32_t)0x00;
	}

	if (HSEStatus == (uint32_t)0x01)
	{
		// Skip this because not truly understand
		/* Enable Prefetch Buffer and set Flash Latency */
		//FLASH->ACR = FLASH_ACR_PRFTBE | FLASH_ACR_LATENCY;

		/* HCLK = SYSCLK */
		*(RCC->CFGR) |= (uint32_t)RCC_CFGR_HPRE_DIV1;

		/* PCLK = HCLK */
		*(RCC->CFGR) |= (uint32_t)RCC_CFGR_PPRE_DIV1;

		/* PLL configuration */
		// Clear bits
		*(RCC->CFGR) &= (uint32_t)((uint32_t)~0x003F0000);
		//*(RCC->CFGR) &= (uint32_t)((uint32_t)~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLMULL));
		// Set bits
		*(RCC->CFGR) |= (uint32_t)(0x00110000);
		//*(RCC->CFGR) |= (uint32_t)(RCC_CFGR_PLLSRC_PREDIV1 | RCC_CFGR_PLLXTPRE_PREDIV1 | RCC_CFGR_PLLMULL6);

		/* Enable PLL */
		//*(RCC->CR) |= RCC_CR_PLLON;
		*(RCC->CR) |= (uint32_t)0x01000000;

		/* Wait till PLL is ready */
		while((*(RCC->CR) & RCC_CR_PLLRDY) == 0)
		{
		}

		/* Select PLL as system clock source */
		//*(RCC->CFGR) &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
		*(RCC->CFGR) &= (uint32_t)((uint32_t)~(0x00000003));
		//*(RCC->CFGR) |= (uint32_t)RCC_CFGR_SW_PLL;
		*(RCC->CFGR) |= (uint32_t)0x00000002;

		/* Wait till PLL is used as system clock source */
		while ((*(RCC->CFGR) & (uint32_t)0x0000000C) != (uint32_t)0x00000008)
		{
		}
	}
	else
	{ /* If HSE fails to start-up, the application will have wrong clock
	 configuration. User can add here some code to deal with this error */
	}
}

/**
  * @brief  Setup the microcontroller system.
  *         Initialize the Embedded Flash Interface, the PLL and update the
  *         SystemCoreClock variable.
  * @param  None
  * @retval None
  */
void SystemInit(void)
{
	/* Set HSION bit */
	*(RCC->CR) |= (uint32_t)0x00000001;

	/* Reset SW[1:0], HPRE[3:0], PPRE[2:0], PPRE[2:0], ADCPRE and MCOSEL[2:0] bits */
	//RCC->CFGR &= (uint32_t)0xF8FFB80C;
	*(RCC->CFGR) &= (uint32_t)0xF8FFC00C;	// also reset PPRE2[2:0]

	/* Reset HSEON, CSSON and PLLON bits */
	*(RCC->CR) &= (uint32_t)0xFEF6FFFF;

	/* Reset HSEBYP bit */
	*(RCC->CR) &= (uint32_t)0xFFFBFFFF;

	/* Reset PLLSRC, PLLXTPRE and PLLMUL[3:0] bits */
	*(RCC->CFGR) &= (uint32_t)0xFFC0FFFF;

	/* Reset PREDIV1[3:0] bits */
	// Reference at 8.3.12 RM0008
	//RCC->CFGR2 &= (uint32_t)0xFFFFFFF0;

	/* Reset USARTSW[1:0], I2CSW, CECSW and ADCSW bits */
	//RCC->CFGR3 &= (uint32_t)0xFFFFFEAC;

	/* Reset HSI14 bit */
	//RCC->CR2 &= (uint32_t)0xFFFFFFFE;

	/* Disable all interrupts */
	*(RCC->CIR) = 0x00000000;

	/* Configure the System clock frequency, AHB/APBx prescalers and Flash settings */
	SetSysClock();
}


/**
  * @brief  Update SystemCoreClock according to Clock Register Values
  *         The SystemCoreClock variable contains the core clock (HCLK), it can
  *         be used by the user application to setup the SysTick timer or configure
  *         other parameters.
  *
  * @note   Each time the core clock (HCLK) changes, this function must be called
  *         to update SystemCoreClock variable value. Otherwise, any configuration
  *         based on this variable will be incorrect.
  *
  * @note   - The system frequency computed by this function is not the real
  *           frequency in the chip. It is calculated based on the predefined
  *           constant and the selected clock source:
  *
  *           - If SYSCLK source is HSI, SystemCoreClock will contain the HSI_VALUE(*)
  *
  *           - If SYSCLK source is HSE, SystemCoreClock will contain the HSE_VALUE(**)
  *
  *           - If SYSCLK source is PLL, SystemCoreClock will contain the HSE_VALUE(**)
  *             or HSI_VALUE(*) multiplied/divided by the PLL factors.
  *
  *         (*) HSI_VALUE is a constant defined in stm32f0xx.h file (default value
  *             8 MHz) but the real value may vary depending on the variations
  *             in voltage and temperature.
  *
  *         (**) HSE_VALUE is a constant defined in stm32f0xx.h file (default value
  *              8 MHz), user has to ensure that HSE_VALUE is same as the real
  *              frequency of the crystal used. Otherwise, this function may
  *              have wrong result.
  *
  *         - The result of this function could be not correct when using fractional
  *           value for HSE crystal.
  * @param  None
  * @retval None
  */
void SystemCoreClockUpdate (void)
{
  uint32_t tmp = 0, pllmull = 0, pllsource = 0, prediv1factor = 0;

  /* Get SYSCLK source -------------------------------------------------------*/
  tmp = RCC->CFGR & RCC_CFGR_SWS;

  switch (tmp)
  {
    case 0x00:  /* HSI used as system clock */
      SystemCoreClock = HSI_VALUE;
      break;
    case 0x04:  /* HSE used as system clock */
      SystemCoreClock = HSE_VALUE;
      break;
    case 0x08:  /* PLL used as system clock */
      /* Get PLL clock source and multiplication factor ----------------------*/
      pllmull = RCC->CFGR & RCC_CFGR_PLLMULL;
      pllsource = RCC->CFGR & RCC_CFGR_PLLSRC;
      pllmull = ( pllmull >> 18) + 2;

      if (pllsource == 0x00)
      {
        /* HSI oscillator clock divided by 2 selected as PLL clock entry */
        SystemCoreClock = (HSI_VALUE >> 1) * pllmull;
      }
      else
      {
        prediv1factor = (RCC->CFGR2 & RCC_CFGR2_PREDIV1) + 1;
        /* HSE oscillator clock selected as PREDIV1 clock entry */
        SystemCoreClock = (HSE_VALUE / prediv1factor) * pllmull;
      }
      break;
    default: /* HSI used as system clock */
      SystemCoreClock = HSI_VALUE;
      break;
  }
  /* Compute HCLK clock frequency ----------------*/
  /* Get HCLK prescaler */
  tmp = AHBPrescTable[((RCC->CFGR & RCC_CFGR_HPRE) >> 4)];
  /* HCLK clock frequency */
  SystemCoreClock >>= tmp;
}

#endif /* PLL_H_ */
