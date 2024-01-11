/*
 * Register.h
 *
 *  Created on: Jan 11, 2024
 *      Author: TBTHANH
 *     Purpose: To create a memory map structure
 */

#ifndef REGISTER_H_
#define REGISTER_H_

/* Register address */
// Base address
#define RCC_BASE			(0x40021000)
#define GPIO_A_BASE			((volatile uint32_t *)(0x40010800))
#define GPIO_B_BASE			((volatile uint32_t *)(0x40010C00))
// GPIO registers (ref: RM0008 9.2)
#define GPIOx_CRL			((uint32_t *)(0x00))
#define GPIOx_CRH			((volatile uint32_t *)(0x04))
#define GPIOx_IDR			((volatile uint32_t *)(0x08))
#define GPIOx_ODR			((volatile uint32_t *)(0x0C))

// portA registers
#define GPIO_A_CRL			((volatile uint32_t *)(GPIO_A_BASE + 0x00))
#define GPIO_A_IDR			((volatile uint32_t *)(GPIO_A_BASE + 0x08))
#define GPIO_A_ODR			((volatile uint32_t *)(GPIO_A_BASE + 0x0C))

//  RCC clock registers
#define RCC_APB2ENR         ((volatile uint32_t *)(RCC_BASE + 0x18))



#endif /* REGISTER_H_ */
