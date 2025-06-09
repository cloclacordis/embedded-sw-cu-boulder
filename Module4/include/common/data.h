/*****************************************************************************
 * @file data.h
 * @brief Integer-to-ASCII and ASCII-to-Integer conversion routines
 *
 * This code was written as part of the Introduction to Embedded Systems
 * Software and Development Environments course (University of Colorado Boulder).
 *
 * @author Timofei Alekseenko
 * @date June 9, 2025
 *
 *****************************************************************************/

#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>

/**
 * @brief Convert signed 32-bit integer to null-terminated ASCII string.
 * @param data  Value to convert
 * @param ptr   Destination buffer (must be large enough)
 * @param base  Radix (2..16)
 * @return Length of resulting string, including null terminator
 */
uint32_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Convert ASCII string to signed 32-bit integer.
 * @param ptr    Source string (null-terminated)
 * @param digits Number of characters to parse (including '\0')
 * @param base   Radix (2..16)
 * @return Converted integer
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */

