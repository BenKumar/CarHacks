/*
  mcp_can.h
  2012 Copyright (c) Seeed Technology Inc.  All right reserved.
  2017 Copyright (c) Cory J. Fowler  All Rights Reserved.

  Author:Loovee
  Contributor: Cory J. Fowler
  2017-09-25
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-
  1301  USA
*/
#ifndef _MCP2515_H_
#define _MCP2515_H_

#include "mcp2515_can_dfs.h"
#define MAX_CHAR_IN_MESSAGE 8

INT8U mcp2515_begin(INT8U idmodeset, INT8U speedset, INT8U clockset,    // Initialize controller parameters
            INT8U interruptset, INT8U _CS);                                                  
INT8U mcp2515_init_Mask(INT8U num, INT8U ext, INT32U ulData);               // Initialize Mask(s)
INT8U mcp2515_init_Mask(INT8U num, INT32U ulData);                          // Initialize Mask(s)
INT8U mcp2515_init_Filt(INT8U num, INT8U ext, INT32U ulData);               // Initialize Filter(s)
INT8U mcp2515_init_Filt(INT8U num, INT32U ulData);                          // Initialize Filter(s)
INT8U mcp2515_setMode(INT8U opMode);                                        // Set operational mode
INT8U mcp2515_sendMsgBuf(INT32U id, INT8U ext, INT8U len, INT8U *buf);      // Send message to transmit buffer
INT8U mcp2515_sendMsgBuf(INT32U id, INT8U len, INT8U *buf);                 // Send message to transmit buffer
INT8U mcp2515_readMsgBuf(INT32U *id, INT8U *ext, INT8U *len, INT8U *buf);   // Read message from receive buffer
INT8U mcp2515_readMsgBuf(INT32U *id, INT8U *len, INT8U *buf);               // Read message from receive buffer
INT8U mcp2515_checkReceive(void);                                           // Check for received data
INT8U mcp2515_checkError(void);                                             // Check for errors
INT8U mcp2515_getError(void);                                               // Check for errors
INT8U mcp2515_errorCountRX(void);                                           // Get error count
INT8U mcp2515_errorCountTX(void);                                           // Get error count
INT8U mcp2515_enOneShotTX(void);                                            // Enable one-shot transmission
INT8U mcp2515_disOneShotTX(void);                                           // Disable one-shot transmission
INT8U mcp2515_abortTX(void);                                                // Abort queued transmission(s)
INT8U mcp2515_setGPO(INT8U data);                                           // Sets GPO
INT8U mcp2515_getGPI(void);                                                 // Reads GPI
void mcp2515_resetInterrupts(void);                                         // Sets interrupt flag register to 0
INT8U mcp2515_getInterrupts(void);                                          // Returns state of interrupt flag register


#endif
/*********************************************************************************************************
 *  END FILE
 *********************************************************************************************************/
