/*
  RXRead.cpp

  Author: B. Kumar
  2018-12-14
*/

#include "mcp2515_can.h"
#include "RXRead.h"

static long unsigned int rxId;
static unsigned char len = 0;
static unsigned char rxBuf[8];
static char msgString[128];

void ReadRXBuffer( void )
{
  mcp2515_readMsgBuf(&rxId, &len, rxBuf);      // Read data: len = data length, buf = data byte(s)
    
  if((rxId & 0x80000000) == 0x80000000)     // Determine if ID is standard (11 bits) or extended (29 bits)
    sprintf(msgString, "Extended ID: 0x%.8lX  DLC: %1d  Data:", (rxId & 0x1FFFFFFF), len);
  else
    sprintf(msgString, "Standard ID: 0x%.3lX       DLC: %1d  Data:", rxId, len);

  Serial.print(msgString);

  if((rxId & 0x40000000) == 0x40000000){    // Determine if message is a remote request frame.
    sprintf(msgString, " REMOTE REQUEST FRAME");
    Serial.print(msgString);
  } else {
    for(byte i = 0; i<len; i++){
      sprintf(msgString, " 0x%.2X", rxBuf[i]);
      Serial.print(msgString);
    }
  }
      
  Serial.println();
}
