;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.0.0 #11528 (Linux)
;--------------------------------------------------------
	.module nixie_tube
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _delay
	.globl _select_char
	.globl _select_nixie_tube
	.globl _TF2
	.globl _EXF2
	.globl _RCLK
	.globl _TCLK
	.globl _EXEN2
	.globl _TR2
	.globl _C_T2
	.globl _CP_RL2
	.globl _T2CON_7
	.globl _T2CON_6
	.globl _T2CON_5
	.globl _T2CON_4
	.globl _T2CON_3
	.globl _T2CON_2
	.globl _T2CON_1
	.globl _T2CON_0
	.globl _PT2
	.globl _ET2
	.globl _CY
	.globl _AC
	.globl _F0
	.globl _RS1
	.globl _RS0
	.globl _OV
	.globl _F1
	.globl _P
	.globl _PS
	.globl _PT1
	.globl _PX1
	.globl _PT0
	.globl _PX0
	.globl _RD
	.globl _WR
	.globl _T1
	.globl _T0
	.globl _INT1
	.globl _INT0
	.globl _TXD
	.globl _RXD
	.globl _P3_7
	.globl _P3_6
	.globl _P3_5
	.globl _P3_4
	.globl _P3_3
	.globl _P3_2
	.globl _P3_1
	.globl _P3_0
	.globl _EA
	.globl _ES
	.globl _ET1
	.globl _EX1
	.globl _ET0
	.globl _EX0
	.globl _P2_7
	.globl _P2_6
	.globl _P2_5
	.globl _P2_4
	.globl _P2_3
	.globl _P2_2
	.globl _P2_1
	.globl _P2_0
	.globl _SM0
	.globl _SM1
	.globl _SM2
	.globl _REN
	.globl _TB8
	.globl _RB8
	.globl _TI
	.globl _RI
	.globl _P1_7
	.globl _P1_6
	.globl _P1_5
	.globl _P1_4
	.globl _P1_3
	.globl _P1_2
	.globl _P1_1
	.globl _P1_0
	.globl _TF1
	.globl _TR1
	.globl _TF0
	.globl _TR0
	.globl _IE1
	.globl _IT1
	.globl _IE0
	.globl _IT0
	.globl _P0_7
	.globl _P0_6
	.globl _P0_5
	.globl _P0_4
	.globl _P0_3
	.globl _P0_2
	.globl _P0_1
	.globl _P0_0
	.globl _TH2
	.globl _TL2
	.globl _RCAP2H
	.globl _RCAP2L
	.globl _T2CON
	.globl _B
	.globl _ACC
	.globl _PSW
	.globl _IP
	.globl _P3
	.globl _IE
	.globl _P2
	.globl _SBUF
	.globl _SCON
	.globl _P1
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _P0
	.globl _alphabet
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0	=	0x0080
_SP	=	0x0081
_DPL	=	0x0082
_DPH	=	0x0083
_PCON	=	0x0087
_TCON	=	0x0088
_TMOD	=	0x0089
_TL0	=	0x008a
_TL1	=	0x008b
_TH0	=	0x008c
_TH1	=	0x008d
_P1	=	0x0090
_SCON	=	0x0098
_SBUF	=	0x0099
_P2	=	0x00a0
_IE	=	0x00a8
_P3	=	0x00b0
_IP	=	0x00b8
_PSW	=	0x00d0
_ACC	=	0x00e0
_B	=	0x00f0
_T2CON	=	0x00c8
_RCAP2L	=	0x00ca
_RCAP2H	=	0x00cb
_TL2	=	0x00cc
_TH2	=	0x00cd
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0_0	=	0x0080
_P0_1	=	0x0081
_P0_2	=	0x0082
_P0_3	=	0x0083
_P0_4	=	0x0084
_P0_5	=	0x0085
_P0_6	=	0x0086
_P0_7	=	0x0087
_IT0	=	0x0088
_IE0	=	0x0089
_IT1	=	0x008a
_IE1	=	0x008b
_TR0	=	0x008c
_TF0	=	0x008d
_TR1	=	0x008e
_TF1	=	0x008f
_P1_0	=	0x0090
_P1_1	=	0x0091
_P1_2	=	0x0092
_P1_3	=	0x0093
_P1_4	=	0x0094
_P1_5	=	0x0095
_P1_6	=	0x0096
_P1_7	=	0x0097
_RI	=	0x0098
_TI	=	0x0099
_RB8	=	0x009a
_TB8	=	0x009b
_REN	=	0x009c
_SM2	=	0x009d
_SM1	=	0x009e
_SM0	=	0x009f
_P2_0	=	0x00a0
_P2_1	=	0x00a1
_P2_2	=	0x00a2
_P2_3	=	0x00a3
_P2_4	=	0x00a4
_P2_5	=	0x00a5
_P2_6	=	0x00a6
_P2_7	=	0x00a7
_EX0	=	0x00a8
_ET0	=	0x00a9
_EX1	=	0x00aa
_ET1	=	0x00ab
_ES	=	0x00ac
_EA	=	0x00af
_P3_0	=	0x00b0
_P3_1	=	0x00b1
_P3_2	=	0x00b2
_P3_3	=	0x00b3
_P3_4	=	0x00b4
_P3_5	=	0x00b5
_P3_6	=	0x00b6
_P3_7	=	0x00b7
_RXD	=	0x00b0
_TXD	=	0x00b1
_INT0	=	0x00b2
_INT1	=	0x00b3
_T0	=	0x00b4
_T1	=	0x00b5
_WR	=	0x00b6
_RD	=	0x00b7
_PX0	=	0x00b8
_PT0	=	0x00b9
_PX1	=	0x00ba
_PT1	=	0x00bb
_PS	=	0x00bc
_P	=	0x00d0
_F1	=	0x00d1
_OV	=	0x00d2
_RS0	=	0x00d3
_RS1	=	0x00d4
_F0	=	0x00d5
_AC	=	0x00d6
_CY	=	0x00d7
_ET2	=	0x00ad
_PT2	=	0x00bd
_T2CON_0	=	0x00c8
_T2CON_1	=	0x00c9
_T2CON_2	=	0x00ca
_T2CON_3	=	0x00cb
_T2CON_4	=	0x00cc
_T2CON_5	=	0x00cd
_T2CON_6	=	0x00ce
_T2CON_7	=	0x00cf
_CP_RL2	=	0x00c8
_C_T2	=	0x00c9
_TR2	=	0x00ca
_EXEN2	=	0x00cb
_TCLK	=	0x00cc
_RCLK	=	0x00cd
_EXF2	=	0x00ce
_TF2	=	0x00cf
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_alphabet::
	.ds 17
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG
__start__stack:
	.ds	1

;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
;	nixie_tube.c:59: char alphabet[17] = {
	mov	_alphabet,#0x3f
	mov	(_alphabet + 0x0001),#0x06
	mov	(_alphabet + 0x0002),#0x5b
	mov	(_alphabet + 0x0003),#0x4f
	mov	(_alphabet + 0x0004),#0x66
	mov	(_alphabet + 0x0005),#0x6d
	mov	(_alphabet + 0x0006),#0x7d
	mov	(_alphabet + 0x0007),#0x07
	mov	(_alphabet + 0x0008),#0x7f
	mov	(_alphabet + 0x0009),#0x6f
	mov	(_alphabet + 0x000a),#0x77
	mov	(_alphabet + 0x000b),#0x7c
	mov	(_alphabet + 0x000c),#0x39
	mov	(_alphabet + 0x000d),#0x5e
	mov	(_alphabet + 0x000e),#0x79
	mov	(_alphabet + 0x000f),#0x71
	mov	(_alphabet + 0x0010),#0x80
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	ljmp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'select_nixie_tube'
;------------------------------------------------------------
;num                       Allocated to registers r7 
;------------------------------------------------------------
;	nixie_tube.c:6: void select_nixie_tube(char num) {
;	-----------------------------------------
;	 function select_nixie_tube
;	-----------------------------------------
_select_nixie_tube:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
;	nixie_tube.c:7: switch(num){
	mov	a,dpl
	mov	r7,a
	add	a,#0xff - 0x07
	jnc	00116$
	ret
00116$:
	mov	a,r7
	add	a,#(00117$-3-.)
	movc	a,@a+pc
	mov	dpl,a
	mov	a,r7
	add	a,#(00118$-3-.)
	movc	a,@a+pc
	mov	dph,a
	clr	a
	jmp	@a+dptr
00117$:
	.db	00101$
	.db	00102$
	.db	00103$
	.db	00104$
	.db	00105$
	.db	00106$
	.db	00107$
	.db	00108$
00118$:
	.db	00101$>>8
	.db	00102$>>8
	.db	00103$>>8
	.db	00104$>>8
	.db	00105$>>8
	.db	00106$>>8
	.db	00107$>>8
	.db	00108$>>8
;	nixie_tube.c:8: case 0:
00101$:
;	nixie_tube.c:9: bit0 = 0;
;	assignBit
	clr	_P2_2
;	nixie_tube.c:10: bit1 = 0;
;	assignBit
	clr	_P2_3
;	nixie_tube.c:11: bit2 = 0;
;	assignBit
	clr	_P2_4
;	nixie_tube.c:12: break;
;	nixie_tube.c:13: case 1:
	ret
00102$:
;	nixie_tube.c:14: bit0 = 1; 
;	assignBit
	setb	_P2_2
;	nixie_tube.c:15: bit1 = 0; 
;	assignBit
	clr	_P2_3
;	nixie_tube.c:16: bit2 = 0;
;	assignBit
	clr	_P2_4
;	nixie_tube.c:17: break;
;	nixie_tube.c:18: case 2:
	ret
00103$:
;	nixie_tube.c:19: bit0 = 0;
;	assignBit
	clr	_P2_2
;	nixie_tube.c:20: bit1 = 1; 
;	assignBit
	setb	_P2_3
;	nixie_tube.c:21: bit2 = 0;
;	assignBit
	clr	_P2_4
;	nixie_tube.c:22: break;
;	nixie_tube.c:23: case 3:
	ret
00104$:
;	nixie_tube.c:24: bit0 = 1; 
;	assignBit
	setb	_P2_2
;	nixie_tube.c:25: bit1 = 1; 
;	assignBit
	setb	_P2_3
;	nixie_tube.c:26: bit2 = 0; 
;	assignBit
	clr	_P2_4
;	nixie_tube.c:27: break;
;	nixie_tube.c:28: case 4:
	ret
00105$:
;	nixie_tube.c:29: bit0 = 0;
;	assignBit
	clr	_P2_2
;	nixie_tube.c:30: bit1 = 0;
;	assignBit
	clr	_P2_3
;	nixie_tube.c:31: bit2 = 1;
;	assignBit
	setb	_P2_4
;	nixie_tube.c:32: break;
;	nixie_tube.c:33: case 5:
	ret
00106$:
;	nixie_tube.c:34: bit0 = 1;
;	assignBit
	setb	_P2_2
;	nixie_tube.c:35: bit1 = 0; 
;	assignBit
	clr	_P2_3
;	nixie_tube.c:36: bit2 = 1;
;	assignBit
	setb	_P2_4
;	nixie_tube.c:37: break;
;	nixie_tube.c:38: case 6:
	ret
00107$:
;	nixie_tube.c:39: bit0 = 0; 
;	assignBit
	clr	_P2_2
;	nixie_tube.c:40: bit1 = 1;
;	assignBit
	setb	_P2_3
;	nixie_tube.c:41: bit2 = 1;
;	assignBit
	setb	_P2_4
;	nixie_tube.c:42: break;
;	nixie_tube.c:43: case 7:
	ret
00108$:
;	nixie_tube.c:44: bit0 = 1;
;	assignBit
	setb	_P2_2
;	nixie_tube.c:45: bit1 = 1;
;	assignBit
	setb	_P2_3
;	nixie_tube.c:46: bit2 = 1;
;	assignBit
	setb	_P2_4
;	nixie_tube.c:48: }
;	nixie_tube.c:49: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'select_char'
;------------------------------------------------------------
;number                    Allocated to registers r7 
;------------------------------------------------------------
;	nixie_tube.c:63: void select_char(char number) {
;	-----------------------------------------
;	 function select_char
;	-----------------------------------------
_select_char:
;	nixie_tube.c:64: P0 = alphabet[number];
	mov	a,dpl
	add	a,#_alphabet
	mov	r1,a
	mov	_P0,@r1
;	nixie_tube.c:65: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'delay'
;------------------------------------------------------------
;n                         Allocated to registers 
;------------------------------------------------------------
;	nixie_tube.c:67: void delay(int n) {
;	-----------------------------------------
;	 function delay
;	-----------------------------------------
_delay:
	mov	r6,dpl
	mov	r7,dph
;	nixie_tube.c:68: while(n--);
00101$:
	mov	ar4,r6
	mov	ar5,r7
	dec	r6
	cjne	r6,#0xff,00111$
	dec	r7
00111$:
	mov	a,r4
	orl	a,r5
	jnz	00101$
;	nixie_tube.c:69: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;tube_block                Allocated to registers 
;num                       Allocated to registers r5 
;------------------------------------------------------------
;	nixie_tube.c:71: void main(void) {
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	nixie_tube.c:73: while(1) {
	mov	r7,#0x00
00102$:
;	nixie_tube.c:74: char num = tube_block%8;	
	mov	ar5,r7
	anl	ar5,#0x07
;	nixie_tube.c:75: select_char(num);
	mov	dpl,r5
	push	ar7
	push	ar5
	lcall	_select_char
	pop	ar5
;	nixie_tube.c:76: select_nixie_tube(num);
	mov	dpl,r5
	lcall	_select_nixie_tube
	pop	ar7
;	nixie_tube.c:77: ++tube_block;
	inc	r7
;	nixie_tube.c:78: delay(100000);
	mov	dptr,#0x86a0
	push	ar7
	lcall	_delay
	pop	ar7
;	nixie_tube.c:80: }
	sjmp	00102$
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
