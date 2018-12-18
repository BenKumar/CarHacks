/*
  TXSend.cpp

  Author: B. Kumar
  2018-12-15
*/

#include "mcp2515_can.h"
#include "TXSend.h"

static byte LockData[] = LOCK_CMD;
static byte UnlockData[] = UNLOCK_CMD;
static byte WiperOnData[] = WIPER_MANUAL;
static byte WiperAutoMed[] = WIPER_AUTO_MED;
static byte ParkData[] = GEAR_SELECT_P_STATE;
static byte DriveData[] = GEAR_SELECT_D_STATE;

void ToggleLocks(void* context)
{
  static uint8_t LockState = 0;
  byte sndStat;

  switch (LockState) 
  {
    case 0:
      sndStat = mcp2515_sendMsgBuf(DOOR_LOCK_ID, EXTENDED_ID, DOOR_LOCK_LEN, LockData);
  
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
      sndStat = mcp2515_sendMsgBuf(DOOR_LOCK_ID, EXTENDED_ID, DOOR_LOCK_LEN, UnlockData);
  
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
  byte sndStat = mcp2515_sendMsgBuf(WIPER_ID, EXTENDED_ID, WIPER_LEN, WiperOnData);

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
  byte sndStat = mcp2515_sendMsgBuf(WIPER_ID, EXTENDED_ID, WIPER_LEN, WiperAutoMed);

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


void ToggleGear(void* context)
{
  static uint8_t GearState = 0;
  byte sndStat;

  switch (GearState) 
  {
    case 0:
      sndStat = mcp2515_sendMsgBuf(GEAR_SELECT_ID, EXTENDED_ID, GEAR_SELECT_LEN, ParkData);
  
      if(sndStat == CAN_OK)
      {
        Serial.println("Gear Park: Message Sent Successfully!");
      } 
      else if (sndStat == CAN_GETTXBFTIMEOUT) 
      {
        Serial.println("Gear Park: Get TX Buffer Timeout");
      }
      else if (sndStat == CAN_SENDMSGTIMEOUT) 
      {
        Serial.println("Gear Park: Can Send Message Timeout");
      }
      else 
      {
        Serial.println("Gear Park: Error sending message");
      }

      GearState = 1;
      break;
    case 1:
      sndStat = mcp2515_sendMsgBuf(GEAR_SELECT_ID, EXTENDED_ID, GEAR_SELECT_LEN, DriveData);
  
      if(sndStat == CAN_OK)
      {
        Serial.println("Gear Drive: Message Sent Successfully!");
      } 
      else if (sndStat == CAN_GETTXBFTIMEOUT) 
      {
        Serial.println("Gear Drive: Get TX Buffer Timeout");
      }
      else if (sndStat == CAN_SENDMSGTIMEOUT) 
      {
        Serial.println("Gear Drive: Can Send Message Timeout");
      }
      else 
      {
        Serial.println("Gear Drive: Error sending message");
      }

      GearState = 0;
      break;
  }
}
