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

	AREA mySection3, CODE, READONLY
		
myApplication
	;Enable port A & C in RCC_APB2
	MOV 	R0,#0x04
	LDR 	R1,=RCC_APB2ENR
	STR 	R0,[R1]
	
	;Config GPIO A0,A1 for input, A2 for output
	LDR		R3,=GPIOA
	MOV32	R2,#0x00000288		; 171/1136 RM0008
	STR		R2,[R3,#0X00]		; GPIOA_CRL
	;Set input pull-up for A0, A1, clear LED
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
	
	MOV32	R9,#198				; to use the perlintable when breathe butt is pressed
	LDR		R8,=PerlinTable
	AND		R4,R2,#0x02			; R4 = breathe button
	CMP		R4,#0x02
	BNE		breathe
	
	AND		R4,R2,#0x01			; R4 = change button
	CMP		R4,#0x01
	BNE		change

	B		PWM
	B		loop				; just a dummy cause B PWM is enough

; turn on the led PA2
LED_On
	LDR 	R1,=GPIOA
	LDR 	R0,[R1,#0x0C]
	ORR 	R0,R0,#0x04 		; bit 2 high
	STR 	R0,[R1,#0x0C]
	BX 		LR

; turn off the led PA2
LED_Off
	LDR 	R1,=GPIOA
	LDR 	R0,[R1,#0x0C]
	BIC 	R0,R0,#0x04 		; bit 2 low
	STR 	R0,[R1,#0x0C]
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

;; function to wait 100ns * R0 but for TI launchboard
;; need 8 cycle cause 1 cycle is 12.5ns
;Delay
;	NOP 						; dummy operation
;	NOP							; page 35/121 ID070610 Cortex - M4 Revision r0p1
;	NOP
;	NOP
;	SUBS 	R0,R0,#1			; 3 cycle
;	BNE  	Delay
;	BX   	LR

; function to wait 100ns * R0
; https://developer.arm.com/documentation/ddi0484/c/CHDCICDF
; Because STM32f103c8 only run at 72MHz -> 1 cycle is 14ns
; So it takes 7 cycle to reach approximately 100ns
Delay
	;NOP 						; 1 cycle - dummy operation
	;NOP							; 1 cycle
	;NOP							; 1 cycle
	NOP							; 1 cycle
	SUBS 	R0,R0,#1			; 1 cycle
	BNE  	Delay				; 1 if not, 2 if taken
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
	MOV32	R6,#500000			;  50ms
	B		PWM

duty_cycle_04
	MOV32	R5,#500000			;  50ms
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
	LDR		R5,[R8]
	MOV32	R6,#0x0000C350		; 50000
	SUBS	R6,R6,R5			; R6 = 500000 - R5
	
	BL   	LED_On
	MOV  	R0,R5 				; H
	BL   	Delay
	BL   	LED_Off
	MOV  	R0,R6 				; L
	BL   	Delay
	
	ADD 	R8,R8,#8
	SUBS	R9,R9,#1
	BEQ		butt_check			; at the end of the Perlintable, turn back to buttcheck to restart the table index
	
	; checking if breate button is still being push
	LDR		R2,[R3,#0x08]
    AND		R4,R2,#0x02			; R4 = breathe button
	CMP		R4,#0x02
	BNE		breathe
	
; 256 points with values from 100 to 9900      
PerlinTable
	DCD 1000,1490,1980,2470,2960,3450,3940,4430,4920,5410,5900,6390,6880,7370,7860,8350,8840,9330,9820
	DCD	10310,10800,11290,11780,12270,12760,13250,13740,14230,14720,15210,15700,16190,16680,17170,17660,18150
	DCD	18640,19130,19620,20110,20600,21090,21580,22070,22560,23050,23540,24030,24520,25010,25500,25990,26480
	DCD	26970,27460,27950,28440,28930,29420,29910,30400,30890,31380,31870,32360,32850,33340,33830,34320,34810
	DCD	35300,35790,36280,36770,37260,37750,38240,38730,39220,39710,40200,40690,41180,41670,42160,42650,43140
	DCD	43630,44120,44610,45100,45590,46080,46570,47060,47550,48040,48530,49020,49510,49020,48530
	DCD	48040,47550,47060,46570,46080,45590,45100,44610,44120,43630,43140,42650,42160,41670,41180,40690,40200
	DCD	39710,39220,38730,38240,37750,37260,36770,36280,35790,35300,34810,34320,33830,33340,32850,32360,31870
	DCD	31380,30890,30400,29910,29420,28930,28440,27950,27460,26970,26480,25990,25500,25010,24520,24030,23540
	DCD	23050,22560,22070,21580,21090,20600,20110,19620,19130,18640,18150,17660,17170,16680,16190,15700,15210
	DCD	14720,14230,13740,13250,12760,12270,11780,11290,10800,10310,9820,9330,8840,8350,7860,7370,6880,6390
	DCD	5900,5410,4920,4430,3940,3450,2960,2470,1980,1490,1000
	

	
	ALIGN 4
	
	END

