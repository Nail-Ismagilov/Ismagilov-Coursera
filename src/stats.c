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
 * @file <stats.c>
 * @brief <array sorting program providing statistic of the array>
 *
 * The programm gets as input an array with size 40 char objects and sorts it. 
 * Finds minimum and maximum of the array, finds median and mean value.
 * In the end programm prints both the observed data and sorted array. 
 *
 * @author <Nail Ismagilov>
 * @date <June 2021>
 *
 */



#include <stdio.h>
#include "stats.h"
#include "platform.h"

#define SIZE (40) 	// size of dataset


void print_statistic(unsigned char * array, int size){

  /* print statististic */
  PRINTF("\n\nMinimum value of set of numbers: %d\n", find_minimum(array,size));
  print_array(array,size);
  PRINTF("\nThe maximum value of the given array: %d\n", find_maximum(array,size));
  PRINTF("\nThe mean value of the set: %f\n", find_mean(array, size));
  PRINTF("\nThe median value of the set: %f\n\n", find_median(array, size));
  sort_array(array,size);
  PRINTF("\nThe sorted array is:\n ");
  print_array(array,size);
}


void print_array(unsigned char * numbers, int size){
#ifdef VERBOSE
  int column = 1;
  PRINTF( "\n\nArray:\n");

  for (int i = 0; i < size; i++){ 
    if (column < 8)
      PRINTF("%d\t ", *numbers);
    else{
      PRINTF("%d\n", *numbers);
      column = 0;
    }
    column++;
    numbers++;
  }
#endif

}


int find_minimum(unsigned char * numbers, int counts){

  int min = *numbers;

  for (int i = 0; i < counts; i++){
    if (min > *numbers)
      min = *numbers;
    numbers++;
  }
  return (min);
}


int find_maximum(unsigned char * numbers, int counts){

  int max = *numbers;

  for (int i = 0; i < counts; i++){
    if (max < *numbers){
      max = *numbers;
    }
    numbers++;
  }
  return max;
}


float find_mean(unsigned char * numbers, int counts){

  float average = 0, mean;

  for(int i = 0; i < counts; i++){
    average += *numbers;
    numbers++;
  }
  mean = average/counts;
  return mean;
}

float find_median(unsigned char * numbers, int counts){
  
  float median, a, b;
  if (counts % 2 == 0){
      a = *(numbers + counts / 2);
      b = *(numbers + counts / 2 - 1);
      median = (a + b) / 2;
  }    
  else
      median = *(numbers + counts / 2);	  
  return median;

}

void sort_array(unsigned char * numbers, int counts){

  int i, j, temp;
  for (i = 0; i < counts; i++){
    for (j = i+1; j < counts; j++){
      if (*(numbers + i) < (*(numbers + j))){
        temp = *(numbers + i);
        *(numbers + i) = *(numbers + j);
        *(numbers + j) = temp;
      }
    }
  }

}

