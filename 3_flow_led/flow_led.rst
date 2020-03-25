                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.0.0 #11528 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module flow_led
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _main
                                     12 	.globl _CY
                                     13 	.globl _AC
                                     14 	.globl _F0
                                     15 	.globl _RS1
                                     16 	.globl _RS0
                                     17 	.globl _OV
                                     18 	.globl _F1
                                     19 	.globl _P
                                     20 	.globl _PS
                                     21 	.globl _PT1
                                     22 	.globl _PX1
                                     23 	.globl _PT0
                                     24 	.globl _PX0
                                     25 	.globl _RD
                                     26 	.globl _WR
                                     27 	.globl _T1
                                     28 	.globl _T0
                                     29 	.globl _INT1
                                     30 	.globl _INT0
                                     31 	.globl _TXD
                                     32 	.globl _RXD
                                     33 	.globl _P3_7
                                     34 	.globl _P3_6
                                     35 	.globl _P3_5
                                     36 	.globl _P3_4
                                     37 	.globl _P3_3
                                     38 	.globl _P3_2
                                     39 	.globl _P3_1
                                     40 	.globl _P3_0
                                     41 	.globl _EA
                                     42 	.globl _ES
                                     43 	.globl _ET1
                                     44 	.globl _EX1
                                     45 	.globl _ET0
                                     46 	.globl _EX0
                                     47 	.globl _P2_7
                                     48 	.globl _P2_6
                                     49 	.globl _P2_5
                                     50 	.globl _P2_4
                                     51 	.globl _P2_3
                                     52 	.globl _P2_2
                                     53 	.globl _P2_1
                                     54 	.globl _P2_0
                                     55 	.globl _SM0
                                     56 	.globl _SM1
                                     57 	.globl _SM2
                                     58 	.globl _REN
                                     59 	.globl _TB8
                                     60 	.globl _RB8
                                     61 	.globl _TI
                                     62 	.globl _RI
                                     63 	.globl _P1_7
                                     64 	.globl _P1_6
                                     65 	.globl _P1_5
                                     66 	.globl _P1_4
                                     67 	.globl _P1_3
                                     68 	.globl _P1_2
                                     69 	.globl _P1_1
                                     70 	.globl _P1_0
                                     71 	.globl _TF1
                                     72 	.globl _TR1
                                     73 	.globl _TF0
                                     74 	.globl _TR0
                                     75 	.globl _IE1
                                     76 	.globl _IT1
                                     77 	.globl _IE0
                                     78 	.globl _IT0
                                     79 	.globl _P0_7
                                     80 	.globl _P0_6
                                     81 	.globl _P0_5
                                     82 	.globl _P0_4
                                     83 	.globl _P0_3
                                     84 	.globl _P0_2
                                     85 	.globl _P0_1
                                     86 	.globl _P0_0
                                     87 	.globl _B
                                     88 	.globl _ACC
                                     89 	.globl _PSW
                                     90 	.globl _IP
                                     91 	.globl _P3
                                     92 	.globl _IE
                                     93 	.globl _P2
                                     94 	.globl _SBUF
                                     95 	.globl _SCON
                                     96 	.globl _P1
                                     97 	.globl _TH1
                                     98 	.globl _TH0
                                     99 	.globl _TL1
                                    100 	.globl _TL0
                                    101 	.globl _TMOD
                                    102 	.globl _TCON
                                    103 	.globl _PCON
                                    104 	.globl _DPH
                                    105 	.globl _DPL
                                    106 	.globl _SP
                                    107 	.globl _P0
                                    108 ;--------------------------------------------------------
                                    109 ; special function registers
                                    110 ;--------------------------------------------------------
                                    111 	.area RSEG    (ABS,DATA)
      000000                        112 	.org 0x0000
                           000080   113 _P0	=	0x0080
                           000081   114 _SP	=	0x0081
                           000082   115 _DPL	=	0x0082
                           000083   116 _DPH	=	0x0083
                           000087   117 _PCON	=	0x0087
                           000088   118 _TCON	=	0x0088
                           000089   119 _TMOD	=	0x0089
                           00008A   120 _TL0	=	0x008a
                           00008B   121 _TL1	=	0x008b
                           00008C   122 _TH0	=	0x008c
                           00008D   123 _TH1	=	0x008d
                           000090   124 _P1	=	0x0090
                           000098   125 _SCON	=	0x0098
                           000099   126 _SBUF	=	0x0099
                           0000A0   127 _P2	=	0x00a0
                           0000A8   128 _IE	=	0x00a8
                           0000B0   129 _P3	=	0x00b0
                           0000B8   130 _IP	=	0x00b8
                           0000D0   131 _PSW	=	0x00d0
                           0000E0   132 _ACC	=	0x00e0
                           0000F0   133 _B	=	0x00f0
                                    134 ;--------------------------------------------------------
                                    135 ; special function bits
                                    136 ;--------------------------------------------------------
                                    137 	.area RSEG    (ABS,DATA)
      000000                        138 	.org 0x0000
                           000080   139 _P0_0	=	0x0080
                           000081   140 _P0_1	=	0x0081
                           000082   141 _P0_2	=	0x0082
                           000083   142 _P0_3	=	0x0083
                           000084   143 _P0_4	=	0x0084
                           000085   144 _P0_5	=	0x0085
                           000086   145 _P0_6	=	0x0086
                           000087   146 _P0_7	=	0x0087
                           000088   147 _IT0	=	0x0088
                           000089   148 _IE0	=	0x0089
                           00008A   149 _IT1	=	0x008a
                           00008B   150 _IE1	=	0x008b
                           00008C   151 _TR0	=	0x008c
                           00008D   152 _TF0	=	0x008d
                           00008E   153 _TR1	=	0x008e
                           00008F   154 _TF1	=	0x008f
                           000090   155 _P1_0	=	0x0090
                           000091   156 _P1_1	=	0x0091
                           000092   157 _P1_2	=	0x0092
                           000093   158 _P1_3	=	0x0093
                           000094   159 _P1_4	=	0x0094
                           000095   160 _P1_5	=	0x0095
                           000096   161 _P1_6	=	0x0096
                           000097   162 _P1_7	=	0x0097
                           000098   163 _RI	=	0x0098
                           000099   164 _TI	=	0x0099
                           00009A   165 _RB8	=	0x009a
                           00009B   166 _TB8	=	0x009b
                           00009C   167 _REN	=	0x009c
                           00009D   168 _SM2	=	0x009d
                           00009E   169 _SM1	=	0x009e
                           00009F   170 _SM0	=	0x009f
                           0000A0   171 _P2_0	=	0x00a0
                           0000A1   172 _P2_1	=	0x00a1
                           0000A2   173 _P2_2	=	0x00a2
                           0000A3   174 _P2_3	=	0x00a3
                           0000A4   175 _P2_4	=	0x00a4
                           0000A5   176 _P2_5	=	0x00a5
                           0000A6   177 _P2_6	=	0x00a6
                           0000A7   178 _P2_7	=	0x00a7
                           0000A8   179 _EX0	=	0x00a8
                           0000A9   180 _ET0	=	0x00a9
                           0000AA   181 _EX1	=	0x00aa
                           0000AB   182 _ET1	=	0x00ab
                           0000AC   183 _ES	=	0x00ac
                           0000AF   184 _EA	=	0x00af
                           0000B0   185 _P3_0	=	0x00b0
                           0000B1   186 _P3_1	=	0x00b1
                           0000B2   187 _P3_2	=	0x00b2
                           0000B3   188 _P3_3	=	0x00b3
                           0000B4   189 _P3_4	=	0x00b4
                           0000B5   190 _P3_5	=	0x00b5
                           0000B6   191 _P3_6	=	0x00b6
                           0000B7   192 _P3_7	=	0x00b7
                           0000B0   193 _RXD	=	0x00b0
                           0000B1   194 _TXD	=	0x00b1
                           0000B2   195 _INT0	=	0x00b2
                           0000B3   196 _INT1	=	0x00b3
                           0000B4   197 _T0	=	0x00b4
                           0000B5   198 _T1	=	0x00b5
                           0000B6   199 _WR	=	0x00b6
                           0000B7   200 _RD	=	0x00b7
                           0000B8   201 _PX0	=	0x00b8
                           0000B9   202 _PT0	=	0x00b9
                           0000BA   203 _PX1	=	0x00ba
                           0000BB   204 _PT1	=	0x00bb
                           0000BC   205 _PS	=	0x00bc
                           0000D0   206 _P	=	0x00d0
                           0000D1   207 _F1	=	0x00d1
                           0000D2   208 _OV	=	0x00d2
                           0000D3   209 _RS0	=	0x00d3
                           0000D4   210 _RS1	=	0x00d4
                           0000D5   211 _F0	=	0x00d5
                           0000D6   212 _AC	=	0x00d6
                           0000D7   213 _CY	=	0x00d7
                                    214 ;--------------------------------------------------------
                                    215 ; overlayable register banks
                                    216 ;--------------------------------------------------------
                                    217 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        218 	.ds 8
                                    219 ;--------------------------------------------------------
                                    220 ; internal ram data
                                    221 ;--------------------------------------------------------
                                    222 	.area DSEG    (DATA)
                                    223 ;--------------------------------------------------------
                                    224 ; overlayable items in internal ram 
                                    225 ;--------------------------------------------------------
                                    226 	.area	OSEG    (OVR,DATA)
                                    227 ;--------------------------------------------------------
                                    228 ; Stack segment in internal ram 
                                    229 ;--------------------------------------------------------
                                    230 	.area	SSEG
      000008                        231 __start__stack:
      000008                        232 	.ds	1
                                    233 
                                    234 ;--------------------------------------------------------
                                    235 ; indirectly addressable internal ram data
                                    236 ;--------------------------------------------------------
                                    237 	.area ISEG    (DATA)
                                    238 ;--------------------------------------------------------
                                    239 ; absolute internal ram data
                                    240 ;--------------------------------------------------------
                                    241 	.area IABS    (ABS,DATA)
                                    242 	.area IABS    (ABS,DATA)
                                    243 ;--------------------------------------------------------
                                    244 ; bit data
                                    245 ;--------------------------------------------------------
                                    246 	.area BSEG    (BIT)
                                    247 ;--------------------------------------------------------
                                    248 ; paged external ram data
                                    249 ;--------------------------------------------------------
                                    250 	.area PSEG    (PAG,XDATA)
                                    251 ;--------------------------------------------------------
                                    252 ; external ram data
                                    253 ;--------------------------------------------------------
                                    254 	.area XSEG    (XDATA)
                                    255 ;--------------------------------------------------------
                                    256 ; absolute external ram data
                                    257 ;--------------------------------------------------------
                                    258 	.area XABS    (ABS,XDATA)
                                    259 ;--------------------------------------------------------
                                    260 ; external initialized ram data
                                    261 ;--------------------------------------------------------
                                    262 	.area XISEG   (XDATA)
                                    263 	.area HOME    (CODE)
                                    264 	.area GSINIT0 (CODE)
                                    265 	.area GSINIT1 (CODE)
                                    266 	.area GSINIT2 (CODE)
                                    267 	.area GSINIT3 (CODE)
                                    268 	.area GSINIT4 (CODE)
                                    269 	.area GSINIT5 (CODE)
                                    270 	.area GSINIT  (CODE)
                                    271 	.area GSFINAL (CODE)
                                    272 	.area CSEG    (CODE)
                                    273 ;--------------------------------------------------------
                                    274 ; interrupt vector 
                                    275 ;--------------------------------------------------------
                                    276 	.area HOME    (CODE)
      000000                        277 __interrupt_vect:
      000000 02 00 06         [24]  278 	ljmp	__sdcc_gsinit_startup
                                    279 ;--------------------------------------------------------
                                    280 ; global & static initialisations
                                    281 ;--------------------------------------------------------
                                    282 	.area HOME    (CODE)
                                    283 	.area GSINIT  (CODE)
                                    284 	.area GSFINAL (CODE)
                                    285 	.area GSINIT  (CODE)
                                    286 	.globl __sdcc_gsinit_startup
                                    287 	.globl __sdcc_program_startup
                                    288 	.globl __start__stack
                                    289 	.globl __mcs51_genXINIT
                                    290 	.globl __mcs51_genXRAMCLEAR
                                    291 	.globl __mcs51_genRAMCLEAR
                                    292 	.area GSFINAL (CODE)
      00005F 02 00 03         [24]  293 	ljmp	__sdcc_program_startup
                                    294 ;--------------------------------------------------------
                                    295 ; Home
                                    296 ;--------------------------------------------------------
                                    297 	.area HOME    (CODE)
                                    298 	.area HOME    (CODE)
      000003                        299 __sdcc_program_startup:
      000003 02 00 62         [24]  300 	ljmp	_main
                                    301 ;	return from main will return to caller
                                    302 ;--------------------------------------------------------
                                    303 ; code
                                    304 ;--------------------------------------------------------
                                    305 	.area CSEG    (CODE)
                                    306 ;------------------------------------------------------------
                                    307 ;Allocation info for local variables in function 'main'
                                    308 ;------------------------------------------------------------
                                    309 ;i                         Allocated to registers r6 r7 
                                    310 ;j                         Allocated to registers r4 r5 
                                    311 ;------------------------------------------------------------
                                    312 ;	flow_led.c:10: void main(void)
                                    313 ;	-----------------------------------------
                                    314 ;	 function main
                                    315 ;	-----------------------------------------
      000062                        316 _main:
                           000007   317 	ar7 = 0x07
                           000006   318 	ar6 = 0x06
                           000005   319 	ar5 = 0x05
                           000004   320 	ar4 = 0x04
                           000003   321 	ar3 = 0x03
                           000002   322 	ar2 = 0x02
                           000001   323 	ar1 = 0x01
                           000000   324 	ar0 = 0x00
                                    325 ;	flow_led.c:12: while(1)	
      000062                        326 00118$:
                                    327 ;	flow_led.c:16: led7 = 1;
                                    328 ;	assignBit
      000062 D2 A7            [12]  329 	setb	_P2_7
                                    330 ;	flow_led.c:17: led0 = 0;
                                    331 ;	assignBit
      000064 C2 A0            [12]  332 	clr	_P2_0
                                    333 ;	flow_led.c:18: for(i=0; i<100; ++i)
      000066 7E 00            [12]  334 	mov	r6,#0x00
      000068 7F 00            [12]  335 	mov	r7,#0x00
                                    336 ;	flow_led.c:19: for(j=0; j<100; ++j);
      00006A                        337 00162$:
      00006A 7C 64            [12]  338 	mov	r4,#0x64
      00006C 7D 00            [12]  339 	mov	r5,#0x00
      00006E                        340 00122$:
      00006E 1C               [12]  341 	dec	r4
      00006F BC FF 01         [24]  342 	cjne	r4,#0xff,00310$
      000072 1D               [12]  343 	dec	r5
      000073                        344 00310$:
      000073 EC               [12]  345 	mov	a,r4
      000074 4D               [12]  346 	orl	a,r5
      000075 70 F7            [24]  347 	jnz	00122$
                                    348 ;	flow_led.c:18: for(i=0; i<100; ++i)
      000077 0E               [12]  349 	inc	r6
      000078 BE 00 01         [24]  350 	cjne	r6,#0x00,00312$
      00007B 0F               [12]  351 	inc	r7
      00007C                        352 00312$:
      00007C C3               [12]  353 	clr	c
      00007D EE               [12]  354 	mov	a,r6
      00007E 94 64            [12]  355 	subb	a,#0x64
      000080 EF               [12]  356 	mov	a,r7
      000081 64 80            [12]  357 	xrl	a,#0x80
      000083 94 80            [12]  358 	subb	a,#0x80
      000085 40 E3            [24]  359 	jc	00162$
                                    360 ;	flow_led.c:20: led0 = 1;
                                    361 ;	assignBit
      000087 D2 A0            [12]  362 	setb	_P2_0
                                    363 ;	flow_led.c:21: led1 = 0;
                                    364 ;	assignBit
      000089 C2 A1            [12]  365 	clr	_P2_1
                                    366 ;	flow_led.c:22: for(i=0; i<100; ++i)
      00008B 7E 00            [12]  367 	mov	r6,#0x00
      00008D 7F 00            [12]  368 	mov	r7,#0x00
                                    369 ;	flow_led.c:23: for(j=0; j<100; ++j);
      00008F                        370 00166$:
      00008F 7C 64            [12]  371 	mov	r4,#0x64
      000091 7D 00            [12]  372 	mov	r5,#0x00
      000093                        373 00127$:
      000093 1C               [12]  374 	dec	r4
      000094 BC FF 01         [24]  375 	cjne	r4,#0xff,00314$
      000097 1D               [12]  376 	dec	r5
      000098                        377 00314$:
      000098 EC               [12]  378 	mov	a,r4
      000099 4D               [12]  379 	orl	a,r5
      00009A 70 F7            [24]  380 	jnz	00127$
                                    381 ;	flow_led.c:22: for(i=0; i<100; ++i)
      00009C 0E               [12]  382 	inc	r6
      00009D BE 00 01         [24]  383 	cjne	r6,#0x00,00316$
      0000A0 0F               [12]  384 	inc	r7
      0000A1                        385 00316$:
      0000A1 C3               [12]  386 	clr	c
      0000A2 EE               [12]  387 	mov	a,r6
      0000A3 94 64            [12]  388 	subb	a,#0x64
      0000A5 EF               [12]  389 	mov	a,r7
      0000A6 64 80            [12]  390 	xrl	a,#0x80
      0000A8 94 80            [12]  391 	subb	a,#0x80
      0000AA 40 E3            [24]  392 	jc	00166$
                                    393 ;	flow_led.c:24: led1 = 1;
                                    394 ;	assignBit
      0000AC D2 A1            [12]  395 	setb	_P2_1
                                    396 ;	flow_led.c:25: led2 = 0;
                                    397 ;	assignBit
      0000AE C2 A2            [12]  398 	clr	_P2_2
                                    399 ;	flow_led.c:26: for(i=0; i<100; ++i)
      0000B0 7E 00            [12]  400 	mov	r6,#0x00
      0000B2 7F 00            [12]  401 	mov	r7,#0x00
                                    402 ;	flow_led.c:27: for(j=0; j<100; ++j);
      0000B4                        403 00170$:
      0000B4 7C 64            [12]  404 	mov	r4,#0x64
      0000B6 7D 00            [12]  405 	mov	r5,#0x00
      0000B8                        406 00132$:
      0000B8 1C               [12]  407 	dec	r4
      0000B9 BC FF 01         [24]  408 	cjne	r4,#0xff,00318$
      0000BC 1D               [12]  409 	dec	r5
      0000BD                        410 00318$:
      0000BD EC               [12]  411 	mov	a,r4
      0000BE 4D               [12]  412 	orl	a,r5
      0000BF 70 F7            [24]  413 	jnz	00132$
                                    414 ;	flow_led.c:26: for(i=0; i<100; ++i)
      0000C1 0E               [12]  415 	inc	r6
      0000C2 BE 00 01         [24]  416 	cjne	r6,#0x00,00320$
      0000C5 0F               [12]  417 	inc	r7
      0000C6                        418 00320$:
      0000C6 C3               [12]  419 	clr	c
      0000C7 EE               [12]  420 	mov	a,r6
      0000C8 94 64            [12]  421 	subb	a,#0x64
      0000CA EF               [12]  422 	mov	a,r7
      0000CB 64 80            [12]  423 	xrl	a,#0x80
      0000CD 94 80            [12]  424 	subb	a,#0x80
      0000CF 40 E3            [24]  425 	jc	00170$
                                    426 ;	flow_led.c:28: led2 = 1;
                                    427 ;	assignBit
      0000D1 D2 A2            [12]  428 	setb	_P2_2
                                    429 ;	flow_led.c:29: led3 = 0;
                                    430 ;	assignBit
      0000D3 C2 A3            [12]  431 	clr	_P2_3
                                    432 ;	flow_led.c:30: for(i=0; i<100; ++i)
      0000D5 7E 00            [12]  433 	mov	r6,#0x00
      0000D7 7F 00            [12]  434 	mov	r7,#0x00
                                    435 ;	flow_led.c:31: for(j=0; j<100; ++j);
      0000D9                        436 00174$:
      0000D9 7C 64            [12]  437 	mov	r4,#0x64
      0000DB 7D 00            [12]  438 	mov	r5,#0x00
      0000DD                        439 00137$:
      0000DD 1C               [12]  440 	dec	r4
      0000DE BC FF 01         [24]  441 	cjne	r4,#0xff,00322$
      0000E1 1D               [12]  442 	dec	r5
      0000E2                        443 00322$:
      0000E2 EC               [12]  444 	mov	a,r4
      0000E3 4D               [12]  445 	orl	a,r5
      0000E4 70 F7            [24]  446 	jnz	00137$
                                    447 ;	flow_led.c:30: for(i=0; i<100; ++i)
      0000E6 0E               [12]  448 	inc	r6
      0000E7 BE 00 01         [24]  449 	cjne	r6,#0x00,00324$
      0000EA 0F               [12]  450 	inc	r7
      0000EB                        451 00324$:
      0000EB C3               [12]  452 	clr	c
      0000EC EE               [12]  453 	mov	a,r6
      0000ED 94 64            [12]  454 	subb	a,#0x64
      0000EF EF               [12]  455 	mov	a,r7
      0000F0 64 80            [12]  456 	xrl	a,#0x80
      0000F2 94 80            [12]  457 	subb	a,#0x80
      0000F4 40 E3            [24]  458 	jc	00174$
                                    459 ;	flow_led.c:32: led3 = 1;
                                    460 ;	assignBit
      0000F6 D2 A3            [12]  461 	setb	_P2_3
                                    462 ;	flow_led.c:33: led4 = 0;
                                    463 ;	assignBit
      0000F8 C2 A4            [12]  464 	clr	_P2_4
                                    465 ;	flow_led.c:34: for(i=0; i<100; ++i)
      0000FA 7E 00            [12]  466 	mov	r6,#0x00
      0000FC 7F 00            [12]  467 	mov	r7,#0x00
                                    468 ;	flow_led.c:35: for(j=0; j<100; ++j);
      0000FE                        469 00178$:
      0000FE 7C 64            [12]  470 	mov	r4,#0x64
      000100 7D 00            [12]  471 	mov	r5,#0x00
      000102                        472 00142$:
      000102 1C               [12]  473 	dec	r4
      000103 BC FF 01         [24]  474 	cjne	r4,#0xff,00326$
      000106 1D               [12]  475 	dec	r5
      000107                        476 00326$:
      000107 EC               [12]  477 	mov	a,r4
      000108 4D               [12]  478 	orl	a,r5
      000109 70 F7            [24]  479 	jnz	00142$
                                    480 ;	flow_led.c:34: for(i=0; i<100; ++i)
      00010B 0E               [12]  481 	inc	r6
      00010C BE 00 01         [24]  482 	cjne	r6,#0x00,00328$
      00010F 0F               [12]  483 	inc	r7
      000110                        484 00328$:
      000110 C3               [12]  485 	clr	c
      000111 EE               [12]  486 	mov	a,r6
      000112 94 64            [12]  487 	subb	a,#0x64
      000114 EF               [12]  488 	mov	a,r7
      000115 64 80            [12]  489 	xrl	a,#0x80
      000117 94 80            [12]  490 	subb	a,#0x80
      000119 40 E3            [24]  491 	jc	00178$
                                    492 ;	flow_led.c:36: led4 = 1;
                                    493 ;	assignBit
      00011B D2 A4            [12]  494 	setb	_P2_4
                                    495 ;	flow_led.c:37: led5 = 0;
                                    496 ;	assignBit
      00011D C2 A5            [12]  497 	clr	_P2_5
                                    498 ;	flow_led.c:38: for(i=0; i<100; ++i)
      00011F 7E 00            [12]  499 	mov	r6,#0x00
      000121 7F 00            [12]  500 	mov	r7,#0x00
                                    501 ;	flow_led.c:39: for(j=0; j<100; ++j);
      000123                        502 00182$:
      000123 7C 64            [12]  503 	mov	r4,#0x64
      000125 7D 00            [12]  504 	mov	r5,#0x00
      000127                        505 00147$:
      000127 1C               [12]  506 	dec	r4
      000128 BC FF 01         [24]  507 	cjne	r4,#0xff,00330$
      00012B 1D               [12]  508 	dec	r5
      00012C                        509 00330$:
      00012C EC               [12]  510 	mov	a,r4
      00012D 4D               [12]  511 	orl	a,r5
      00012E 70 F7            [24]  512 	jnz	00147$
                                    513 ;	flow_led.c:38: for(i=0; i<100; ++i)
      000130 0E               [12]  514 	inc	r6
      000131 BE 00 01         [24]  515 	cjne	r6,#0x00,00332$
      000134 0F               [12]  516 	inc	r7
      000135                        517 00332$:
      000135 C3               [12]  518 	clr	c
      000136 EE               [12]  519 	mov	a,r6
      000137 94 64            [12]  520 	subb	a,#0x64
      000139 EF               [12]  521 	mov	a,r7
      00013A 64 80            [12]  522 	xrl	a,#0x80
      00013C 94 80            [12]  523 	subb	a,#0x80
      00013E 40 E3            [24]  524 	jc	00182$
                                    525 ;	flow_led.c:40: led5 = 1;
                                    526 ;	assignBit
      000140 D2 A5            [12]  527 	setb	_P2_5
                                    528 ;	flow_led.c:41: led6 = 0;
                                    529 ;	assignBit
      000142 C2 A6            [12]  530 	clr	_P2_6
                                    531 ;	flow_led.c:42: for(i=0; i<100; ++i)
      000144 7E 00            [12]  532 	mov	r6,#0x00
      000146 7F 00            [12]  533 	mov	r7,#0x00
                                    534 ;	flow_led.c:43: for(j=0; j<100; ++j);
      000148                        535 00186$:
      000148 7C 64            [12]  536 	mov	r4,#0x64
      00014A 7D 00            [12]  537 	mov	r5,#0x00
      00014C                        538 00152$:
      00014C 1C               [12]  539 	dec	r4
      00014D BC FF 01         [24]  540 	cjne	r4,#0xff,00334$
      000150 1D               [12]  541 	dec	r5
      000151                        542 00334$:
      000151 EC               [12]  543 	mov	a,r4
      000152 4D               [12]  544 	orl	a,r5
      000153 70 F7            [24]  545 	jnz	00152$
                                    546 ;	flow_led.c:42: for(i=0; i<100; ++i)
      000155 0E               [12]  547 	inc	r6
      000156 BE 00 01         [24]  548 	cjne	r6,#0x00,00336$
      000159 0F               [12]  549 	inc	r7
      00015A                        550 00336$:
      00015A C3               [12]  551 	clr	c
      00015B EE               [12]  552 	mov	a,r6
      00015C 94 64            [12]  553 	subb	a,#0x64
      00015E EF               [12]  554 	mov	a,r7
      00015F 64 80            [12]  555 	xrl	a,#0x80
      000161 94 80            [12]  556 	subb	a,#0x80
      000163 40 E3            [24]  557 	jc	00186$
                                    558 ;	flow_led.c:44: led6 = 1;
                                    559 ;	assignBit
      000165 D2 A6            [12]  560 	setb	_P2_6
                                    561 ;	flow_led.c:45: led7 = 0;
                                    562 ;	assignBit
      000167 C2 A7            [12]  563 	clr	_P2_7
                                    564 ;	flow_led.c:46: for(i=0; i<100; ++i)
      000169 7E 00            [12]  565 	mov	r6,#0x00
      00016B 7F 00            [12]  566 	mov	r7,#0x00
                                    567 ;	flow_led.c:47: for(j=0; j<100; ++j);
      00016D                        568 00190$:
      00016D 7C 64            [12]  569 	mov	r4,#0x64
      00016F 7D 00            [12]  570 	mov	r5,#0x00
      000171                        571 00157$:
      000171 1C               [12]  572 	dec	r4
      000172 BC FF 01         [24]  573 	cjne	r4,#0xff,00338$
      000175 1D               [12]  574 	dec	r5
      000176                        575 00338$:
      000176 EC               [12]  576 	mov	a,r4
      000177 4D               [12]  577 	orl	a,r5
      000178 70 F7            [24]  578 	jnz	00157$
                                    579 ;	flow_led.c:46: for(i=0; i<100; ++i)
      00017A 0E               [12]  580 	inc	r6
      00017B BE 00 01         [24]  581 	cjne	r6,#0x00,00340$
      00017E 0F               [12]  582 	inc	r7
      00017F                        583 00340$:
      00017F C3               [12]  584 	clr	c
      000180 EE               [12]  585 	mov	a,r6
      000181 94 64            [12]  586 	subb	a,#0x64
      000183 EF               [12]  587 	mov	a,r7
      000184 64 80            [12]  588 	xrl	a,#0x80
      000186 94 80            [12]  589 	subb	a,#0x80
      000188 40 E3            [24]  590 	jc	00190$
                                    591 ;	flow_led.c:49: }
      00018A 02 00 62         [24]  592 	ljmp	00118$
                                    593 	.area CSEG    (CODE)
                                    594 	.area CONST   (CODE)
                                    595 	.area XINIT   (CODE)
                                    596 	.area CABS    (ABS,CODE)
