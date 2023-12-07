;****************** Lab3.s ***************
; Program written by: Tran Ba Thanh
; Date Created: 07/12/2023
; Last Modified: 07/12/2023
; Brief description of the program
;   The LED toggles at 2 Hz and a varying duty-cycle
; Hardware connections (External: Two buttons and one LED)
;  Change is Button PA0 input  (1 means pressed, 0 means not pressed)
;  Breathe is Button PA1 input  (1 means pressed, 0 means not pressed)
;  LED is an output PC13 (1 activates external LED)
; Overall functionality of this system is to operate like this
;   1) Make LED an output and make Change and Breathe inputs.
;   2) The system starts with the the LED toggling at 2Hz,
;      which is 2 times per second with a duty-cycle of 30%.
;      Therefore, the LED is ON for 150ms and off for 350 ms.
;   3) When the Change button is pmressed-and-released increase
;      the duty cycle by 20% (modulo 100%). Therefore for each
;      press-and-release the duty cycle changes from 30% to 70% to 70%
;      to 90% to 10% to 30% so on
;   4) Implement a "breathing LED" when Breathe Switch is pressed:

; Input 	PA00, PA01
; Output	PA02

;********* Register *********
; R1 is GPIOC based address
; R3 is GPIOA based address
; R5, R6 is H & L of delay fuction
;
;****************************

; define base address
	EXPORT myApplication
RCC_APB2ENR	EQU	0x40021018
GPIOA		EQU	0x40010800
GPIOC		EQU 0x40011000

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
	
	;Config GPIO A0,A1 for input
	LDR		R3,=GPIOA
	MOV32	R2,#0x00000088
	STR		R2,[R3,#0X00]		;GPIOA_CRL
	;Set input pull-up for A0, A1
	MOV32	R4,#0x00000003
	STR		R4,[R3,#0x0C]		;Table 20 in RM0008_Rev21
	
	MOV32	R7,#0x00000000		; clear R7 to make it change button counter
	MOV32	R5,#1500000			; 150ms
	MOV32	R6,#3500000			; 350ms
	
loop
; main engine goes here
; check input
butt_check
	; read data from A00 and A01
	LDR		R2,[R3,#0x08]	
	
	MOV32	R9,#256				; to use the perlintable when breathe butt is pressed
	LDR		R8,=PerlinTable
	AND		R4,R2,#0x02			; R4 = breathe button
	CMP		R4,#0x02
	BNE		breathe
	
	AND		R4,R2,#0x01			; R4 = change button
	CMP		R4,#0x01
	BNE		change

	B		PWM
	B		loop				; just a dummy cause B PWM is enough

; turn on the led PE4
LED_On
	MOV32	R0,#0x00000000		; pin 13 off
	STR		R0,[R1,#0x0C]
	BX 		LR

; turn off the led PE4
LED_Off
	MOV32	R0,#0x00002000		; pin 13 on
	STR		R0,[R1,#0x0C]
	BX 		LR

; R5 is H, the time the LED is on
; R6 is L, the time the LED is off (H+L should be constant)
PWM   
	BL   	LED_On
	MOV  	R0,R5 				;H
	BL   	Delay
	BL   	LED_Off
	MOV  	R0,R6 				;L
	BL   	Delay
	B		butt_check

; function to wait 100ns*R0
Delay
	NOP 						;dummy operation
	NOP
	NOP
	NOP
	SUBS 	R0,R0,#1
	BNE  	Delay
	BX   	LR

duty_cycle_00
	MOV32	R7,#0x00000000		; clear
	MOV32	R5,#1500000			; 150ms
	MOV32	R6,#3500000			; 350ms
	B		PWM
	LTORG

duty_cycle_01
	MOV32	R5,#2500000			; 250ms
	MOV32	R6,#2500000			; 250ms
	B		PWM

duty_cycle_02
	MOV32	R5,#3500000			; 350ms
	MOV32	R6,#1500000			; 150ms
	B		PWM

duty_cycle_03
	MOV32	R5,#4500000			; 450ms
	MOV32	R6,#500000			; 50ms
	B		PWM

duty_cycle_04
	MOV32	R5,#500000			; 50ms
	MOV32	R6,#4500000			; 450ms
	B		PWM

; this "change" function get called when change button (PE0) is pressed
; it will change the R5 - H and R6 - L of the PWM fuction
change
	ADD		R7,#0x01
	
	CMP		R7,#0x01
	BEQ		duty_cycle_01
	
	CMP		R7,#0x02
	BEQ		duty_cycle_02
	
	CMP		R7,#0x03
	BEQ		duty_cycle_03
	
	CMP		R7,#0x04
	BEQ		duty_cycle_04
	
	CMP		R7,#0x05			; 5 is 0, this also reset R7 to 0
	BEQ		duty_cycle_00
	
	B		butt_check
	

; this "breathe" fuction get called when breathe button (PE2) is pressed
breathe
	; impliment breathe til breathe is release
	LDRH	R5,[R8]
	MOV32	R6,#10000
	SUB		R6,R6,R5			; R6 = 10000 - R5
	
	BL   	LED_On
	MOV  	R0,R5 				; H
	BL   	Delay
	BL   	LED_Off
	MOV  	R0,R6 				; L
	BL   	Delay
	
	ADD 	R8,R8,#2
	SUBS	R9,R9,#1
	BEQ		butt_check			; at the end of the Perlintable, turn back to buttcheck to restart the table index
	
	; checking if breate button is still being push
	LDR		R2,[R3,#0x08]
    AND		R4,R2,#0x02			; R4 = breathe button
	CMP		R4,#0x02
	BNE		breathe
	
	B		butt_check
	
; 256 points with values from 100 to 9900      
PerlinTable
	DCW 5880,6225,5345,3584,3545,674,5115,598,7795,3737,3775,2129,7527,9020,368,8713,5459,1478,4043,1248,2741,5536,406
	DCW 3890,1516,9288,904,483,980,7373,330,5766,9555,4694,9058,2971,100,1095,7641,2473,3698,9747,8484,7871,4579,1440
	DCW 521,1325,2282,6876,1363,3469,9173,5804,2244,3430,6761,866,4885,5306,6646,6531,2703,6799,2933,6416,2818,5230,5421
	DCW 1938,1134,6455,3048,5689,6148,8943,3277,4349,8866,4770,2397,8177,5191,8905,8522,4120,3622,1670,2205,1861,9479
	DCW 1631,9441,4005,5574,2167,2588,1057,2512,6263,138,8369,3163,2895,8101,3009,5153,7259,8063,3507,789,6570,7756,7603
	DCW 5268,5077,4541,7297,6187,3392,6378,3928,4273,7680,6723,7220,215,2550,2091,8407,8752,9670,4847,4809,291,7833,1555
	DCW 5727,4617,4923,9862,3239,3354,8216,8024,7986,2359,8790,1899,713,2320,751,7067,7335,1172,1708,8637,7105,6608,8254
	DCW 4655,9594,5919,177,1784,5995,6340,2780,8560,5957,3966,6034,6493,1746,6684,445,5038,942,1593,9785,827,3852,4234
	DCW 4311,3124,4426,8675,8981,6914,7182,4388,4081,8445,9517,3813,8828,9709,1402,9364,7488,9211,8139,5613,559,7412
	DCW 6952,6302,9326,3201,2052,5651,9096,9632,636,9249,4196,1976,7450,8292,1287,7029,7718,4158,6110,7144,3316,7909
	DCW 6838,4502,4732,2014,1823,4962,253,5842,9823,5383,9134,7948,3660,8598,4464,2665,1210,1019,2856,9402,5498,5000
	DCW 7565,3086,2627,8330,2435,6072,6991
; 100 numbers from 0 to 10000
; sinusoidal shape
	ALIGN 4
	
	END

