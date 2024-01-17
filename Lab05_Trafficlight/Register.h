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


#endif /* REGISTER_H_ */
