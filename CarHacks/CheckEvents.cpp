/*------------------------------------------------------------------------------
  Name: CheckEvents.cpp

  Author: B. Kumar
  Date: 2018-12-17
  Description: Contains functions for sampling CAN and LIN buses and looking 
  for changes of interest since the last sample
------------------------------------------------------------------------------*/

#include <SPI.h>
#include "mcp2515_can.h"
#include "CheckEvents.h"
#include "CanFrames.h"
#include "Array.h"

/*****************************************************************************/
//Private Function Prototypes
static EventType CheckCANEvents();
static EventType CheckGearSelectEvents();
static EventType CheckDoorLockEvents();
static EventType CheckLINEvents();
/*****************************************************************************/


/*****************************************************************************/
//Module-Level Variables
static long unsigned int rxId;
static unsigned char len = 0;
static unsigned char rxBuf[8];
static char msgString[128];
/*****************************************************************************/


/*******************************************************************************
** Function name:           CheckEvents
** Descriptions:            Public function, Loops through CAN & LIN event 
*                           checkers; immediately returns if an event has been
*                           found
*******************************************************************************/
EventType CheckEvents()
{
  EventType can = CheckCANEvents();
  if (can != 0)
  {
    return can;
  }
  
  EventType lin = CheckLINEvents();
  if (lin != 0)
  {
    return lin;
  }
  
  return NO_EVENT;
}

/*******************************************************************************
** Function name:           CheckCANEvents
** Descriptions:            Private function, immediately returns if an event
*                           of interest has been found from the CAN bus
*******************************************************************************/
static EventType CheckCANEvents()
{ 
  EventType event;
  
  // If there is data loaded onto RX buffers
  if((mcp2515_getInterrupts() & (MCP_RX1IF | MCP_RX0IF)) != 0)
  {
     // Read data: len = data length, buf = data byte(s)
     mcp2515_readMsgBuf(&rxId, &len, rxBuf);
     
     sprintf(msgString, "Extended ID: 0x%.8lX  DLC: %1d  Data:", (rxId & 0x1FFFFFFF), len);
     Serial.print(msgString);
     for(byte i = 0; i<len; i++)
     {
        sprintf(msgString, " 0x%.2X", rxBuf[i]);
        Serial.print(msgString);
     }
     Serial.println();

     switch(rxId & 0x1FFFFFFF)
     {
        case GEAR_SELECT_ID:
          event = CheckGearSelectEvents();
          if(event != NO_EVENT)
          {
            return event;
          }
          break;
        case DOOR_LOCK_ID:
          event = CheckDoorLockEvents();
          if(event != NO_EVENT)
          {
            return event;
          }
          break;
     }
  }
  return NO_EVENT;
}

/*******************************************************************************
** Function name:           CheckGearSelectEvents
** Descriptions:            Private function, immediately returns if an event
*                           of interest has been found from the gear select
*                           frame
*******************************************************************************/
static EventType CheckGearSelectEvents()
{
  static const unsigned char GearSelectDState[] = GEAR_SELECT_D_STATE;
  static const unsigned char GearSelectPState[] = GEAR_SELECT_P_STATE;
  static unsigned char LastGear[GEAR_SELECT_LEN] = GEAR_SELECT_P_STATE; 
  unsigned char CurrentGear[GEAR_SELECT_LEN];

  SetEqual(rxBuf, CurrentGear, GEAR_SELECT_LEN);
          
  if( (!IsEqual(CurrentGear, LastGear, GEAR_SELECT_LEN))
      && (IsEqual(CurrentGear, GearSelectDState, GEAR_SELECT_LEN)) )
  {
    SetEqual(CurrentGear, LastGear, GEAR_SELECT_LEN);
    return GS_DRIVE;
  }

  if( (!IsEqual(CurrentGear, LastGear, GEAR_SELECT_LEN))
      && (IsEqual(CurrentGear, GearSelectPState, GEAR_SELECT_LEN)) )
  {
    SetEqual(CurrentGear, LastGear, GEAR_SELECT_LEN);
    return GS_PARK;
  }

  return NO_EVENT;
}

/*******************************************************************************
** Function name:           CheckDoorLockEvents
** Descriptions:            Private function, immediately returns if an event
*                           of interest has been found from the door lock
*                           frame
*******************************************************************************/
static EventType CheckDoorLockEvents()
{
  static const unsigned char DoorsLocked[] = LOCK_STATE;
  static const unsigned char DoorsUnlocked[] = UNLOCK_STATE;
  static unsigned char LastLockState[DOOR_LOCK_LEN] = UNLOCK_STATE;
  unsigned char CurrentLockState[DOOR_LOCK_LEN];

  SetEqual(rxBuf, CurrentLockState, DOOR_LOCK_LEN);

  if( (!IsEqual(CurrentLockState, LastLockState, DOOR_LOCK_LEN))
      && (IsEqual(CurrentLockState, DoorsLocked, DOOR_LOCK_LEN)) )
  {
    SetEqual(CurrentLockState, LastLockState, DOOR_LOCK_LEN);
    return DOORS_LOCKED;
  }

  if( (!IsEqual(CurrentLockState, LastLockState, DOOR_LOCK_LEN))
      && (IsEqual(CurrentLockState, DoorsUnlocked, DOOR_LOCK_LEN)) )
  {
    SetEqual(CurrentLockState, LastLockState, DOOR_LOCK_LEN);
    return DOORS_UNLOCKED;
  }

  return NO_EVENT;
}

/*******************************************************************************
** Function name:           CheckLINEvents
** Descriptions:            Private function, immediately returns if an event
*                           of interest has been found on the LIN bus
*******************************************************************************/
static EventType CheckLINEvents()
{
  return NO_EVENT;
}
