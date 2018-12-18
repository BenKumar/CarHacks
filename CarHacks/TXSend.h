/*
  TXSend.h

  Author: B. Kumar
  2018-12-15
*/

#ifndef TX_Send_h
#define TX_Send_h

#include "CanFrames.h"

#define EXTENDED_ID 1
#define STANDARD_ID 0

void ToggleLocks(void* context);
void WipersOn(void* context);
void DimLights(void* context);
void WiperAutoMedOn(void* context);
void ToggleGear(void* context);

#endif
