/*------------------------------------------------------------------------------
  Name: Array.h

  Author: B. Kumar
  Date: 2018-12-17
  Description: Contains function prototypes for comparing two arrays as well as
  setting an array equal to another array
------------------------------------------------------------------------------*/

#ifndef ARRAY_H
#define ARRAY_H


void SetEqual(unsigned char OriginalArray[], 
              unsigned char NewArray[],
              unsigned char ArrayLen);
unsigned char IsEqual(unsigned char Array1[],
                      const unsigned char Array2[],
                      unsigned char ArrayLen);

#endif
