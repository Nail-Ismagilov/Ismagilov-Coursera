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


#define SIZE (40) 	// size of dataset

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  print_array(test, SIZE);	// prints initial array
  sort_array(test, SIZE);	
  print_statistic(test, SIZE);  
  print_array(test, SIZE);	// prints sorted array

}


void print_statistic(unsigned char * array, int size){
  
  int minimum, maximum;
  float mean, median;
 
  /* observing of data */
  minimum = find_minimum(array, size);
  maximum = find_maximum(array, size);
  mean = find_mean(array, size);
  median = find_median(array, size);
  
  /* print statististic */
  printf("\n\nMinimum value of set of numbers: %d\n", minimum);
  printf("\nThe maximum value of the given array: %d\n", maximum);
  printf("\nThe mean value of the set: %f\n", mean);
  printf("\nThe median value of the set: %f\n\n", median);
}

void print_array(unsigned char * numbers, int size){

  int column = 1;
  printf( "\n\nArray:\n");

  for (int i = 0; i < size; i++){ 
    if (column < 8)
      printf("%d ", *numbers);
    else{
      printf("%d\n", *numbers);
      column = 0;
    }
    column++;
    numbers++;
  } 
  

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

