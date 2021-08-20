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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stdlib.h>

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief copies thesource pointer location in memory to destination 
 * pointer location in memory
 * 
 * takes two byt pointers(source and destination) and a length of 
 * bytes to copy from source to destination. First source copies to
 * a temporyrly created memory location, then to a destination. And
 * clear temporary reserved memory allocation. No data corruption.
 *
 *
 * @param src pointer to a memory location
 * @param length size in bytes
 + @param dst destination pinter to a memory location
 *
 * @return pointer to the destination (dst).
 */


uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief copies thesource pointer location in memory to destination 
 * pointer location in memory
 *
 * takes two byt pointers(source and destination) and a length of 
 * bytes to copy from source to destination. The behaviour undefined
 * if there is overlap of source and destination.Could corrupt data.
 *
 * @param src pointer to a memory location
 * @param length size in bytes
 + @param dst destination pinter to a memory location
 *
 * @return pointer to the destination (dst).
 */


uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief set given memory to a given memory area that has legth size
 *
 * Given a pointer to source memory location, a legth in bytes
 * and set all locations in that memory to a given
 *
 * @param src pointer to a memory location
 * @param length size in bytes
 + @param value a value should be set on the memory location
 *
 * @return pointer to the source.
 */


uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief zero out all of the memory location
 *
 * take a pointer to memory location, a length in bytes and zero out
 * all of the memory
 *
 * @param src pointer to memory location
 * @param legth size in bytes
 *
 * @return pointer to the source (src)
 */


uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief reverse bytes order
 *
 * Given a pointer to a unsigned integer, reverse given set data
 * that allocating in dynamic memory.
 *
 * @param src pointer to a first element of data
 * @param length number of elements
 *
 * @return pointer to the source
 */


int32_t * reserve_words(size_t length);

/**
 * @brief Clears elements in a data array
 *
 * Allocates dinamyc memory with size of length
 *
 * @param length
 *
 * @return ppointer to memory if successful, Null pointer if
 * not successful.
 */


void free_words(uint32_t * src);

/**
 * @brief Clears elements in a memory setion
 *
 * free a dynamic memory allocation by proiding the pointer src.
 *
 *
 * @param src begining of memmory allocation address
 *
 * @return void.
 */


#endif /* __MEMORY_H__ */
