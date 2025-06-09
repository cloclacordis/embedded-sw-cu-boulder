/*****************************************************************************
 * @file data.c
 * @brief Implementation of integer-to-ASCII and ASCII-to-integer conversions
 *
 * Provides:
 *  - my_itoa : convert signed 32-bit integer to ASCII string in base 2–16
 *  - my_atoi : convert ASCII string to signed 32-bit integer in base 2–16
 *
 * Uses pointer arithmetic exclusively; no library string functions.
 *
 * This code was written as part of the Introduction to Embedded Systems
 * Software and Development Environments course (University of Colorado Boulder).
 *
 * @author Timofei Alekseenko
 * @date June 9, 2025
 *
 *****************************************************************************/

#include "data.h"
#include <stdint.h>

/**
 * @brief Convert a digit value (0–15) to its ASCII character.
 */
static uint8_t digit_to_char(uint8_t d) {
  return (d < 10) ? ('0' + d) : ('A' + (d - 10));
}

uint32_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
  uint8_t * p = ptr;
  uint32_t len = 0;
  int32_t value = data;

  /* Handle negative sign */
  if (value < 0) {
    *p++ = '-';
    value = -value;
    len++;
  }

  /* Convert digits in reverse order */
  uint8_t * start = p;
  do {
    uint8_t rem = value % base;
    *p++ = digit_to_char(rem);
    value /= base;
    len++;
  } while (value != 0);

  /* Null-terminate */
  *p++ = '\0';
  len++;

  /* Reverse the digit characters */
  uint8_t * left  = start;
  uint8_t * right = p - 2; /* before '\0' */
  while (left < right) {
    uint8_t tmp = *left;
    *left++ = *right;
    *right-- = tmp;
  }

  return len;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint8_t base) {
  int32_t result = 0;
  uint8_t * p = ptr;
  uint8_t negative = 0;

  /* Check for optional leading '-' */
  if (*p == '-') {
    negative = 1;
    p++;
  }

  /* Parse digits up to null or digits count */
  uint8_t count = 0;
  while (*p != '\0' && count < digits) {
    uint8_t c = *p++;
    uint8_t val;

    if (c >= '0' && c <= '9')       val = c - '0';
    else if (c >= 'A' && c <= 'F')  val = 10 + (c - 'A');
    else if (c >= 'a' && c <= 'f')  val = 10 + (c - 'a');
    else break;

    result = result * base + val;
    count++;
  }

  return negative ? -result : result;
}

