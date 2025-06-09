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
 * @file memory.c
 * @brief Implementation of advanced memory manipulation functions
 *
 * Provides:
 *  - set_value    : write a byte at an index
 *  - clear_value  : clear a byte at an index
 *  - get_value    : read a byte at an index
 *  - set_all      : fill a range with a value
 *  - clear_all    : zero a range
 *  - my_memmove   : safe move with overlap handling
 *  - my_memcopy   : simple copy (overlap undefined)
 *  - my_memset    : set memory to value
 *  - my_memzero   : zero out memory
 *  - my_reverse   : reverse byte order
 *  - reserve_words / free_words : dynamic allocation of 32-bit words
 *
 * This code was written as part of the Introduction to Embedded Systems
 * Software and Development Environments course (University of Colorado Boulder).
 *
 * @author Timofei Alekseenko (modified)
 * @date June 9, 2025
 *
 *****************************************************************************/
 
#include "memory.h"
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

/**
 * @brief Write a value into a memory buffer at a given index.
 * @param ptr   Pointer to start of buffer
 * @param index Byte offset to write at
 * @param value Byte value to write
 */
void set_value(char * ptr, unsigned int index, char value) {
  ptr[index] = value;
}

/**
 * @brief Clear (set to zero) a value in a memory buffer at a given index.
 * @param ptr   Pointer to start of buffer
 * @param index Byte offset to clear
 */
void clear_value(char * ptr, unsigned int index) {
  set_value(ptr, index, 0);
}

/**
 * @brief Read a value from a memory buffer at a given index.
 * @param ptr   Pointer to start of buffer
 * @param index Byte offset to read from
 * @return      Byte value read
 */
char get_value(char * ptr, unsigned int index) {
  return ptr[index];
}

/**
 * @brief Write a given value to every element of a memory buffer.
 * @param ptr   Pointer to start of buffer
 * @param value Byte value to write
 * @param size  Number of bytes to write
 */
void set_all(char * ptr, char value, unsigned int size) {
  for (unsigned int i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

/**
 * @brief Clear (set to zero) all elements of a memory buffer.
 * @param ptr  Pointer to start of buffer
 * @param size Number of bytes to clear
 */
void clear_all(char * ptr, unsigned int size) {
  set_all(ptr, 0, size);
}

/**
 * @brief Move length bytes from src to dst, safe for overlapping regions.
 * @param src    Pointer to source memory
 * @param dst    Pointer to destination memory
 * @param length Number of bytes to move
 * @return       Pointer to dst
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length) {
  if (dst < src) {
    /* Copy forward when dest is before src */
    for (size_t i = 0; i < length; i++) {
      *(dst + i) = *(src + i);
    }
  } else if (dst > src) {
    /* Copy backward when dest overlaps src end */
    for (size_t i = length; i > 0; i--) {
      *(dst + i - 1) = *(src + i - 1);
    }
  }
  return dst;
}

/**
 * @brief Copy length bytes from src to dst. Overlap undefined.
 * @param src    Pointer to source memory
 * @param dst    Pointer to destination memory
 * @param length Number of bytes to copy
 * @return       Pointer to dst
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length) {
  for (size_t i = 0; i < length; i++) {
    *(dst + i) = *(src + i);
  }
  return dst;
}

/**
 * @brief Fill length bytes at src with value.
 * @param src     Pointer to start of memory
 * @param length  Number of bytes to set
 * @param value   Value to set each byte to
 * @return        Pointer to src
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value) {
  for (size_t i = 0; i < length; i++) {
    *(src + i) = value;
  }
  return src;
}

/**
 * @brief Zero out length bytes at src.
 * @param src    Pointer to start of memory
 * @param length Number of bytes to zero
 * @return       Pointer to src
 */
uint8_t * my_memzero(uint8_t * src, size_t length) {
  for (size_t i = 0; i < length; i++) {
    *(src + i) = 0;
  }
  return src;
}

/**
 * @brief Reverse the order of length bytes at src.
 * @param src    Pointer to start of memory
 * @param length Number of bytes to reverse
 * @return       Pointer to src
 */
uint8_t * my_reverse(uint8_t * src, size_t length) {
  size_t start = 0, end = length - 1;
  while (start < end) {
    uint8_t tmp = *(src + start);
    *(src + start) = *(src + end);
    *(src + end)   = tmp;
    start++;
    end--;
  }
  return src;
}

/**
 * @brief Dynamically allocate a buffer of length 32-bit words.
 * @param length Number of 32-bit words to allocate
 * @return       Pointer to allocated buffer, or NULL if allocation fails
 */
int32_t * reserve_words(size_t length) {
  return (int32_t *) malloc(length * sizeof(int32_t));
}

/**
 * @brief Free a buffer previously allocated by reserve_words.
 * @param src Pointer returned by reserve_words
 */
void free_words(uint32_t * src) {
  free(src);
}

