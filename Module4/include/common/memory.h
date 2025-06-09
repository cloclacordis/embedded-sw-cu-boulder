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
/*****************************************************************************
 * @file memory.h
 * @brief Abstraction of memory manipulation operations
 *
 * This header declares functions to move, copy, set, zero, reverse memory,
 * and to allocate/free word buffers dynamically.
 *
 * This code was written as part of the Introduction to Embedded Systems
 * Software and Development Environments course (University of Colorado Boulder).
 *
 * @author Timofei Alekseenko (modified)
 * @date June 9, 2025
 *
 *****************************************************************************/
 
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stddef.h>

/* ===== Existing simple operations ===== */

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/* ===== New memory-manipulation functions ===== */

/**
 * @brief Move length bytes from src to dst, safe for overlapping regions.
 * @param src Source byte pointer
 * @param dst Destination byte pointer
 * @param length Number of bytes to move
 * @return Pointer to dst
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copy length bytes from src to dst (overlap undefined).
 * @param src Source byte pointer
 * @param dst Destination byte pointer
 * @param length Number of bytes to copy
 * @return Pointer to dst
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Set length bytes at src to given value.
 * @param src Byte pointer
 * @param length Number of bytes to set
 * @param value Byte value to set
 * @return Pointer to src
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Zero out length bytes at src.
 * @param src Byte pointer
 * @param length Number of bytes to zero
 * @return Pointer to src
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverse the order of length bytes at src.
 * @param src Byte pointer
 * @param length Number of bytes to reverse
 * @return Pointer to src
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Dynamically allocate a buffer of length 32-bit words.
 * @param length Number of 32-bit words
 * @return Pointer to allocated buffer, or NULL on failure
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Free a buffer previously allocated by reserve_words.
 * @param src Pointer returned by reserve_words
 */
void free_words(uint32_t * src);

#endif /* __MEMORY_H__ */

