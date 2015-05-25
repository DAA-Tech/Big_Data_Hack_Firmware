_interrupt:
;BLEP_Click.c,53 :: 		void interrupt() iv IVT_INT_USART3 ics ICS_AUTO
SUB	SP, SP, #12
STR	LR, [SP, #0]
;BLEP_Click.c,55 :: 		txt[i] = UART3_Read();         // Read data and store it to txrt string
MOVW	R0, #lo_addr(_i+0)
MOVT	R0, #hi_addr(_i+0)
STR	R0, [SP, #8]
LDRSH	R1, [R0, #0]
MOVW	R0, #lo_addr(_txt+0)
MOVT	R0, #hi_addr(_txt+0)
ADDS	R0, R0, R1
STR	R0, [SP, #4]
BL	_UART3_Read+0
LDR	R1, [SP, #4]
STRB	R0, [R1, #0]
;BLEP_Click.c,56 :: 		i++;                         // Increment string index
LDR	R1, [SP, #8]
MOV	R0, R1
LDRSH	R0, [R0, #0]
ADDS	R0, R0, #1
SXTH	R0, R0
STRH	R0, [R1, #0]
;BLEP_Click.c,57 :: 		if (i > 768)
CMP	R0, #768
IT	LE
BLE	L_interrupt0
;BLEP_Click.c,59 :: 		i = 0;
MOVS	R1, #0
SXTH	R1, R1
MOVW	R0, #lo_addr(_i+0)
MOVT	R0, #hi_addr(_i+0)
STRH	R1, [R0, #0]
;BLEP_Click.c,60 :: 		}
L_interrupt0:
;BLEP_Click.c,61 :: 		}
L_end_interrupt:
LDR	LR, [SP, #0]
ADD	SP, SP, #12
BX	LR
; end of _interrupt
_SysTick_interrupt:
;BLEP_Click.c,63 :: 		SysTick_interrupt() iv IVT_INT_SysTick
;BLEP_Click.c,67 :: 		LED_ORNG = 1;
MOVS	R1, #1
SXTB	R1, R1
MOVW	R0, #lo_addr(GPIOD_ODR+0)
MOVT	R0, #hi_addr(GPIOD_ODR+0)
STR	R1, [R0, #0]
;BLEP_Click.c,68 :: 		Delay_ms(100);
MOVW	R7, #4521
MOVT	R7, #4
NOP
NOP
L_SysTick_interrupt1:
SUBS	R7, R7, #1
BNE	L_SysTick_interrupt1
NOP
NOP
;BLEP_Click.c,69 :: 		LED_ORNG = 0;
MOVS	R1, #0
SXTB	R1, R1
MOVW	R0, #lo_addr(GPIOD_ODR+0)
MOVT	R0, #hi_addr(GPIOD_ODR+0)
STR	R1, [R0, #0]
;BLEP_Click.c,70 :: 		Delay_ms(100);
MOVW	R7, #4521
MOVT	R7, #4
NOP
NOP
L_SysTick_interrupt3:
SUBS	R7, R7, #1
BNE	L_SysTick_interrupt3
NOP
NOP
;BLEP_Click.c,71 :: 		}
L_end_SysTick_interrupt:
BX	LR
; end of _SysTick_interrupt
_Init_MCU:
;BLEP_Click.c,73 :: 		void Init_MCU() {
SUB	SP, SP, #4
STR	LR, [SP, #0]
;BLEP_Click.c,78 :: 		GPIO_Digital_Input (&GPIOA_BASE, _GPIO_PINMASK_0); // configure PORTA pins as input
MOVW	R1, #1
MOVW	R0, #lo_addr(GPIOA_BASE+0)
MOVT	R0, #hi_addr(GPIOA_BASE+0)
BL	_GPIO_Digital_Input+0
;BLEP_Click.c,79 :: 		GPIO_Alternate_Function_Enable(&_GPIO_MODULE_USART2_PA23);
MOVW	R0, #lo_addr(__GPIO_MODULE_USART2_PA23+0)
MOVT	R0, #hi_addr(__GPIO_MODULE_USART2_PA23+0)
BL	_GPIO_Alternate_Function_Enable+0
;BLEP_Click.c,81 :: 		GPIO_Digital_Output(&GPIOD_ODR, _GPIO_PINMASK_6);                             // Set PD6 (RST) as digital output
MOVW	R1, #64
MOVW	R0, #lo_addr(GPIOD_ODR+0)
MOVT	R0, #hi_addr(GPIOD_ODR+0)
BL	_GPIO_Digital_Output+0
;BLEP_Click.c,82 :: 		GPIO_Digital_Input(&GPIOB_IDR, _GPIO_PINMASK_0);                              // Set PB0(ACT) as digital input ChangedAA
MOVW	R1, #1
MOVW	R0, #lo_addr(GPIOB_IDR+0)
MOVT	R0, #hi_addr(GPIOB_IDR+0)
BL	_GPIO_Digital_Input+0
;BLEP_Click.c,83 :: 		GPIO_Digital_Output(&GPIOD_ODR, _GPIO_PINMASK_7);                             // Set PD7 (REQ) as digital output
MOVW	R1, #128
MOVW	R0, #lo_addr(GPIOD_ODR+0)
MOVT	R0, #hi_addr(GPIOD_ODR+0)
BL	_GPIO_Digital_Output+0
;BLEP_Click.c,84 :: 		GPIO_Digital_Input(&GPIOC_IDR, _GPIO_PINMASK_11);                             // Set PC11 (RDY) as digital input
MOVW	R1, #2048
MOVW	R0, #lo_addr(GPIOC_IDR+0)
MOVT	R0, #hi_addr(GPIOC_IDR+0)
BL	_GPIO_Digital_Input+0
;BLEP_Click.c,85 :: 		GPIO_Digital_Output(&GPIOD_BASE, _GPIO_PINMASK_15);                           // Set PA0 (CONN)
MOVW	R1, #32768
MOVW	R0, #lo_addr(GPIOD_BASE+0)
MOVT	R0, #hi_addr(GPIOD_BASE+0)
BL	_GPIO_Digital_Output+0
;BLEP_Click.c,86 :: 		GPIO_Digital_Output(&GPIOD_ODR, _GPIO_PINMASK_12);                            // LED GREEN
MOVW	R1, #4096
MOVW	R0, #lo_addr(GPIOD_ODR+0)
MOVT	R0, #hi_addr(GPIOD_ODR+0)
BL	_GPIO_Digital_Output+0
;BLEP_Click.c,87 :: 		GPIO_Digital_Output(&GPIOD_ODR, _GPIO_PINMASK_13);                            // LED ORANGE
MOVW	R1, #8192
MOVW	R0, #lo_addr(GPIOD_ODR+0)
MOVT	R0, #hi_addr(GPIOD_ODR+0)
BL	_GPIO_Digital_Output+0
;BLEP_Click.c,88 :: 		GPIO_Digital_Output(&GPIOD_ODR, _GPIO_PINMASK_14);                            // LED RED
MOVW	R1, #16384
MOVW	R0, #lo_addr(GPIOD_ODR+0)
MOVT	R0, #hi_addr(GPIOD_ODR+0)
BL	_GPIO_Digital_Output+0
;BLEP_Click.c,89 :: 		GPIO_Digital_Output(&GPIOC_IDR, _GPIO_PINMASK_5);                             // GSM_STAT
MOVW	R1, #32
MOVW	R0, #lo_addr(GPIOC_IDR+0)
MOVT	R0, #hi_addr(GPIOC_IDR+0)
BL	_GPIO_Digital_Output+0
;BLEP_Click.c,90 :: 		GPIO_Digital_Output(&GPIOE_ODR, _GPIO_PINMASK_4);                             // GSM_RST
MOVW	R1, #16
MOVW	R0, #lo_addr(GPIOE_ODR+0)
MOVT	R0, #hi_addr(GPIOE_ODR+0)
BL	_GPIO_Digital_Output+0
;BLEP_Click.c,91 :: 		GPIO_Digital_Output(&GPIOB_ODR, _GPIO_PINMASK_1);                             // GSM_PWRKEY
MOVW	R1, #2
MOVW	R0, #lo_addr(GPIOB_ODR+0)
MOVT	R0, #hi_addr(GPIOB_ODR+0)
BL	_GPIO_Digital_Output+0
;BLEP_Click.c,92 :: 		GPIO_Digital_Output(&GPIOE_ODR, _GPIO_PINMASK_10);                             // GPS_RST
MOVW	R1, #1024
MOVW	R0, #lo_addr(GPIOE_ODR+0)
MOVT	R0, #hi_addr(GPIOE_ODR+0)
BL	_GPIO_Digital_Output+0
;BLEP_Click.c,94 :: 		SPI3_Init_Advanced(_SPI_FPCLK_DIV16, _SPI_MASTER | _SPI_8_BIT | _SPI_CLK_IDLE_LOW | _SPI_FIRST_CLK_EDGE_TRANSITION | _SPI_LSB_FIRST | _SPI_SS_DISABLE | _SPI_SSM_ENABLE | _SPI_SSI_1, &_GPIO_MODULE_SPI3_PB345);
MOVW	R2, #lo_addr(__GPIO_MODULE_SPI3_PB345+0)
MOVT	R2, #hi_addr(__GPIO_MODULE_SPI3_PB345+0)
MOVW	R1, #900
MOVS	R0, #3
BL	_SPI3_Init_Advanced+0
;BLEP_Click.c,95 :: 		UART2_Init_Advanced(9600, _UART_8_BIT_DATA, _UART_NOPARITY, _UART_ONE_STOPBIT, &_GPIO_MODULE_USART2_PA23);
MOVW	R0, #lo_addr(__GPIO_MODULE_USART2_PA23+0)
MOVT	R0, #hi_addr(__GPIO_MODULE_USART2_PA23+0)
PUSH	(R0)
MOVW	R3, #0
MOVW	R2, #0
MOVW	R1, #0
MOVW	R0, #9600
BL	_UART2_Init_Advanced+0
ADD	SP, SP, #4
;BLEP_Click.c,97 :: 		UART3_Init_Advanced(9600, _UART_8_BIT_DATA, _UART_NOPARITY, _UART_ONE_STOPBIT, &_GPIO_MODULE_USART3_PB10_11);
MOVW	R0, #lo_addr(__GPIO_MODULE_USART3_PB10_11+0)
MOVT	R0, #hi_addr(__GPIO_MODULE_USART3_PB10_11+0)
PUSH	(R0)
MOVW	R3, #0
MOVW	R2, #0
MOVW	R1, #0
MOVW	R0, #9600
BL	_UART3_Init_Advanced+0
ADD	SP, SP, #4
;BLEP_Click.c,98 :: 		Delay_ms(100);
MOVW	R7, #4521
MOVT	R7, #4
NOP
NOP
L_Init_MCU5:
SUBS	R7, R7, #1
BNE	L_Init_MCU5
NOP
NOP
;BLEP_Click.c,99 :: 		USART3_CR1bits.RXNEIE = 1;       // enable uart rx interrupt
MOVS	R1, #1
SXTB	R1, R1
MOVW	R0, #lo_addr(USART3_CR1bits+0)
MOVT	R0, #hi_addr(USART3_CR1bits+0)
STR	R1, [R0, #0]
;BLEP_Click.c,100 :: 		NVIC_IntEnable(IVT_INT_USART3);  // enable interrupt vector
MOVW	R0, #55
BL	_NVIC_IntEnable+0
;BLEP_Click.c,101 :: 		Delay_ms(100);                        // Wait for UART module to stabilize
MOVW	R7, #4521
MOVT	R7, #4
NOP
NOP
L_Init_MCU7:
SUBS	R7, R7, #1
BNE	L_Init_MCU7
NOP
NOP
;BLEP_Click.c,103 :: 		UART6_Init_Advanced(9600, _UART_8_BIT_DATA, _UART_NOPARITY, _UART_ONE_STOPBIT, &_GPIO_MODULE_USART6_PC67 );
MOVW	R0, #lo_addr(__GPIO_MODULE_USART6_PC67+0)
MOVT	R0, #hi_addr(__GPIO_MODULE_USART6_PC67+0)
PUSH	(R0)
MOVW	R3, #0
MOVW	R2, #0
MOVW	R1, #0
MOVW	R0, #9600
BL	_UART6_Init_Advanced+0
ADD	SP, SP, #4
;BLEP_Click.c,104 :: 		Delay_ms(100);
MOVW	R7, #4521
MOVT	R7, #4
NOP
NOP
L_Init_MCU9:
SUBS	R7, R7, #1
BNE	L_Init_MCU9
NOP
NOP
;BLEP_Click.c,109 :: 		NVIC_SYSTICKRVR = 8000000;     //10ms
MOVW	R1, #4608
MOVT	R1, #122
MOVW	R0, #lo_addr(NVIC_SYSTICKRVR+0)
MOVT	R0, #hi_addr(NVIC_SYSTICKRVR+0)
STR	R1, [R0, #0]
;BLEP_Click.c,113 :: 		NVIC_SYSTICKCVR = 0; // Set Curent Value Register
MOVS	R1, #0
MOVW	R0, #lo_addr(NVIC_SYSTICKCVR+0)
MOVT	R0, #hi_addr(NVIC_SYSTICKCVR+0)
STR	R1, [R0, #0]
;BLEP_Click.c,115 :: 		NVIC_SYSTICKCSR.B0 = 1; // SysTick Timer Enable
MOVS	R2, #1
SXTB	R2, R2
MOVW	R1, #lo_addr(NVIC_SYSTICKCSR+0)
MOVT	R1, #hi_addr(NVIC_SYSTICKCSR+0)
LDR	R0, [R1, #0]
BFI	R0, R2, #0, #1
STR	R0, [R1, #0]
;BLEP_Click.c,116 :: 		NVIC_SYSTICKCSR.B1 = 1; // Enable SysTick Interrupt generation
MOVW	R1, #lo_addr(NVIC_SYSTICKCSR+0)
MOVT	R1, #hi_addr(NVIC_SYSTICKCSR+0)
LDR	R0, [R1, #0]
BFI	R0, R2, #1, #1
STR	R0, [R1, #0]
;BLEP_Click.c,117 :: 		NVIC_SYSTICKCSR.B2 = 1; // Use processor free runing clock
MOVW	R1, #lo_addr(NVIC_SYSTICKCSR+0)
MOVT	R1, #hi_addr(NVIC_SYSTICKCSR+0)
LDR	R0, [R1, #0]
BFI	R0, R2, #2, #1
STR	R0, [R1, #0]
;BLEP_Click.c,119 :: 		NVIC_SetIntPriority(IVT_INT_SysTick, _NVIC_INT_PRIORITY_LVL4);
MOVS	R1, #4
MOVS	R0, #15
BL	_NVIC_SetIntPriority+0
;BLEP_Click.c,121 :: 		NVIC_SetIntPriority(IVT_INT_USART3, _NVIC_INT_PRIORITY_LVL0);
MOVS	R1, #0
MOVS	R0, #55
BL	_NVIC_SetIntPriority+0
;BLEP_Click.c,123 :: 		Blep_RST = 0;
MOVS	R0, #0
SXTB	R0, R0
MOVW	R2, #lo_addr(GPIOD_ODR+0)
MOVT	R2, #hi_addr(GPIOD_ODR+0)
STR	R0, [R2, #0]
;BLEP_Click.c,124 :: 		Blep_REQ = 1;
MOVS	R1, #1
SXTB	R1, R1
MOVW	R0, #lo_addr(GPIOD_ODR+0)
MOVT	R0, #hi_addr(GPIOD_ODR+0)
STR	R1, [R0, #0]
;BLEP_Click.c,125 :: 		Blep_RST = 1;
STR	R1, [R2, #0]
;BLEP_Click.c,126 :: 		Delay_ms(100);
MOVW	R7, #4521
MOVT	R7, #4
NOP
NOP
L_Init_MCU11:
SUBS	R7, R7, #1
BNE	L_Init_MCU11
NOP
NOP
;BLEP_Click.c,127 :: 		Blep_RST = 0;
MOVS	R1, #0
SXTB	R1, R1
MOVW	R0, #lo_addr(GPIOD_ODR+0)
MOVT	R0, #hi_addr(GPIOD_ODR+0)
STR	R1, [R0, #0]
;BLEP_Click.c,128 :: 		Delay_ms(100);
MOVW	R7, #4521
MOVT	R7, #4
NOP
NOP
L_Init_MCU13:
SUBS	R7, R7, #1
BNE	L_Init_MCU13
NOP
NOP
;BLEP_Click.c,129 :: 		Blep_RST = 1;
MOVS	R1, #1
SXTB	R1, R1
MOVW	R0, #lo_addr(GPIOD_ODR+0)
MOVT	R0, #hi_addr(GPIOD_ODR+0)
STR	R1, [R0, #0]
;BLEP_Click.c,130 :: 		GSM_RST = 0;
MOVS	R1, #0
SXTB	R1, R1
MOVW	R0, #lo_addr(GPIOE_ODR+0)
MOVT	R0, #hi_addr(GPIOE_ODR+0)
STR	R1, [R0, #0]
;BLEP_Click.c,132 :: 		Delay_ms(200);
MOVW	R7, #9043
MOVT	R7, #8
NOP
NOP
L_Init_MCU15:
SUBS	R7, R7, #1
BNE	L_Init_MCU15
NOP
NOP
NOP
NOP
;BLEP_Click.c,133 :: 		GSM_PWRKEY = 1;
MOVS	R1, #1
SXTB	R1, R1
MOVW	R0, #lo_addr(GPIOB_ODR+0)
MOVT	R0, #hi_addr(GPIOB_ODR+0)
STR	R1, [R0, #0]
;BLEP_Click.c,134 :: 		Delay_ms(2000);
MOVW	R7, #24915
MOVT	R7, #81
NOP
NOP
L_Init_MCU17:
SUBS	R7, R7, #1
BNE	L_Init_MCU17
NOP
NOP
NOP
NOP
;BLEP_Click.c,135 :: 		GSM_PWRKEY = 0;
MOVS	R1, #0
SXTB	R1, R1
MOVW	R0, #lo_addr(GPIOB_ODR+0)
MOVT	R0, #hi_addr(GPIOB_ODR+0)
STR	R1, [R0, #0]
;BLEP_Click.c,137 :: 		wait();
BL	_wait+0
;BLEP_Click.c,138 :: 		wait();
BL	_wait+0
;BLEP_Click.c,139 :: 		wait();
BL	_wait+0
;BLEP_Click.c,140 :: 		wait();
BL	_wait+0
;BLEP_Click.c,142 :: 		LED_GRN = 1;
MOVS	R1, #1
SXTB	R1, R1
MOVW	R0, #lo_addr(GPIOD_ODR+0)
MOVT	R0, #hi_addr(GPIOD_ODR+0)
STR	R1, [R0, #0]
;BLEP_Click.c,143 :: 		UART_Set_Active(&UART3_Read, &UART3_Write, &UART3_Data_Ready, &UART3_Tx_Idle); // set UART3 active
MOVW	R3, #lo_addr(_UART3_Tx_Idle+0)
MOVT	R3, #hi_addr(_UART3_Tx_Idle+0)
MOVW	R2, #lo_addr(_UART3_Data_Ready+0)
MOVT	R2, #hi_addr(_UART3_Data_Ready+0)
MOVW	R1, #lo_addr(_UART3_Write+0)
MOVT	R1, #hi_addr(_UART3_Write+0)
MOVW	R0, #lo_addr(_UART3_Read+0)
MOVT	R0, #hi_addr(_UART3_Read+0)
BL	_UART_Set_Active+0
;BLEP_Click.c,144 :: 		}
L_end_Init_MCU:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _Init_MCU
_wait:
;BLEP_Click.c,146 :: 		void wait() {
;BLEP_Click.c,147 :: 		Delay_ms(3000);          // 3 seconds delay
MOVW	R7, #4606
MOVT	R7, #122
NOP
NOP
L_wait19:
SUBS	R7, R7, #1
BNE	L_wait19
NOP
NOP
NOP
;BLEP_Click.c,148 :: 		}
L_end_wait:
BX	LR
; end of _wait
_read_gps_data:
;BLEP_Click.c,150 :: 		void read_gps_data()
;BLEP_Click.c,153 :: 		}
L_end_read_gps_data:
BX	LR
; end of _read_gps_data
_Open_GPRS:
;BLEP_Click.c,155 :: 		void Open_GPRS()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;BLEP_Click.c,157 :: 		DisableInterrupts();
BL	_DisableInterrupts+0
;BLEP_Click.c,158 :: 		UART_Set_Active(&UART6_Read, &UART6_Write, &UART6_Data_Ready, &UART6_Tx_Idle);
MOVW	R3, #lo_addr(_UART6_Tx_Idle+0)
MOVT	R3, #hi_addr(_UART6_Tx_Idle+0)
MOVW	R2, #lo_addr(_UART6_Data_Ready+0)
MOVT	R2, #hi_addr(_UART6_Data_Ready+0)
MOVW	R1, #lo_addr(_UART6_Write+0)
MOVT	R1, #hi_addr(_UART6_Write+0)
MOVW	R0, #lo_addr(_UART6_Read+0)
MOVT	R0, #hi_addr(_UART6_Read+0)
BL	_UART_Set_Active+0
;BLEP_Click.c,159 :: 		UART6_Write_Text("AT+SAPBR=3,1,Contype,GPRS\r\n");
MOVW	R0, #lo_addr(?lstr1_BLEP_Click+0)
MOVT	R0, #hi_addr(?lstr1_BLEP_Click+0)
BL	_UART6_Write_Text+0
;BLEP_Click.c,160 :: 		Delay_ms(1000);
MOVW	R7, #45225
MOVT	R7, #40
NOP
NOP
L_Open_GPRS21:
SUBS	R7, R7, #1
BNE	L_Open_GPRS21
NOP
NOP
;BLEP_Click.c,161 :: 		UART6_Write_Text("AT+SAPBR=3,1,APN,payandgo.o2.co.uk\r\n");
MOVW	R0, #lo_addr(?lstr2_BLEP_Click+0)
MOVT	R0, #hi_addr(?lstr2_BLEP_Click+0)
BL	_UART6_Write_Text+0
;BLEP_Click.c,162 :: 		Delay_ms(1000);
MOVW	R7, #45225
MOVT	R7, #40
NOP
NOP
L_Open_GPRS23:
SUBS	R7, R7, #1
BNE	L_Open_GPRS23
NOP
NOP
;BLEP_Click.c,163 :: 		UART6_Write_Text("AT+SAPBR=3,1,USER,payandgo\r\n");
MOVW	R0, #lo_addr(?lstr3_BLEP_Click+0)
MOVT	R0, #hi_addr(?lstr3_BLEP_Click+0)
BL	_UART6_Write_Text+0
;BLEP_Click.c,164 :: 		Delay_ms(1000);
MOVW	R7, #45225
MOVT	R7, #40
NOP
NOP
L_Open_GPRS25:
SUBS	R7, R7, #1
BNE	L_Open_GPRS25
NOP
NOP
;BLEP_Click.c,165 :: 		UART6_Write_Text("AT+SAPBR=3,1,PWD,password\r\n");
MOVW	R0, #lo_addr(?lstr4_BLEP_Click+0)
MOVT	R0, #hi_addr(?lstr4_BLEP_Click+0)
BL	_UART6_Write_Text+0
;BLEP_Click.c,166 :: 		Delay_ms(1000);
MOVW	R7, #45225
MOVT	R7, #40
NOP
NOP
L_Open_GPRS27:
SUBS	R7, R7, #1
BNE	L_Open_GPRS27
NOP
NOP
;BLEP_Click.c,167 :: 		UART6_Write_Text("AT+SAPBR=1,1\r\n");  //open gprs
MOVW	R0, #lo_addr(?lstr5_BLEP_Click+0)
MOVT	R0, #hi_addr(?lstr5_BLEP_Click+0)
BL	_UART6_Write_Text+0
;BLEP_Click.c,168 :: 		Delay_ms(1000);
MOVW	R7, #45225
MOVT	R7, #40
NOP
NOP
L_Open_GPRS29:
SUBS	R7, R7, #1
BNE	L_Open_GPRS29
NOP
NOP
;BLEP_Click.c,169 :: 		LED_GRN = 0;
MOVS	R1, #0
SXTB	R1, R1
MOVW	R0, #lo_addr(GPIOD_ODR+0)
MOVT	R0, #hi_addr(GPIOD_ODR+0)
STR	R1, [R0, #0]
;BLEP_Click.c,170 :: 		EnableInterrupts();
BL	_EnableInterrupts+0
;BLEP_Click.c,171 :: 		return;
;BLEP_Click.c,172 :: 		}
L_end_Open_GPRS:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _Open_GPRS
_Close_GPRS:
;BLEP_Click.c,174 :: 		void Close_GPRS()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;BLEP_Click.c,176 :: 		DisableInterrupts();
BL	_DisableInterrupts+0
;BLEP_Click.c,177 :: 		UART6_Write_Text("AT+SAPBR=0,1\r\n");  //close gprs
MOVW	R0, #lo_addr(?lstr6_BLEP_Click+0)
MOVT	R0, #hi_addr(?lstr6_BLEP_Click+0)
BL	_UART6_Write_Text+0
;BLEP_Click.c,178 :: 		Delay_ms(1000);
MOVW	R7, #45225
MOVT	R7, #40
NOP
NOP
L_Close_GPRS31:
SUBS	R7, R7, #1
BNE	L_Close_GPRS31
NOP
NOP
;BLEP_Click.c,179 :: 		EnableInterrupts();
BL	_EnableInterrupts+0
;BLEP_Click.c,180 :: 		return;
;BLEP_Click.c,181 :: 		}
L_end_Close_GPRS:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _Close_GPRS
_start_HTTP:
;BLEP_Click.c,183 :: 		void start_HTTP(char *post_data)
SUB	SP, SP, #8
STR	LR, [SP, #0]
STR	R0, [SP, #4]
;BLEP_Click.c,185 :: 		DisableInterrupts();
BL	_DisableInterrupts+0
;BLEP_Click.c,187 :: 		UART_Set_Active(&UART6_Read, &UART6_Write, &UART6_Data_Ready, &UART6_Tx_Idle);
MOVW	R3, #lo_addr(_UART6_Tx_Idle+0)
MOVT	R3, #hi_addr(_UART6_Tx_Idle+0)
MOVW	R2, #lo_addr(_UART6_Data_Ready+0)
MOVT	R2, #hi_addr(_UART6_Data_Ready+0)
MOVW	R1, #lo_addr(_UART6_Write+0)
MOVT	R1, #hi_addr(_UART6_Write+0)
MOVW	R0, #lo_addr(_UART6_Read+0)
MOVT	R0, #hi_addr(_UART6_Read+0)
BL	_UART_Set_Active+0
;BLEP_Click.c,188 :: 		UART6_Write_Text("AT+HTTPINIT\r\n");
MOVW	R1, #lo_addr(?lstr7_BLEP_Click+0)
MOVT	R1, #hi_addr(?lstr7_BLEP_Click+0)
MOV	R0, R1
BL	_UART6_Write_Text+0
;BLEP_Click.c,189 :: 		Delay_ms(1000);
MOVW	R7, #45225
MOVT	R7, #40
NOP
NOP
L_start_HTTP33:
SUBS	R7, R7, #1
BNE	L_start_HTTP33
NOP
NOP
;BLEP_Click.c,190 :: 		UART6_Write_Text("AT+HTTPPARA=CID,1\r\n");
MOVW	R1, #lo_addr(?lstr8_BLEP_Click+0)
MOVT	R1, #hi_addr(?lstr8_BLEP_Click+0)
MOV	R0, R1
BL	_UART6_Write_Text+0
;BLEP_Click.c,191 :: 		Delay_ms(1000);
MOVW	R7, #45225
MOVT	R7, #40
NOP
NOP
L_start_HTTP35:
SUBS	R7, R7, #1
BNE	L_start_HTTP35
NOP
NOP
;BLEP_Click.c,192 :: 		UART6_Write_Text("AT+HTTPPARA=URL,http://requestb.in/1jpw8ja1\r\n");
MOVW	R1, #lo_addr(?lstr9_BLEP_Click+0)
MOVT	R1, #hi_addr(?lstr9_BLEP_Click+0)
MOV	R0, R1
BL	_UART6_Write_Text+0
;BLEP_Click.c,193 :: 		Delay_ms(1000);
MOVW	R7, #45225
MOVT	R7, #40
NOP
NOP
L_start_HTTP37:
SUBS	R7, R7, #1
BNE	L_start_HTTP37
NOP
NOP
;BLEP_Click.c,194 :: 		UART6_Write_Text("AT+HTTPPARA=CONTENT,text/plain\r\n");
MOVW	R1, #lo_addr(?lstr10_BLEP_Click+0)
MOVT	R1, #hi_addr(?lstr10_BLEP_Click+0)
MOV	R0, R1
BL	_UART6_Write_Text+0
;BLEP_Click.c,195 :: 		Delay_ms(1000);
MOVW	R7, #45225
MOVT	R7, #40
NOP
NOP
L_start_HTTP39:
SUBS	R7, R7, #1
BNE	L_start_HTTP39
NOP
NOP
;BLEP_Click.c,196 :: 		UART6_Write_Text("AT+HTTPDATA=1200,5000\r\n");
MOVW	R1, #lo_addr(?lstr11_BLEP_Click+0)
MOVT	R1, #hi_addr(?lstr11_BLEP_Click+0)
MOV	R0, R1
BL	_UART6_Write_Text+0
;BLEP_Click.c,197 :: 		Delay_ms(500);
MOVW	R7, #22611
MOVT	R7, #20
NOP
NOP
L_start_HTTP41:
SUBS	R7, R7, #1
BNE	L_start_HTTP41
NOP
NOP
NOP
NOP
;BLEP_Click.c,200 :: 		while(*post_data)
L_start_HTTP43:
LDR	R1, [SP, #4]
LDRB	R1, [R1, #0]
CMP	R1, #0
IT	EQ
BEQ	L_start_HTTP44
;BLEP_Click.c,202 :: 		UART6_Write(*post_data++);
LDR	R1, [SP, #4]
LDRB	R1, [R1, #0]
UXTH	R0, R1
BL	_UART6_Write+0
LDR	R1, [SP, #4]
ADDS	R1, R1, #1
STR	R1, [SP, #4]
;BLEP_Click.c,203 :: 		}
IT	AL
BAL	L_start_HTTP43
L_start_HTTP44:
;BLEP_Click.c,204 :: 		UART6_Write(0x0D);                             // terminate command with CR
MOVS	R0, #13
BL	_UART6_Write+0
;BLEP_Click.c,205 :: 		UART6_Write_Text("DATA From Tracker\r\n");
MOVW	R1, #lo_addr(?lstr12_BLEP_Click+0)
MOVT	R1, #hi_addr(?lstr12_BLEP_Click+0)
MOV	R0, R1
BL	_UART6_Write_Text+0
;BLEP_Click.c,206 :: 		UART6_Write(0x0D);
MOVS	R0, #13
BL	_UART6_Write+0
;BLEP_Click.c,207 :: 		Delay_ms(10000);
MOVW	R7, #59049
MOVT	R7, #406
NOP
NOP
L_start_HTTP45:
SUBS	R7, R7, #1
BNE	L_start_HTTP45
NOP
NOP
;BLEP_Click.c,208 :: 		UART6_Write_Text("AT+HTTPACTION=1\r\n");
MOVW	R1, #lo_addr(?lstr13_BLEP_Click+0)
MOVT	R1, #hi_addr(?lstr13_BLEP_Click+0)
MOV	R0, R1
BL	_UART6_Write_Text+0
;BLEP_Click.c,209 :: 		Delay_ms(1000);
MOVW	R7, #45225
MOVT	R7, #40
NOP
NOP
L_start_HTTP47:
SUBS	R7, R7, #1
BNE	L_start_HTTP47
NOP
NOP
;BLEP_Click.c,211 :: 		EnableInterrupts();
BL	_EnableInterrupts+0
;BLEP_Click.c,212 :: 		return;
;BLEP_Click.c,213 :: 		}
L_end_start_HTTP:
LDR	LR, [SP, #0]
ADD	SP, SP, #8
BX	LR
; end of _start_HTTP
_term_HTTP:
;BLEP_Click.c,215 :: 		void term_HTTP()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;BLEP_Click.c,217 :: 		DisableInterrupts();
BL	_DisableInterrupts+0
;BLEP_Click.c,218 :: 		LED_RED = 1;
MOVS	R1, #1
SXTB	R1, R1
MOVW	R0, #lo_addr(GPIOD_ODR+0)
MOVT	R0, #hi_addr(GPIOD_ODR+0)
STR	R1, [R0, #0]
;BLEP_Click.c,219 :: 		UART_Set_Active(&UART6_Read, &UART6_Write, &UART6_Data_Ready, &UART6_Tx_Idle);
MOVW	R3, #lo_addr(_UART6_Tx_Idle+0)
MOVT	R3, #hi_addr(_UART6_Tx_Idle+0)
MOVW	R2, #lo_addr(_UART6_Data_Ready+0)
MOVT	R2, #hi_addr(_UART6_Data_Ready+0)
MOVW	R1, #lo_addr(_UART6_Write+0)
MOVT	R1, #hi_addr(_UART6_Write+0)
MOVW	R0, #lo_addr(_UART6_Read+0)
MOVT	R0, #hi_addr(_UART6_Read+0)
BL	_UART_Set_Active+0
;BLEP_Click.c,220 :: 		UART6_Write_Text("AT+HTTPTERM\r\n");
MOVW	R0, #lo_addr(?lstr14_BLEP_Click+0)
MOVT	R0, #hi_addr(?lstr14_BLEP_Click+0)
BL	_UART6_Write_Text+0
;BLEP_Click.c,221 :: 		Delay_ms(1000);
MOVW	R7, #45225
MOVT	R7, #40
NOP
NOP
L_term_HTTP49:
SUBS	R7, R7, #1
BNE	L_term_HTTP49
NOP
NOP
;BLEP_Click.c,222 :: 		EnableInterrupts();
BL	_EnableInterrupts+0
;BLEP_Click.c,223 :: 		return;
;BLEP_Click.c,224 :: 		}
L_end_term_HTTP:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _term_HTTP
_Send_GPS_Data:
;BLEP_Click.c,226 :: 		void Send_GPS_Data(char reps)
; reps start address is: 0 (R0)
SUB	SP, SP, #4
STR	LR, [SP, #0]
; reps end address is: 0 (R0)
; reps start address is: 0 (R0)
;BLEP_Click.c,230 :: 		if (reps > 10)
CMP	R0, #10
IT	LS
BLS	L_Send_GPS_Data51
;BLEP_Click.c,232 :: 		for (c = 0; c <= reps; c++ )
; c start address is: 32 (R8)
MOVW	R8, #0
; reps end address is: 0 (R0)
; c end address is: 32 (R8)
UXTB	R9, R0
L_Send_GPS_Data52:
; c start address is: 32 (R8)
; reps start address is: 36 (R9)
CMP	R8, R9
IT	HI
BHI	L_Send_GPS_Data53
;BLEP_Click.c,234 :: 		Open_GPRS();
BL	_Open_GPRS+0
;BLEP_Click.c,235 :: 		start_HTTP(txt);
MOVW	R0, #lo_addr(_txt+0)
MOVT	R0, #hi_addr(_txt+0)
BL	_start_HTTP+0
;BLEP_Click.c,236 :: 		term_HTTP();
BL	_term_HTTP+0
;BLEP_Click.c,237 :: 		Delay_Ms(30000);
MOVW	R7, #46078
MOVT	R7, #1220
NOP
NOP
L_Send_GPS_Data55:
SUBS	R7, R7, #1
BNE	L_Send_GPS_Data55
NOP
NOP
NOP
;BLEP_Click.c,232 :: 		for (c = 0; c <= reps; c++ )
ADD	R8, R8, #1
UXTB	R8, R8
;BLEP_Click.c,238 :: 		}
; reps end address is: 36 (R9)
; c end address is: 32 (R8)
IT	AL
BAL	L_Send_GPS_Data52
L_Send_GPS_Data53:
;BLEP_Click.c,239 :: 		}
IT	AL
BAL	L_Send_GPS_Data57
L_Send_GPS_Data51:
;BLEP_Click.c,243 :: 		for (c = 0; c <= reps; c++ )
; c start address is: 36 (R9)
; reps start address is: 0 (R0)
MOVW	R9, #0
; reps end address is: 0 (R0)
; c end address is: 36 (R9)
UXTB	R8, R0
L_Send_GPS_Data58:
; c start address is: 36 (R9)
; reps start address is: 32 (R8)
CMP	R9, R8
IT	HI
BHI	L_Send_GPS_Data59
;BLEP_Click.c,245 :: 		Open_GPRS();
BL	_Open_GPRS+0
;BLEP_Click.c,246 :: 		start_HTTP(txt);
MOVW	R0, #lo_addr(_txt+0)
MOVT	R0, #hi_addr(_txt+0)
BL	_start_HTTP+0
;BLEP_Click.c,247 :: 		term_HTTP();
BL	_term_HTTP+0
;BLEP_Click.c,243 :: 		for (c = 0; c <= reps; c++ )
ADD	R9, R9, #1
UXTB	R9, R9
;BLEP_Click.c,249 :: 		}
; reps end address is: 32 (R8)
; c end address is: 36 (R9)
IT	AL
BAL	L_Send_GPS_Data58
L_Send_GPS_Data59:
;BLEP_Click.c,250 :: 		}
L_Send_GPS_Data57:
;BLEP_Click.c,251 :: 		return;
;BLEP_Click.c,252 :: 		}
L_end_Send_GPS_Data:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _Send_GPS_Data
_main:
;BLEP_Click.c,254 :: 		void main()
;BLEP_Click.c,256 :: 		Init_MCU();
BL	_Init_MCU+0
;BLEP_Click.c,257 :: 		Delay_ms(200);
MOVW	R7, #9043
MOVT	R7, #8
NOP
NOP
L_main61:
SUBS	R7, R7, #1
BNE	L_main61
NOP
NOP
NOP
NOP
;BLEP_Click.c,258 :: 		Blep_Setup();
BL	_Blep_Setup+0
;BLEP_Click.c,259 :: 		LED_CONN = 0;
MOVS	R1, #0
SXTB	R1, R1
MOVW	R0, #lo_addr(GPIOD_ODR+0)
MOVT	R0, #hi_addr(GPIOD_ODR+0)
STR	R1, [R0, #0]
;BLEP_Click.c,260 :: 		Blep_Bond(0xB4, 0x20);
MOVS	R1, #32
MOVS	R0, #180
BL	_Blep_Bond+0
;BLEP_Click.c,261 :: 		delay_ms(2000);
MOVW	R7, #24915
MOVT	R7, #81
NOP
NOP
L_main63:
SUBS	R7, R7, #1
BNE	L_main63
NOP
NOP
NOP
NOP
;BLEP_Click.c,265 :: 		while (1)
L_main65:
;BLEP_Click.c,267 :: 		NEW_EVT = Blep_EventCode();                                               //Wait for new event
BL	_Blep_EventCode+0
MOVW	R1, #lo_addr(_NEW_EVT+0)
MOVT	R1, #hi_addr(_NEW_EVT+0)
STRB	R0, [R1, #0]
;BLEP_Click.c,268 :: 		EVT_STATUS = Blep_EventStatus();                                         //Event Status
BL	_Blep_EventStatus+0
MOVW	R1, #lo_addr(_EVT_STATUS+0)
MOVT	R1, #hi_addr(_EVT_STATUS+0)
STRB	R0, [R1, #0]
;BLEP_Click.c,269 :: 		EVT_OPCODE = Blep_EventOpcode();                                         //Event Opcode
BL	_Blep_EventOpcode+0
MOVW	R1, #lo_addr(_EVT_OPCODE+0)
MOVT	R1, #hi_addr(_EVT_OPCODE+0)
STRB	R0, [R1, #0]
;BLEP_Click.c,271 :: 		switch(NEW_EVT)
IT	AL
BAL	L_main67
;BLEP_Click.c,273 :: 		case ACI_EVT_HW_ERROR:
L_main69:
;BLEP_Click.c,278 :: 		if (CONN_STATE) {
MOVW	R0, #lo_addr(_CONN_STATE+0)
MOVT	R0, #hi_addr(_CONN_STATE+0)
LDRB	R0, [R0, #0]
CMP	R0, #0
IT	EQ
BEQ	L_main70
;BLEP_Click.c,279 :: 		delay_ms(20);
MOVW	R7, #53331
MOVT	R7, #0
NOP
NOP
L_main71:
SUBS	R7, R7, #1
BNE	L_main71
NOP
NOP
NOP
NOP
;BLEP_Click.c,280 :: 		}
L_main70:
;BLEP_Click.c,281 :: 		break;
IT	AL
BAL	L_main68
;BLEP_Click.c,282 :: 		case ACI_EVT_CMD_RSP:
L_main73:
;BLEP_Click.c,284 :: 		if (EVT_STATUS > 0x03) { //error
MOVW	R0, #lo_addr(_EVT_STATUS+0)
MOVT	R0, #hi_addr(_EVT_STATUS+0)
LDRB	R0, [R0, #0]
CMP	R0, #3
IT	LS
BLS	L_main74
;BLEP_Click.c,285 :: 		Blep_Disconnect();
BL	_Blep_Disconnect+0
;BLEP_Click.c,286 :: 		delay_ms(20);
MOVW	R7, #53331
MOVT	R7, #0
NOP
NOP
L_main75:
SUBS	R7, R7, #1
BNE	L_main75
NOP
NOP
NOP
NOP
;BLEP_Click.c,287 :: 		}
L_main74:
;BLEP_Click.c,288 :: 		break;
IT	AL
BAL	L_main68
;BLEP_Click.c,289 :: 		case ACI_EVT_CONNECTED:
L_main77:
;BLEP_Click.c,290 :: 		CONN_STATE = 1;
MOVS	R1, #1
MOVW	R0, #lo_addr(_CONN_STATE+0)
MOVT	R0, #hi_addr(_CONN_STATE+0)
STRB	R1, [R0, #0]
;BLEP_Click.c,291 :: 		LED_CONN = CONN_STATE;
MOVS	R1, #1
MOVW	R0, #lo_addr(GPIOD_ODR+0)
MOVT	R0, #hi_addr(GPIOD_ODR+0)
STR	R1, [R0, #0]
;BLEP_Click.c,292 :: 		Send_GPS_Data(24);
MOVS	R0, #24
BL	_Send_GPS_Data+0
;BLEP_Click.c,293 :: 		break;
IT	AL
BAL	L_main68
;BLEP_Click.c,294 :: 		case ACI_EVT_DISCONNECTED:
L_main78:
;BLEP_Click.c,295 :: 		CONN_STATE = 0;
MOVS	R1, #0
MOVW	R0, #lo_addr(_CONN_STATE+0)
MOVT	R0, #hi_addr(_CONN_STATE+0)
STRB	R1, [R0, #0]
;BLEP_Click.c,296 :: 		LED_CONN = CONN_STATE;
MOVS	R1, #0
MOVW	R0, #lo_addr(GPIOD_ODR+0)
MOVT	R0, #hi_addr(GPIOD_ODR+0)
STR	R1, [R0, #0]
;BLEP_Click.c,297 :: 		Blep_Bond(0xB4, 0x20);
MOVS	R1, #32
MOVS	R0, #180
BL	_Blep_Bond+0
;BLEP_Click.c,298 :: 		break;
IT	AL
BAL	L_main68
;BLEP_Click.c,299 :: 		case ACI_EVT_DATA_RECEIVED:
L_main79:
;BLEP_Click.c,300 :: 		OnDataReceived();
BL	_OnDataReceived+0
;BLEP_Click.c,301 :: 		}
IT	AL
BAL	L_main68
L_main67:
MOVW	R0, #lo_addr(_NEW_EVT+0)
MOVT	R0, #hi_addr(_NEW_EVT+0)
LDRB	R0, [R0, #0]
CMP	R0, #131
IT	EQ
BEQ	L_main69
MOVW	R0, #lo_addr(_NEW_EVT+0)
MOVT	R0, #hi_addr(_NEW_EVT+0)
LDRB	R0, [R0, #0]
CMP	R0, #132
IT	EQ
BEQ	L_main73
MOVW	R0, #lo_addr(_NEW_EVT+0)
MOVT	R0, #hi_addr(_NEW_EVT+0)
LDRB	R0, [R0, #0]
CMP	R0, #133
IT	EQ
BEQ	L_main77
MOVW	R0, #lo_addr(_NEW_EVT+0)
MOVT	R0, #hi_addr(_NEW_EVT+0)
LDRB	R0, [R0, #0]
CMP	R0, #134
IT	EQ
BEQ	L_main78
MOVW	R0, #lo_addr(_NEW_EVT+0)
MOVT	R0, #hi_addr(_NEW_EVT+0)
LDRB	R0, [R0, #0]
CMP	R0, #140
IT	EQ
BEQ	L_main79
L_main68:
;BLEP_Click.c,303 :: 		}
IT	AL
BAL	L_main65
;BLEP_Click.c,305 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
