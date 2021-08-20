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
 * @file memory.c
 * @brief Memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a pointer
 * used for manipulation.
 *
 * @author Nail Ismagilov
 * @date June 20 2021
 *
 */

#include <stddef.h>
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/

uint8_t *my_memmove(uint8_t *src, uint8_t *dst, size_t length){
  uint8_t *buffer = NULL;
  buffer = malloc(length * sizeof(uint8_t));
  for (int i = 0; i<length; i++){
    *(buffer+i) = *(src+i);
  }
  for (int i=0; i<length; i++){
    *(dst+i) = *(buffer+i);
  }
  free(buffer);
  return (dst);
}

uint8_t*my_memcopy(uint8_t *src, uint8_t *dst, size_t length){
    for (;length > 0; length--){
    *dst = *src;
    dst++;
    src++;
    }
  return (dst);
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
  unsigned short i;
  for (i = 0; i < length; i++){
    *src = value;
    src++;
  }
  return (src);

}

uint8_t * my_memzero(uint8_t * src, size_t length){
  my_memset(src, length, 0);
  return(src);
}

uint8_t * my_reverse(uint8_t * src, size_t length){
  uint8_t * end, *begin, temp;
  end = src + length - 1;
  begin = src;
  for (short int i = 0; i < length/2; i++){
    temp = *end;
    *end = *begin;
    *begin = temp;

    begin++;
    end--;
  }
  return(src);
}

int32_t * reserve_words(size_t length){
  int32_t *ptr;
  ptr = (int32_t *) malloc(length * sizeof(uint32_t));
  if (ptr)
    return(ptr);
  else
    return(NULL); 
}

void free_words(uint32_t* src){
  free(src);
}
