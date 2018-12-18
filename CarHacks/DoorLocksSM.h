/*------------------------------------------------------------------------------
  Name: DoorLocksSM.h

  Author: B. Kumar
  Date: 2018-12-17
  Description: State machine for door locks. Locks doors if gear select is in 
  drive and unlocks doors if gear select moves into park
------------------------------------------------------------------------------*/

#ifndef DOOR_LOCKS_SM_H
#define DOOR_LOCKS_SM_H

#include "CheckEvents.h"

typedef enum
{
  Locked = 0,
  Unlocked
}DoorLocksState;

void RunDoorLocksSM( EventType Event );

#endif
