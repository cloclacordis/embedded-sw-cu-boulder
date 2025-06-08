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
 * @file stats.h
 * @brief Header file for statistical array analysis functions
 *
 * This file contains declarations and documentation for functions that perform
 * statistical analysis on unsigned char arrays, including finding minimum,
 * maximum, mean, median values, sorting arrays, and printing results.
 *
 * This code was written as part of the Introduction to Embedded Systems
 * Software and Development Environments course (University of Colorado Boulder).
 *
 * @author Timofei Alekseenko
 * @date May 20, 2025
 *
 *****************************************************************************/

/* Include guard */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Prints statistics (min, max, mean, median) of an array
 * @param data Pointer to the data array
 * @param size Size of the array
 */
void print_statistics(unsigned char *data, unsigned int size);

/**
 * @brief Prints the array to the screen
 * @param data Pointer to the data array
 * @param size Size of the array
 */
void print_array(unsigned char *data, unsigned int size);

/**
 * @brief Finds the median of the array (rounded down)
 * @param data Pointer to the data array
 * @param size Size of the array
 * @return Median value
 */
unsigned char find_median(unsigned char *data, unsigned int size);

/**
 * @brief Finds the mean of the array (rounded down)
 * @param data Pointer to the data array
 * @param size Size of the array
 * @return Mean value
 */
unsigned char find_mean(unsigned char *data, unsigned int size);

/**
 * @brief Finds the maximum value in the array
 * @param data Pointer to the data array
 * @param size Size of the array
 * @return Maximum value
 */
unsigned char find_maximum(unsigned char *data, unsigned int size);

/**
 * @brief Finds the minimum value in the array
 * @param data Pointer to the data array
 * @param size Size of the array
 * @return Minimum value
 */
unsigned char find_minimum(unsigned char *data, unsigned int size);

/**
 * @brief Sorts the array from largest to smallest
 * @param data Pointer to the data array
 * @param size Size of the array
 */
void sort_array(unsigned char *data, unsigned int size);

#endif /* __STATS_H__ */

