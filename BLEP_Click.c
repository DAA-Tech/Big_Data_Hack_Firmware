/*
  Author: Ayo Adigun
  Company: DAA Technology Solutions Ltd
  Date: 25/05/2015
  Release Version: 0.1
*/
#include "Blep.h"
#include "aci_cmds.h"
#include "aci_evts.h"
#include "Android.h"
//******************************************************************************
//******************************************************************************
sbit Blep_RST    at GPIOD_ODR.B6;
sbit Blep_BONDED at GPIOD_ODR.B14;
sbit Blep_RDY    at GPIOC_IDR.B11;
sbit Blep_REQ    at GPIOD_ODR.B7;
sbit Blep_ACT    at GPIOB_IDR.B0;
sbit LED_CONN    at GPIOD_ODR.B15;
//******************************************************************************
sbit GSM_STAT      at GPIOC_IDR.B5;
sbit GSM_RST       at GPIOE_ODR.B4;
sbit GSM_CTS       at GPIOD_IDR.B2;
sbit GSM_RTS       at GPIOE_ODR.B5;
sbit GSM_PWRKEY    at GPIOB_ODR.B1;
//******************************************************************************
sbit GPS_RST    at GPIOE_ODR.B10;
//******************************************************************************
sbit LED_GRN     at GPIOD_ODR.B12;
sbit LED_ORNG    at GPIOD_ODR.B13;
sbit LED_RED     at GPIOD_ODR.B14;
//******************************************************************************
char CONN_STATE = 0;
char NEW_EVT, EVT_STATUS, EVT_OPCODE;
//******************************************************************************
char txt[768];
char txt2[1200];
char *string;
int i = 0;
unsigned short data_ready;
char lat_str[8];
char long_str[9];
unsigned short tmp, DataReady;
unsigned long ticked = 0;
unsigned int l = 0;
unsigned int cnt = 0;
//******************************************************************************
/*******************************************************************************
***********************************Functions***********************************/
void wait();
void read_gps_data();
void send_atc(const char *s);
void Open_GPRS();
void Close_GPRS();
void Send_GPS_Data(char reps);
/*******************************************************************************
***********************************interupts***********************************/
void interrupt() iv IVT_INT_USART3 ics ICS_AUTO
{
    txt[i] = UART3_Read();         // Read data and store it to txrt string
    i++;                         // Increment string index
    if (i > 768)
    {                // If index = 768,
      i = 0;
    }
}
//******************************************************************************
SysTick_interrupt() iv IVT_INT_SysTick          //systic counter interrupt service routine
{
    //l++;
    LED_ORNG = 1;
    Delay_ms(100);
    LED_ORNG = 0;
    Delay_ms(100);
}
//******************************************************************************
void Init_MCU() {
  //PORT
 // GPIO_Digital_Output(&GPIOD_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_1 | _GPIO_PINMASK_2 | _GPIO_PINMASK_3) ;
 // GPIO_Digital_Input(&GPIOD_BASE, _GPIO_PINMASK_4 | _GPIO_PINMASK_5 | _GPIO_PINMASK_6 | _GPIO_PINMASK_7);
  //CLICK
  GPIO_Digital_Input (&GPIOA_BASE, _GPIO_PINMASK_0); // configure PORTA pins as input
  GPIO_Alternate_Function_Enable(&_GPIO_MODULE_USART2_PA23);
  
  GPIO_Digital_Output(&GPIOD_ODR, _GPIO_PINMASK_6);                             // Set PD6 (RST) as digital output
  GPIO_Digital_Input(&GPIOB_IDR, _GPIO_PINMASK_0);                              // Set PB0(ACT) as digital input ChangedAA
  GPIO_Digital_Output(&GPIOD_ODR, _GPIO_PINMASK_7);                             // Set PD7 (REQ) as digital output
  GPIO_Digital_Input(&GPIOC_IDR, _GPIO_PINMASK_11);                             // Set PC11 (RDY) as digital input
  GPIO_Digital_Output(&GPIOD_BASE, _GPIO_PINMASK_15);                           // Set PA0 (CONN)
  GPIO_Digital_Output(&GPIOD_ODR, _GPIO_PINMASK_12);                            // LED GREEN
  GPIO_Digital_Output(&GPIOD_ODR, _GPIO_PINMASK_13);                            // LED ORANGE
  GPIO_Digital_Output(&GPIOD_ODR, _GPIO_PINMASK_14);                            // LED RED
  GPIO_Digital_Output(&GPIOC_IDR, _GPIO_PINMASK_5);                             // GSM_STAT
  GPIO_Digital_Output(&GPIOE_ODR, _GPIO_PINMASK_4);                             // GSM_RST
  GPIO_Digital_Output(&GPIOB_ODR, _GPIO_PINMASK_1);                             // GSM_PWRKEY
  GPIO_Digital_Output(&GPIOE_ODR, _GPIO_PINMASK_10);                             // GPS_RST

  SPI3_Init_Advanced(_SPI_FPCLK_DIV16, _SPI_MASTER | _SPI_8_BIT | _SPI_CLK_IDLE_LOW | _SPI_FIRST_CLK_EDGE_TRANSITION | _SPI_LSB_FIRST | _SPI_SS_DISABLE | _SPI_SSM_ENABLE | _SPI_SSI_1, &_GPIO_MODULE_SPI3_PB345);
  UART2_Init_Advanced(9600, _UART_8_BIT_DATA, _UART_NOPARITY, _UART_ONE_STOPBIT, &_GPIO_MODULE_USART2_PA23);
  //****************************************************************************
  UART3_Init_Advanced(9600, _UART_8_BIT_DATA, _UART_NOPARITY, _UART_ONE_STOPBIT, &_GPIO_MODULE_USART3_PB10_11);
  Delay_ms(100);
  USART3_CR1bits.RXNEIE = 1;       // enable uart rx interrupt
  NVIC_IntEnable(IVT_INT_USART3);  // enable interrupt vector
  Delay_ms(100);                        // Wait for UART module to stabilize
  //****************************************************************************
  UART6_Init_Advanced(9600, _UART_8_BIT_DATA, _UART_NOPARITY, _UART_ONE_STOPBIT, &_GPIO_MODULE_USART6_PC67 );
  Delay_ms(100);

  //****************************************************************************
  //****************************************************************************
  // SysTick Reload Value Register (0xE000E014)
  NVIC_SYSTICKRVR = 8000000;     //10ms
  // Reload value when the timer reaches 0 (value = fclock [Mhz] * desired_period [s] => 800000 = 8000000 * 0.1 => 800000 <=> 100 ms,
  //the SysTick Timer will generate an Interrupt at every 100 ms). The SysTick Timer Reload Value must be in 24 bits range.
  // SysTick Current Value Register (0xE000E018)
  NVIC_SYSTICKCVR = 0; // Set Curent Value Register
  // SysTick Control and Status Register (0xE000E010)
  NVIC_SYSTICKCSR.B0 = 1; // SysTick Timer Enable
  NVIC_SYSTICKCSR.B1 = 1; // Enable SysTick Interrupt generation
  NVIC_SYSTICKCSR.B2 = 1; // Use processor free runing clock
  //****************************************************************************
  NVIC_SetIntPriority(IVT_INT_SysTick, _NVIC_INT_PRIORITY_LVL4);
  //NVIC_SetIntPriority(IVT_INT_USART6, _NVIC_INT_PRIORITY_LVL1);
  NVIC_SetIntPriority(IVT_INT_USART3, _NVIC_INT_PRIORITY_LVL0);
  //****************************************************************************
  Blep_RST = 0;
  Blep_REQ = 1;
  Blep_RST = 1;
  Delay_ms(100);
  Blep_RST = 0;
  Delay_ms(100);
  Blep_RST = 1;
  GSM_RST = 0;

  Delay_ms(200);
  GSM_PWRKEY = 1;
  Delay_ms(2000);
  GSM_PWRKEY = 0;

  wait();
  wait();
  wait();
  wait();
  
  LED_GRN = 1;
  UART_Set_Active(&UART3_Read, &UART3_Write, &UART3_Data_Ready, &UART3_Tx_Idle); // set UART3 active
}
//******************************************************************************
void wait() {
  Delay_ms(3000);          // 3 seconds delay
}
//******************************************************************************
void read_gps_data()
{

}
//******************************************************************************
void Open_GPRS()
{
    DisableInterrupts();
    UART_Set_Active(&UART6_Read, &UART6_Write, &UART6_Data_Ready, &UART6_Tx_Idle);
    UART6_Write_Text("AT+SAPBR=3,1,Contype,GPRS\r\n");
    Delay_ms(1000);
    UART6_Write_Text("AT+SAPBR=3,1,APN,payandgo.o2.co.uk\r\n");
    Delay_ms(1000);
    UART6_Write_Text("AT+SAPBR=3,1,USER,payandgo\r\n");
    Delay_ms(1000);
    UART6_Write_Text("AT+SAPBR=3,1,PWD,password\r\n");
    Delay_ms(1000);
    UART6_Write_Text("AT+SAPBR=1,1\r\n");  //open gprs
    Delay_ms(1000);
    LED_GRN = 0;
    EnableInterrupts();
    return;
}
//******************************************************************************
void Close_GPRS()
{
    DisableInterrupts();
    UART6_Write_Text("AT+SAPBR=0,1\r\n");  //close gprs
    Delay_ms(1000);
    EnableInterrupts();
    return;
}
//******************************************************************************
void start_HTTP(char *post_data)
{
    DisableInterrupts();
    //read_gps_data();
    UART_Set_Active(&UART6_Read, &UART6_Write, &UART6_Data_Ready, &UART6_Tx_Idle);
    UART6_Write_Text("AT+HTTPINIT\r\n");
    Delay_ms(1000);
    UART6_Write_Text("AT+HTTPPARA=CID,1\r\n");
    Delay_ms(1000);
    UART6_Write_Text("AT+HTTPPARA=URL,http://requestb.in/1jpw8ja1\r\n");
    Delay_ms(1000);
    UART6_Write_Text("AT+HTTPPARA=CONTENT,text/plain\r\n");
    Delay_ms(1000);
    UART6_Write_Text("AT+HTTPDATA=1200,5000\r\n");
    Delay_ms(500);                                   
    // send command string
   // UART6_Write_Text(post_data);
      while(*post_data)
      {
        UART6_Write(*post_data++);
      }
    UART6_Write(0x0D);                             // terminate command with CR
    UART6_Write_Text("DATA From Tracker\r\n");
    UART6_Write(0x0D);
    Delay_ms(10000);
    UART6_Write_Text("AT+HTTPACTION=1\r\n");
    Delay_ms(1000);
    //LED_CONN = 1;
    EnableInterrupts();
    return;
}
//******************************************************************************
void term_HTTP()
{
    DisableInterrupts();
    LED_RED = 1;
    UART_Set_Active(&UART6_Read, &UART6_Write, &UART6_Data_Ready, &UART6_Tx_Idle);
    UART6_Write_Text("AT+HTTPTERM\r\n");
    Delay_ms(1000);
    EnableInterrupts();
    return;
}
//******************************************************************************
void Send_GPS_Data(char reps)
{
     unsigned char c;
     
     if (reps > 10)
     {
        for (c = 0; c <= reps; c++ )
         {
              Open_GPRS();
              start_HTTP(txt);
              term_HTTP();
              Delay_Ms(30000);
         }
     }
     
     else{
     
         for (c = 0; c <= reps; c++ )
         {
              Open_GPRS();
              start_HTTP(txt);
              term_HTTP();
              //LED_CONN =0;
         }
     }
    return;
}
//******************************************************************************
void main() 
{
  Init_MCU();
  Delay_ms(200);
  Blep_Setup();
  LED_CONN = 0;
  Blep_Bond(0xB4, 0x20);
  delay_ms(2000);


  
  while (1)
     {
        NEW_EVT = Blep_EventCode();                                               //Wait for new event
        EVT_STATUS = Blep_EventStatus();                                         //Event Status
        EVT_OPCODE = Blep_EventOpcode();                                         //Event Opcode

          switch(NEW_EVT)
          {
              case ACI_EVT_HW_ERROR:
                //DebugInfoEvent returns hardware error debug information
                //This event is sent from nRF8001 to the external application
                //controller to provide debug information. In case of firmware
                //failure this event follows the DeviceStartedEvent.
                if (CONN_STATE) {
                  delay_ms(20);
                }
                break;
              case ACI_EVT_CMD_RSP:
                //CommandResponseEvent confirms reception or execution of an ACI command.
                if (EVT_STATUS > 0x03) { //error
                 Blep_Disconnect();
                 delay_ms(20);
                }
                break;
              case ACI_EVT_CONNECTED:
                CONN_STATE = 1;
                LED_CONN = CONN_STATE;
                Send_GPS_Data(24);
                break;
              case ACI_EVT_DISCONNECTED:
                CONN_STATE = 0;
                LED_CONN = CONN_STATE;
                Blep_Bond(0xB4, 0x20);
                break;
              case ACI_EVT_DATA_RECEIVED:
                 OnDataReceived();
          }

     }

}