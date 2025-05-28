/*****************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/*****************************************************************************
 * @file stats.c 
 * @brief Implementation of statistical array analysis
 *
 * This file contains functions to analyze unsigned char arrays:
 * - Calculate statistics (min, max, mean, median)
 * - Sort arrays in descending order
 * - Print formatted results
 * All statistics are rounded down to nearest integer.
 *
 * This code was written as part of the Introduction to Embedded Systems
 * Software and Development Environments course (University of Colorado Boulder).
 *
 * @author Timofei Alekseenko
 * @date May 20, 2025
 *
 *****************************************************************************/

#include <stdio.h>
#include "stats.h"

/* ========== Size of the Data Set ========== */

#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* ========== Printing Functions ========== */

  printf("Original array:\n");
  print_array(test, SIZE);
  
  sort_array(test, SIZE);
  printf("\nSorted array:\n");
  print_array(test, SIZE);
  
  print_statistics(test, SIZE);
}

/* ========== Function Implementations ========== */

void print_statistics(unsigned char *data, unsigned int size) {
  printf("\nStatistics:\n");
  printf("Maximum: %d\n", find_maximum(data, size));
  printf("Minimum: %d\n", find_minimum(data, size));
  printf("Mean: %d\n", find_mean(data, size));
  printf("Median: %d\n", find_median(data, size));
}

void print_array(unsigned char *data, unsigned int size) {
  for (unsigned int i = 0; i < size; i++) {
    printf("%3d ", data[i]);
    if ((i + 1) % 8 == 0) printf("\n"); // 8 elements per line
  }
}

unsigned char find_median(unsigned char *data, unsigned int size) {
  sort_array(data, size); // Median requires sorting
  return data[size / 2];
}

unsigned char find_mean(unsigned char *data, unsigned int size) {
  unsigned int sum = 0;
  for (unsigned int i = 0; i < size; i++) sum += data[i];
  return (unsigned char)(sum / size); // Automatic rounding down
}

unsigned char find_maximum(unsigned char *data, unsigned int size) {
  unsigned char max = data[0];
  for (unsigned int i = 1; i < size; i++) 
    if (data[i] > max) max = data[i];
  return max;
}

unsigned char find_minimum(unsigned char *data, unsigned int size) {
  unsigned char min = data[0];
  for (unsigned int i = 1; i < size; i++) 
    if (data[i] < min) min = data[i];
  return min;
}

void sort_array(unsigned char *data, unsigned int size) {
  // Bubble sort in descending order
  for (unsigned int i = 0; i < size - 1; i++) {
    for (unsigned int j = 0; j < size - i - 1; j++) {
      if (data[j] < data[j + 1]) {
        unsigned char temp = data[j];
        data[j] = data[j + 1];
        data[j + 1] = temp;
      }
    }
  }
}

