/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of converting int
 * to string and vica versa via function calls itoa and atoi. 
 *
 * @author Nail Ismagilov
 * @date June 20 2021
 *
 */

#ifndef __DATA_H__
#define __DATA_H__

#include "stdint.h"


uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief <The function converts integer values to string>
 *
 * the functiion converts given integer data to string and returns
 * length of the converted data. At the end of the string a null 
 * terminator is added
 *
 * @param data signed 32-bit integer value, 
 * @param *ptr unsigned 8-bit integer pointer, to store converted char values
 * @param base unsigned 32-bit integer value, determins the base of given data
 *
 * @return i - length of the converted data including negative sign
 */

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

/**
 * @brief <The function prints array and statistic>
 *
 * the function converts ASCII to integer. All operations are performed
 * using pointer arithmetic. The function able to support bases 2 to 16
 *
 *
 *
 * @param ptr the character string to convert
 * @param digits the number of digits in the character set
 * @param base characters should be converted to
 *
 * @return sum  converted signed integer
 */

#endif

