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
 * @file <stats.h> 
 * @brief <a header file for stats.c programm>
 *
 * The header declares functions are used in stats.c and comtains their
 * description
 *
 * @author <Nail Ismagilov>
 * @date <June 2021>
 *
 */

#ifndef __STATS_H__
#define __STATS_H__


void print_statistic(unsigned char *, int);

/**
 * @brief <The function prints array and statistic>
 *
 * the function calls other functions to find  
 * max, min, median and mean values and prins the 
 * obtained values
 * 
 *
 * @param minimum integer value calls function to find minimum value
 * @param maximum integer value calls function, that finds max value
 * @param mean integer value calls function, that finds mean  value
 * @param median integer value calls function, that finds mean value
 *
 * @return NULL
 */
void print_array(unsigned char *, int);
/**
 * @brief prints a given unsigned char array with a defined size
 * The function prints array if there is a VERBOSE compiler switch is defied.
* otherwise, makes nothing
 * This function takes as input an unsigned char array and integer size, 
 * the length if the array, prints it in 4 lines with 8 columns each. For 
 * loop usese to read and print the content of unsigned char array.
 *
 * @param column The column counter wchich is reset to zero when
 *               reaches 8
 * @param i The integer number used in for loop as a condition value 
 *          to read the array
 *
 * @return NULL
 */

int find_minimum(unsigned char *, int);
/**
 * @brief Finds a minimum value of unsigned char array
 *
 * The function takes as an input unsigned char array with integer size.
 * First it declares the first value of the array as a minimum value and
 * compare it to other values of the array. If the value located in min 
 * is greater than compared array value, then the compared value is 
 * declared as a minimum value. No else statement.
 *
 * @param min minimum value of the array
 * @param i the integer counter of the for loop
 *
 * @return Minimum integer value of the array
 */

int find_maximum(unsigned char *, int);
/**
 * @brief The function finds a maximum value of the array
 * 
 * The function takes as an input unsigned char array with integer size.
 * First it declares the first value of the array as a maximum value and
 * compare it to other values of the array. If the value located in max 
 * is less than compared array value, then the compared value is 
 * declared as a maximum value. No else statement.
 *
 *
 * @param max The maximum value of the array
 * @param i the integer value of the for loop
 *
 * @return The maximum value of the  array
 */

float find_mean(unsigned char *, int);
/**
 * @brief Find a mean value of the array
 *
 * The function takes as an input unsigned char array with integer size.
 * First it finds a sum of all elemnts of the array then divides the sum
 * to size of the array
 *
 * @param average The sum of thr all element of the array, float number.
 * @param mean The float mean value of the array
 * @param i the integer value of the for loop
 *
 * @return The float mean value of the array
 */

float find_median(unsigned char *, int);
/**
 * @brief Find a median value of the array
 *
 * The function takes as an input unsigned char array with integer size.
 * If the array consists of even number of values, the median values is
 * equal to arithmetic mean of the two middle values, else the median value
 * is the middle value of the dataset. 
 *
 * @param median The median value of the array
 * @param a Integer first middle value of the even number of dataset
 * @param b Integer second middle element of the even array
 *
 * @return The median value of the array
 */

void sort_array(unsigned char *, int);
/**
 * @brief sorts array from highest to lowest value
 *
 * The function takes as an input unsigned char array with integer size.
 * It compares with hlep two for loop and one if statement each element of 
 * the array to other elements and sorts it from highest value to lowest.
 *
 * @param i The integer counter value of the first for loop
 * @param j the integer counter value of the second for loop
 * @param temp The integer temporary value to swap i and j elements
 *
 * @return NULL
 */


#endif /* __STATS_H__ */
