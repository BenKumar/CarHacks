#include <SPI.h>
#include "mcp2515_can.h"
#include "timer.h"
#include "RXRead.h"
#include "TXSend.h"
#include "CanFrames.h"

#define CAN0_INT 2    // Set interrupt to pin 2

Timer t;

void setup()
{
  Serial.begin(38400);

  // Initialize MCP2515 running at 16MHz with a baudrate of 33.3kb/s 
  // and the masks and filters enabled.
  if(mcp2515_begin(MCP_STDEXT, CAN_33K3BPS, MCP_16MHZ, (MCP_RX1IF | MCP_RX0IF), 10) == CAN_OK) 
  {
    Serial.println("MCP2515 Initialized Successfully!");
  }
  else 
  {
    Serial.println("Error Initializing MCP2515...");
  }

  // Change to normal mode to allow messages to be transmitted
  mcp2515_setMode(MCP_NORMAL); 


  //Initialize masks and filters
  mcp2515_init_Mask(0, 1, ALL_BITS);
  mcp2515_init_Mask(1, 1, ALL_BITS);

  mcp2515_init_Filt(0, 1, GEAR_SELECT);
  mcp2515_init_Filt(1, 1, GEAR_SELECT);
  mcp2515_init_Filt(2, 1, GEAR_SELECT);
  delay(1);
  mcp2515_init_Filt(3, 1, GEAR_SELECT);
  mcp2515_init_Filt(4, 1, GEAR_SELECT);
  mcp2515_init_Filt(5, 1, GEAR_SELECT);

  // Configure pin for input
  pinMode(CAN0_INT, INPUT);

  // Configure timer for sending message
  int event = t.every(5000, WiperAutoMedOn, (void*)2);
}

void loop()
{
  if((mcp2515_getInterrupts() & (MCP_RX1IF | MCP_RX0IF)) != 0)    // If there is data loaded onto RX buffers
  {
     ReadRXBuffer();
  }
  t.update();
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
