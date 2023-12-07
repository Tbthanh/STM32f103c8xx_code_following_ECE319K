;****************** Lab1.s ***************
; Program initially written by: Yerraballi and Valvano
; Author: Tran Ba Thanh                
; Date Created: 1/15/2018 
; Last Modified: 18/11/2023
; Brief description of the program: Solution to Lab1
; The objective of this system is to implement a parity system
; Hardware connections:
;  Output is negative logic, 0 turns on the LED, 1 turns off the LED
;  Inputs are negative logic, meaning switch not pressed is 1, pressed is 0
;	PA0 	is an input   
;	PA1 	is an input   
;	PA2 	is an input  
;	PC13 	is the output 

	;myAplication get called in startup!
	EXPORT myApplication	

RCC_APB2ENR	EQU	0x40021018
GPIOA		EQU	0x40010800
GPIOC		EQU 0x40011000
	
	;The |.text| in this case mySection3
	;can change but have to match the .sct linker files
	AREA mySection3, CODE, READONLY

myApplication
	;Enable port A & C in RCC_APB2
	MOV 	R0,#0x14
	LDR 	R1,=RCC_APB2ENR
	STR 	R0,[R1]
	
	;Config GPIO C13 for output
	LDR 	R1,=GPIOC
	MOV32	R0,#0x00200000		;172/1136_RM0008_Rev21
	STR		R0,[R1,#0X04]		;GPIOC_CRH
	
	;Clear led
	MOV32	R0,#0x00002000		;Because internal pull up
	STR		R0,[R1,#0x0C]
	
	;Config GPIO A0,A1,A2 for input
	LDR		R3,=GPIOA
	MOV32	R2,#0x00000888
	STR		R2,[R3,#0X00]		;GPIOA_CRL
	;Set input pull-up for A0, A1, A2
	MOV32	R4,#0x00000007
	STR		R4,[R3,#0x0C]		;Table 20 in RM0008_Rev21
	
	;Y = A0 ^ A1 ^ A2
CHECK_INPUT
	LDR		R4,[R3,#0x08]
	AND		R5,R4,#0x00000001	;A0 = R5
	AND		R6,R4,#0x00000002	;A1 = R5
	AND		R7,R4,#0x00000004	;A2 = R7
	;Have to shift bits before compare them
	LSR		R6,R6,#1
	LSR		R7,R7,#2
	EOR		R5,R5,R6
	EOR		R5,R5,R7			;Y = R5
	ANDS	R5,R5,#0x00000001
	BEQ		LED_ON
	BNE		LED_OFF
	B		LOOP
	
LED_ON
	;Turn the led on
	MOV32	R0,#0x00000000
	STR		R0,[R1,#0x0C]
	B		CHECK_INPUT
	
LED_OFF
	;Turn the led off
	MOV32	R0,#0x00002000
	STR		R0,[R1,#0x0C]
	B		CHECK_INPUT

LOOP
	B		CHECK_INPUT
	
	END