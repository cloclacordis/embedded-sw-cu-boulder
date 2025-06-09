/*****************************************************************************
 * @file main.c
 * @brief Application entry point switch for course1 demo
 *
 * Calls course1() when compiled with -DCOURSE1.
 *
 * This code was written as part of the Introduction to Embedded Systems
 * Software and Development Environments course (University of Colorado Boulder).
 *
 * @author Timofei Alekseenko
 * @date June 9, 2025
 *
 *****************************************************************************/

#include "platform.h"
#include "course1.h"

int main(void) {
#ifdef COURSE1
  course1();
#endif
  return 0;
}

