
#include "Blep.h"
#include "aci_cmds.h"
#include "aci_evts.h"
//#include "acilib_prototypes.h"
#include "Android.h"

extern char readBuff[32];
extern char writeBuff[32];

char txPipe;

static void SetIntValueToBuffer(unsigned int Value){
  //Divide to 4x4bit value
  writeBuff[0] = (char)((Value >> 12) & 0xF);  //HHHsb
  writeBuff[1] = (char)((Value >> 8) & 0xF);   //HHsb
  writeBuff[2] = (char)((Value >> 4) & 0xF);   //Hsb
  writeBuff[3] = (char)(Value & 0xF);          //Lsb
}


//Message format:
//readBuff[0] - Message Lenght
//readBuff[1] - Event
//readBuff[2] - Service Pipe No.
//readBuff[3...20] - Received data
void OnDataReceived() {

   unsigned int tmp1,tmp2,tmp3;


   if (readBuff[ANDR_CMD_POS] == 0x50) {  //read buffer[4] is cmd byte
         //Output
         tmp1 = readBuff[ANDR_CMD_POS + 1];
         GPIOD_ODR = tmp1 & 0xF;
         //Input
         tmp2 = (char)GPIOD_IDR & 0xF0;
         writeBuff[0] = (char)(tmp2 >> 4);
         writeBuff[1] = (char)(tmp2 & 0xF);
         //Adc
         tmp3 = ADC1_Get_Sample(5);
         delay_ms(20);
         writeBuff[2] = (char)((tmp3 >> 12)& 0xF); //HHHsb
         writeBuff[3] = (char)((tmp3 >> 8)& 0xF);  //HHsb
         writeBuff[4] = (char)((tmp3 >> 4) & 0xF); //Hsb
         writeBuff[5] = (char)(tmp3 & 0xF);        //Lsb
         txPipe = readBuff[2] + 1;
         Blep_SendData(&writeBuff,6,txPipe);
   }
}