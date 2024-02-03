/*
 * Register.h
 *
 *  Created on: Jan 11, 2024
 *      Author: Tran Ba Thanh
 *     Purpose: To create a memory map structure of GPIOA,B and RCC
 */

#ifndef REGISTER_H_
#define REGISTER_H_
#include <stdint.h>

/* Register address */
// Base address
#define RCC_BASE				(0x40021000)
#define GPIOA_BASE			(0x40010800)
#define GPIOB_BASE			(0x40010C00)

// RCC structure
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t AHPRSTR;
	volatile uint32_t CFGR2;
}RCC_struct;
#define RCC ((RCC_struct *)RCC_BASE)


typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_struct;
#define GPIOA ((GPIO_struct *) GPIOA_BASE)
#define GPIOB ((GPIO_struct *) GPIOB_BASE)


/*
Copied from: https://github.com/csrohit/bluepill-systick/blob/047398aa746acd989d3ad4792f8e3cb7e1bcaf31/baremetal/include/stm32f103xb.h
*/
/*!< Interrupt Number Definition */
typedef enum
{
/******  Cortex-M3 Processor Exceptions Numbers ***************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                             */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M3 Hard Fault Interrupt                     */
  MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M3 Memory Management Interrupt              */
  BusFault_IRQn               = -11,    /*!< 5 Cortex-M3 Bus Fault Interrupt                      */
  UsageFault_IRQn             = -10,    /*!< 6 Cortex-M3 Usage Fault Interrupt                    */
  SVCall_IRQn                 = -5,     /*!< 11 Cortex-M3 SV Call Interrupt                       */
  DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M3 Debug Monitor Interrupt                 */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M3 Pend SV Interrupt                       */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M3 System Tick Interrupt                   */

/******  STM32 specific Interrupt Numbers *********************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                            */
  PVD_IRQn                    = 1,      /*!< PVD through EXTI Line detection Interrupt            */
  TAMPER_IRQn                 = 2,      /*!< Tamper Interrupt                                     */
  RTC_IRQn                    = 3,      /*!< RTC global Interrupt                                 */
  FLASH_IRQn                  = 4,      /*!< FLASH global Interrupt                               */
  RCC_IRQn                    = 5,      /*!< RCC global Interrupt                                 */
  EXTI0_IRQn                  = 6,      /*!< EXTI Line0 Interrupt                                 */
  EXTI1_IRQn                  = 7,      /*!< EXTI Line1 Interrupt                                 */
  EXTI2_IRQn                  = 8,      /*!< EXTI Line2 Interrupt                                 */
  EXTI3_IRQn                  = 9,      /*!< EXTI Line3 Interrupt                                 */
  EXTI4_IRQn                  = 10,     /*!< EXTI Line4 Interrupt                                 */
  DMA1_Channel1_IRQn          = 11,     /*!< DMA1 Channel 1 global Interrupt                      */
  DMA1_Channel2_IRQn          = 12,     /*!< DMA1 Channel 2 global Interrupt                      */
  DMA1_Channel3_IRQn          = 13,     /*!< DMA1 Channel 3 global Interrupt                      */
  DMA1_Channel4_IRQn          = 14,     /*!< DMA1 Channel 4 global Interrupt                      */
  DMA1_Channel5_IRQn          = 15,     /*!< DMA1 Channel 5 global Interrupt                      */
  DMA1_Channel6_IRQn          = 16,     /*!< DMA1 Channel 6 global Interrupt                      */
  DMA1_Channel7_IRQn          = 17,     /*!< DMA1 Channel 7 global Interrupt                      */
  ADC1_2_IRQn                 = 18,     /*!< ADC1 and ADC2 global Interrupt                       */
  USB_HP_CAN1_TX_IRQn         = 19,     /*!< USB Device High Priority or CAN1 TX Interrupts       */
  USB_LP_CAN1_RX0_IRQn        = 20,     /*!< USB Device Low Priority or CAN1 RX0 Interrupts       */
  CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1 Interrupt                                   */
  CAN1_SCE_IRQn               = 22,     /*!< CAN1 SCE Interrupt                                   */
  EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                        */
  TIM1_BRK_IRQn               = 24,     /*!< TIM1 Break Interrupt                                 */
  TIM1_UP_IRQn                = 25,     /*!< TIM1 Update Interrupt                                */
  TIM1_TRG_COM_IRQn           = 26,     /*!< TIM1 Trigger and Commutation Interrupt               */
  TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                       */
  TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                */
  TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                */
  TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                */
  I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                 */
  I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                 */
  I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                 */
  I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                 */
  SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                */
  SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                */
  USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                              */
  USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                              */
  USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                              */
  EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                      */
  RTC_Alarm_IRQn              = 41,     /*!< RTC Alarm through EXTI Line Interrupt                */
  USBWakeUp_IRQn              = 42,     /*!< USB Device WakeUp from suspend through EXTI Line Interrupt */
} IRQn_Type;

/******************************************************************************/
/*                         Peripheral Registers_Bits_Definition               */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                         Reset and Clock Control                            */
/*                                                                            */
/******************************************************************************/

/********************  Bit definition for RCC_CR register  ********************/
#define RCC_CR_HSION_Pos                     (0U)                              
#define RCC_CR_HSION_Msk                     (0x1UL << RCC_CR_HSION_Pos)        /*!< 0x00000001 */
#define RCC_CR_HSION                         RCC_CR_HSION_Msk                  /*!< Internal High Speed clock enable */
#define RCC_CR_HSIRDY_Pos                    (1U)                              
#define RCC_CR_HSIRDY_Msk                    (0x1UL << RCC_CR_HSIRDY_Pos)       /*!< 0x00000002 */
#define RCC_CR_HSIRDY                        RCC_CR_HSIRDY_Msk                 /*!< Internal High Speed clock ready flag */
#define RCC_CR_HSITRIM_Pos                   (3U)                              
#define RCC_CR_HSITRIM_Msk                   (0x1FUL << RCC_CR_HSITRIM_Pos)     /*!< 0x000000F8 */
#define RCC_CR_HSITRIM                       RCC_CR_HSITRIM_Msk                /*!< Internal High Speed clock trimming */
#define RCC_CR_HSICAL_Pos                    (8U)                              
#define RCC_CR_HSICAL_Msk                    (0xFFUL << RCC_CR_HSICAL_Pos)      /*!< 0x0000FF00 */
#define RCC_CR_HSICAL                        RCC_CR_HSICAL_Msk                 /*!< Internal High Speed clock Calibration */
#define RCC_CR_HSEON_Pos                     (16U)                             
#define RCC_CR_HSEON_Msk                     (0x1UL << RCC_CR_HSEON_Pos)        /*!< 0x00010000 */
#define RCC_CR_HSEON                         RCC_CR_HSEON_Msk                  /*!< External High Speed clock enable */
#define RCC_CR_HSERDY_Pos                    (17U)                             
#define RCC_CR_HSERDY_Msk                    (0x1UL << RCC_CR_HSERDY_Pos)       /*!< 0x00020000 */
#define RCC_CR_HSERDY                        RCC_CR_HSERDY_Msk                 /*!< External High Speed clock ready flag */
#define RCC_CR_HSEBYP_Pos                    (18U)                             
#define RCC_CR_HSEBYP_Msk                    (0x1UL << RCC_CR_HSEBYP_Pos)       /*!< 0x00040000 */
#define RCC_CR_HSEBYP                        RCC_CR_HSEBYP_Msk                 /*!< External High Speed clock Bypass */
#define RCC_CR_CSSON_Pos                     (19U)                             
#define RCC_CR_CSSON_Msk                     (0x1UL << RCC_CR_CSSON_Pos)        /*!< 0x00080000 */
#define RCC_CR_CSSON                         RCC_CR_CSSON_Msk                  /*!< Clock Security System enable */
#define RCC_CR_PLLON_Pos                     (24U)                             
#define RCC_CR_PLLON_Msk                     (0x1UL << RCC_CR_PLLON_Pos)        /*!< 0x01000000 */
#define RCC_CR_PLLON                         RCC_CR_PLLON_Msk                  /*!< PLL enable */
#define RCC_CR_PLLRDY_Pos                    (25U)                             
#define RCC_CR_PLLRDY_Msk                    (0x1UL << RCC_CR_PLLRDY_Pos)       /*!< 0x02000000 */
#define RCC_CR_PLLRDY                        RCC_CR_PLLRDY_Msk                 /*!< PLL clock ready flag */


/*******************  Bit definition for RCC_CFGR register  *******************/
/*!< SW configuration */
#define RCC_CFGR_SW_Pos                      (0U)                              
#define RCC_CFGR_SW_Msk                      (0x3UL << RCC_CFGR_SW_Pos)         /*!< 0x00000003 */
#define RCC_CFGR_SW                          RCC_CFGR_SW_Msk                   /*!< SW[1:0] bits (System clock Switch) */
#define RCC_CFGR_SW_0                        (0x1UL << RCC_CFGR_SW_Pos)         /*!< 0x00000001 */
#define RCC_CFGR_SW_1                        (0x2UL << RCC_CFGR_SW_Pos)         /*!< 0x00000002 */

#define RCC_CFGR_SW_HSI                      0x00000000U                       /*!< HSI selected as system clock */
#define RCC_CFGR_SW_HSE                      0x00000001U                       /*!< HSE selected as system clock */
#define RCC_CFGR_SW_PLL                      0x00000002U                       /*!< PLL selected as system clock */

/*!< SWS configuration */
#define RCC_CFGR_SWS_Pos                     (2U)                              
#define RCC_CFGR_SWS_Msk                     (0x3UL << RCC_CFGR_SWS_Pos)        /*!< 0x0000000C */
#define RCC_CFGR_SWS                         RCC_CFGR_SWS_Msk                  /*!< SWS[1:0] bits (System Clock Switch Status) */
#define RCC_CFGR_SWS_0                       (0x1UL << RCC_CFGR_SWS_Pos)        /*!< 0x00000004 */
#define RCC_CFGR_SWS_1                       (0x2UL << RCC_CFGR_SWS_Pos)        /*!< 0x00000008 */

#define RCC_CFGR_SWS_HSI                     0x00000000U                       /*!< HSI oscillator used as system clock */
#define RCC_CFGR_SWS_HSE                     0x00000004U                       /*!< HSE oscillator used as system clock */
#define RCC_CFGR_SWS_PLL                     0x00000008U                       /*!< PLL used as system clock */

/*!< HPRE configuration */
#define RCC_CFGR_HPRE_Pos                    (4U)                              
#define RCC_CFGR_HPRE_Msk                    (0xFUL << RCC_CFGR_HPRE_Pos)       /*!< 0x000000F0 */
#define RCC_CFGR_HPRE                        RCC_CFGR_HPRE_Msk                 /*!< HPRE[3:0] bits (AHB prescaler) */
#define RCC_CFGR_HPRE_0                      (0x1UL << RCC_CFGR_HPRE_Pos)       /*!< 0x00000010 */
#define RCC_CFGR_HPRE_1                      (0x2UL << RCC_CFGR_HPRE_Pos)       /*!< 0x00000020 */
#define RCC_CFGR_HPRE_2                      (0x4UL << RCC_CFGR_HPRE_Pos)       /*!< 0x00000040 */
#define RCC_CFGR_HPRE_3                      (0x8UL << RCC_CFGR_HPRE_Pos)       /*!< 0x00000080 */

#define RCC_CFGR_HPRE_DIV1                   0x00000000U                       /*!< SYSCLK not divided */
#define RCC_CFGR_HPRE_DIV2                   0x00000080U                       /*!< SYSCLK divided by 2 */
#define RCC_CFGR_HPRE_DIV4                   0x00000090U                       /*!< SYSCLK divided by 4 */
#define RCC_CFGR_HPRE_DIV8                   0x000000A0U                       /*!< SYSCLK divided by 8 */
#define RCC_CFGR_HPRE_DIV16                  0x000000B0U                       /*!< SYSCLK divided by 16 */
#define RCC_CFGR_HPRE_DIV64                  0x000000C0U                       /*!< SYSCLK divided by 64 */
#define RCC_CFGR_HPRE_DIV128                 0x000000D0U                       /*!< SYSCLK divided by 128 */
#define RCC_CFGR_HPRE_DIV256                 0x000000E0U                       /*!< SYSCLK divided by 256 */
#define RCC_CFGR_HPRE_DIV512                 0x000000F0U                       /*!< SYSCLK divided by 512 */

/*!< PPRE1 configuration */
#define RCC_CFGR_PPRE1_Pos                   (8U)                              
#define RCC_CFGR_PPRE1_Msk                   (0x7UL << RCC_CFGR_PPRE1_Pos)      /*!< 0x00000700 */
#define RCC_CFGR_PPRE1                       RCC_CFGR_PPRE1_Msk                /*!< PRE1[2:0] bits (APB1 prescaler) */
#define RCC_CFGR_PPRE1_0                     (0x1UL << RCC_CFGR_PPRE1_Pos)      /*!< 0x00000100 */
#define RCC_CFGR_PPRE1_1                     (0x2UL << RCC_CFGR_PPRE1_Pos)      /*!< 0x00000200 */
#define RCC_CFGR_PPRE1_2                     (0x4UL << RCC_CFGR_PPRE1_Pos)      /*!< 0x00000400 */

#define RCC_CFGR_PPRE1_DIV1                  0x00000000U                       /*!< HCLK not divided */
#define RCC_CFGR_PPRE1_DIV2                  0x00000400U                       /*!< HCLK divided by 2 */
#define RCC_CFGR_PPRE1_DIV4                  0x00000500U                       /*!< HCLK divided by 4 */
#define RCC_CFGR_PPRE1_DIV8                  0x00000600U                       /*!< HCLK divided by 8 */
#define RCC_CFGR_PPRE1_DIV16                 0x00000700U                       /*!< HCLK divided by 16 */

/*!< PPRE2 configuration */
#define RCC_CFGR_PPRE2_Pos                   (11U)                             
#define RCC_CFGR_PPRE2_Msk                   (0x7UL << RCC_CFGR_PPRE2_Pos)      /*!< 0x00003800 */
#define RCC_CFGR_PPRE2                       RCC_CFGR_PPRE2_Msk                /*!< PRE2[2:0] bits (APB2 prescaler) */
#define RCC_CFGR_PPRE2_0                     (0x1UL << RCC_CFGR_PPRE2_Pos)      /*!< 0x00000800 */
#define RCC_CFGR_PPRE2_1                     (0x2UL << RCC_CFGR_PPRE2_Pos)      /*!< 0x00001000 */
#define RCC_CFGR_PPRE2_2                     (0x4UL << RCC_CFGR_PPRE2_Pos)      /*!< 0x00002000 */

#define RCC_CFGR_PPRE2_DIV1                  0x00000000U                       /*!< HCLK not divided */
#define RCC_CFGR_PPRE2_DIV2                  0x00002000U                       /*!< HCLK divided by 2 */
#define RCC_CFGR_PPRE2_DIV4                  0x00002800U                       /*!< HCLK divided by 4 */
#define RCC_CFGR_PPRE2_DIV8                  0x00003000U                       /*!< HCLK divided by 8 */
#define RCC_CFGR_PPRE2_DIV16                 0x00003800U                       /*!< HCLK divided by 16 */

/*!< ADCPPRE configuration */
#define RCC_CFGR_ADCPRE_Pos                  (14U)                             
#define RCC_CFGR_ADCPRE_Msk                  (0x3UL << RCC_CFGR_ADCPRE_Pos)     /*!< 0x0000C000 */
#define RCC_CFGR_ADCPRE                      RCC_CFGR_ADCPRE_Msk               /*!< ADCPRE[1:0] bits (ADC prescaler) */
#define RCC_CFGR_ADCPRE_0                    (0x1UL << RCC_CFGR_ADCPRE_Pos)     /*!< 0x00004000 */
#define RCC_CFGR_ADCPRE_1                    (0x2UL << RCC_CFGR_ADCPRE_Pos)     /*!< 0x00008000 */

#define RCC_CFGR_ADCPRE_DIV2                 0x00000000U                       /*!< PCLK2 divided by 2 */
#define RCC_CFGR_ADCPRE_DIV4                 0x00004000U                       /*!< PCLK2 divided by 4 */
#define RCC_CFGR_ADCPRE_DIV6                 0x00008000U                       /*!< PCLK2 divided by 6 */
#define RCC_CFGR_ADCPRE_DIV8                 0x0000C000U                       /*!< PCLK2 divided by 8 */

#define RCC_CFGR_PLLSRC_Pos                  (16U)                             
#define RCC_CFGR_PLLSRC_Msk                  (0x1UL << RCC_CFGR_PLLSRC_Pos)     /*!< 0x00010000 */
#define RCC_CFGR_PLLSRC                      RCC_CFGR_PLLSRC_Msk               /*!< PLL entry clock source */

#define RCC_CFGR_PLLXTPRE_Pos                (17U)                             
#define RCC_CFGR_PLLXTPRE_Msk                (0x1UL << RCC_CFGR_PLLXTPRE_Pos)   /*!< 0x00020000 */
#define RCC_CFGR_PLLXTPRE                    RCC_CFGR_PLLXTPRE_Msk             /*!< HSE divider for PLL entry */

/*!< PLLMUL configuration */
#define RCC_CFGR_PLLMULL_Pos                 (18U)                             
#define RCC_CFGR_PLLMULL_Msk                 (0xFUL << RCC_CFGR_PLLMULL_Pos)    /*!< 0x003C0000 */
#define RCC_CFGR_PLLMULL                     RCC_CFGR_PLLMULL_Msk              /*!< PLLMUL[3:0] bits (PLL multiplication factor) */
#define RCC_CFGR_PLLMULL_0                   (0x1UL << RCC_CFGR_PLLMULL_Pos)    /*!< 0x00040000 */
#define RCC_CFGR_PLLMULL_1                   (0x2UL << RCC_CFGR_PLLMULL_Pos)    /*!< 0x00080000 */
#define RCC_CFGR_PLLMULL_2                   (0x4UL << RCC_CFGR_PLLMULL_Pos)    /*!< 0x00100000 */
#define RCC_CFGR_PLLMULL_3                   (0x8UL << RCC_CFGR_PLLMULL_Pos)    /*!< 0x00200000 */

#define RCC_CFGR_PLLXTPRE_HSE                0x00000000U                      /*!< HSE clock not divided for PLL entry */
#define RCC_CFGR_PLLXTPRE_HSE_DIV2           0x00020000U                      /*!< HSE clock divided by 2 for PLL entry */

#define RCC_CFGR_PLLMULL2                    0x00000000U                       /*!< PLL input clock*2 */
#define RCC_CFGR_PLLMULL3_Pos                (18U)                             
#define RCC_CFGR_PLLMULL3_Msk                (0x1UL << RCC_CFGR_PLLMULL3_Pos)   /*!< 0x00040000 */
#define RCC_CFGR_PLLMULL3                    RCC_CFGR_PLLMULL3_Msk             /*!< PLL input clock*3 */
#define RCC_CFGR_PLLMULL4_Pos                (19U)                             
#define RCC_CFGR_PLLMULL4_Msk                (0x1UL << RCC_CFGR_PLLMULL4_Pos)   /*!< 0x00080000 */
#define RCC_CFGR_PLLMULL4                    RCC_CFGR_PLLMULL4_Msk             /*!< PLL input clock*4 */
#define RCC_CFGR_PLLMULL5_Pos                (18U)                             
#define RCC_CFGR_PLLMULL5_Msk                (0x3UL << RCC_CFGR_PLLMULL5_Pos)   /*!< 0x000C0000 */
#define RCC_CFGR_PLLMULL5                    RCC_CFGR_PLLMULL5_Msk             /*!< PLL input clock*5 */
#define RCC_CFGR_PLLMULL6_Pos                (20U)                             
#define RCC_CFGR_PLLMULL6_Msk                (0x1UL << RCC_CFGR_PLLMULL6_Pos)   /*!< 0x00100000 */
#define RCC_CFGR_PLLMULL6                    RCC_CFGR_PLLMULL6_Msk             /*!< PLL input clock*6 */
#define RCC_CFGR_PLLMULL7_Pos                (18U)                             
#define RCC_CFGR_PLLMULL7_Msk                (0x5UL << RCC_CFGR_PLLMULL7_Pos)   /*!< 0x00140000 */
#define RCC_CFGR_PLLMULL7                    RCC_CFGR_PLLMULL7_Msk             /*!< PLL input clock*7 */
#define RCC_CFGR_PLLMULL8_Pos                (19U)                             
#define RCC_CFGR_PLLMULL8_Msk                (0x3UL << RCC_CFGR_PLLMULL8_Pos)   /*!< 0x00180000 */
#define RCC_CFGR_PLLMULL8                    RCC_CFGR_PLLMULL8_Msk             /*!< PLL input clock*8 */
#define RCC_CFGR_PLLMULL9_Pos                (18U)                             
#define RCC_CFGR_PLLMULL9_Msk                (0x7UL << RCC_CFGR_PLLMULL9_Pos)   /*!< 0x001C0000 */
#define RCC_CFGR_PLLMULL9                    RCC_CFGR_PLLMULL9_Msk             /*!< PLL input clock*9 */
#define RCC_CFGR_PLLMULL10_Pos               (21U)                             
#define RCC_CFGR_PLLMULL10_Msk               (0x1UL << RCC_CFGR_PLLMULL10_Pos)  /*!< 0x00200000 */
#define RCC_CFGR_PLLMULL10                   RCC_CFGR_PLLMULL10_Msk            /*!< PLL input clock10 */
#define RCC_CFGR_PLLMULL11_Pos               (18U)                             
#define RCC_CFGR_PLLMULL11_Msk               (0x9UL << RCC_CFGR_PLLMULL11_Pos)  /*!< 0x00240000 */
#define RCC_CFGR_PLLMULL11                   RCC_CFGR_PLLMULL11_Msk            /*!< PLL input clock*11 */
#define RCC_CFGR_PLLMULL12_Pos               (19U)                             
#define RCC_CFGR_PLLMULL12_Msk               (0x5UL << RCC_CFGR_PLLMULL12_Pos)  /*!< 0x00280000 */
#define RCC_CFGR_PLLMULL12                   RCC_CFGR_PLLMULL12_Msk            /*!< PLL input clock*12 */
#define RCC_CFGR_PLLMULL13_Pos               (18U)                             
#define RCC_CFGR_PLLMULL13_Msk               (0xBUL << RCC_CFGR_PLLMULL13_Pos)  /*!< 0x002C0000 */
#define RCC_CFGR_PLLMULL13                   RCC_CFGR_PLLMULL13_Msk            /*!< PLL input clock*13 */
#define RCC_CFGR_PLLMULL14_Pos               (20U)                             
#define RCC_CFGR_PLLMULL14_Msk               (0x3UL << RCC_CFGR_PLLMULL14_Pos)  /*!< 0x00300000 */
#define RCC_CFGR_PLLMULL14                   RCC_CFGR_PLLMULL14_Msk            /*!< PLL input clock*14 */
#define RCC_CFGR_PLLMULL15_Pos               (18U)                             
#define RCC_CFGR_PLLMULL15_Msk               (0xDUL << RCC_CFGR_PLLMULL15_Pos)  /*!< 0x00340000 */
#define RCC_CFGR_PLLMULL15                   RCC_CFGR_PLLMULL15_Msk            /*!< PLL input clock*15 */
#define RCC_CFGR_PLLMULL16_Pos               (19U)                             
#define RCC_CFGR_PLLMULL16_Msk               (0x7UL << RCC_CFGR_PLLMULL16_Pos)  /*!< 0x00380000 */
#define RCC_CFGR_PLLMULL16                   RCC_CFGR_PLLMULL16_Msk            /*!< PLL input clock*16 */
#define RCC_CFGR_USBPRE_Pos                  (22U)                             
#define RCC_CFGR_USBPRE_Msk                  (0x1UL << RCC_CFGR_USBPRE_Pos)     /*!< 0x00400000 */
#define RCC_CFGR_USBPRE                      RCC_CFGR_USBPRE_Msk               /*!< USB Device prescaler */

/*!< MCO configuration */
#define RCC_CFGR_MCO_Pos                     (24U)                             
#define RCC_CFGR_MCO_Msk                     (0x7UL << RCC_CFGR_MCO_Pos)        /*!< 0x07000000 */
#define RCC_CFGR_MCO                         RCC_CFGR_MCO_Msk                  /*!< MCO[2:0] bits (Microcontroller Clock Output) */
#define RCC_CFGR_MCO_0                       (0x1UL << RCC_CFGR_MCO_Pos)        /*!< 0x01000000 */
#define RCC_CFGR_MCO_1                       (0x2UL << RCC_CFGR_MCO_Pos)        /*!< 0x02000000 */
#define RCC_CFGR_MCO_2                       (0x4UL << RCC_CFGR_MCO_Pos)        /*!< 0x04000000 */

#define RCC_CFGR_MCO_NOCLOCK                 0x00000000U                        /*!< No clock */
#define RCC_CFGR_MCO_SYSCLK                  0x04000000U                        /*!< System clock selected as MCO source */
#define RCC_CFGR_MCO_HSI                     0x05000000U                        /*!< HSI clock selected as MCO source */
#define RCC_CFGR_MCO_HSE                     0x06000000U                        /*!< HSE clock selected as MCO source  */
#define RCC_CFGR_MCO_PLLCLK_DIV2             0x07000000U                        /*!< PLL clock divided by 2 selected as MCO source */

 /* Reference defines */
 #define RCC_CFGR_MCOSEL                      RCC_CFGR_MCO
 #define RCC_CFGR_MCOSEL_0                    RCC_CFGR_MCO_0
 #define RCC_CFGR_MCOSEL_1                    RCC_CFGR_MCO_1
 #define RCC_CFGR_MCOSEL_2                    RCC_CFGR_MCO_2
 #define RCC_CFGR_MCOSEL_NOCLOCK              RCC_CFGR_MCO_NOCLOCK
 #define RCC_CFGR_MCOSEL_SYSCLK               RCC_CFGR_MCO_SYSCLK
 #define RCC_CFGR_MCOSEL_HSI                  RCC_CFGR_MCO_HSI
 #define RCC_CFGR_MCOSEL_HSE                  RCC_CFGR_MCO_HSE
 #define RCC_CFGR_MCOSEL_PLL_DIV2             RCC_CFGR_MCO_PLLCLK_DIV2

/*!<******************  Bit definition for RCC_CIR register  ********************/
#define RCC_CIR_LSIRDYF_Pos                  (0U)                              
#define RCC_CIR_LSIRDYF_Msk                  (0x1UL << RCC_CIR_LSIRDYF_Pos)     /*!< 0x00000001 */
#define RCC_CIR_LSIRDYF                      RCC_CIR_LSIRDYF_Msk               /*!< LSI Ready Interrupt flag */
#define RCC_CIR_LSERDYF_Pos                  (1U)                              
#define RCC_CIR_LSERDYF_Msk                  (0x1UL << RCC_CIR_LSERDYF_Pos)     /*!< 0x00000002 */
#define RCC_CIR_LSERDYF                      RCC_CIR_LSERDYF_Msk               /*!< LSE Ready Interrupt flag */
#define RCC_CIR_HSIRDYF_Pos                  (2U)                              
#define RCC_CIR_HSIRDYF_Msk                  (0x1UL << RCC_CIR_HSIRDYF_Pos)     /*!< 0x00000004 */
#define RCC_CIR_HSIRDYF                      RCC_CIR_HSIRDYF_Msk               /*!< HSI Ready Interrupt flag */
#define RCC_CIR_HSERDYF_Pos                  (3U)                              
#define RCC_CIR_HSERDYF_Msk                  (0x1UL << RCC_CIR_HSERDYF_Pos)     /*!< 0x00000008 */
#define RCC_CIR_HSERDYF                      RCC_CIR_HSERDYF_Msk               /*!< HSE Ready Interrupt flag */
#define RCC_CIR_PLLRDYF_Pos                  (4U)                              
#define RCC_CIR_PLLRDYF_Msk                  (0x1UL << RCC_CIR_PLLRDYF_Pos)     /*!< 0x00000010 */
#define RCC_CIR_PLLRDYF                      RCC_CIR_PLLRDYF_Msk               /*!< PLL Ready Interrupt flag */
#define RCC_CIR_CSSF_Pos                     (7U)                              
#define RCC_CIR_CSSF_Msk                     (0x1UL << RCC_CIR_CSSF_Pos)        /*!< 0x00000080 */
#define RCC_CIR_CSSF                         RCC_CIR_CSSF_Msk                  /*!< Clock Security System Interrupt flag */
#define RCC_CIR_LSIRDYIE_Pos                 (8U)                              
#define RCC_CIR_LSIRDYIE_Msk                 (0x1UL << RCC_CIR_LSIRDYIE_Pos)    /*!< 0x00000100 */
#define RCC_CIR_LSIRDYIE                     RCC_CIR_LSIRDYIE_Msk              /*!< LSI Ready Interrupt Enable */
#define RCC_CIR_LSERDYIE_Pos                 (9U)                              
#define RCC_CIR_LSERDYIE_Msk                 (0x1UL << RCC_CIR_LSERDYIE_Pos)    /*!< 0x00000200 */
#define RCC_CIR_LSERDYIE                     RCC_CIR_LSERDYIE_Msk              /*!< LSE Ready Interrupt Enable */
#define RCC_CIR_HSIRDYIE_Pos                 (10U)                             
#define RCC_CIR_HSIRDYIE_Msk                 (0x1UL << RCC_CIR_HSIRDYIE_Pos)    /*!< 0x00000400 */
#define RCC_CIR_HSIRDYIE                     RCC_CIR_HSIRDYIE_Msk              /*!< HSI Ready Interrupt Enable */
#define RCC_CIR_HSERDYIE_Pos                 (11U)                             
#define RCC_CIR_HSERDYIE_Msk                 (0x1UL << RCC_CIR_HSERDYIE_Pos)    /*!< 0x00000800 */
#define RCC_CIR_HSERDYIE                     RCC_CIR_HSERDYIE_Msk              /*!< HSE Ready Interrupt Enable */
#define RCC_CIR_PLLRDYIE_Pos                 (12U)                             
#define RCC_CIR_PLLRDYIE_Msk                 (0x1UL << RCC_CIR_PLLRDYIE_Pos)    /*!< 0x00001000 */
#define RCC_CIR_PLLRDYIE                     RCC_CIR_PLLRDYIE_Msk              /*!< PLL Ready Interrupt Enable */
#define RCC_CIR_LSIRDYC_Pos                  (16U)                             
#define RCC_CIR_LSIRDYC_Msk                  (0x1UL << RCC_CIR_LSIRDYC_Pos)     /*!< 0x00010000 */
#define RCC_CIR_LSIRDYC                      RCC_CIR_LSIRDYC_Msk               /*!< LSI Ready Interrupt Clear */
#define RCC_CIR_LSERDYC_Pos                  (17U)                             
#define RCC_CIR_LSERDYC_Msk                  (0x1UL << RCC_CIR_LSERDYC_Pos)     /*!< 0x00020000 */
#define RCC_CIR_LSERDYC                      RCC_CIR_LSERDYC_Msk               /*!< LSE Ready Interrupt Clear */
#define RCC_CIR_HSIRDYC_Pos                  (18U)                             
#define RCC_CIR_HSIRDYC_Msk                  (0x1UL << RCC_CIR_HSIRDYC_Pos)     /*!< 0x00040000 */
#define RCC_CIR_HSIRDYC                      RCC_CIR_HSIRDYC_Msk               /*!< HSI Ready Interrupt Clear */
#define RCC_CIR_HSERDYC_Pos                  (19U)                             
#define RCC_CIR_HSERDYC_Msk                  (0x1UL << RCC_CIR_HSERDYC_Pos)     /*!< 0x00080000 */
#define RCC_CIR_HSERDYC                      RCC_CIR_HSERDYC_Msk               /*!< HSE Ready Interrupt Clear */
#define RCC_CIR_PLLRDYC_Pos                  (20U)                             
#define RCC_CIR_PLLRDYC_Msk                  (0x1UL << RCC_CIR_PLLRDYC_Pos)     /*!< 0x00100000 */
#define RCC_CIR_PLLRDYC                      RCC_CIR_PLLRDYC_Msk               /*!< PLL Ready Interrupt Clear */
#define RCC_CIR_CSSC_Pos                     (23U)                             
#define RCC_CIR_CSSC_Msk                     (0x1UL << RCC_CIR_CSSC_Pos)        /*!< 0x00800000 */
#define RCC_CIR_CSSC                         RCC_CIR_CSSC_Msk                  /*!< Clock Security System Interrupt Clear */


/*****************  Bit definition for RCC_APB2RSTR register  *****************/
#define RCC_APB2RSTR_AFIORST_Pos             (0U)                              
#define RCC_APB2RSTR_AFIORST_Msk             (0x1UL << RCC_APB2RSTR_AFIORST_Pos) /*!< 0x00000001 */
#define RCC_APB2RSTR_AFIORST                 RCC_APB2RSTR_AFIORST_Msk          /*!< Alternate Function I/O reset */
#define RCC_APB2RSTR_IOPARST_Pos             (2U)                              
#define RCC_APB2RSTR_IOPARST_Msk             (0x1UL << RCC_APB2RSTR_IOPARST_Pos) /*!< 0x00000004 */
#define RCC_APB2RSTR_IOPARST                 RCC_APB2RSTR_IOPARST_Msk          /*!< I/O port A reset */
#define RCC_APB2RSTR_IOPBRST_Pos             (3U)                              
#define RCC_APB2RSTR_IOPBRST_Msk             (0x1UL << RCC_APB2RSTR_IOPBRST_Pos) /*!< 0x00000008 */
#define RCC_APB2RSTR_IOPBRST                 RCC_APB2RSTR_IOPBRST_Msk          /*!< I/O port B reset */
#define RCC_APB2RSTR_IOPCRST_Pos             (4U)                              
#define RCC_APB2RSTR_IOPCRST_Msk             (0x1UL << RCC_APB2RSTR_IOPCRST_Pos) /*!< 0x00000010 */
#define RCC_APB2RSTR_IOPCRST                 RCC_APB2RSTR_IOPCRST_Msk          /*!< I/O port C reset */
#define RCC_APB2RSTR_IOPDRST_Pos             (5U)                              
#define RCC_APB2RSTR_IOPDRST_Msk             (0x1UL << RCC_APB2RSTR_IOPDRST_Pos) /*!< 0x00000020 */
#define RCC_APB2RSTR_IOPDRST                 RCC_APB2RSTR_IOPDRST_Msk          /*!< I/O port D reset */
#define RCC_APB2RSTR_ADC1RST_Pos             (9U)                              
#define RCC_APB2RSTR_ADC1RST_Msk             (0x1UL << RCC_APB2RSTR_ADC1RST_Pos) /*!< 0x00000200 */
#define RCC_APB2RSTR_ADC1RST                 RCC_APB2RSTR_ADC1RST_Msk          /*!< ADC 1 interface reset */

#define RCC_APB2RSTR_ADC2RST_Pos             (10U)                             
#define RCC_APB2RSTR_ADC2RST_Msk             (0x1UL << RCC_APB2RSTR_ADC2RST_Pos) /*!< 0x00000400 */
#define RCC_APB2RSTR_ADC2RST                 RCC_APB2RSTR_ADC2RST_Msk          /*!< ADC 2 interface reset */

#define RCC_APB2RSTR_TIM1RST_Pos             (11U)                             
#define RCC_APB2RSTR_TIM1RST_Msk             (0x1UL << RCC_APB2RSTR_TIM1RST_Pos) /*!< 0x00000800 */
#define RCC_APB2RSTR_TIM1RST                 RCC_APB2RSTR_TIM1RST_Msk          /*!< TIM1 Timer reset */
#define RCC_APB2RSTR_SPI1RST_Pos             (12U)                             
#define RCC_APB2RSTR_SPI1RST_Msk             (0x1UL << RCC_APB2RSTR_SPI1RST_Pos) /*!< 0x00001000 */
#define RCC_APB2RSTR_SPI1RST                 RCC_APB2RSTR_SPI1RST_Msk          /*!< SPI 1 reset */
#define RCC_APB2RSTR_USART1RST_Pos           (14U)                             
#define RCC_APB2RSTR_USART1RST_Msk           (0x1UL << RCC_APB2RSTR_USART1RST_Pos) /*!< 0x00004000 */
#define RCC_APB2RSTR_USART1RST               RCC_APB2RSTR_USART1RST_Msk        /*!< USART1 reset */


#define RCC_APB2RSTR_IOPERST_Pos             (6U)                              
#define RCC_APB2RSTR_IOPERST_Msk             (0x1UL << RCC_APB2RSTR_IOPERST_Pos) /*!< 0x00000040 */
#define RCC_APB2RSTR_IOPERST                 RCC_APB2RSTR_IOPERST_Msk          /*!< I/O port E reset */




/*****************  Bit definition for RCC_APB1RSTR register  *****************/
#define RCC_APB1RSTR_TIM2RST_Pos             (0U)                              
#define RCC_APB1RSTR_TIM2RST_Msk             (0x1UL << RCC_APB1RSTR_TIM2RST_Pos) /*!< 0x00000001 */
#define RCC_APB1RSTR_TIM2RST                 RCC_APB1RSTR_TIM2RST_Msk          /*!< Timer 2 reset */
#define RCC_APB1RSTR_TIM3RST_Pos             (1U)                              
#define RCC_APB1RSTR_TIM3RST_Msk             (0x1UL << RCC_APB1RSTR_TIM3RST_Pos) /*!< 0x00000002 */
#define RCC_APB1RSTR_TIM3RST                 RCC_APB1RSTR_TIM3RST_Msk          /*!< Timer 3 reset */
#define RCC_APB1RSTR_WWDGRST_Pos             (11U)                             
#define RCC_APB1RSTR_WWDGRST_Msk             (0x1UL << RCC_APB1RSTR_WWDGRST_Pos) /*!< 0x00000800 */
#define RCC_APB1RSTR_WWDGRST                 RCC_APB1RSTR_WWDGRST_Msk          /*!< Window Watchdog reset */
#define RCC_APB1RSTR_USART2RST_Pos           (17U)                             
#define RCC_APB1RSTR_USART2RST_Msk           (0x1UL << RCC_APB1RSTR_USART2RST_Pos) /*!< 0x00020000 */
#define RCC_APB1RSTR_USART2RST               RCC_APB1RSTR_USART2RST_Msk        /*!< USART 2 reset */
#define RCC_APB1RSTR_I2C1RST_Pos             (21U)                             
#define RCC_APB1RSTR_I2C1RST_Msk             (0x1UL << RCC_APB1RSTR_I2C1RST_Pos) /*!< 0x00200000 */
#define RCC_APB1RSTR_I2C1RST                 RCC_APB1RSTR_I2C1RST_Msk          /*!< I2C 1 reset */

#define RCC_APB1RSTR_CAN1RST_Pos             (25U)                             
#define RCC_APB1RSTR_CAN1RST_Msk             (0x1UL << RCC_APB1RSTR_CAN1RST_Pos) /*!< 0x02000000 */
#define RCC_APB1RSTR_CAN1RST                 RCC_APB1RSTR_CAN1RST_Msk          /*!< CAN1 reset */

#define RCC_APB1RSTR_BKPRST_Pos              (27U)                             
#define RCC_APB1RSTR_BKPRST_Msk              (0x1UL << RCC_APB1RSTR_BKPRST_Pos) /*!< 0x08000000 */
#define RCC_APB1RSTR_BKPRST                  RCC_APB1RSTR_BKPRST_Msk           /*!< Backup interface reset */
#define RCC_APB1RSTR_PWRRST_Pos              (28U)                             
#define RCC_APB1RSTR_PWRRST_Msk              (0x1UL << RCC_APB1RSTR_PWRRST_Pos) /*!< 0x10000000 */
#define RCC_APB1RSTR_PWRRST                  RCC_APB1RSTR_PWRRST_Msk           /*!< Power interface reset */

#define RCC_APB1RSTR_TIM4RST_Pos             (2U)                              
#define RCC_APB1RSTR_TIM4RST_Msk             (0x1UL << RCC_APB1RSTR_TIM4RST_Pos) /*!< 0x00000004 */
#define RCC_APB1RSTR_TIM4RST                 RCC_APB1RSTR_TIM4RST_Msk          /*!< Timer 4 reset */
#define RCC_APB1RSTR_SPI2RST_Pos             (14U)                             
#define RCC_APB1RSTR_SPI2RST_Msk             (0x1UL << RCC_APB1RSTR_SPI2RST_Pos) /*!< 0x00004000 */
#define RCC_APB1RSTR_SPI2RST                 RCC_APB1RSTR_SPI2RST_Msk          /*!< SPI 2 reset */
#define RCC_APB1RSTR_USART3RST_Pos           (18U)                             
#define RCC_APB1RSTR_USART3RST_Msk           (0x1UL << RCC_APB1RSTR_USART3RST_Pos) /*!< 0x00040000 */
#define RCC_APB1RSTR_USART3RST               RCC_APB1RSTR_USART3RST_Msk        /*!< USART 3 reset */
#define RCC_APB1RSTR_I2C2RST_Pos             (22U)                             
#define RCC_APB1RSTR_I2C2RST_Msk             (0x1UL << RCC_APB1RSTR_I2C2RST_Pos) /*!< 0x00400000 */
#define RCC_APB1RSTR_I2C2RST                 RCC_APB1RSTR_I2C2RST_Msk          /*!< I2C 2 reset */

#define RCC_APB1RSTR_USBRST_Pos              (23U)                             
#define RCC_APB1RSTR_USBRST_Msk              (0x1UL << RCC_APB1RSTR_USBRST_Pos) /*!< 0x00800000 */
#define RCC_APB1RSTR_USBRST                  RCC_APB1RSTR_USBRST_Msk           /*!< USB Device reset */






/******************  Bit definition for RCC_AHBENR register  ******************/
#define RCC_AHBENR_DMA1EN_Pos                (0U)                              
#define RCC_AHBENR_DMA1EN_Msk                (0x1UL << RCC_AHBENR_DMA1EN_Pos)   /*!< 0x00000001 */
#define RCC_AHBENR_DMA1EN                    RCC_AHBENR_DMA1EN_Msk             /*!< DMA1 clock enable */
#define RCC_AHBENR_SRAMEN_Pos                (2U)                              
#define RCC_AHBENR_SRAMEN_Msk                (0x1UL << RCC_AHBENR_SRAMEN_Pos)   /*!< 0x00000004 */
#define RCC_AHBENR_SRAMEN                    RCC_AHBENR_SRAMEN_Msk             /*!< SRAM interface clock enable */
#define RCC_AHBENR_FLITFEN_Pos               (4U)                              
#define RCC_AHBENR_FLITFEN_Msk               (0x1UL << RCC_AHBENR_FLITFEN_Pos)  /*!< 0x00000010 */
#define RCC_AHBENR_FLITFEN                   RCC_AHBENR_FLITFEN_Msk            /*!< FLITF clock enable */
#define RCC_AHBENR_CRCEN_Pos                 (6U)                              
#define RCC_AHBENR_CRCEN_Msk                 (0x1UL << RCC_AHBENR_CRCEN_Pos)    /*!< 0x00000040 */
#define RCC_AHBENR_CRCEN                     RCC_AHBENR_CRCEN_Msk              /*!< CRC clock enable */




/******************  Bit definition for RCC_APB2ENR register  *****************/
#define RCC_APB2ENR_AFIOEN_Pos               (0U)                              
#define RCC_APB2ENR_AFIOEN_Msk               (0x1UL << RCC_APB2ENR_AFIOEN_Pos)  /*!< 0x00000001 */
#define RCC_APB2ENR_AFIOEN                   RCC_APB2ENR_AFIOEN_Msk            /*!< Alternate Function I/O clock enable */
#define RCC_APB2ENR_IOPAEN_Pos               (2U)                              
#define RCC_APB2ENR_IOPAEN_Msk               (0x1UL << RCC_APB2ENR_IOPAEN_Pos)  /*!< 0x00000004 */
#define RCC_APB2ENR_IOPAEN                   RCC_APB2ENR_IOPAEN_Msk            /*!< I/O port A clock enable */
#define RCC_APB2ENR_IOPBEN_Pos               (3U)                              
#define RCC_APB2ENR_IOPBEN_Msk               (0x1UL << RCC_APB2ENR_IOPBEN_Pos)  /*!< 0x00000008 */
#define RCC_APB2ENR_IOPBEN                   RCC_APB2ENR_IOPBEN_Msk            /*!< I/O port B clock enable */
#define RCC_APB2ENR_IOPCEN_Pos               (4U)                              
#define RCC_APB2ENR_IOPCEN_Msk               (0x1UL << RCC_APB2ENR_IOPCEN_Pos)  /*!< 0x00000010 */
#define RCC_APB2ENR_IOPCEN                   RCC_APB2ENR_IOPCEN_Msk            /*!< I/O port C clock enable */
#define RCC_APB2ENR_IOPDEN_Pos               (5U)                              
#define RCC_APB2ENR_IOPDEN_Msk               (0x1UL << RCC_APB2ENR_IOPDEN_Pos)  /*!< 0x00000020 */
#define RCC_APB2ENR_IOPDEN                   RCC_APB2ENR_IOPDEN_Msk            /*!< I/O port D clock enable */
#define RCC_APB2ENR_ADC1EN_Pos               (9U)                              
#define RCC_APB2ENR_ADC1EN_Msk               (0x1UL << RCC_APB2ENR_ADC1EN_Pos)  /*!< 0x00000200 */
#define RCC_APB2ENR_ADC1EN                   RCC_APB2ENR_ADC1EN_Msk            /*!< ADC 1 interface clock enable */

#define RCC_APB2ENR_ADC2EN_Pos               (10U)                             
#define RCC_APB2ENR_ADC2EN_Msk               (0x1UL << RCC_APB2ENR_ADC2EN_Pos)  /*!< 0x00000400 */
#define RCC_APB2ENR_ADC2EN                   RCC_APB2ENR_ADC2EN_Msk            /*!< ADC 2 interface clock enable */

#define RCC_APB2ENR_TIM1EN_Pos               (11U)                             
#define RCC_APB2ENR_TIM1EN_Msk               (0x1UL << RCC_APB2ENR_TIM1EN_Pos)  /*!< 0x00000800 */
#define RCC_APB2ENR_TIM1EN                   RCC_APB2ENR_TIM1EN_Msk            /*!< TIM1 Timer clock enable */
#define RCC_APB2ENR_SPI1EN_Pos               (12U)                             
#define RCC_APB2ENR_SPI1EN_Msk               (0x1UL << RCC_APB2ENR_SPI1EN_Pos)  /*!< 0x00001000 */
#define RCC_APB2ENR_SPI1EN                   RCC_APB2ENR_SPI1EN_Msk            /*!< SPI 1 clock enable */
#define RCC_APB2ENR_USART1EN_Pos             (14U)                             
#define RCC_APB2ENR_USART1EN_Msk             (0x1UL << RCC_APB2ENR_USART1EN_Pos) /*!< 0x00004000 */
#define RCC_APB2ENR_USART1EN                 RCC_APB2ENR_USART1EN_Msk          /*!< USART1 clock enable */


#define RCC_APB2ENR_IOPEEN_Pos               (6U)                              
#define RCC_APB2ENR_IOPEEN_Msk               (0x1UL << RCC_APB2ENR_IOPEEN_Pos)  /*!< 0x00000040 */
#define RCC_APB2ENR_IOPEEN                   RCC_APB2ENR_IOPEEN_Msk            /*!< I/O port E clock enable */




/*****************  Bit definition for RCC_APB1ENR register  ******************/
#define RCC_APB1ENR_TIM2EN_Pos               (0U)                              
#define RCC_APB1ENR_TIM2EN_Msk               (0x1UL << RCC_APB1ENR_TIM2EN_Pos)  /*!< 0x00000001 */
#define RCC_APB1ENR_TIM2EN                   RCC_APB1ENR_TIM2EN_Msk            /*!< Timer 2 clock enabled*/
#define RCC_APB1ENR_TIM3EN_Pos               (1U)                              
#define RCC_APB1ENR_TIM3EN_Msk               (0x1UL << RCC_APB1ENR_TIM3EN_Pos)  /*!< 0x00000002 */
#define RCC_APB1ENR_TIM3EN                   RCC_APB1ENR_TIM3EN_Msk            /*!< Timer 3 clock enable */
#define RCC_APB1ENR_WWDGEN_Pos               (11U)                             
#define RCC_APB1ENR_WWDGEN_Msk               (0x1UL << RCC_APB1ENR_WWDGEN_Pos)  /*!< 0x00000800 */
#define RCC_APB1ENR_WWDGEN                   RCC_APB1ENR_WWDGEN_Msk            /*!< Window Watchdog clock enable */
#define RCC_APB1ENR_USART2EN_Pos             (17U)                             
#define RCC_APB1ENR_USART2EN_Msk             (0x1UL << RCC_APB1ENR_USART2EN_Pos) /*!< 0x00020000 */
#define RCC_APB1ENR_USART2EN                 RCC_APB1ENR_USART2EN_Msk          /*!< USART 2 clock enable */
#define RCC_APB1ENR_I2C1EN_Pos               (21U)                             
#define RCC_APB1ENR_I2C1EN_Msk               (0x1UL << RCC_APB1ENR_I2C1EN_Pos)  /*!< 0x00200000 */
#define RCC_APB1ENR_I2C1EN                   RCC_APB1ENR_I2C1EN_Msk            /*!< I2C 1 clock enable */

#define RCC_APB1ENR_CAN1EN_Pos               (25U)                             
#define RCC_APB1ENR_CAN1EN_Msk               (0x1UL << RCC_APB1ENR_CAN1EN_Pos)  /*!< 0x02000000 */
#define RCC_APB1ENR_CAN1EN                   RCC_APB1ENR_CAN1EN_Msk            /*!< CAN1 clock enable */

#define RCC_APB1ENR_BKPEN_Pos                (27U)                             
#define RCC_APB1ENR_BKPEN_Msk                (0x1UL << RCC_APB1ENR_BKPEN_Pos)   /*!< 0x08000000 */
#define RCC_APB1ENR_BKPEN                    RCC_APB1ENR_BKPEN_Msk             /*!< Backup interface clock enable */
#define RCC_APB1ENR_PWREN_Pos                (28U)                             
#define RCC_APB1ENR_PWREN_Msk                (0x1UL << RCC_APB1ENR_PWREN_Pos)   /*!< 0x10000000 */
#define RCC_APB1ENR_PWREN                    RCC_APB1ENR_PWREN_Msk             /*!< Power interface clock enable */

#define RCC_APB1ENR_TIM4EN_Pos               (2U)                              
#define RCC_APB1ENR_TIM4EN_Msk               (0x1UL << RCC_APB1ENR_TIM4EN_Pos)  /*!< 0x00000004 */
#define RCC_APB1ENR_TIM4EN                   RCC_APB1ENR_TIM4EN_Msk            /*!< Timer 4 clock enable */
#define RCC_APB1ENR_SPI2EN_Pos               (14U)                             
#define RCC_APB1ENR_SPI2EN_Msk               (0x1UL << RCC_APB1ENR_SPI2EN_Pos)  /*!< 0x00004000 */
#define RCC_APB1ENR_SPI2EN                   RCC_APB1ENR_SPI2EN_Msk            /*!< SPI 2 clock enable */
#define RCC_APB1ENR_USART3EN_Pos             (18U)                             
#define RCC_APB1ENR_USART3EN_Msk             (0x1UL << RCC_APB1ENR_USART3EN_Pos) /*!< 0x00040000 */
#define RCC_APB1ENR_USART3EN                 RCC_APB1ENR_USART3EN_Msk          /*!< USART 3 clock enable */
#define RCC_APB1ENR_I2C2EN_Pos               (22U)                             
#define RCC_APB1ENR_I2C2EN_Msk               (0x1UL << RCC_APB1ENR_I2C2EN_Pos)  /*!< 0x00400000 */
#define RCC_APB1ENR_I2C2EN                   RCC_APB1ENR_I2C2EN_Msk            /*!< I2C 2 clock enable */

#define RCC_APB1ENR_USBEN_Pos                (23U)                             
#define RCC_APB1ENR_USBEN_Msk                (0x1UL << RCC_APB1ENR_USBEN_Pos)   /*!< 0x00800000 */
#define RCC_APB1ENR_USBEN                    RCC_APB1ENR_USBEN_Msk             /*!< USB Device clock enable */






/*******************  Bit definition for RCC_BDCR register  *******************/
#define RCC_BDCR_LSEON_Pos                   (0U)                              
#define RCC_BDCR_LSEON_Msk                   (0x1UL << RCC_BDCR_LSEON_Pos)      /*!< 0x00000001 */
#define RCC_BDCR_LSEON                       RCC_BDCR_LSEON_Msk                /*!< External Low Speed oscillator enable */
#define RCC_BDCR_LSERDY_Pos                  (1U)                              
#define RCC_BDCR_LSERDY_Msk                  (0x1UL << RCC_BDCR_LSERDY_Pos)     /*!< 0x00000002 */
#define RCC_BDCR_LSERDY                      RCC_BDCR_LSERDY_Msk               /*!< External Low Speed oscillator Ready */
#define RCC_BDCR_LSEBYP_Pos                  (2U)                              
#define RCC_BDCR_LSEBYP_Msk                  (0x1UL << RCC_BDCR_LSEBYP_Pos)     /*!< 0x00000004 */
#define RCC_BDCR_LSEBYP                      RCC_BDCR_LSEBYP_Msk               /*!< External Low Speed oscillator Bypass */

#define RCC_BDCR_RTCSEL_Pos                  (8U)                              
#define RCC_BDCR_RTCSEL_Msk                  (0x3UL << RCC_BDCR_RTCSEL_Pos)     /*!< 0x00000300 */
#define RCC_BDCR_RTCSEL                      RCC_BDCR_RTCSEL_Msk               /*!< RTCSEL[1:0] bits (RTC clock source selection) */
#define RCC_BDCR_RTCSEL_0                    (0x1UL << RCC_BDCR_RTCSEL_Pos)     /*!< 0x00000100 */
#define RCC_BDCR_RTCSEL_1                    (0x2UL << RCC_BDCR_RTCSEL_Pos)     /*!< 0x00000200 */

/*!< RTC congiguration */
#define RCC_BDCR_RTCSEL_NOCLOCK              0x00000000U                       /*!< No clock */
#define RCC_BDCR_RTCSEL_LSE                  0x00000100U                       /*!< LSE oscillator clock used as RTC clock */
#define RCC_BDCR_RTCSEL_LSI                  0x00000200U                       /*!< LSI oscillator clock used as RTC clock */
#define RCC_BDCR_RTCSEL_HSE                  0x00000300U                       /*!< HSE oscillator clock divided by 128 used as RTC clock */

#define RCC_BDCR_RTCEN_Pos                   (15U)                             
#define RCC_BDCR_RTCEN_Msk                   (0x1UL << RCC_BDCR_RTCEN_Pos)      /*!< 0x00008000 */
#define RCC_BDCR_RTCEN                       RCC_BDCR_RTCEN_Msk                /*!< RTC clock enable */
#define RCC_BDCR_BDRST_Pos                   (16U)                             
#define RCC_BDCR_BDRST_Msk                   (0x1UL << RCC_BDCR_BDRST_Pos)      /*!< 0x00010000 */
#define RCC_BDCR_BDRST                       RCC_BDCR_BDRST_Msk                /*!< Backup domain software reset  */

/*******************  Bit definition for RCC_CSR register  ********************/  
#define RCC_CSR_LSION_Pos                    (0U)                              
#define RCC_CSR_LSION_Msk                    (0x1UL << RCC_CSR_LSION_Pos)       /*!< 0x00000001 */
#define RCC_CSR_LSION                        RCC_CSR_LSION_Msk                 /*!< Internal Low Speed oscillator enable */
#define RCC_CSR_LSIRDY_Pos                   (1U)                              
#define RCC_CSR_LSIRDY_Msk                   (0x1UL << RCC_CSR_LSIRDY_Pos)      /*!< 0x00000002 */
#define RCC_CSR_LSIRDY                       RCC_CSR_LSIRDY_Msk                /*!< Internal Low Speed oscillator Ready */
#define RCC_CSR_RMVF_Pos                     (24U)                             
#define RCC_CSR_RMVF_Msk                     (0x1UL << RCC_CSR_RMVF_Pos)        /*!< 0x01000000 */
#define RCC_CSR_RMVF                         RCC_CSR_RMVF_Msk                  /*!< Remove reset flag */
#define RCC_CSR_PINRSTF_Pos                  (26U)                             
#define RCC_CSR_PINRSTF_Msk                  (0x1UL << RCC_CSR_PINRSTF_Pos)     /*!< 0x04000000 */
#define RCC_CSR_PINRSTF                      RCC_CSR_PINRSTF_Msk               /*!< PIN reset flag */
#define RCC_CSR_PORRSTF_Pos                  (27U)                             
#define RCC_CSR_PORRSTF_Msk                  (0x1UL << RCC_CSR_PORRSTF_Pos)     /*!< 0x08000000 */
#define RCC_CSR_PORRSTF                      RCC_CSR_PORRSTF_Msk               /*!< POR/PDR reset flag */
#define RCC_CSR_SFTRSTF_Pos                  (28U)                             
#define RCC_CSR_SFTRSTF_Msk                  (0x1UL << RCC_CSR_SFTRSTF_Pos)     /*!< 0x10000000 */
#define RCC_CSR_SFTRSTF                      RCC_CSR_SFTRSTF_Msk               /*!< Software Reset flag */
#define RCC_CSR_IWDGRSTF_Pos                 (29U)                             
#define RCC_CSR_IWDGRSTF_Msk                 (0x1UL << RCC_CSR_IWDGRSTF_Pos)    /*!< 0x20000000 */
#define RCC_CSR_IWDGRSTF                     RCC_CSR_IWDGRSTF_Msk              /*!< Independent Watchdog reset flag */
#define RCC_CSR_WWDGRSTF_Pos                 (30U)                             
#define RCC_CSR_WWDGRSTF_Msk                 (0x1UL << RCC_CSR_WWDGRSTF_Pos)    /*!< 0x40000000 */
#define RCC_CSR_WWDGRSTF                     RCC_CSR_WWDGRSTF_Msk              /*!< Window watchdog reset flag */
#define RCC_CSR_LPWRRSTF_Pos                 (31U)                             
#define RCC_CSR_LPWRRSTF_Msk                 (0x1UL << RCC_CSR_LPWRRSTF_Pos)    /*!< 0x80000000 */
#define RCC_CSR_LPWRRSTF                     RCC_CSR_LPWRRSTF_Msk              /*!< Low-Power reset flag */

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
#define  RCC_CFGR2_PREDIV1_DIV16             ((uint32_t)0x0000000F) 

 
/******************************************************************************/
/*                                                                            */
/*                General Purpose and Alternate Function I/O                  */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for GPIO_CRL register  *******************/
#define GPIO_CRL_MODE_Pos                    (0U)                              
#define GPIO_CRL_MODE_Msk                    (0x33333333UL << GPIO_CRL_MODE_Pos) /*!< 0x33333333 */
#define GPIO_CRL_MODE                        GPIO_CRL_MODE_Msk                 /*!< Port x mode bits */

#define GPIO_CRL_MODE0_Pos                   (0U)                              
#define GPIO_CRL_MODE0_Msk                   (0x3UL << GPIO_CRL_MODE0_Pos)      /*!< 0x00000003 */
#define GPIO_CRL_MODE0                       GPIO_CRL_MODE0_Msk                /*!< MODE0[1:0] bits (Port x mode bits, pin 0) */
#define GPIO_CRL_MODE0_0                     (0x1UL << GPIO_CRL_MODE0_Pos)      /*!< 0x00000001 */
#define GPIO_CRL_MODE0_1                     (0x2UL << GPIO_CRL_MODE0_Pos)      /*!< 0x00000002 */

#define GPIO_CRL_MODE1_Pos                   (4U)                              
#define GPIO_CRL_MODE1_Msk                   (0x3UL << GPIO_CRL_MODE1_Pos)      /*!< 0x00000030 */
#define GPIO_CRL_MODE1                       GPIO_CRL_MODE1_Msk                /*!< MODE1[1:0] bits (Port x mode bits, pin 1) */
#define GPIO_CRL_MODE1_0                     (0x1UL << GPIO_CRL_MODE1_Pos)      /*!< 0x00000010 */
#define GPIO_CRL_MODE1_1                     (0x2UL << GPIO_CRL_MODE1_Pos)      /*!< 0x00000020 */

#define GPIO_CRL_MODE2_Pos                   (8U)                              
#define GPIO_CRL_MODE2_Msk                   (0x3UL << GPIO_CRL_MODE2_Pos)      /*!< 0x00000300 */
#define GPIO_CRL_MODE2                       GPIO_CRL_MODE2_Msk                /*!< MODE2[1:0] bits (Port x mode bits, pin 2) */
#define GPIO_CRL_MODE2_0                     (0x1UL << GPIO_CRL_MODE2_Pos)      /*!< 0x00000100 */
#define GPIO_CRL_MODE2_1                     (0x2UL << GPIO_CRL_MODE2_Pos)      /*!< 0x00000200 */

#define GPIO_CRL_MODE3_Pos                   (12U)                             
#define GPIO_CRL_MODE3_Msk                   (0x3UL << GPIO_CRL_MODE3_Pos)      /*!< 0x00003000 */
#define GPIO_CRL_MODE3                       GPIO_CRL_MODE3_Msk                /*!< MODE3[1:0] bits (Port x mode bits, pin 3) */
#define GPIO_CRL_MODE3_0                     (0x1UL << GPIO_CRL_MODE3_Pos)      /*!< 0x00001000 */
#define GPIO_CRL_MODE3_1                     (0x2UL << GPIO_CRL_MODE3_Pos)      /*!< 0x00002000 */

#define GPIO_CRL_MODE4_Pos                   (16U)                             
#define GPIO_CRL_MODE4_Msk                   (0x3UL << GPIO_CRL_MODE4_Pos)      /*!< 0x00030000 */
#define GPIO_CRL_MODE4                       GPIO_CRL_MODE4_Msk                /*!< MODE4[1:0] bits (Port x mode bits, pin 4) */
#define GPIO_CRL_MODE4_0                     (0x1UL << GPIO_CRL_MODE4_Pos)      /*!< 0x00010000 */
#define GPIO_CRL_MODE4_1                     (0x2UL << GPIO_CRL_MODE4_Pos)      /*!< 0x00020000 */

#define GPIO_CRL_MODE5_Pos                   (20U)                             
#define GPIO_CRL_MODE5_Msk                   (0x3UL << GPIO_CRL_MODE5_Pos)      /*!< 0x00300000 */
#define GPIO_CRL_MODE5                       GPIO_CRL_MODE5_Msk                /*!< MODE5[1:0] bits (Port x mode bits, pin 5) */
#define GPIO_CRL_MODE5_0                     (0x1UL << GPIO_CRL_MODE5_Pos)      /*!< 0x00100000 */
#define GPIO_CRL_MODE5_1                     (0x2UL << GPIO_CRL_MODE5_Pos)      /*!< 0x00200000 */

#define GPIO_CRL_MODE6_Pos                   (24U)                             
#define GPIO_CRL_MODE6_Msk                   (0x3UL << GPIO_CRL_MODE6_Pos)      /*!< 0x03000000 */
#define GPIO_CRL_MODE6                       GPIO_CRL_MODE6_Msk                /*!< MODE6[1:0] bits (Port x mode bits, pin 6) */
#define GPIO_CRL_MODE6_0                     (0x1UL << GPIO_CRL_MODE6_Pos)      /*!< 0x01000000 */
#define GPIO_CRL_MODE6_1                     (0x2UL << GPIO_CRL_MODE6_Pos)      /*!< 0x02000000 */

#define GPIO_CRL_MODE7_Pos                   (28U)                             
#define GPIO_CRL_MODE7_Msk                   (0x3UL << GPIO_CRL_MODE7_Pos)      /*!< 0x30000000 */
#define GPIO_CRL_MODE7                       GPIO_CRL_MODE7_Msk                /*!< MODE7[1:0] bits (Port x mode bits, pin 7) */
#define GPIO_CRL_MODE7_0                     (0x1UL << GPIO_CRL_MODE7_Pos)      /*!< 0x10000000 */
#define GPIO_CRL_MODE7_1                     (0x2UL << GPIO_CRL_MODE7_Pos)      /*!< 0x20000000 */

#define GPIO_CRL_CNF_Pos                     (2U)                              
#define GPIO_CRL_CNF_Msk                     (0x33333333UL << GPIO_CRL_CNF_Pos) /*!< 0xCCCCCCCC */
#define GPIO_CRL_CNF                         GPIO_CRL_CNF_Msk                  /*!< Port x configuration bits */

#define GPIO_CRL_CNF0_Pos                    (2U)                              
#define GPIO_CRL_CNF0_Msk                    (0x3UL << GPIO_CRL_CNF0_Pos)       /*!< 0x0000000C */
#define GPIO_CRL_CNF0                        GPIO_CRL_CNF0_Msk                 /*!< CNF0[1:0] bits (Port x configuration bits, pin 0) */
#define GPIO_CRL_CNF0_0                      (0x1UL << GPIO_CRL_CNF0_Pos)       /*!< 0x00000004 */
#define GPIO_CRL_CNF0_1                      (0x2UL << GPIO_CRL_CNF0_Pos)       /*!< 0x00000008 */

#define GPIO_CRL_CNF1_Pos                    (6U)                              
#define GPIO_CRL_CNF1_Msk                    (0x3UL << GPIO_CRL_CNF1_Pos)       /*!< 0x000000C0 */
#define GPIO_CRL_CNF1                        GPIO_CRL_CNF1_Msk                 /*!< CNF1[1:0] bits (Port x configuration bits, pin 1) */
#define GPIO_CRL_CNF1_0                      (0x1UL << GPIO_CRL_CNF1_Pos)       /*!< 0x00000040 */
#define GPIO_CRL_CNF1_1                      (0x2UL << GPIO_CRL_CNF1_Pos)       /*!< 0x00000080 */

#define GPIO_CRL_CNF2_Pos                    (10U)                             
#define GPIO_CRL_CNF2_Msk                    (0x3UL << GPIO_CRL_CNF2_Pos)       /*!< 0x00000C00 */
#define GPIO_CRL_CNF2                        GPIO_CRL_CNF2_Msk                 /*!< CNF2[1:0] bits (Port x configuration bits, pin 2) */
#define GPIO_CRL_CNF2_0                      (0x1UL << GPIO_CRL_CNF2_Pos)       /*!< 0x00000400 */
#define GPIO_CRL_CNF2_1                      (0x2UL << GPIO_CRL_CNF2_Pos)       /*!< 0x00000800 */

#define GPIO_CRL_CNF3_Pos                    (14U)                             
#define GPIO_CRL_CNF3_Msk                    (0x3UL << GPIO_CRL_CNF3_Pos)       /*!< 0x0000C000 */
#define GPIO_CRL_CNF3                        GPIO_CRL_CNF3_Msk                 /*!< CNF3[1:0] bits (Port x configuration bits, pin 3) */
#define GPIO_CRL_CNF3_0                      (0x1UL << GPIO_CRL_CNF3_Pos)       /*!< 0x00004000 */
#define GPIO_CRL_CNF3_1                      (0x2UL << GPIO_CRL_CNF3_Pos)       /*!< 0x00008000 */

#define GPIO_CRL_CNF4_Pos                    (18U)                             
#define GPIO_CRL_CNF4_Msk                    (0x3UL << GPIO_CRL_CNF4_Pos)       /*!< 0x000C0000 */
#define GPIO_CRL_CNF4                        GPIO_CRL_CNF4_Msk                 /*!< CNF4[1:0] bits (Port x configuration bits, pin 4) */
#define GPIO_CRL_CNF4_0                      (0x1UL << GPIO_CRL_CNF4_Pos)       /*!< 0x00040000 */
#define GPIO_CRL_CNF4_1                      (0x2UL << GPIO_CRL_CNF4_Pos)       /*!< 0x00080000 */

#define GPIO_CRL_CNF5_Pos                    (22U)                             
#define GPIO_CRL_CNF5_Msk                    (0x3UL << GPIO_CRL_CNF5_Pos)       /*!< 0x00C00000 */
#define GPIO_CRL_CNF5                        GPIO_CRL_CNF5_Msk                 /*!< CNF5[1:0] bits (Port x configuration bits, pin 5) */
#define GPIO_CRL_CNF5_0                      (0x1UL << GPIO_CRL_CNF5_Pos)       /*!< 0x00400000 */
#define GPIO_CRL_CNF5_1                      (0x2UL << GPIO_CRL_CNF5_Pos)       /*!< 0x00800000 */

#define GPIO_CRL_CNF6_Pos                    (26U)                             
#define GPIO_CRL_CNF6_Msk                    (0x3UL << GPIO_CRL_CNF6_Pos)       /*!< 0x0C000000 */
#define GPIO_CRL_CNF6                        GPIO_CRL_CNF6_Msk                 /*!< CNF6[1:0] bits (Port x configuration bits, pin 6) */
#define GPIO_CRL_CNF6_0                      (0x1UL << GPIO_CRL_CNF6_Pos)       /*!< 0x04000000 */
#define GPIO_CRL_CNF6_1                      (0x2UL << GPIO_CRL_CNF6_Pos)       /*!< 0x08000000 */

#define GPIO_CRL_CNF7_Pos                    (30U)                             
#define GPIO_CRL_CNF7_Msk                    (0x3UL << GPIO_CRL_CNF7_Pos)       /*!< 0xC0000000 */
#define GPIO_CRL_CNF7                        GPIO_CRL_CNF7_Msk                 /*!< CNF7[1:0] bits (Port x configuration bits, pin 7) */
#define GPIO_CRL_CNF7_0                      (0x1UL << GPIO_CRL_CNF7_Pos)       /*!< 0x40000000 */
#define GPIO_CRL_CNF7_1                      (0x2UL << GPIO_CRL_CNF7_Pos)       /*!< 0x80000000 */

/*******************  Bit definition for GPIO_CRH register  *******************/
#define GPIO_CRH_MODE_Pos                    (0U)                              
#define GPIO_CRH_MODE_Msk                    (0x33333333UL << GPIO_CRH_MODE_Pos) /*!< 0x33333333 */
#define GPIO_CRH_MODE                        GPIO_CRH_MODE_Msk                 /*!< Port x mode bits */

#define GPIO_CRH_MODE8_Pos                   (0U)                              
#define GPIO_CRH_MODE8_Msk                   (0x3UL << GPIO_CRH_MODE8_Pos)      /*!< 0x00000003 */
#define GPIO_CRH_MODE8                       GPIO_CRH_MODE8_Msk                /*!< MODE8[1:0] bits (Port x mode bits, pin 8) */
#define GPIO_CRH_MODE8_0                     (0x1UL << GPIO_CRH_MODE8_Pos)      /*!< 0x00000001 */
#define GPIO_CRH_MODE8_1                     (0x2UL << GPIO_CRH_MODE8_Pos)      /*!< 0x00000002 */

#define GPIO_CRH_MODE9_Pos                   (4U)                              
#define GPIO_CRH_MODE9_Msk                   (0x3UL << GPIO_CRH_MODE9_Pos)      /*!< 0x00000030 */
#define GPIO_CRH_MODE9                       GPIO_CRH_MODE9_Msk                /*!< MODE9[1:0] bits (Port x mode bits, pin 9) */
#define GPIO_CRH_MODE9_0                     (0x1UL << GPIO_CRH_MODE9_Pos)      /*!< 0x00000010 */
#define GPIO_CRH_MODE9_1                     (0x2UL << GPIO_CRH_MODE9_Pos)      /*!< 0x00000020 */

#define GPIO_CRH_MODE10_Pos                  (8U)                              
#define GPIO_CRH_MODE10_Msk                  (0x3UL << GPIO_CRH_MODE10_Pos)     /*!< 0x00000300 */
#define GPIO_CRH_MODE10                      GPIO_CRH_MODE10_Msk               /*!< MODE10[1:0] bits (Port x mode bits, pin 10) */
#define GPIO_CRH_MODE10_0                    (0x1UL << GPIO_CRH_MODE10_Pos)     /*!< 0x00000100 */
#define GPIO_CRH_MODE10_1                    (0x2UL << GPIO_CRH_MODE10_Pos)     /*!< 0x00000200 */

#define GPIO_CRH_MODE11_Pos                  (12U)                             
#define GPIO_CRH_MODE11_Msk                  (0x3UL << GPIO_CRH_MODE11_Pos)     /*!< 0x00003000 */
#define GPIO_CRH_MODE11                      GPIO_CRH_MODE11_Msk               /*!< MODE11[1:0] bits (Port x mode bits, pin 11) */
#define GPIO_CRH_MODE11_0                    (0x1UL << GPIO_CRH_MODE11_Pos)     /*!< 0x00001000 */
#define GPIO_CRH_MODE11_1                    (0x2UL << GPIO_CRH_MODE11_Pos)     /*!< 0x00002000 */

#define GPIO_CRH_MODE12_Pos                  (16U)                             
#define GPIO_CRH_MODE12_Msk                  (0x3UL << GPIO_CRH_MODE12_Pos)     /*!< 0x00030000 */
#define GPIO_CRH_MODE12                      GPIO_CRH_MODE12_Msk               /*!< MODE12[1:0] bits (Port x mode bits, pin 12) */
#define GPIO_CRH_MODE12_0                    (0x1UL << GPIO_CRH_MODE12_Pos)     /*!< 0x00010000 */
#define GPIO_CRH_MODE12_1                    (0x2UL << GPIO_CRH_MODE12_Pos)     /*!< 0x00020000 */

#define GPIO_CRH_MODE13_Pos                  (20U)                             
#define GPIO_CRH_MODE13_Msk                  (0x3UL << GPIO_CRH_MODE13_Pos)     /*!< 0x00300000 */
#define GPIO_CRH_MODE13                      GPIO_CRH_MODE13_Msk               /*!< MODE13[1:0] bits (Port x mode bits, pin 13) */
#define GPIO_CRH_MODE13_0                    (0x1UL << GPIO_CRH_MODE13_Pos)     /*!< 0x00100000 */
#define GPIO_CRH_MODE13_1                    (0x2UL << GPIO_CRH_MODE13_Pos)     /*!< 0x00200000 */

#define GPIO_CRH_MODE14_Pos                  (24U)                             
#define GPIO_CRH_MODE14_Msk                  (0x3UL << GPIO_CRH_MODE14_Pos)     /*!< 0x03000000 */
#define GPIO_CRH_MODE14                      GPIO_CRH_MODE14_Msk               /*!< MODE14[1:0] bits (Port x mode bits, pin 14) */
#define GPIO_CRH_MODE14_0                    (0x1UL << GPIO_CRH_MODE14_Pos)     /*!< 0x01000000 */
#define GPIO_CRH_MODE14_1                    (0x2UL << GPIO_CRH_MODE14_Pos)     /*!< 0x02000000 */

#define GPIO_CRH_MODE15_Pos                  (28U)                             
#define GPIO_CRH_MODE15_Msk                  (0x3UL << GPIO_CRH_MODE15_Pos)     /*!< 0x30000000 */
#define GPIO_CRH_MODE15                      GPIO_CRH_MODE15_Msk               /*!< MODE15[1:0] bits (Port x mode bits, pin 15) */
#define GPIO_CRH_MODE15_0                    (0x1UL << GPIO_CRH_MODE15_Pos)     /*!< 0x10000000 */
#define GPIO_CRH_MODE15_1                    (0x2UL << GPIO_CRH_MODE15_Pos)     /*!< 0x20000000 */

#define GPIO_CRH_CNF_Pos                     (2U)                              
#define GPIO_CRH_CNF_Msk                     (0x33333333UL << GPIO_CRH_CNF_Pos) /*!< 0xCCCCCCCC */
#define GPIO_CRH_CNF                         GPIO_CRH_CNF_Msk                  /*!< Port x configuration bits */

#define GPIO_CRH_CNF8_Pos                    (2U)                              
#define GPIO_CRH_CNF8_Msk                    (0x3UL << GPIO_CRH_CNF8_Pos)       /*!< 0x0000000C */
#define GPIO_CRH_CNF8                        GPIO_CRH_CNF8_Msk                 /*!< CNF8[1:0] bits (Port x configuration bits, pin 8) */
#define GPIO_CRH_CNF8_0                      (0x1UL << GPIO_CRH_CNF8_Pos)       /*!< 0x00000004 */
#define GPIO_CRH_CNF8_1                      (0x2UL << GPIO_CRH_CNF8_Pos)       /*!< 0x00000008 */

#define GPIO_CRH_CNF9_Pos                    (6U)                              
#define GPIO_CRH_CNF9_Msk                    (0x3UL << GPIO_CRH_CNF9_Pos)       /*!< 0x000000C0 */
#define GPIO_CRH_CNF9                        GPIO_CRH_CNF9_Msk                 /*!< CNF9[1:0] bits (Port x configuration bits, pin 9) */
#define GPIO_CRH_CNF9_0                      (0x1UL << GPIO_CRH_CNF9_Pos)       /*!< 0x00000040 */
#define GPIO_CRH_CNF9_1                      (0x2UL << GPIO_CRH_CNF9_Pos)       /*!< 0x00000080 */

#define GPIO_CRH_CNF10_Pos                   (10U)                             
#define GPIO_CRH_CNF10_Msk                   (0x3UL << GPIO_CRH_CNF10_Pos)      /*!< 0x00000C00 */
#define GPIO_CRH_CNF10                       GPIO_CRH_CNF10_Msk                /*!< CNF10[1:0] bits (Port x configuration bits, pin 10) */
#define GPIO_CRH_CNF10_0                     (0x1UL << GPIO_CRH_CNF10_Pos)      /*!< 0x00000400 */
#define GPIO_CRH_CNF10_1                     (0x2UL << GPIO_CRH_CNF10_Pos)      /*!< 0x00000800 */

#define GPIO_CRH_CNF11_Pos                   (14U)                             
#define GPIO_CRH_CNF11_Msk                   (0x3UL << GPIO_CRH_CNF11_Pos)      /*!< 0x0000C000 */
#define GPIO_CRH_CNF11                       GPIO_CRH_CNF11_Msk                /*!< CNF11[1:0] bits (Port x configuration bits, pin 11) */
#define GPIO_CRH_CNF11_0                     (0x1UL << GPIO_CRH_CNF11_Pos)      /*!< 0x00004000 */
#define GPIO_CRH_CNF11_1                     (0x2UL << GPIO_CRH_CNF11_Pos)      /*!< 0x00008000 */

#define GPIO_CRH_CNF12_Pos                   (18U)                             
#define GPIO_CRH_CNF12_Msk                   (0x3UL << GPIO_CRH_CNF12_Pos)      /*!< 0x000C0000 */
#define GPIO_CRH_CNF12                       GPIO_CRH_CNF12_Msk                /*!< CNF12[1:0] bits (Port x configuration bits, pin 12) */
#define GPIO_CRH_CNF12_0                     (0x1UL << GPIO_CRH_CNF12_Pos)      /*!< 0x00040000 */
#define GPIO_CRH_CNF12_1                     (0x2UL << GPIO_CRH_CNF12_Pos)      /*!< 0x00080000 */

#define GPIO_CRH_CNF13_Pos                   (22U)                             
#define GPIO_CRH_CNF13_Msk                   (0x3UL << GPIO_CRH_CNF13_Pos)      /*!< 0x00C00000 */
#define GPIO_CRH_CNF13                       GPIO_CRH_CNF13_Msk                /*!< CNF13[1:0] bits (Port x configuration bits, pin 13) */
#define GPIO_CRH_CNF13_0                     (0x1UL << GPIO_CRH_CNF13_Pos)      /*!< 0x00400000 */
#define GPIO_CRH_CNF13_1                     (0x2UL << GPIO_CRH_CNF13_Pos)      /*!< 0x00800000 */

#define GPIO_CRH_CNF14_Pos                   (26U)                             
#define GPIO_CRH_CNF14_Msk                   (0x3UL << GPIO_CRH_CNF14_Pos)      /*!< 0x0C000000 */
#define GPIO_CRH_CNF14                       GPIO_CRH_CNF14_Msk                /*!< CNF14[1:0] bits (Port x configuration bits, pin 14) */
#define GPIO_CRH_CNF14_0                     (0x1UL << GPIO_CRH_CNF14_Pos)      /*!< 0x04000000 */
#define GPIO_CRH_CNF14_1                     (0x2UL << GPIO_CRH_CNF14_Pos)      /*!< 0x08000000 */

#define GPIO_CRH_CNF15_Pos                   (30U)                             
#define GPIO_CRH_CNF15_Msk                   (0x3UL << GPIO_CRH_CNF15_Pos)      /*!< 0xC0000000 */
#define GPIO_CRH_CNF15                       GPIO_CRH_CNF15_Msk                /*!< CNF15[1:0] bits (Port x configuration bits, pin 15) */
#define GPIO_CRH_CNF15_0                     (0x1UL << GPIO_CRH_CNF15_Pos)      /*!< 0x40000000 */
#define GPIO_CRH_CNF15_1                     (0x2UL << GPIO_CRH_CNF15_Pos)      /*!< 0x80000000 */

/*!<******************  Bit definition for GPIO_IDR register  *******************/
#define GPIO_IDR_IDR0_Pos                    (0U)                              
#define GPIO_IDR_IDR0_Msk                    (0x1UL << GPIO_IDR_IDR0_Pos)       /*!< 0x00000001 */
#define GPIO_IDR_IDR0                        GPIO_IDR_IDR0_Msk                 /*!< Port input data, bit 0 */
#define GPIO_IDR_IDR1_Pos                    (1U)                              
#define GPIO_IDR_IDR1_Msk                    (0x1UL << GPIO_IDR_IDR1_Pos)       /*!< 0x00000002 */
#define GPIO_IDR_IDR1                        GPIO_IDR_IDR1_Msk                 /*!< Port input data, bit 1 */
#define GPIO_IDR_IDR2_Pos                    (2U)                              
#define GPIO_IDR_IDR2_Msk                    (0x1UL << GPIO_IDR_IDR2_Pos)       /*!< 0x00000004 */
#define GPIO_IDR_IDR2                        GPIO_IDR_IDR2_Msk                 /*!< Port input data, bit 2 */
#define GPIO_IDR_IDR3_Pos                    (3U)                              
#define GPIO_IDR_IDR3_Msk                    (0x1UL << GPIO_IDR_IDR3_Pos)       /*!< 0x00000008 */
#define GPIO_IDR_IDR3                        GPIO_IDR_IDR3_Msk                 /*!< Port input data, bit 3 */
#define GPIO_IDR_IDR4_Pos                    (4U)                              
#define GPIO_IDR_IDR4_Msk                    (0x1UL << GPIO_IDR_IDR4_Pos)       /*!< 0x00000010 */
#define GPIO_IDR_IDR4                        GPIO_IDR_IDR4_Msk                 /*!< Port input data, bit 4 */
#define GPIO_IDR_IDR5_Pos                    (5U)                              
#define GPIO_IDR_IDR5_Msk                    (0x1UL << GPIO_IDR_IDR5_Pos)       /*!< 0x00000020 */
#define GPIO_IDR_IDR5                        GPIO_IDR_IDR5_Msk                 /*!< Port input data, bit 5 */
#define GPIO_IDR_IDR6_Pos                    (6U)                              
#define GPIO_IDR_IDR6_Msk                    (0x1UL << GPIO_IDR_IDR6_Pos)       /*!< 0x00000040 */
#define GPIO_IDR_IDR6                        GPIO_IDR_IDR6_Msk                 /*!< Port input data, bit 6 */
#define GPIO_IDR_IDR7_Pos                    (7U)                              
#define GPIO_IDR_IDR7_Msk                    (0x1UL << GPIO_IDR_IDR7_Pos)       /*!< 0x00000080 */
#define GPIO_IDR_IDR7                        GPIO_IDR_IDR7_Msk                 /*!< Port input data, bit 7 */
#define GPIO_IDR_IDR8_Pos                    (8U)                              
#define GPIO_IDR_IDR8_Msk                    (0x1UL << GPIO_IDR_IDR8_Pos)       /*!< 0x00000100 */
#define GPIO_IDR_IDR8                        GPIO_IDR_IDR8_Msk                 /*!< Port input data, bit 8 */
#define GPIO_IDR_IDR9_Pos                    (9U)                              
#define GPIO_IDR_IDR9_Msk                    (0x1UL << GPIO_IDR_IDR9_Pos)       /*!< 0x00000200 */
#define GPIO_IDR_IDR9                        GPIO_IDR_IDR9_Msk                 /*!< Port input data, bit 9 */
#define GPIO_IDR_IDR10_Pos                   (10U)                             
#define GPIO_IDR_IDR10_Msk                   (0x1UL << GPIO_IDR_IDR10_Pos)      /*!< 0x00000400 */
#define GPIO_IDR_IDR10                       GPIO_IDR_IDR10_Msk                /*!< Port input data, bit 10 */
#define GPIO_IDR_IDR11_Pos                   (11U)                             
#define GPIO_IDR_IDR11_Msk                   (0x1UL << GPIO_IDR_IDR11_Pos)      /*!< 0x00000800 */
#define GPIO_IDR_IDR11                       GPIO_IDR_IDR11_Msk                /*!< Port input data, bit 11 */
#define GPIO_IDR_IDR12_Pos                   (12U)                             
#define GPIO_IDR_IDR12_Msk                   (0x1UL << GPIO_IDR_IDR12_Pos)      /*!< 0x00001000 */
#define GPIO_IDR_IDR12                       GPIO_IDR_IDR12_Msk                /*!< Port input data, bit 12 */
#define GPIO_IDR_IDR13_Pos                   (13U)                             
#define GPIO_IDR_IDR13_Msk                   (0x1UL << GPIO_IDR_IDR13_Pos)      /*!< 0x00002000 */
#define GPIO_IDR_IDR13                       GPIO_IDR_IDR13_Msk                /*!< Port input data, bit 13 */
#define GPIO_IDR_IDR14_Pos                   (14U)                             
#define GPIO_IDR_IDR14_Msk                   (0x1UL << GPIO_IDR_IDR14_Pos)      /*!< 0x00004000 */
#define GPIO_IDR_IDR14                       GPIO_IDR_IDR14_Msk                /*!< Port input data, bit 14 */
#define GPIO_IDR_IDR15_Pos                   (15U)                             
#define GPIO_IDR_IDR15_Msk                   (0x1UL << GPIO_IDR_IDR15_Pos)      /*!< 0x00008000 */
#define GPIO_IDR_IDR15                       GPIO_IDR_IDR15_Msk                /*!< Port input data, bit 15 */

/*******************  Bit definition for GPIO_ODR register  *******************/
#define GPIO_ODR_ODR0_Pos                    (0U)                              
#define GPIO_ODR_ODR0_Msk                    (0x1UL << GPIO_ODR_ODR0_Pos)       /*!< 0x00000001 */
#define GPIO_ODR_ODR0                        GPIO_ODR_ODR0_Msk                 /*!< Port output data, bit 0 */
#define GPIO_ODR_ODR1_Pos                    (1U)                              
#define GPIO_ODR_ODR1_Msk                    (0x1UL << GPIO_ODR_ODR1_Pos)       /*!< 0x00000002 */
#define GPIO_ODR_ODR1                        GPIO_ODR_ODR1_Msk                 /*!< Port output data, bit 1 */
#define GPIO_ODR_ODR2_Pos                    (2U)                              
#define GPIO_ODR_ODR2_Msk                    (0x1UL << GPIO_ODR_ODR2_Pos)       /*!< 0x00000004 */
#define GPIO_ODR_ODR2                        GPIO_ODR_ODR2_Msk                 /*!< Port output data, bit 2 */
#define GPIO_ODR_ODR3_Pos                    (3U)                              
#define GPIO_ODR_ODR3_Msk                    (0x1UL << GPIO_ODR_ODR3_Pos)       /*!< 0x00000008 */
#define GPIO_ODR_ODR3                        GPIO_ODR_ODR3_Msk                 /*!< Port output data, bit 3 */
#define GPIO_ODR_ODR4_Pos                    (4U)                              
#define GPIO_ODR_ODR4_Msk                    (0x1UL << GPIO_ODR_ODR4_Pos)       /*!< 0x00000010 */
#define GPIO_ODR_ODR4                        GPIO_ODR_ODR4_Msk                 /*!< Port output data, bit 4 */
#define GPIO_ODR_ODR5_Pos                    (5U)                              
#define GPIO_ODR_ODR5_Msk                    (0x1UL << GPIO_ODR_ODR5_Pos)       /*!< 0x00000020 */
#define GPIO_ODR_ODR5                        GPIO_ODR_ODR5_Msk                 /*!< Port output data, bit 5 */
#define GPIO_ODR_ODR6_Pos                    (6U)                              
#define GPIO_ODR_ODR6_Msk                    (0x1UL << GPIO_ODR_ODR6_Pos)       /*!< 0x00000040 */
#define GPIO_ODR_ODR6                        GPIO_ODR_ODR6_Msk                 /*!< Port output data, bit 6 */
#define GPIO_ODR_ODR7_Pos                    (7U)                              
#define GPIO_ODR_ODR7_Msk                    (0x1UL << GPIO_ODR_ODR7_Pos)       /*!< 0x00000080 */
#define GPIO_ODR_ODR7                        GPIO_ODR_ODR7_Msk                 /*!< Port output data, bit 7 */
#define GPIO_ODR_ODR8_Pos                    (8U)                              
#define GPIO_ODR_ODR8_Msk                    (0x1UL << GPIO_ODR_ODR8_Pos)       /*!< 0x00000100 */
#define GPIO_ODR_ODR8                        GPIO_ODR_ODR8_Msk                 /*!< Port output data, bit 8 */
#define GPIO_ODR_ODR9_Pos                    (9U)                              
#define GPIO_ODR_ODR9_Msk                    (0x1UL << GPIO_ODR_ODR9_Pos)       /*!< 0x00000200 */
#define GPIO_ODR_ODR9                        GPIO_ODR_ODR9_Msk                 /*!< Port output data, bit 9 */
#define GPIO_ODR_ODR10_Pos                   (10U)                             
#define GPIO_ODR_ODR10_Msk                   (0x1UL << GPIO_ODR_ODR10_Pos)      /*!< 0x00000400 */
#define GPIO_ODR_ODR10                       GPIO_ODR_ODR10_Msk                /*!< Port output data, bit 10 */
#define GPIO_ODR_ODR11_Pos                   (11U)                             
#define GPIO_ODR_ODR11_Msk                   (0x1UL << GPIO_ODR_ODR11_Pos)      /*!< 0x00000800 */
#define GPIO_ODR_ODR11                       GPIO_ODR_ODR11_Msk                /*!< Port output data, bit 11 */
#define GPIO_ODR_ODR12_Pos                   (12U)                             
#define GPIO_ODR_ODR12_Msk                   (0x1UL << GPIO_ODR_ODR12_Pos)      /*!< 0x00001000 */
#define GPIO_ODR_ODR12                       GPIO_ODR_ODR12_Msk                /*!< Port output data, bit 12 */
#define GPIO_ODR_ODR13_Pos                   (13U)                             
#define GPIO_ODR_ODR13_Msk                   (0x1UL << GPIO_ODR_ODR13_Pos)      /*!< 0x00002000 */
#define GPIO_ODR_ODR13                       GPIO_ODR_ODR13_Msk                /*!< Port output data, bit 13 */
#define GPIO_ODR_ODR14_Pos                   (14U)                             
#define GPIO_ODR_ODR14_Msk                   (0x1UL << GPIO_ODR_ODR14_Pos)      /*!< 0x00004000 */
#define GPIO_ODR_ODR14                       GPIO_ODR_ODR14_Msk                /*!< Port output data, bit 14 */
#define GPIO_ODR_ODR15_Pos                   (15U)                             
#define GPIO_ODR_ODR15_Msk                   (0x1UL << GPIO_ODR_ODR15_Pos)      /*!< 0x00008000 */
#define GPIO_ODR_ODR15                       GPIO_ODR_ODR15_Msk                /*!< Port output data, bit 15 */

/******************  Bit definition for GPIO_BSRR register  *******************/
#define GPIO_BSRR_BS0_Pos                    (0U)                              
#define GPIO_BSRR_BS0_Msk                    (0x1UL << GPIO_BSRR_BS0_Pos)       /*!< 0x00000001 */
#define GPIO_BSRR_BS0                        GPIO_BSRR_BS0_Msk                 /*!< Port x Set bit 0 */
#define GPIO_BSRR_BS1_Pos                    (1U)                              
#define GPIO_BSRR_BS1_Msk                    (0x1UL << GPIO_BSRR_BS1_Pos)       /*!< 0x00000002 */
#define GPIO_BSRR_BS1                        GPIO_BSRR_BS1_Msk                 /*!< Port x Set bit 1 */
#define GPIO_BSRR_BS2_Pos                    (2U)                              
#define GPIO_BSRR_BS2_Msk                    (0x1UL << GPIO_BSRR_BS2_Pos)       /*!< 0x00000004 */
#define GPIO_BSRR_BS2                        GPIO_BSRR_BS2_Msk                 /*!< Port x Set bit 2 */
#define GPIO_BSRR_BS3_Pos                    (3U)                              
#define GPIO_BSRR_BS3_Msk                    (0x1UL << GPIO_BSRR_BS3_Pos)       /*!< 0x00000008 */
#define GPIO_BSRR_BS3                        GPIO_BSRR_BS3_Msk                 /*!< Port x Set bit 3 */
#define GPIO_BSRR_BS4_Pos                    (4U)                              
#define GPIO_BSRR_BS4_Msk                    (0x1UL << GPIO_BSRR_BS4_Pos)       /*!< 0x00000010 */
#define GPIO_BSRR_BS4                        GPIO_BSRR_BS4_Msk                 /*!< Port x Set bit 4 */
#define GPIO_BSRR_BS5_Pos                    (5U)                              
#define GPIO_BSRR_BS5_Msk                    (0x1UL << GPIO_BSRR_BS5_Pos)       /*!< 0x00000020 */
#define GPIO_BSRR_BS5                        GPIO_BSRR_BS5_Msk                 /*!< Port x Set bit 5 */
#define GPIO_BSRR_BS6_Pos                    (6U)                              
#define GPIO_BSRR_BS6_Msk                    (0x1UL << GPIO_BSRR_BS6_Pos)       /*!< 0x00000040 */
#define GPIO_BSRR_BS6                        GPIO_BSRR_BS6_Msk                 /*!< Port x Set bit 6 */
#define GPIO_BSRR_BS7_Pos                    (7U)                              
#define GPIO_BSRR_BS7_Msk                    (0x1UL << GPIO_BSRR_BS7_Pos)       /*!< 0x00000080 */
#define GPIO_BSRR_BS7                        GPIO_BSRR_BS7_Msk                 /*!< Port x Set bit 7 */
#define GPIO_BSRR_BS8_Pos                    (8U)                              
#define GPIO_BSRR_BS8_Msk                    (0x1UL << GPIO_BSRR_BS8_Pos)       /*!< 0x00000100 */
#define GPIO_BSRR_BS8                        GPIO_BSRR_BS8_Msk                 /*!< Port x Set bit 8 */
#define GPIO_BSRR_BS9_Pos                    (9U)                              
#define GPIO_BSRR_BS9_Msk                    (0x1UL << GPIO_BSRR_BS9_Pos)       /*!< 0x00000200 */
#define GPIO_BSRR_BS9                        GPIO_BSRR_BS9_Msk                 /*!< Port x Set bit 9 */
#define GPIO_BSRR_BS10_Pos                   (10U)                             
#define GPIO_BSRR_BS10_Msk                   (0x1UL << GPIO_BSRR_BS10_Pos)      /*!< 0x00000400 */
#define GPIO_BSRR_BS10                       GPIO_BSRR_BS10_Msk                /*!< Port x Set bit 10 */
#define GPIO_BSRR_BS11_Pos                   (11U)                             
#define GPIO_BSRR_BS11_Msk                   (0x1UL << GPIO_BSRR_BS11_Pos)      /*!< 0x00000800 */
#define GPIO_BSRR_BS11                       GPIO_BSRR_BS11_Msk                /*!< Port x Set bit 11 */
#define GPIO_BSRR_BS12_Pos                   (12U)                             
#define GPIO_BSRR_BS12_Msk                   (0x1UL << GPIO_BSRR_BS12_Pos)      /*!< 0x00001000 */
#define GPIO_BSRR_BS12                       GPIO_BSRR_BS12_Msk                /*!< Port x Set bit 12 */
#define GPIO_BSRR_BS13_Pos                   (13U)                             
#define GPIO_BSRR_BS13_Msk                   (0x1UL << GPIO_BSRR_BS13_Pos)      /*!< 0x00002000 */
#define GPIO_BSRR_BS13                       GPIO_BSRR_BS13_Msk                /*!< Port x Set bit 13 */
#define GPIO_BSRR_BS14_Pos                   (14U)                             
#define GPIO_BSRR_BS14_Msk                   (0x1UL << GPIO_BSRR_BS14_Pos)      /*!< 0x00004000 */
#define GPIO_BSRR_BS14                       GPIO_BSRR_BS14_Msk                /*!< Port x Set bit 14 */
#define GPIO_BSRR_BS15_Pos                   (15U)                             
#define GPIO_BSRR_BS15_Msk                   (0x1UL << GPIO_BSRR_BS15_Pos)      /*!< 0x00008000 */
#define GPIO_BSRR_BS15                       GPIO_BSRR_BS15_Msk                /*!< Port x Set bit 15 */

#define GPIO_BSRR_BR0_Pos                    (16U)                             
#define GPIO_BSRR_BR0_Msk                    (0x1UL << GPIO_BSRR_BR0_Pos)       /*!< 0x00010000 */
#define GPIO_BSRR_BR0                        GPIO_BSRR_BR0_Msk                 /*!< Port x Reset bit 0 */
#define GPIO_BSRR_BR1_Pos                    (17U)                             
#define GPIO_BSRR_BR1_Msk                    (0x1UL << GPIO_BSRR_BR1_Pos)       /*!< 0x00020000 */
#define GPIO_BSRR_BR1                        GPIO_BSRR_BR1_Msk                 /*!< Port x Reset bit 1 */
#define GPIO_BSRR_BR2_Pos                    (18U)                             
#define GPIO_BSRR_BR2_Msk                    (0x1UL << GPIO_BSRR_BR2_Pos)       /*!< 0x00040000 */
#define GPIO_BSRR_BR2                        GPIO_BSRR_BR2_Msk                 /*!< Port x Reset bit 2 */
#define GPIO_BSRR_BR3_Pos                    (19U)                             
#define GPIO_BSRR_BR3_Msk                    (0x1UL << GPIO_BSRR_BR3_Pos)       /*!< 0x00080000 */
#define GPIO_BSRR_BR3                        GPIO_BSRR_BR3_Msk                 /*!< Port x Reset bit 3 */
#define GPIO_BSRR_BR4_Pos                    (20U)                             
#define GPIO_BSRR_BR4_Msk                    (0x1UL << GPIO_BSRR_BR4_Pos)       /*!< 0x00100000 */
#define GPIO_BSRR_BR4                        GPIO_BSRR_BR4_Msk                 /*!< Port x Reset bit 4 */
#define GPIO_BSRR_BR5_Pos                    (21U)                             
#define GPIO_BSRR_BR5_Msk                    (0x1UL << GPIO_BSRR_BR5_Pos)       /*!< 0x00200000 */
#define GPIO_BSRR_BR5                        GPIO_BSRR_BR5_Msk                 /*!< Port x Reset bit 5 */
#define GPIO_BSRR_BR6_Pos                    (22U)                             
#define GPIO_BSRR_BR6_Msk                    (0x1UL << GPIO_BSRR_BR6_Pos)       /*!< 0x00400000 */
#define GPIO_BSRR_BR6                        GPIO_BSRR_BR6_Msk                 /*!< Port x Reset bit 6 */
#define GPIO_BSRR_BR7_Pos                    (23U)                             
#define GPIO_BSRR_BR7_Msk                    (0x1UL << GPIO_BSRR_BR7_Pos)       /*!< 0x00800000 */
#define GPIO_BSRR_BR7                        GPIO_BSRR_BR7_Msk                 /*!< Port x Reset bit 7 */
#define GPIO_BSRR_BR8_Pos                    (24U)                             
#define GPIO_BSRR_BR8_Msk                    (0x1UL << GPIO_BSRR_BR8_Pos)       /*!< 0x01000000 */
#define GPIO_BSRR_BR8                        GPIO_BSRR_BR8_Msk                 /*!< Port x Reset bit 8 */
#define GPIO_BSRR_BR9_Pos                    (25U)                             
#define GPIO_BSRR_BR9_Msk                    (0x1UL << GPIO_BSRR_BR9_Pos)       /*!< 0x02000000 */
#define GPIO_BSRR_BR9                        GPIO_BSRR_BR9_Msk                 /*!< Port x Reset bit 9 */
#define GPIO_BSRR_BR10_Pos                   (26U)                             
#define GPIO_BSRR_BR10_Msk                   (0x1UL << GPIO_BSRR_BR10_Pos)      /*!< 0x04000000 */
#define GPIO_BSRR_BR10                       GPIO_BSRR_BR10_Msk                /*!< Port x Reset bit 10 */
#define GPIO_BSRR_BR11_Pos                   (27U)                             
#define GPIO_BSRR_BR11_Msk                   (0x1UL << GPIO_BSRR_BR11_Pos)      /*!< 0x08000000 */
#define GPIO_BSRR_BR11                       GPIO_BSRR_BR11_Msk                /*!< Port x Reset bit 11 */
#define GPIO_BSRR_BR12_Pos                   (28U)                             
#define GPIO_BSRR_BR12_Msk                   (0x1UL << GPIO_BSRR_BR12_Pos)      /*!< 0x10000000 */
#define GPIO_BSRR_BR12                       GPIO_BSRR_BR12_Msk                /*!< Port x Reset bit 12 */
#define GPIO_BSRR_BR13_Pos                   (29U)                             
#define GPIO_BSRR_BR13_Msk                   (0x1UL << GPIO_BSRR_BR13_Pos)      /*!< 0x20000000 */
#define GPIO_BSRR_BR13                       GPIO_BSRR_BR13_Msk                /*!< Port x Reset bit 13 */
#define GPIO_BSRR_BR14_Pos                   (30U)                             
#define GPIO_BSRR_BR14_Msk                   (0x1UL << GPIO_BSRR_BR14_Pos)      /*!< 0x40000000 */
#define GPIO_BSRR_BR14                       GPIO_BSRR_BR14_Msk                /*!< Port x Reset bit 14 */
#define GPIO_BSRR_BR15_Pos                   (31U)                             
#define GPIO_BSRR_BR15_Msk                   (0x1UL << GPIO_BSRR_BR15_Pos)      /*!< 0x80000000 */
#define GPIO_BSRR_BR15                       GPIO_BSRR_BR15_Msk                /*!< Port x Reset bit 15 */

/*******************  Bit definition for GPIO_BRR register  *******************/
#define GPIO_BRR_BR0_Pos                     (0U)                              
#define GPIO_BRR_BR0_Msk                     (0x1UL << GPIO_BRR_BR0_Pos)        /*!< 0x00000001 */
#define GPIO_BRR_BR0                         GPIO_BRR_BR0_Msk                  /*!< Port x Reset bit 0 */
#define GPIO_BRR_BR1_Pos                     (1U)                              
#define GPIO_BRR_BR1_Msk                     (0x1UL << GPIO_BRR_BR1_Pos)        /*!< 0x00000002 */
#define GPIO_BRR_BR1                         GPIO_BRR_BR1_Msk                  /*!< Port x Reset bit 1 */
#define GPIO_BRR_BR2_Pos                     (2U)                              
#define GPIO_BRR_BR2_Msk                     (0x1UL << GPIO_BRR_BR2_Pos)        /*!< 0x00000004 */
#define GPIO_BRR_BR2                         GPIO_BRR_BR2_Msk                  /*!< Port x Reset bit 2 */
#define GPIO_BRR_BR3_Pos                     (3U)                              
#define GPIO_BRR_BR3_Msk                     (0x1UL << GPIO_BRR_BR3_Pos)        /*!< 0x00000008 */
#define GPIO_BRR_BR3                         GPIO_BRR_BR3_Msk                  /*!< Port x Reset bit 3 */
#define GPIO_BRR_BR4_Pos                     (4U)                              
#define GPIO_BRR_BR4_Msk                     (0x1UL << GPIO_BRR_BR4_Pos)        /*!< 0x00000010 */
#define GPIO_BRR_BR4                         GPIO_BRR_BR4_Msk                  /*!< Port x Reset bit 4 */
#define GPIO_BRR_BR5_Pos                     (5U)                              
#define GPIO_BRR_BR5_Msk                     (0x1UL << GPIO_BRR_BR5_Pos)        /*!< 0x00000020 */
#define GPIO_BRR_BR5                         GPIO_BRR_BR5_Msk                  /*!< Port x Reset bit 5 */
#define GPIO_BRR_BR6_Pos                     (6U)                              
#define GPIO_BRR_BR6_Msk                     (0x1UL << GPIO_BRR_BR6_Pos)        /*!< 0x00000040 */
#define GPIO_BRR_BR6                         GPIO_BRR_BR6_Msk                  /*!< Port x Reset bit 6 */
#define GPIO_BRR_BR7_Pos                     (7U)                              
#define GPIO_BRR_BR7_Msk                     (0x1UL << GPIO_BRR_BR7_Pos)        /*!< 0x00000080 */
#define GPIO_BRR_BR7                         GPIO_BRR_BR7_Msk                  /*!< Port x Reset bit 7 */
#define GPIO_BRR_BR8_Pos                     (8U)                              
#define GPIO_BRR_BR8_Msk                     (0x1UL << GPIO_BRR_BR8_Pos)        /*!< 0x00000100 */
#define GPIO_BRR_BR8                         GPIO_BRR_BR8_Msk                  /*!< Port x Reset bit 8 */
#define GPIO_BRR_BR9_Pos                     (9U)                              
#define GPIO_BRR_BR9_Msk                     (0x1UL << GPIO_BRR_BR9_Pos)        /*!< 0x00000200 */
#define GPIO_BRR_BR9                         GPIO_BRR_BR9_Msk                  /*!< Port x Reset bit 9 */
#define GPIO_BRR_BR10_Pos                    (10U)                             
#define GPIO_BRR_BR10_Msk                    (0x1UL << GPIO_BRR_BR10_Pos)       /*!< 0x00000400 */
#define GPIO_BRR_BR10                        GPIO_BRR_BR10_Msk                 /*!< Port x Reset bit 10 */
#define GPIO_BRR_BR11_Pos                    (11U)                             
#define GPIO_BRR_BR11_Msk                    (0x1UL << GPIO_BRR_BR11_Pos)       /*!< 0x00000800 */
#define GPIO_BRR_BR11                        GPIO_BRR_BR11_Msk                 /*!< Port x Reset bit 11 */
#define GPIO_BRR_BR12_Pos                    (12U)                             
#define GPIO_BRR_BR12_Msk                    (0x1UL << GPIO_BRR_BR12_Pos)       /*!< 0x00001000 */
#define GPIO_BRR_BR12                        GPIO_BRR_BR12_Msk                 /*!< Port x Reset bit 12 */
#define GPIO_BRR_BR13_Pos                    (13U)                             
#define GPIO_BRR_BR13_Msk                    (0x1UL << GPIO_BRR_BR13_Pos)       /*!< 0x00002000 */
#define GPIO_BRR_BR13                        GPIO_BRR_BR13_Msk                 /*!< Port x Reset bit 13 */
#define GPIO_BRR_BR14_Pos                    (14U)                             
#define GPIO_BRR_BR14_Msk                    (0x1UL << GPIO_BRR_BR14_Pos)       /*!< 0x00004000 */
#define GPIO_BRR_BR14                        GPIO_BRR_BR14_Msk                 /*!< Port x Reset bit 14 */
#define GPIO_BRR_BR15_Pos                    (15U)                             
#define GPIO_BRR_BR15_Msk                    (0x1UL << GPIO_BRR_BR15_Pos)       /*!< 0x00008000 */
#define GPIO_BRR_BR15                        GPIO_BRR_BR15_Msk                 /*!< Port x Reset bit 15 */

/******************  Bit definition for GPIO_LCKR register  *******************/
#define GPIO_LCKR_LCK0_Pos                   (0U)                              
#define GPIO_LCKR_LCK0_Msk                   (0x1UL << GPIO_LCKR_LCK0_Pos)      /*!< 0x00000001 */
#define GPIO_LCKR_LCK0                       GPIO_LCKR_LCK0_Msk                /*!< Port x Lock bit 0 */
#define GPIO_LCKR_LCK1_Pos                   (1U)                              
#define GPIO_LCKR_LCK1_Msk                   (0x1UL << GPIO_LCKR_LCK1_Pos)      /*!< 0x00000002 */
#define GPIO_LCKR_LCK1                       GPIO_LCKR_LCK1_Msk                /*!< Port x Lock bit 1 */
#define GPIO_LCKR_LCK2_Pos                   (2U)                              
#define GPIO_LCKR_LCK2_Msk                   (0x1UL << GPIO_LCKR_LCK2_Pos)      /*!< 0x00000004 */
#define GPIO_LCKR_LCK2                       GPIO_LCKR_LCK2_Msk                /*!< Port x Lock bit 2 */
#define GPIO_LCKR_LCK3_Pos                   (3U)                              
#define GPIO_LCKR_LCK3_Msk                   (0x1UL << GPIO_LCKR_LCK3_Pos)      /*!< 0x00000008 */
#define GPIO_LCKR_LCK3                       GPIO_LCKR_LCK3_Msk                /*!< Port x Lock bit 3 */
#define GPIO_LCKR_LCK4_Pos                   (4U)                              
#define GPIO_LCKR_LCK4_Msk                   (0x1UL << GPIO_LCKR_LCK4_Pos)      /*!< 0x00000010 */
#define GPIO_LCKR_LCK4                       GPIO_LCKR_LCK4_Msk                /*!< Port x Lock bit 4 */
#define GPIO_LCKR_LCK5_Pos                   (5U)                              
#define GPIO_LCKR_LCK5_Msk                   (0x1UL << GPIO_LCKR_LCK5_Pos)      /*!< 0x00000020 */
#define GPIO_LCKR_LCK5                       GPIO_LCKR_LCK5_Msk                /*!< Port x Lock bit 5 */
#define GPIO_LCKR_LCK6_Pos                   (6U)                              
#define GPIO_LCKR_LCK6_Msk                   (0x1UL << GPIO_LCKR_LCK6_Pos)      /*!< 0x00000040 */
#define GPIO_LCKR_LCK6                       GPIO_LCKR_LCK6_Msk                /*!< Port x Lock bit 6 */
#define GPIO_LCKR_LCK7_Pos                   (7U)                              
#define GPIO_LCKR_LCK7_Msk                   (0x1UL << GPIO_LCKR_LCK7_Pos)      /*!< 0x00000080 */
#define GPIO_LCKR_LCK7                       GPIO_LCKR_LCK7_Msk                /*!< Port x Lock bit 7 */
#define GPIO_LCKR_LCK8_Pos                   (8U)                              
#define GPIO_LCKR_LCK8_Msk                   (0x1UL << GPIO_LCKR_LCK8_Pos)      /*!< 0x00000100 */
#define GPIO_LCKR_LCK8                       GPIO_LCKR_LCK8_Msk                /*!< Port x Lock bit 8 */
#define GPIO_LCKR_LCK9_Pos                   (9U)                              
#define GPIO_LCKR_LCK9_Msk                   (0x1UL << GPIO_LCKR_LCK9_Pos)      /*!< 0x00000200 */
#define GPIO_LCKR_LCK9                       GPIO_LCKR_LCK9_Msk                /*!< Port x Lock bit 9 */
#define GPIO_LCKR_LCK10_Pos                  (10U)                             
#define GPIO_LCKR_LCK10_Msk                  (0x1UL << GPIO_LCKR_LCK10_Pos)     /*!< 0x00000400 */
#define GPIO_LCKR_LCK10                      GPIO_LCKR_LCK10_Msk               /*!< Port x Lock bit 10 */
#define GPIO_LCKR_LCK11_Pos                  (11U)                             
#define GPIO_LCKR_LCK11_Msk                  (0x1UL << GPIO_LCKR_LCK11_Pos)     /*!< 0x00000800 */
#define GPIO_LCKR_LCK11                      GPIO_LCKR_LCK11_Msk               /*!< Port x Lock bit 11 */
#define GPIO_LCKR_LCK12_Pos                  (12U)                             
#define GPIO_LCKR_LCK12_Msk                  (0x1UL << GPIO_LCKR_LCK12_Pos)     /*!< 0x00001000 */
#define GPIO_LCKR_LCK12                      GPIO_LCKR_LCK12_Msk               /*!< Port x Lock bit 12 */
#define GPIO_LCKR_LCK13_Pos                  (13U)                             
#define GPIO_LCKR_LCK13_Msk                  (0x1UL << GPIO_LCKR_LCK13_Pos)     /*!< 0x00002000 */
#define GPIO_LCKR_LCK13                      GPIO_LCKR_LCK13_Msk               /*!< Port x Lock bit 13 */
#define GPIO_LCKR_LCK14_Pos                  (14U)                             
#define GPIO_LCKR_LCK14_Msk                  (0x1UL << GPIO_LCKR_LCK14_Pos)     /*!< 0x00004000 */
#define GPIO_LCKR_LCK14                      GPIO_LCKR_LCK14_Msk               /*!< Port x Lock bit 14 */
#define GPIO_LCKR_LCK15_Pos                  (15U)                             
#define GPIO_LCKR_LCK15_Msk                  (0x1UL << GPIO_LCKR_LCK15_Pos)     /*!< 0x00008000 */
#define GPIO_LCKR_LCK15                      GPIO_LCKR_LCK15_Msk               /*!< Port x Lock bit 15 */
#define GPIO_LCKR_LCKK_Pos                   (16U)                             
#define GPIO_LCKR_LCKK_Msk                   (0x1UL << GPIO_LCKR_LCKK_Pos)      /*!< 0x00010000 */
#define GPIO_LCKR_LCKK                       GPIO_LCKR_LCKK_Msk                /*!< Lock key */

/*----------------------------------------------------------------------------*/
#endif /* REGISTER_H_ */
