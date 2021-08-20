/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 ***********************************************************************
******/
/**
 * @file data.c
 * @brief converting integer to string and vica versa
 *
 * This implementation file provides converting unsigned integer
 * for base between 2 and 16 to string and convert string back to 
 * integer.
 *
 * @author Nail Ismagilov
 * @date June 20 2021
 *
 */

#include "data.h"
#include "course1.h"

/***********************************************************
 Function Definitions
***********************************************************/

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
  uint8_t j, i = 0;
  int32_t sign = data;
  /*checking for negative value*/

  if (!((2 <= base) || (16 >= base))){
    return(TEST_ERROR);
  }

  if (sign < 0){
    data = -data;
  }
  do {       /* generate digits in reverse order */ 
    i++;
    j = data % base;
    if (j <= 9)
      *ptr = (j + '0');
    else 
      *ptr = ((j-10) + 'A');
    ptr++;
  } while ((data /= base) > 0);     /* delete it */  
  /* assigning negative value */
  if (sign < 0){
    i++;
    *ptr++ = '-';
  }
  *ptr = '\0';  /* Null Terminator */
  return(i);
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
  int8_t sign = 1;
  int32_t sum = 0;
  uint32_t n = 1;
  /* only base 2 up to 16 can be proceed atoi */
  if (!((2 <= base) || (16 >= base))){
    return(TEST_ERROR);
  }


  do {
    if (*ptr == '-'){
      sign = -1;
      ptr++;
      break;
    }

    if ((*ptr <= '9') && (*ptr >= '0')){
      sum += n * (*ptr - '0');
    }
    else if ((*ptr >= 'A') && (*ptr <='F')){
      sum += n * (*ptr - 'A');
    }
    ptr++;
    n *= base;
  }while (*ptr != '\0');

  sum = sum * sign;

  return(sum);
}

