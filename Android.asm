Android_SetIntValueToBuffer:
;Android.c,13 :: 		static void SetIntValueToBuffer(unsigned int Value){
; Value start address is: 0 (R0)
; Value end address is: 0 (R0)
; Value start address is: 0 (R0)
;Android.c,15 :: 		writeBuff[0] = (char)((Value >> 12) & 0xF);  //HHHsb
LSRS	R1, R0, #12
UXTH	R1, R1
AND	R1, R1, #15
UXTB	R2, R1
MOVW	R1, #lo_addr(_writeBuff+0)
MOVT	R1, #hi_addr(_writeBuff+0)
STRB	R2, [R1, #0]
;Android.c,16 :: 		writeBuff[1] = (char)((Value >> 8) & 0xF);   //HHsb
LSRS	R1, R0, #8
UXTH	R1, R1
AND	R1, R1, #15
UXTB	R2, R1
MOVW	R1, #lo_addr(_writeBuff+1)
MOVT	R1, #hi_addr(_writeBuff+1)
STRB	R2, [R1, #0]
;Android.c,17 :: 		writeBuff[2] = (char)((Value >> 4) & 0xF);   //Hsb
LSRS	R1, R0, #4
UXTH	R1, R1
AND	R1, R1, #15
UXTB	R2, R1
MOVW	R1, #lo_addr(_writeBuff+2)
MOVT	R1, #hi_addr(_writeBuff+2)
STRB	R2, [R1, #0]
;Android.c,18 :: 		writeBuff[3] = (char)(Value & 0xF);          //Lsb
AND	R1, R0, #15
; Value end address is: 0 (R0)
UXTB	R2, R1
MOVW	R1, #lo_addr(_writeBuff+3)
MOVT	R1, #hi_addr(_writeBuff+3)
STRB	R2, [R1, #0]
;Android.c,19 :: 		}
L_end_SetIntValueToBuffer:
BX	LR
; end of Android_SetIntValueToBuffer
_OnDataReceived:
;Android.c,27 :: 		void OnDataReceived() {
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Android.c,32 :: 		if (readBuff[ANDR_CMD_POS] == 0x50) {  //read buffer[4] is cmd byte
MOVW	R0, #lo_addr(_readBuff+4)
MOVT	R0, #hi_addr(_readBuff+4)
LDRSB	R0, [R0, #0]
CMP	R0, #80
IT	NE
BNE	L_OnDataReceived0
;Android.c,34 :: 		tmp1 = readBuff[ANDR_CMD_POS + 1];
MOVW	R0, #lo_addr(_readBuff+5)
MOVT	R0, #hi_addr(_readBuff+5)
; tmp1 start address is: 0 (R0)
LDRSB	R0, [R0, #0]
;Android.c,35 :: 		GPIOD_ODR = tmp1 & 0xF;
AND	R1, R0, #15
UXTH	R1, R1
; tmp1 end address is: 0 (R0)
MOVW	R0, #lo_addr(GPIOD_ODR+0)
MOVT	R0, #hi_addr(GPIOD_ODR+0)
STR	R1, [R0, #0]
;Android.c,37 :: 		tmp2 = (char)GPIOD_IDR & 0xF0;
MOVW	R0, #lo_addr(GPIOD_IDR+0)
MOVT	R0, #hi_addr(GPIOD_IDR+0)
LDR	R0, [R0, #0]
AND	R0, R0, #240
UXTB	R0, R0
; tmp2 start address is: 8 (R2)
UXTB	R2, R0
;Android.c,38 :: 		writeBuff[0] = (char)(tmp2 >> 4);
LSRS	R0, R2, #4
UXTB	R1, R0
MOVW	R0, #lo_addr(_writeBuff+0)
MOVT	R0, #hi_addr(_writeBuff+0)
STRB	R1, [R0, #0]
;Android.c,39 :: 		writeBuff[1] = (char)(tmp2 & 0xF);
AND	R0, R2, #15
; tmp2 end address is: 8 (R2)
UXTB	R1, R0
MOVW	R0, #lo_addr(_writeBuff+1)
MOVT	R0, #hi_addr(_writeBuff+1)
STRB	R1, [R0, #0]
;Android.c,41 :: 		tmp3 = ADC1_Get_Sample(5);
MOVS	R0, #5
BL	_ADC1_Get_Sample+0
; tmp3 start address is: 8 (R2)
UXTH	R2, R0
;Android.c,42 :: 		delay_ms(20);
MOVW	R7, #53331
MOVT	R7, #0
NOP
NOP
L_OnDataReceived1:
SUBS	R7, R7, #1
BNE	L_OnDataReceived1
NOP
NOP
NOP
NOP
;Android.c,43 :: 		writeBuff[2] = (char)((tmp3 >> 12)& 0xF); //HHHsb
LSRS	R0, R2, #12
UXTH	R0, R0
AND	R0, R0, #15
UXTB	R1, R0
MOVW	R0, #lo_addr(_writeBuff+2)
MOVT	R0, #hi_addr(_writeBuff+2)
STRB	R1, [R0, #0]
;Android.c,44 :: 		writeBuff[3] = (char)((tmp3 >> 8)& 0xF);  //HHsb
LSRS	R0, R2, #8
UXTH	R0, R0
AND	R0, R0, #15
UXTB	R1, R0
MOVW	R0, #lo_addr(_writeBuff+3)
MOVT	R0, #hi_addr(_writeBuff+3)
STRB	R1, [R0, #0]
;Android.c,45 :: 		writeBuff[4] = (char)((tmp3 >> 4) & 0xF); //Hsb
LSRS	R0, R2, #4
UXTH	R0, R0
AND	R0, R0, #15
UXTB	R1, R0
MOVW	R0, #lo_addr(_writeBuff+4)
MOVT	R0, #hi_addr(_writeBuff+4)
STRB	R1, [R0, #0]
;Android.c,46 :: 		writeBuff[5] = (char)(tmp3 & 0xF);        //Lsb
AND	R0, R2, #15
; tmp3 end address is: 8 (R2)
UXTB	R1, R0
MOVW	R0, #lo_addr(_writeBuff+5)
MOVT	R0, #hi_addr(_writeBuff+5)
STRB	R1, [R0, #0]
;Android.c,47 :: 		txPipe = readBuff[2] + 1;
MOVW	R0, #lo_addr(_readBuff+2)
MOVT	R0, #hi_addr(_readBuff+2)
LDRSB	R0, [R0, #0]
ADDS	R1, R0, #1
MOVW	R0, #lo_addr(_txPipe+0)
MOVT	R0, #hi_addr(_txPipe+0)
STRB	R1, [R0, #0]
;Android.c,48 :: 		Blep_SendData(&writeBuff,6,txPipe);
UXTB	R0, R1
UXTB	R2, R0
MOVS	R1, #6
MOVW	R0, #lo_addr(_writeBuff+0)
MOVT	R0, #hi_addr(_writeBuff+0)
BL	_Blep_SendData+0
;Android.c,49 :: 		}
L_OnDataReceived0:
;Android.c,50 :: 		}
L_end_OnDataReceived:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _OnDataReceived
