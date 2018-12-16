/*
  TXSend.cpp

  Author: B. Kumar
  2018-12-15
*/

#include "mcp2515_can.h"
#include "TXSend.h"

static byte LockData[] = LOCK_DATA;
static byte UnlockData[] = UNLOCK_DATA;
static byte WiperOnData[] = WIPER_ON;
static byte WiperAutoMed[] = WIPER_AUTO_MED;
static byte DimLightsData[] = DIM_LIGHTS_DATA;

void ToggleLocks(void* context)
{
  static uint8_t LockState = 0;
  byte sndStat;

  switch (LockState) 
  {
    case 0:
      sndStat = mcp2515_sendMsgBuf(DOOR_LOCK_FRAME_ID, EXTENDED_ID, LOCK_DATA_LEN, LockData);
  
      if(sndStat == CAN_OK)
      {
        Serial.println("Message Sent Successfully!");
      } 
      else if (sndStat == CAN_GETTXBFTIMEOUT) 
      {
        Serial.println("Get TX Buffer Timeout");
      }
      else if (sndStat == CAN_SENDMSGTIMEOUT) 
      {
        Serial.println("Can Send Message Timeout");
      }
      else 
      {
        Serial.println("Error sending message");
      }

      LockState = 1;
      break;
    case 1:
      sndStat = mcp2515_sendMsgBuf(DOOR_LOCK_FRAME_ID, EXTENDED_ID, UNLOCK_DATA_LEN, UnlockData);
  
      if(sndStat == CAN_OK)
      {
        Serial.println("Message Sent Successfully!");
      } 
      else if (sndStat == CAN_GETTXBFTIMEOUT) 
      {
        Serial.println("Get TX Buffer Timeout");
      }
      else if (sndStat == CAN_SENDMSGTIMEOUT) 
      {
        Serial.println("Can Send Message Timeout");
      }
      else 
      {
        Serial.println("Error sending message");
      }

      LockState = 0;
      break;
  }
}

void WipersOn(void* context)
{
  byte sndStat = mcp2515_sendMsgBuf(WIPER_FRAME_ID, EXTENDED_ID, WIPER_ON_LEN, WiperOnData);

  if(sndStat == CAN_OK)
  {
    Serial.println("Message Sent Successfully!");
  } 
  else if (sndStat == CAN_GETTXBFTIMEOUT) 
  {
    Serial.println("Get TX Buffer Timeout");
  }
  else if (sndStat == CAN_SENDMSGTIMEOUT) 
  {
    Serial.println("Can Send Message Timeout");
  }
  else 
  {
    Serial.println("Error sending message");
  }
}

void DimLights(void* context)
{
  byte sndStat = mcp2515_sendMsgBuf(HEADLIGHTS_ID, EXTENDED_ID, DIM_LIGHTS_LEN, DimLightsData);

  if(sndStat == CAN_OK)
  {
    Serial.println("Message Sent Successfully!");
  } 
  else if (sndStat == CAN_GETTXBFTIMEOUT) 
  {
    Serial.println("Get TX Buffer Timeout");
  }
  else if (sndStat == CAN_SENDMSGTIMEOUT) 
  {
    Serial.println("Can Send Message Timeout");
  }
  else 
  {
    Serial.println("Error sending message");
  }
}

void WiperAutoMedOn(void* context)
{
  byte sndStat = mcp2515_sendMsgBuf(WIPER_AUTO_FRAME_ID, EXTENDED_ID, WIPER_AUTO_LEN, WiperAutoMed);

  if(sndStat == CAN_OK)
  {
    Serial.println("Message Sent Successfully!");
  } 
  else if (sndStat == CAN_GETTXBFTIMEOUT) 
  {
    Serial.println("Get TX Buffer Timeout");
  }
  else if (sndStat == CAN_SENDMSGTIMEOUT) 
  {
    Serial.println("Can Send Message Timeout");
  }
  else 
  {
    Serial.println("Error sending message");
  }
}
