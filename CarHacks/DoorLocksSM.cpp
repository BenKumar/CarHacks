/*------------------------------------------------------------------------------
  Name: DoorLocksSM.cpp

  Author: B. Kumar
  Date: 2018-12-17
  Description: State machine for door locks. Locks doors if gear select is in 
  drive and unlocks doors if gear select moves into park
------------------------------------------------------------------------------*/

#include <SPI.h>
#include "mcp2515_can.h"
#include "DoorLocksSM.h"
#include "CanFrames.h"

static byte LockData[] = LOCK_CMD;
static byte UnlockData[] = UNLOCK_CMD;

void RunDoorLocksSM( EventType Event )
{
  //Initialize current state to unlocked
  static DoorLocksState CurrentState = Unlocked;

  switch (CurrentState)
  {
    case Locked:
      if(Event == GS_PARK)
      {
        //Send command to unlock doors
        byte sndStat = mcp2515_sendMsgBuf(DOOR_LOCK_ID, EXTENDED_ID, DOOR_LOCK_LEN, UnlockData);

        if(sndStat == CAN_OK)
        {
          Serial.println("Door Unlock: Message Sent Successfully!");
        } 
        else if (sndStat == CAN_GETTXBFTIMEOUT) 
        {
          Serial.println("Door Unlock: Get TX Buffer Timeout");
        }
        else if (sndStat == CAN_SENDMSGTIMEOUT) 
        {
          Serial.println("Door Unlock: Can Send Message Timeout");
        }
        else 
        {
          Serial.println("Door Unlock: Error sending message");
        }
      }
      if(Event == DOORS_UNLOCKED)
      {
        CurrentState = Unlocked;
      }
      break;
    case Unlocked:
      if(Event == GS_DRIVE)
      {
        //Send command to unlock doors
        byte sndStat = mcp2515_sendMsgBuf(DOOR_LOCK_ID, EXTENDED_ID, DOOR_LOCK_LEN, LockData);

        if(sndStat == CAN_OK)
        {
          Serial.println("Door Lock: Message Sent Successfully!");
        } 
        else if (sndStat == CAN_GETTXBFTIMEOUT) 
        {
          Serial.println("Door Lock: Get TX Buffer Timeout");
        }
        else if (sndStat == CAN_SENDMSGTIMEOUT) 
        {
          Serial.println("Door Lock: Can Send Message Timeout");
        }
        else 
        {
          Serial.println("Door Lock: Error sending message");
        }
      }
      if(Event == DOORS_LOCKED)
      {
        CurrentState = Locked;
      }
      break;
  }
}
