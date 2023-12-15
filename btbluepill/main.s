	EXPORT myApplication
RCC_BASE	EQU	0x40021000
PORTC	    EQU	0x40011000
COUNT       EQU 0x28B0AB
	
      AREA mySection3, CODE, READONLY
myApplication
	;comment: enable port C clock
	LDR R1,= RCC_BASE
	MOV R0,#0x0010
	STR R0,[R1,#0x18]
	
	;chinh huong portc13
	LDR R1,= PORTC
	MOV32 R0,#0x00100000
	STR R0,[R1,#0x04]

loop
	LDR R1,= PORTC
	MOV R0,#0x2000
	STR R0,[R1,#0x0C]
	
	LDR R3,=COUNT
DENBAT	
	SUBS R3,#1
	BNE DENBAT
	
	
	
	
	
	LDR R1,= PORTC
	MOV R0,#0x0000
	STR R0,[R1,#0x0C]
	
	LDR R3,=COUNT
DENTAT	
	SUBS R3,#1
	BNE DENTAT
	
	

	B loop

      ALIGN
		  
      END