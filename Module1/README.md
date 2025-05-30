## Statistical Analysis on a Data Set (40-element `unsigned char` Array)

A simple C application to perform statistical analysis on a dataset of `unsigned char` values (0–255).

### Features

* Calculate and print **maximum**, **minimum**, **mean**, and **median** of a data array.  
* Sort the array in **descending order** (bubble sort).  
* Display the original and sorted arrays in the console.

Functions

* `print_statistics(unsigned char *data, unsigned int size)`: Prints min, max, mean, and median.  
* `print_array(unsigned char *data, unsigned int size)`: Displays array elements (8 per line).  
* `sort_array(unsigned char *data, unsigned int size)`: Sorts data from largest to smallest (bubble sort).  
* `find_maximum(unsigned char *data, unsigned int size)`: Returns maximum value.  
* `find_minimum(unsigned char *data, unsigned int size)`: Returns minimum value.  
* `find_mean(unsigned char *data, unsigned int size)`: Returns mean (rounded down).  
* `find_median(unsigned char *data, unsigned int size)`: Returns median (sorted).  

### Files

* `stats.h` — Function declarations and documentation.  
* `stats.c` — Function implementations and `main()` with test dataset.

### Build & Run

Compile and run with GCC:

```bash
gcc -Wall -Wextra stats.c -o stats
./stats
```

### Output

```
Original array:
 <prints the 40-byte array>

Sorted array:
 <prints the sorted array>

Statistics:
 Maximum: 250
 Minimum: 2
 Mean: 91
 Median: 87
```

---

This code was written as part of the *Introduction to Embedded Systems Software and Development Environments* course (Module 1) by the University of Colorado Boulder.

