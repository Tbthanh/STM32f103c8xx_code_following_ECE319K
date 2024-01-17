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

uint32_t SystemCoreClock    = 48000000;
uint8_t AHBPrescTable[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};

#define RCC_CR_HSEON 	0x00010000
#define RCC_CR_HSERDY	0x00020083
#define RCC_CR_RESET	0x00000083	// NOT SURE!!
#define RCC_CFGR_HPRE_DIV1	0x0070	// HPRE[7:4] 0---
#define RCC_CFGR_PPRE_DIV1	0x0400	// PPRE2[13:11] 0xx PPRE1[10:8] 0xx
#define RCC_CR_PLLRDY 	0x02000083	// NOT SURE!!
#define HSE_STARTUP_TIMEOUT   ((uint16_t)0x5000) /*!< Time out for HSE start up */
#define RCC_CFGR_SWS	0x0000000C
#define HSI_VALUE  ((uint32_t)8000000) /*!< Value of the Internal High Speed oscillator in Hz.
                                             The real value may vary depending on the variations
                                             in voltage and temperature.  */
#define HSE_VALUE    ((uint32_t)8000000) /*!< Value of the External oscillator in Hz*/

/* PLLMUL configuration */
// Ref: RM0008 7.3.2
#define  RCC_CFGR_PLLMUL                    ((uint32_t)0x003C0000)        /*!< PLLMUL[3:0] bits (PLL multiplication factor) */
#define  RCC_CFGR_PLLMUL_0                  ((uint32_t)0x00040000)        /*!< Bit 0 */
#define  RCC_CFGR_PLLMUL_1                  ((uint32_t)0x00080000)        /*!< Bit 1 */
#define  RCC_CFGR_PLLMUL_2                  ((uint32_t)0x00100000)        /*!< Bit 2 */
#define  RCC_CFGR_PLLMUL_3                  ((uint32_t)0x00200000)        /*!< Bit 3 */

#define  RCC_CFGR_PLLMUL2                   ((uint32_t)0x00000000)        /*!< PLL input clock*2 */
#define  RCC_CFGR_PLLMUL3                   ((uint32_t)0x00040000)        /*!< PLL input clock*3 */
#define  RCC_CFGR_PLLMUL4                   ((uint32_t)0x00080000)        /*!< PLL input clock*4 */
#define  RCC_CFGR_PLLMUL5                   ((uint32_t)0x000C0000)        /*!< PLL input clock*5 */
#define  RCC_CFGR_PLLMUL6                   ((uint32_t)0x00100000)        /*!< PLL input clock*6 */
#define  RCC_CFGR_PLLMUL7                   ((uint32_t)0x00140000)        /*!< PLL input clock*7 */
#define  RCC_CFGR_PLLMUL8                   ((uint32_t)0x00180000)        /*!< PLL input clock*8 */
#define  RCC_CFGR_PLLMUL9                   ((uint32_t)0x001C0000)        /*!< PLL input clock*9 */
#define  RCC_CFGR_PLLMUL10                  ((uint32_t)0x00200000)        /*!< PLL input clock10 */
#define  RCC_CFGR_PLLMUL11                  ((uint32_t)0x00240000)        /*!< PLL input clock*11 */
#define  RCC_CFGR_PLLMUL12                  ((uint32_t)0x00280000)        /*!< PLL input clock*12 */
#define  RCC_CFGR_PLLMUL13                  ((uint32_t)0x002C0000)        /*!< PLL input clock*13 */
#define  RCC_CFGR_PLLMUL14                  ((uint32_t)0x00300000)        /*!< PLL input clock*14 */
#define  RCC_CFGR_PLLMUL15                  ((uint32_t)0x00340000)        /*!< PLL input clock*15 */
#define  RCC_CFGR_PLLMUL16                  ((uint32_t)0x00380000)        /*!< PLL input clock*16 */

/* Old PLLMUL configuration bit definition maintained for legacy purposes */
#define  RCC_CFGR_PLLMULL                    RCC_CFGR_PLLMUL        /*!< PLLMUL[3:0] bits (PLL multiplication factor) */
#define  RCC_CFGR_PLLMULL_0                  RCC_CFGR_PLLMUL_0        /*!< Bit 0 */
#define  RCC_CFGR_PLLMULL_1                  RCC_CFGR_PLLMUL_1        /*!< Bit 1 */
#define  RCC_CFGR_PLLMULL_2                  RCC_CFGR_PLLMUL_2        /*!< Bit 2 */
#define  RCC_CFGR_PLLMULL_3                  RCC_CFGR_PLLMUL_3       /*!< Bit 3 */

#define  RCC_CFGR_PLLMULL2                   RCC_CFGR_PLLMUL2       /*!< PLL input clock*2 */
#define  RCC_CFGR_PLLMULL3                   RCC_CFGR_PLLMUL3        /*!< PLL input clock*3 */
#define  RCC_CFGR_PLLMULL4                   RCC_CFGR_PLLMUL4        /*!< PLL input clock*4 */
#define  RCC_CFGR_PLLMULL5                   RCC_CFGR_PLLMUL5        /*!< PLL input clock*5 */
#define  RCC_CFGR_PLLMULL6                   RCC_CFGR_PLLMUL6        /*!< PLL input clock*6 */
#define  RCC_CFGR_PLLMULL7                   RCC_CFGR_PLLMUL7        /*!< PLL input clock*7 */
#define  RCC_CFGR_PLLMULL8                   RCC_CFGR_PLLMUL8        /*!< PLL input clock*8 */
#define  RCC_CFGR_PLLMULL9                   RCC_CFGR_PLLMUL9        /*!< PLL input clock*9 */
#define  RCC_CFGR_PLLMULL10                  RCC_CFGR_PLLMUL10        /*!< PLL input clock10 */
#define  RCC_CFGR_PLLMULL11                  RCC_CFGR_PLLMUL11        /*!< PLL input clock*11 */
#define  RCC_CFGR_PLLMULL12                  RCC_CFGR_PLLMUL12        /*!< PLL input clock*12 */
#define  RCC_CFGR_PLLMULL13                  RCC_CFGR_PLLMUL13        /*!< PLL input clock*13 */
#define  RCC_CFGR_PLLMULL14                  RCC_CFGR_PLLMUL14        /*!< PLL input clock*14 */
#define  RCC_CFGR_PLLMULL15                  RCC_CFGR_PLLMUL15        /*!< PLL input clock*15 */
#define  RCC_CFGR_PLLMULL16                  RCC_CFGR_PLLMUL16        /*!< PLL input clock*16 */

#define  RCC_CFGR_PLLSRC                     ((uint32_t)0x00018000)        /*!< PLL entry clock source */
#define  RCC_CFGR_PLLSRC_0                   ((uint32_t)0x00008000)        /*!< Bit 0 (available only in the STM32F072 devices) */
#define  RCC_CFGR_PLLSRC_1                   ((uint32_t)0x00010000)        /*!< Bit 1 */

#define  RCC_CFGR_PLLSRC_PREDIV1             ((uint32_t)0x00010000)        /*!< PREDIV1 clock selected as PLL entry clock source;
                                                                                Old PREDIV1 bit definition, maintained for legacy purpose */
#define  RCC_CFGR_PLLSRC_HSI_DIV2            ((uint32_t)0x00000000)        /*!< HSI clock divided by 2 selected as PLL entry clock source */
#define  RCC_CFGR_PLLSRC_HSI_PREDIV          ((uint32_t)0x00008000)        /*!< HSI PREDIV clock selected as PLL entry clock source
                                                                                (This bit and configuration is only available for STM32F072 devices)*/
#define  RCC_CFGR_PLLSRC_HSE_PREDIV          ((uint32_t)0x00010000)        /*!< HSE PREDIV clock selected as PLL entry clock source */
#define  RCC_CFGR_PLLSRC_HSI48_PREDIV        ((uint32_t)0x00018000)        /*!< HSI48 PREDIV clock selected as PLL entry clock source */

#define  RCC_CFGR_PLLXTPRE                   ((uint32_t)0x00020000)        /*!< HSE divider for PLL entry */
#define  RCC_CFGR_PLLXTPRE_PREDIV1           ((uint32_t)0x00000000)        /*!< PREDIV1 clock not divided for PLL entry */
#define  RCC_CFGR_PLLXTPRE_PREDIV1_Div2      ((uint32_t)0x00020000)        /*!< PREDIV1 clock divided by 2 for PLL entry */

#define  RCC_CFGR_HPRE                       ((uint32_t)0x000000F0)        /*!< HPRE[3:0] bits (AHB prescaler) */
#define  RCC_CFGR_HPRE_0                     ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  RCC_CFGR_HPRE_1                     ((uint32_t)0x00000020)        /*!< Bit 1 */
#define  RCC_CFGR_HPRE_2                     ((uint32_t)0x00000040)        /*!< Bit 2 */
#define  RCC_CFGR_HPRE_3                     ((uint32_t)0x00000080)        /*!< Bit 3 */
/* HPRE configuration */
#define  RCC_CFGR_HPRE_DIV1                  ((uint32_t)0x00000000)        /*!< SYSCLK not divided */
#define  RCC_CFGR_HPRE_DIV2                  ((uint32_t)0x00000080)        /*!< SYSCLK divided by 2 */
#define  RCC_CFGR_HPRE_DIV4                  ((uint32_t)0x00000090)        /*!< SYSCLK divided by 4 */
#define  RCC_CFGR_HPRE_DIV8                  ((uint32_t)0x000000A0)        /*!< SYSCLK divided by 8 */
#define  RCC_CFGR_HPRE_DIV16                 ((uint32_t)0x000000B0)        /*!< SYSCLK divided by 16 */
#define  RCC_CFGR_HPRE_DIV64                 ((uint32_t)0x000000C0)        /*!< SYSCLK divided by 64 */
#define  RCC_CFGR_HPRE_DIV128                ((uint32_t)0x000000D0)        /*!< SYSCLK divided by 128 */
#define  RCC_CFGR_HPRE_DIV256                ((uint32_t)0x000000E0)        /*!< SYSCLK divided by 256 */
#define  RCC_CFGR_HPRE_DIV512                ((uint32_t)0x000000F0)        /*!< SYSCLK divided by 512 */

/*******************  Bit definition for RCC_CFGR2 register  ******************/
/* PREDIV1 configuration */
#define  RCC_CFGR2_PREDIV1                   ((uint32_t)0x0000000F)        /*!< PREDIV1[3:0] bits */
#define  RCC_CFGR2_PREDIV1_0                 ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  RCC_CFGR2_PREDIV1_1                 ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  RCC_CFGR2_PREDIV1_2                 ((uint32_t)0x00000004)        /*!< Bit 2 */
#define  RCC_CFGR2_PREDIV1_3                 ((uint32_t)0x00000008)        /*!< Bit 3 */

#define  RCC_CFGR2_PREDIV1_DIV1              ((uint32_t)0x00000000)        /*!< PREDIV1 input clock not divided */
#define  RCC_CFGR2_PREDIV1_DIV2              ((uint32_t)0x00000001)        /*!< PREDIV1 input clock divided by 2 */
#define  RCC_CFGR2_PREDIV1_DIV3              ((uint32_t)0x00000002)        /*!< PREDIV1 input clock divided by 3 */
#define  RCC_CFGR2_PREDIV1_DIV4              ((uint32_t)0x00000003)        /*!< PREDIV1 input clock divided by 4 */
#define  RCC_CFGR2_PREDIV1_DIV5              ((uint32_t)0x00000004)        /*!< PREDIV1 input clock divided by 5 */
#define  RCC_CFGR2_PREDIV1_DIV6              ((uint32_t)0x00000005)        /*!< PREDIV1 input clock divided by 6 */
#define  RCC_CFGR2_PREDIV1_DIV7              ((uint32_t)0x00000006)        /*!< PREDIV1 input clock divided by 7 */
#define  RCC_CFGR2_PREDIV1_DIV8              ((uint32_t)0x00000007)        /*!< PREDIV1 input clock divided by 8 */
#define  RCC_CFGR2_PREDIV1_DIV9              ((uint32_t)0x00000008)        /*!< PREDIV1 input clock divided by 9 */
#define  RCC_CFGR2_PREDIV1_DIV10             ((uint32_t)0x00000009)        /*!< PREDIV1 input clock divided by 10 */
#define  RCC_CFGR2_PREDIV1_DIV11             ((uint32_t)0x0000000A)        /*!< PREDIV1 input clock divided by 11 */
#define  RCC_CFGR2_PREDIV1_DIV12             ((uint32_t)0x0000000B)        /*!< PREDIV1 input clock divided by 12 */
#define  RCC_CFGR2_PREDIV1_DIV13             ((uint32_t)0x0000000C)        /*!< PREDIV1 input clock divided by 13 */
#define  RCC_CFGR2_PREDIV1_DIV14             ((uint32_t)0x0000000D)        /*!< PREDIV1 input clock divided by 14 */
#define  RCC_CFGR2_PREDIV1_DIV15             ((uint32_t)0x0000000E)        /*!< PREDIV1 input clock divided by 15 */
#define  RCC_CFGR2_PREDIV1_DIV16             ((uint32_t)0x0000000F)        /*!< PREDIV1 input clock divided by 16 */


// FOR FUTURE USE: https://github.com/Seeed-Studio/MotorBridgeCapeFirmwareSourceCode/blob/b7a4295901a3fc8a72a412de30b4ec96ff6e82dd/STM32F0xx_StdPeriph_Lib_V1.5.0/Libraries/CMSIS/Device/ST/STM32F0xx/Include/stm32f0xx.h

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
  tmp = *(RCC->CFGR) & RCC_CFGR_SWS;

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
      pllmull = *(RCC->CFGR) & RCC_CFGR_PLLMULL;
      pllsource = *(RCC->CFGR) & RCC_CFGR_PLLSRC;
      pllmull = ( pllmull >> 18) + 2;

      if (pllsource == 0x00)
      {
        /* HSI oscillator clock divided by 2 selected as PLL clock entry */
        SystemCoreClock = (HSI_VALUE >> 1) * pllmull;
      }
      else
      {
        prediv1factor = (*(RCC->CFGR2) & RCC_CFGR2_PREDIV1) + 1;
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
  tmp = AHBPrescTable[((*(RCC->CFGR) & RCC_CFGR_HPRE) >> 4)];
  /* HCLK clock frequency */
  SystemCoreClock >>= tmp;
}

#endif /* PLL_H_ */