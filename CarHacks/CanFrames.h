/*------------------------------------------------------------------------------
  Name: CanFrames.h

  Author: B. Kumar
  Date: 2018-12-15
  Description: Contains defenitions for CAN frame ID's, data values, and 
  data lengths
------------------------------------------------------------------------------*/

#ifndef CAN_FRAMES_H
#define CAN_FRAMES_H

#define EXTENDED_ID             1
#define STANDARD_ID             0

#define DOOR_LOCK_ID            0x12F83130
#define DOOR_LOCK_LEN           1
#define UNLOCK_CMD              {0x28}
#define LOCK_CMD                {0x14}
#define UNLOCK_STATE            {0x08}
#define LOCK_STATE              {0x04}

#define GEAR_SELECT_ID          0x12F85150
#define GEAR_SELECT_LEN         2
#define GEAR_SELECT_P_STATE     {0x40, 0x02}
#define GEAR_SELECT_R_STATE     {0x10, 0x02}
#define GEAR_SELECT_N_STATE     {0x04, 0x02}
#define GEAR_SELECT_D_STATE     {0x01, 0x02}
#define GEAR_SELECT_D3_STATE    {0x00, 0x42}
#define GEAR_SELECT_D2_STATE    {0x00, 0x12}
#define GEAR_SELECT_D1_STATE    {0x00, 0x06}

#define WIPER_ID                0x0AF87170
#define WIPER_LEN               3
#define WIPER_OFF               {0x00, 0x00, 0x00}
#define WIPER_MANUAL            {0x02, 0x00, 0x00}
#define WIPER_AUTO_INT          {0x40, 0x00, 0x00}
#define WIPER_AUTO_MED          {0x10, 0x00, 0x00}
#define WIPER_AUTO_HI           {0x04, 0x00, 0x00}


#endif
