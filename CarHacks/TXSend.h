/*
  TXSend.h

  Author: B. Kumar
  2018-12-15
*/

#ifndef TX_Send_h
#define TX_Send_h

#define EXTENDED_ID 1
#define STANDARD_ID 0

#define DOOR_LOCK_FRAME_ID 0x12F83130
#define UNLOCK_DATA {0x28}
#define UNLOCK_DATA_LEN 1
#define LOCK_DATA {0x14}
#define LOCK_DATA_LEN 1

#define WIPER_FRAME_ID 0x0AF87170
#define WIPER_ON {0x02, 0x00, 0x00}
#define WIPER_ON_LEN 3

#define WIPER_AUTO_FRAME_ID 0x0AF87170
#define WIPER_AUTO_INT {0x40, 0x00, 0x00}
#define WIPER_AUTO_MED {0x10, 0x00, 0x00}
#define WIPER_AUTO_HI {0x04, 0x00, 0x00}
#define WIPER_AUTO_LEN 3

#define HEADLIGHTS_ID 0x0AF87070
#define DIM_LIGHTS_DATA {0x40, 0x00}
#define DIM_LIGHTS_LEN 2

void ToggleLocks(void* context);
void WipersOn(void* context);
void DimLights(void* context);
void WiperAutoMedOn(void* context);

#endif
