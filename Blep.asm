_Blep_Write:
;Blep.c,49 :: 		void Blep_Write(unsigned short *dat, unsigned int txLen)  {
SUB	SP, SP, #20
STR	LR, [SP, #0]
STR	R0, [SP, #12]
STRH	R1, [SP, #16]
;Blep.c,52 :: 		Blep_REQ = 0;
MOVS	R3, #0
SXTB	R3, R3
MOVW	R2, #lo_addr(Blep_REQ+0)
MOVT	R2, #hi_addr(Blep_REQ+0)
STR	R3, [R2, #0]
;Blep.c,53 :: 		while(Blep_RDY == 1);
L_Blep_Write0:
MOVW	R3, #lo_addr(Blep_RDY+0)
MOVT	R3, #hi_addr(Blep_RDY+0)
LDR	R2, [R3, #0]
CMP	R2, #0
IT	EQ
BEQ	L_Blep_Write1
IT	AL
BAL	L_Blep_Write0
L_Blep_Write1:
;Blep.c,55 :: 		rcvDummy = SPI_Read(dat[0]);
LDR	R2, [SP, #12]
LDRB	R2, [R2, #0]
UXTH	R0, R2
BL	_SPI_Read+0
;Blep.c,56 :: 		rxLen = SPI_Read(dat[1]);
LDR	R2, [SP, #12]
ADDS	R2, R2, #1
LDRB	R2, [R2, #0]
UXTH	R0, R2
BL	_SPI_Read+0
STRB	R0, [SP, #8]
;Blep.c,57 :: 		if(rxLen != 0) {
UXTB	R2, R0
CMP	R2, #0
IT	EQ
BEQ	L_Blep_Write2
;Blep.c,58 :: 		readBuff[0] = rxLen;
LDRB	R3, [SP, #8]
MOVW	R2, #lo_addr(_readBuff+0)
MOVT	R2, #hi_addr(_readBuff+0)
STRB	R3, [R2, #0]
;Blep.c,59 :: 		}
L_Blep_Write2:
;Blep.c,61 :: 		for (cnt=2; (cnt<txLen + 1) || (cnt<rxLen + 2); cnt++)
; cnt start address is: 24 (R6)
MOVS	R6, #2
; cnt end address is: 24 (R6)
UXTB	R1, R6
L_Blep_Write3:
; cnt start address is: 4 (R1)
LDRH	R2, [SP, #16]
ADDS	R2, R2, #1
UXTH	R2, R2
CMP	R1, R2
IT	CC
BCC	L__Blep_Write34
LDRB	R2, [SP, #8]
ADDS	R2, R2, #2
SXTH	R2, R2
CMP	R1, R2
IT	LT
BLT	L__Blep_Write33
; cnt end address is: 4 (R1)
IT	AL
BAL	L_Blep_Write4
L__Blep_Write34:
; cnt start address is: 4 (R1)
L__Blep_Write33:
;Blep.c,64 :: 		if (cnt < txLen + 1) {
LDRH	R2, [SP, #16]
ADDS	R2, R2, #1
UXTH	R2, R2
CMP	R1, R2
IT	CS
BCS	L_Blep_Write8
;Blep.c,65 :: 		tmp = SPI_Read(dat[cnt]); // transmit
LDR	R2, [SP, #12]
ADDS	R2, R2, R1
LDRB	R2, [R2, #0]
STRB	R1, [SP, #4]
UXTH	R0, R2
BL	_SPI_Read+0
LDRB	R1, [SP, #4]
; tmp start address is: 0 (R0)
UXTB	R0, R0
;Blep.c,66 :: 		} else {
; tmp end address is: 0 (R0)
IT	AL
BAL	L_Blep_Write9
L_Blep_Write8:
;Blep.c,67 :: 		tmp = SPI_Read(0); // receive only
STRB	R1, [SP, #4]
MOVS	R0, #0
BL	_SPI_Read+0
LDRB	R1, [SP, #4]
; tmp start address is: 8 (R2)
UXTB	R2, R0
; tmp end address is: 8 (R2)
UXTB	R0, R2
;Blep.c,68 :: 		}
L_Blep_Write9:
;Blep.c,70 :: 		if (cnt < rxLen + 2) { // receive
; tmp start address is: 0 (R0)
LDRB	R2, [SP, #8]
ADDS	R2, R2, #2
SXTH	R2, R2
CMP	R1, R2
IT	GE
BGE	L_Blep_Write10
;Blep.c,71 :: 		readBuff[cnt-1] = tmp;
SUBS	R3, R1, #1
SXTH	R3, R3
MOVW	R2, #lo_addr(_readBuff+0)
MOVT	R2, #hi_addr(_readBuff+0)
ADDS	R2, R2, R3
STRB	R0, [R2, #0]
; tmp end address is: 0 (R0)
;Blep.c,72 :: 		}
L_Blep_Write10:
;Blep.c,61 :: 		for (cnt=2; (cnt<txLen + 1) || (cnt<rxLen + 2); cnt++)
ADDS	R2, R1, #1
; cnt end address is: 4 (R1)
; cnt start address is: 24 (R6)
UXTB	R6, R2
;Blep.c,73 :: 		}
UXTB	R1, R6
; cnt end address is: 24 (R6)
IT	AL
BAL	L_Blep_Write3
L_Blep_Write4:
;Blep.c,75 :: 		Blep_REQ = 1;
MOVS	R3, #1
SXTB	R3, R3
MOVW	R2, #lo_addr(Blep_REQ+0)
MOVT	R2, #hi_addr(Blep_REQ+0)
STR	R3, [R2, #0]
;Blep.c,76 :: 		acil_decode_evt(readBuff, &p_aci_evt);
MOVW	R1, #lo_addr(_p_aci_evt+0)
MOVT	R1, #hi_addr(_p_aci_evt+0)
MOVW	R0, #lo_addr(_readBuff+0)
MOVT	R0, #hi_addr(_readBuff+0)
BL	_acil_decode_evt+0
;Blep.c,78 :: 		}
L_end_Blep_Write:
LDR	LR, [SP, #0]
ADD	SP, SP, #20
BX	LR
; end of _Blep_Write
_Blep_Read:
;Blep.c,85 :: 		void Blep_Read() {
SUB	SP, SP, #20
STR	LR, [SP, #0]
;Blep.c,88 :: 		while(Blep_RDY);
L_Blep_Read11:
MOVW	R1, #lo_addr(Blep_RDY+0)
MOVT	R1, #hi_addr(Blep_RDY+0)
LDR	R0, [R1, #0]
CMP	R0, #0
IT	EQ
BEQ	L_Blep_Read12
IT	AL
BAL	L_Blep_Read11
L_Blep_Read12:
;Blep.c,89 :: 		Blep_REQ = 0;
MOVS	R1, #0
SXTB	R1, R1
MOVW	R0, #lo_addr(Blep_REQ+0)
MOVT	R0, #hi_addr(Blep_REQ+0)
STR	R1, [R0, #0]
;Blep.c,90 :: 		dummy =  SPI_Read(0);
MOVS	R0, #0
BL	_SPI_Read+0
STRB	R0, [SP, #8]
;Blep.c,91 :: 		readBuff[0] = SPI_Read(dummy);
UXTB	R0, R0
BL	_SPI_Read+0
MOVW	R1, #lo_addr(_readBuff+0)
MOVT	R1, #hi_addr(_readBuff+0)
STRB	R0, [R1, #0]
;Blep.c,92 :: 		if(readBuff[0] > 0) {
UXTB	R0, R0
CMP	R0, #0
IT	LS
BLS	L_Blep_Read13
;Blep.c,93 :: 		for (cnt=0; cnt<readBuff[0]; cnt++){
; cnt start address is: 12 (R3)
MOVS	R3, #0
; cnt end address is: 12 (R3)
UXTB	R2, R3
L_Blep_Read14:
; cnt start address is: 8 (R2)
MOVW	R0, #lo_addr(_readBuff+0)
MOVT	R0, #hi_addr(_readBuff+0)
LDRB	R0, [R0, #0]
CMP	R2, R0
IT	CS
BCS	L_Blep_Read15
;Blep.c,94 :: 		readBuff[cnt + 1] = SPI_Read(dummy);
ADDS	R1, R2, #1
SXTH	R1, R1
MOVW	R0, #lo_addr(_readBuff+0)
MOVT	R0, #hi_addr(_readBuff+0)
ADDS	R0, R0, R1
STR	R0, [SP, #16]
STRB	R2, [SP, #4]
LDRB	R0, [SP, #8]
BL	_SPI_Read+0
LDRB	R2, [SP, #4]
LDR	R1, [SP, #16]
STRB	R0, [R1, #0]
;Blep.c,93 :: 		for (cnt=0; cnt<readBuff[0]; cnt++){
ADDS	R0, R2, #1
; cnt end address is: 8 (R2)
; cnt start address is: 12 (R3)
UXTB	R3, R0
;Blep.c,95 :: 		}
UXTB	R2, R3
; cnt end address is: 12 (R3)
IT	AL
BAL	L_Blep_Read14
L_Blep_Read15:
;Blep.c,96 :: 		}
L_Blep_Read13:
;Blep.c,97 :: 		Blep_REQ = 1;
MOVS	R1, #1
SXTB	R1, R1
MOVW	R0, #lo_addr(Blep_REQ+0)
MOVT	R0, #hi_addr(Blep_REQ+0)
STR	R1, [R0, #0]
;Blep.c,98 :: 		acil_decode_evt(readBuff, &p_aci_evt);
MOVW	R1, #lo_addr(_p_aci_evt+0)
MOVT	R1, #hi_addr(_p_aci_evt+0)
MOVW	R0, #lo_addr(_readBuff+0)
MOVT	R0, #hi_addr(_readBuff+0)
BL	_acil_decode_evt+0
;Blep.c,100 :: 		}
L_end_Blep_Read:
LDR	LR, [SP, #0]
ADD	SP, SP, #20
BX	LR
; end of _Blep_Read
_Blep_EventCode:
;Blep.c,108 :: 		char Blep_EventCode() {
SUB	SP, SP, #20
STR	LR, [SP, #0]
;Blep.c,110 :: 		while(Blep_RDY);
L_Blep_EventCode17:
MOVW	R1, #lo_addr(Blep_RDY+0)
MOVT	R1, #hi_addr(Blep_RDY+0)
LDR	R0, [R1, #0]
CMP	R0, #0
IT	EQ
BEQ	L_Blep_EventCode18
IT	AL
BAL	L_Blep_EventCode17
L_Blep_EventCode18:
;Blep.c,111 :: 		Blep_REQ = 0;
MOVS	R1, #0
SXTB	R1, R1
MOVW	R0, #lo_addr(Blep_REQ+0)
MOVT	R0, #hi_addr(Blep_REQ+0)
STR	R1, [R0, #0]
;Blep.c,112 :: 		dummy =  SPI_Read(0);
MOVS	R0, #0
BL	_SPI_Read+0
STRB	R0, [SP, #8]
;Blep.c,113 :: 		readBuff[0] = SPI_Read(dummy);
UXTB	R0, R0
BL	_SPI_Read+0
MOVW	R1, #lo_addr(_readBuff+0)
MOVT	R1, #hi_addr(_readBuff+0)
STRB	R0, [R1, #0]
;Blep.c,114 :: 		if(readBuff[0] > 0) {
UXTB	R0, R0
CMP	R0, #0
IT	LS
BLS	L_Blep_EventCode19
;Blep.c,115 :: 		for (cnt=0; cnt<readBuff[0]; cnt++){
; cnt start address is: 12 (R3)
MOVS	R3, #0
; cnt end address is: 12 (R3)
UXTB	R2, R3
L_Blep_EventCode20:
; cnt start address is: 8 (R2)
MOVW	R0, #lo_addr(_readBuff+0)
MOVT	R0, #hi_addr(_readBuff+0)
LDRB	R0, [R0, #0]
CMP	R2, R0
IT	CS
BCS	L_Blep_EventCode21
;Blep.c,116 :: 		readBuff[cnt+1] = SPI_Read(dummy);
ADDS	R1, R2, #1
SXTH	R1, R1
MOVW	R0, #lo_addr(_readBuff+0)
MOVT	R0, #hi_addr(_readBuff+0)
ADDS	R0, R0, R1
STR	R0, [SP, #16]
STRB	R2, [SP, #4]
LDRB	R0, [SP, #8]
BL	_SPI_Read+0
LDRB	R2, [SP, #4]
LDR	R1, [SP, #16]
STRB	R0, [R1, #0]
;Blep.c,115 :: 		for (cnt=0; cnt<readBuff[0]; cnt++){
ADDS	R0, R2, #1
; cnt end address is: 8 (R2)
; cnt start address is: 12 (R3)
UXTB	R3, R0
;Blep.c,117 :: 		}
UXTB	R2, R3
; cnt end address is: 12 (R3)
IT	AL
BAL	L_Blep_EventCode20
L_Blep_EventCode21:
;Blep.c,118 :: 		}
L_Blep_EventCode19:
;Blep.c,119 :: 		Blep_REQ = 1;
MOVS	R1, #1
SXTB	R1, R1
MOVW	R0, #lo_addr(Blep_REQ+0)
MOVT	R0, #hi_addr(Blep_REQ+0)
STR	R1, [R0, #0]
;Blep.c,120 :: 		acil_decode_evt(readBuff, &p_aci_evt);
MOVW	R1, #lo_addr(_p_aci_evt+0)
MOVT	R1, #hi_addr(_p_aci_evt+0)
MOVW	R0, #lo_addr(_readBuff+0)
MOVT	R0, #hi_addr(_readBuff+0)
BL	_acil_decode_evt+0
;Blep.c,121 :: 		return p_aci_evt.evt_opcode;
MOVW	R0, #lo_addr(_p_aci_evt+1)
MOVT	R0, #hi_addr(_p_aci_evt+1)
LDRB	R0, [R0, #0]
;Blep.c,122 :: 		}
L_end_Blep_EventCode:
LDR	LR, [SP, #0]
ADD	SP, SP, #20
BX	LR
; end of _Blep_EventCode
_Blep_EventOpcode:
;Blep.c,124 :: 		char Blep_EventOpcode() {
;Blep.c,125 :: 		return p_aci_evt.params.cmd_rsp.cmd_opcode;
MOVW	R0, #lo_addr(_p_aci_evt+4)
MOVT	R0, #hi_addr(_p_aci_evt+4)
LDRB	R0, [R0, #0]
;Blep.c,126 :: 		}
L_end_Blep_EventOpcode:
BX	LR
; end of _Blep_EventOpcode
_Blep_EventStatus:
;Blep.c,128 :: 		char Blep_EventStatus() {
;Blep.c,129 :: 		return p_aci_evt.params.cmd_rsp.cmd_status;
MOVW	R0, #lo_addr(_p_aci_evt+5)
MOVT	R0, #hi_addr(_p_aci_evt+5)
LDRB	R0, [R0, #0]
;Blep.c,130 :: 		}
L_end_Blep_EventStatus:
BX	LR
; end of _Blep_EventStatus
_Blep_WaitForEvent:
;Blep.c,137 :: 		char Blep_WaitForEvent(char event) {
SUB	SP, SP, #8
STR	LR, [SP, #0]
STRB	R0, [SP, #4]
;Blep.c,139 :: 		while(1) {
L_Blep_WaitForEvent23:
;Blep.c,140 :: 		Blep_Read();
BL	_Blep_Read+0
;Blep.c,141 :: 		if(p_aci_evt.evt_opcode == event) {
LDRB	R2, [SP, #4]
MOVW	R1, #lo_addr(_p_aci_evt+1)
MOVT	R1, #hi_addr(_p_aci_evt+1)
LDRB	R1, [R1, #0]
CMP	R1, R2
IT	NE
BNE	L_Blep_WaitForEvent25
;Blep.c,142 :: 		break;
IT	AL
BAL	L_Blep_WaitForEvent24
;Blep.c,143 :: 		}
L_Blep_WaitForEvent25:
;Blep.c,144 :: 		}
IT	AL
BAL	L_Blep_WaitForEvent23
L_Blep_WaitForEvent24:
;Blep.c,145 :: 		}
L_end_Blep_WaitForEvent:
LDR	LR, [SP, #0]
ADD	SP, SP, #8
BX	LR
; end of _Blep_WaitForEvent
_Blep_Bond:
;Blep.c,151 :: 		void Blep_Bond(uint16_t timeout, uint16_t adv_interval) {
; adv_interval start address is: 4 (R1)
; timeout start address is: 0 (R0)
SUB	SP, SP, #4
STR	LR, [SP, #0]
; adv_interval end address is: 4 (R1)
; timeout end address is: 0 (R0)
; timeout start address is: 0 (R0)
; adv_interval start address is: 4 (R1)
;Blep.c,152 :: 		bondParam.timeout = timeout;
MOVW	R2, #lo_addr(_bondParam+0)
MOVT	R2, #hi_addr(_bondParam+0)
STRH	R0, [R2, #0]
; timeout end address is: 0 (R0)
;Blep.c,153 :: 		bondParam.adv_interval = adv_interval;
MOVW	R2, #lo_addr(_bondParam+2)
MOVT	R2, #hi_addr(_bondParam+2)
STRH	R1, [R2, #0]
; adv_interval end address is: 4 (R1)
;Blep.c,154 :: 		acil_encode_cmd_bond(writeBuff, (aci_cmd_params_bond_t*)&bondParam);
MOVW	R1, #lo_addr(_bondParam+0)
MOVT	R1, #hi_addr(_bondParam+0)
MOVW	R0, #lo_addr(_writeBuff+0)
MOVT	R0, #hi_addr(_writeBuff+0)
BL	_acil_encode_cmd_bond+0
;Blep.c,155 :: 		Blep_Write(writeBuff, MSG_BOND_LEN);
MOVS	R1, #5
MOVW	R0, #lo_addr(_writeBuff+0)
MOVT	R0, #hi_addr(_writeBuff+0)
BL	_Blep_Write+0
;Blep.c,156 :: 		}
L_end_Blep_Bond:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _Blep_Bond
_Blep_DirectConnect:
;Blep.c,163 :: 		void Blep_DirectConnect() {
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Blep.c,164 :: 		acil_encode_direct_connect(writeBuff);
MOVW	R0, #lo_addr(_writeBuff+0)
MOVT	R0, #hi_addr(_writeBuff+0)
BL	_acil_encode_direct_connect+0
;Blep.c,165 :: 		Blep_Write(writeBuff, 2);
MOVS	R1, #2
MOVW	R0, #lo_addr(_writeBuff+0)
MOVT	R0, #hi_addr(_writeBuff+0)
BL	_Blep_Write+0
;Blep.c,166 :: 		}
L_end_Blep_DirectConnect:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _Blep_DirectConnect
_Blep_Connect:
;Blep.c,173 :: 		void Blep_Connect() {
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Blep.c,174 :: 		p_aci_cmd_params_connect.timeout = 0;
MOVS	R1, #0
MOVW	R0, #lo_addr(_p_aci_cmd_params_connect+0)
MOVT	R0, #hi_addr(_p_aci_cmd_params_connect+0)
STRH	R1, [R0, #0]
;Blep.c,175 :: 		p_aci_cmd_params_connect.adv_interval = 0x20;
MOVS	R1, #32
MOVW	R0, #lo_addr(_p_aci_cmd_params_connect+2)
MOVT	R0, #hi_addr(_p_aci_cmd_params_connect+2)
STRH	R1, [R0, #0]
;Blep.c,176 :: 		acil_encode_cmd_connect(writeBuff, &p_aci_cmd_params_connect);
MOVW	R1, #lo_addr(_p_aci_cmd_params_connect+0)
MOVT	R1, #hi_addr(_p_aci_cmd_params_connect+0)
MOVW	R0, #lo_addr(_writeBuff+0)
MOVT	R0, #hi_addr(_writeBuff+0)
BL	_acil_encode_cmd_connect+0
;Blep.c,177 :: 		Blep_Write(writeBuff, MSG_CONNECT_LEN);
MOVS	R1, #5
MOVW	R0, #lo_addr(_writeBuff+0)
MOVT	R0, #hi_addr(_writeBuff+0)
BL	_Blep_Write+0
;Blep.c,178 :: 		}
L_end_Blep_Connect:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _Blep_Connect
_Blep_Disconnect:
;Blep.c,185 :: 		void Blep_Disconnect() {
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Blep.c,186 :: 		p_aci_cmd_params_disconnect.reason = ACI_REASON_TERMINATE;
MOVS	R1, #1
MOVW	R0, #lo_addr(_p_aci_cmd_params_disconnect+0)
MOVT	R0, #hi_addr(_p_aci_cmd_params_disconnect+0)
STRB	R1, [R0, #0]
;Blep.c,187 :: 		acil_encode_cmd_disconnect(writeBuff, &p_aci_cmd_params_disconnect);
MOVW	R1, #lo_addr(_p_aci_cmd_params_disconnect+0)
MOVT	R1, #hi_addr(_p_aci_cmd_params_disconnect+0)
MOVW	R0, #lo_addr(_writeBuff+0)
MOVT	R0, #hi_addr(_writeBuff+0)
BL	_acil_encode_cmd_disconnect+0
;Blep.c,188 :: 		Blep_Write(writeBuff, MSG_CONNECT_LEN);
MOVS	R1, #5
MOVW	R0, #lo_addr(_writeBuff+0)
MOVT	R0, #hi_addr(_writeBuff+0)
BL	_Blep_Write+0
;Blep.c,189 :: 		}
L_end_Blep_Disconnect:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _Blep_Disconnect
_Blep_SendData:
;Blep.c,196 :: 		void Blep_SendData(uint8_t *dat, uint8_t len, uint8_t pipe) {
; pipe start address is: 8 (R2)
; dat start address is: 0 (R0)
SUB	SP, SP, #8
STR	LR, [SP, #0]
STRB	R1, [SP, #4]
; pipe end address is: 8 (R2)
; dat end address is: 0 (R0)
; dat start address is: 0 (R0)
; pipe start address is: 8 (R2)
;Blep.c,198 :: 		p_aci_cmd_params_send_data_t.tx_data.pipe_number = pipe;
MOVW	R3, #lo_addr(_p_aci_cmd_params_send_data_t+0)
MOVT	R3, #hi_addr(_p_aci_cmd_params_send_data_t+0)
STRB	R2, [R3, #0]
; pipe end address is: 8 (R2)
;Blep.c,199 :: 		memcpy(p_aci_cmd_params_send_data_t.tx_data.aci_data, dat, len);
LDRB	R2, [SP, #4]
MOV	R1, R0
; dat end address is: 0 (R0)
MOVW	R0, #lo_addr(_p_aci_cmd_params_send_data_t+1)
MOVT	R0, #hi_addr(_p_aci_cmd_params_send_data_t+1)
BL	_memcpy+0
;Blep.c,200 :: 		acil_encode_cmd_send_data(writeBuff, &p_aci_cmd_params_send_data_t, len);
LDRB	R2, [SP, #4]
MOVW	R1, #lo_addr(_p_aci_cmd_params_send_data_t+0)
MOVT	R1, #hi_addr(_p_aci_cmd_params_send_data_t+0)
MOVW	R0, #lo_addr(_writeBuff+0)
MOVT	R0, #hi_addr(_writeBuff+0)
BL	_acil_encode_cmd_send_data+0
;Blep.c,201 :: 		Blep_Write(writeBuff, MSG_SEND_DATA_BASE_LEN + len);
LDRB	R3, [SP, #4]
ADDS	R3, R3, #2
UXTH	R1, R3
MOVW	R0, #lo_addr(_writeBuff+0)
MOVT	R0, #hi_addr(_writeBuff+0)
BL	_Blep_Write+0
;Blep.c,202 :: 		}
L_end_Blep_SendData:
LDR	LR, [SP, #0]
ADD	SP, SP, #8
BX	LR
; end of _Blep_SendData
_Blep_OpenRemotePipe:
;Blep.c,209 :: 		void Blep_OpenRemotePipe(uint8_t pipe) {
; pipe start address is: 0 (R0)
SUB	SP, SP, #4
STR	LR, [SP, #0]
; pipe end address is: 0 (R0)
; pipe start address is: 0 (R0)
;Blep.c,210 :: 		p_aci_cmd_params_open_remote_pipe.pipe_number = pipe;
MOVW	R1, #lo_addr(_p_aci_cmd_params_open_remote_pipe+0)
MOVT	R1, #hi_addr(_p_aci_cmd_params_open_remote_pipe+0)
STRB	R0, [R1, #0]
; pipe end address is: 0 (R0)
;Blep.c,211 :: 		acil_encode_cmd_open_remote_pipe(writeBuff, &p_aci_cmd_params_open_remote_pipe);
MOVW	R1, #lo_addr(_p_aci_cmd_params_open_remote_pipe+0)
MOVT	R1, #hi_addr(_p_aci_cmd_params_open_remote_pipe+0)
MOVW	R0, #lo_addr(_writeBuff+0)
MOVT	R0, #hi_addr(_writeBuff+0)
BL	_acil_encode_cmd_open_remote_pipe+0
;Blep.c,213 :: 		Blep_Write(writeBuff, MSG_OPEN_REMOTE_PIPE_LEN);
MOVS	R1, #2
MOVW	R0, #lo_addr(_writeBuff+0)
MOVT	R0, #hi_addr(_writeBuff+0)
BL	_Blep_Write+0
;Blep.c,214 :: 		}
L_end_Blep_OpenRemotePipe:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _Blep_OpenRemotePipe
_Blep_SendDataAck:
;Blep.c,220 :: 		void Blep_SendDataAck(uint8_t pipe) {
; pipe start address is: 0 (R0)
SUB	SP, SP, #4
STR	LR, [SP, #0]
; pipe end address is: 0 (R0)
; pipe start address is: 0 (R0)
;Blep.c,221 :: 		acil_encode_cmd_send_data_ack(writeBuff, pipe );
UXTB	R1, R0
; pipe end address is: 0 (R0)
MOVW	R0, #lo_addr(_writeBuff+0)
MOVT	R0, #hi_addr(_writeBuff+0)
BL	_acil_encode_cmd_send_data_ack+0
;Blep.c,222 :: 		Blep_Write(writeBuff, MSG_ACK_LEN);
MOVS	R1, #2
MOVW	R0, #lo_addr(_writeBuff+0)
MOVT	R0, #hi_addr(_writeBuff+0)
BL	_Blep_Write+0
;Blep.c,223 :: 		}
L_end_Blep_SendDataAck:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _Blep_SendDataAck
_Blep_GetTemp:
;Blep.c,229 :: 		void Blep_GetTemp() {
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Blep.c,230 :: 		acil_encode_cmd_temparature(writeBuff);
MOVW	R0, #lo_addr(_writeBuff+0)
MOVT	R0, #hi_addr(_writeBuff+0)
BL	_acil_encode_cmd_temparature+0
;Blep.c,231 :: 		Blep_Write(writeBuff, 1);
MOVS	R1, #1
MOVW	R0, #lo_addr(_writeBuff+0)
MOVT	R0, #hi_addr(_writeBuff+0)
BL	_Blep_Write+0
;Blep.c,232 :: 		}
L_end_Blep_GetTemp:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _Blep_GetTemp
_Blep_DecodeTemp:
;Blep.c,239 :: 		char Blep_DecodeTemp() {
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Blep.c,241 :: 		Blep_GetTemp();
BL	_Blep_GetTemp+0
;Blep.c,242 :: 		Blep_WaitForEvent(ACI_EVT_CMD_RSP);
MOVS	R0, #132
BL	_Blep_WaitForEvent+0
;Blep.c,243 :: 		tempValue = 0x8000;
MOVW	R1, #32768
MOVW	R0, #lo_addr(Blep_tempValue+0)
MOVT	R0, #hi_addr(Blep_tempValue+0)
STRH	R1, [R0, #0]
;Blep.c,245 :: 		if(p_aci_evt.params.cmd_rsp.cmd_opcode == ACI_CMD_GET_TEMPERATURE) {
MOVW	R0, #lo_addr(_p_aci_evt+4)
MOVT	R0, #hi_addr(_p_aci_evt+4)
LDRB	R0, [R0, #0]
CMP	R0, #12
IT	NE
BNE	L_Blep_DecodeTemp26
;Blep.c,246 :: 		if(p_aci_evt.params.cmd_rsp.cmd_status == 0) {
MOVW	R0, #lo_addr(_p_aci_evt+5)
MOVT	R0, #hi_addr(_p_aci_evt+5)
LDRB	R0, [R0, #0]
CMP	R0, #0
IT	NE
BNE	L_Blep_DecodeTemp27
;Blep.c,247 :: 		tempValue = (p_aci_evt.params.cmd_rsp.params.get_temperature.temperature_value) >> 2;
MOVW	R0, #lo_addr(_p_aci_evt+8)
MOVT	R0, #hi_addr(_p_aci_evt+8)
LDRSH	R0, [R0, #0]
ASRS	R1, R0, #2
MOVW	R0, #lo_addr(Blep_tempValue+0)
MOVT	R0, #hi_addr(Blep_tempValue+0)
STRH	R1, [R0, #0]
;Blep.c,248 :: 		}
L_Blep_DecodeTemp27:
;Blep.c,249 :: 		}
L_Blep_DecodeTemp26:
;Blep.c,250 :: 		return (char)tempValue;
MOVW	R0, #lo_addr(Blep_tempValue+0)
MOVT	R0, #hi_addr(Blep_tempValue+0)
LDRB	R0, [R0, #0]
;Blep.c,251 :: 		}
L_end_Blep_DecodeTemp:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _Blep_DecodeTemp
_Blep_SetLocalData:
;Blep.c,259 :: 		void Blep_SetLocalData(char *dat, char len, char pipe) {
; pipe start address is: 8 (R2)
; dat start address is: 0 (R0)
SUB	SP, SP, #8
STR	LR, [SP, #0]
STRB	R1, [SP, #4]
; pipe end address is: 8 (R2)
; dat end address is: 0 (R0)
; dat start address is: 0 (R0)
; pipe start address is: 8 (R2)
;Blep.c,260 :: 		p_aci_cmd_params_set_local_data.tx_data.pipe_number = pipe;
MOVW	R3, #lo_addr(_p_aci_cmd_params_set_local_data+0)
MOVT	R3, #hi_addr(_p_aci_cmd_params_set_local_data+0)
STRB	R2, [R3, #0]
; pipe end address is: 8 (R2)
;Blep.c,261 :: 		memcpy(p_aci_cmd_params_set_local_data.tx_data.aci_data, dat, len);
LDRB	R2, [SP, #4]
MOV	R1, R0
; dat end address is: 0 (R0)
MOVW	R0, #lo_addr(_p_aci_cmd_params_set_local_data+1)
MOVT	R0, #hi_addr(_p_aci_cmd_params_set_local_data+1)
BL	_memcpy+0
;Blep.c,262 :: 		acil_encode_cmd_set_local_data(writeBuff, &p_aci_cmd_params_set_local_data, len);
LDRB	R2, [SP, #4]
MOVW	R1, #lo_addr(_p_aci_cmd_params_set_local_data+0)
MOVT	R1, #hi_addr(_p_aci_cmd_params_set_local_data+0)
MOVW	R0, #lo_addr(_writeBuff+0)
MOVT	R0, #hi_addr(_writeBuff+0)
BL	_acil_encode_cmd_set_local_data+0
;Blep.c,263 :: 		Blep_Write(writeBuff, MSG_SET_LOCAL_DATA_BASE_LEN + len);
LDRB	R3, [SP, #4]
ADDS	R3, R3, #2
UXTH	R1, R3
MOVW	R0, #lo_addr(_writeBuff+0)
MOVT	R0, #hi_addr(_writeBuff+0)
BL	_Blep_Write+0
;Blep.c,264 :: 		}
L_end_Blep_SetLocalData:
LDR	LR, [SP, #0]
ADD	SP, SP, #8
BX	LR
; end of _Blep_SetLocalData
_Blep_TestModeState:
;Blep.c,271 :: 		void Blep_TestModeState(char state) {
; state start address is: 0 (R0)
SUB	SP, SP, #4
STR	LR, [SP, #0]
; state end address is: 0 (R0)
; state start address is: 0 (R0)
;Blep.c,272 :: 		p_aci_cmd_params_test.test_mode_change = state;
MOVW	R1, #lo_addr(_p_aci_cmd_params_test+0)
MOVT	R1, #hi_addr(_p_aci_cmd_params_test+0)
STRB	R0, [R1, #0]
; state end address is: 0 (R0)
;Blep.c,273 :: 		acil_encode_cmd_set_test_mode(writeBuff, &p_aci_cmd_params_test);
MOVW	R1, #lo_addr(_p_aci_cmd_params_test+0)
MOVT	R1, #hi_addr(_p_aci_cmd_params_test+0)
MOVW	R0, #lo_addr(_writeBuff+0)
MOVT	R0, #hi_addr(_writeBuff+0)
BL	_acil_encode_cmd_set_test_mode+0
;Blep.c,274 :: 		Blep_Write(writeBuff, 2);
MOVS	R1, #2
MOVW	R0, #lo_addr(_writeBuff+0)
MOVT	R0, #hi_addr(_writeBuff+0)
BL	_Blep_Write+0
;Blep.c,275 :: 		}
L_end_Blep_TestModeState:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _Blep_TestModeState
_Blep_Setup:
;Blep.c,282 :: 		void Blep_Setup() {
SUB	SP, SP, #8
STR	LR, [SP, #0]
;Blep.c,285 :: 		char numOfMsg = 0;
MOVS	R0, #0
STRB	R0, [SP, #4]
;Blep.c,287 :: 		Blep_WaitForEvent(ACI_EVT_DEVICE_STARTED);
MOVS	R0, #129
BL	_Blep_WaitForEvent+0
;Blep.c,289 :: 		Delay_ms(200);
MOVW	R7, #9043
MOVT	R7, #8
NOP
NOP
L_Blep_Setup28:
SUBS	R7, R7, #1
BNE	L_Blep_Setup28
NOP
NOP
NOP
NOP
;Blep.c,291 :: 		while(numOfMsg < NB_SETUP_MESSAGES)
L_Blep_Setup30:
LDRB	R0, [SP, #4]
CMP	R0, #42
IT	CS
BCS	L_Blep_Setup31
;Blep.c,293 :: 		reqLen = setupMsg[numOfMsg].buffer[0];
LDRB	R1, [SP, #4]
MOVS	R0, #33
MULS	R1, R0, R1
MOVW	R0, #lo_addr(_setupMsg+0)
MOVT	R0, #hi_addr(_setupMsg+0)
ADDS	R0, R0, R1
ADDS	R0, R0, #1
;Blep.c,294 :: 		Blep_Write(setupMsg[numOfMsg].buffer, reqLen);
LDRB	R1, [R0, #0]
BL	_Blep_Write+0
;Blep.c,295 :: 		Blep_Read();
BL	_Blep_Read+0
;Blep.c,296 :: 		numOfMsg++;
LDRB	R0, [SP, #4]
ADDS	R0, R0, #1
STRB	R0, [SP, #4]
;Blep.c,297 :: 		}
IT	AL
BAL	L_Blep_Setup30
L_Blep_Setup31:
;Blep.c,299 :: 		Blep_WaitForEvent(ACI_EVT_DEVICE_STARTED);
MOVS	R0, #129
BL	_Blep_WaitForEvent+0
;Blep.c,301 :: 		}
L_end_Blep_Setup:
LDR	LR, [SP, #0]
ADD	SP, SP, #8
BX	LR
; end of _Blep_Setup
