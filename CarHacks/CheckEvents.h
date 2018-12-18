/*------------------------------------------------------------------------------
  Name: CheckEvents.h

  Author: B. Kumar
  Date: 2018-12-17
  Description: Contains function prototypes for sampling CAN and LIN buses and 
  looking for changes of interest since the last sample
------------------------------------------------------------------------------*/

#ifndef CHECK_EVENTS_H
#define CHECK_EVENTS_H

typedef enum
{
  NO_EVENT = 0,
  GS_DRIVE,
  GS_PARK,
  DOORS_LOCKED,
  DOORS_UNLOCKED
}EventType;

EventType CheckEvents();

#endif
