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
 * @brief Implementation of statistical array analysis with optional debug print
 *
 * This file contains functions to analyze unsigned char arrays:
 * - Calculate statistics (max, min, mean, median)
 * - Sort arrays in descending order
 * - Print formatted results (only when VERBOSE is defined)
 *
 * This code was written as part of the Introduction to Embedded Systems
 * Software and Development Environments course (University of Colorado Boulder).
 *
 * @author Timofei Alekseenko
 * @date June 9, 2025 (modified)
 *
 *****************************************************************************/

#include "stats.h"
#include "platform.h"

#define SIZE (40) // Size of the Data Set

/**
 * @brief Application entry point for statistics demo
 */
void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Print original array if VERBOSE */

  PRINTF("Original array:\n");
  print_array(test, SIZE);
  
  sort_array(test, SIZE);
  PRINTF("\nSorted array:\n");
  print_array(test, SIZE);
  
  print_statistics(test, SIZE);
}

/**
 * @brief Print statistics: max, min, mean, median
 */
void print_statistics(unsigned char *data, unsigned int size) {
  PRINTF("\nStatistics:\n");
  PRINTF("Maximum: %d\n", find_maximum(data, size));
  PRINTF("Minimum: %d\n", find_minimum(data, size));
  PRINTF("Mean: %d\n", find_mean(data, size));
  PRINTF("Median: %d\n", find_median(data, size));
}

/**
 * @brief Print array elements in rows of 8 when VERBOSE is enabled
 */
void print_array(unsigned char *data, unsigned int size) {
#ifdef VERBOSE
  for (unsigned int i = 0; i < size; i++) {
    PRINTF("%3d ", data[i]);
    if ((i + 1) % 8 == 0) PRINTF("\n");
  }
#endif
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

/* Bubble sort in descending order */
void sort_array(unsigned char *data, unsigned int size) {
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

