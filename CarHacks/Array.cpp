/*------------------------------------------------------------------------------
  Name: Array.cpp

  Author: B. Kumar
  Date: 2018-12-17
  Description: Contains functions for comparing two arrays as well as
  setting an array equal to another array
------------------------------------------------------------------------------*/

#include <SPI.h>
#include "Array.h"


/*******************************************************************************
** Function name:           SetEqual
** Descriptions:            Public function, sets 2 arrays equal to each other
*******************************************************************************/
void SetEqual(unsigned char OriginalArray[],
              unsigned char NewArray[], 
              unsigned char ArrayLen)
{
  for(byte i = 0; i<ArrayLen; i++)
  {
    NewArray[i] = OriginalArray[i];
  }
}


/*******************************************************************************
** Function name:           Is Equal
** Descriptions:            Public function, returns 1 if 2 arrays are equal
*                           to each other, returns 0 if not
*******************************************************************************/
unsigned char IsEqual(unsigned char Array1[],
                      const unsigned char Array2[],
                      unsigned char ArrayLen)
{
  for(byte i = 0; i<ArrayLen; i++)
  {
    if(Array1[i] != Array2[i])
    {
      return 0;
    }
  }
  return 1;
}
