#ifndef array_utilities_h
#define array_utilities_h

#define SIZE 1000000
#define RAND_VALUE 4096

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef void(sorting_method)(int *);

void fillArrayRandomly(int *array);
void printArray(int *array);
void fillArraySorted(int *array);
void printArray(int *array);
int isSorted(int *array);
void swap(int *a, int *b);
int biggestElement(int *array);
int nDigits(int number);
int isConsistent(int *before, int *after);
int *createCopy(int *array);

double timeElapsed(sorting_method method, int *array);

void merge_sub_routine(int *array, int start, int half, int end);

#endif