#include "array_utilities.h"

void fillArrayRandomly(int *array)
{

    for (int i = 0; i < SIZE; i++)
        array[i] = rand() % RAND_VALUE;
}

void printArray(int *array)
{
    for (int i = 0; i < SIZE; i++)
        printf("%d ", array[i]);

    putchar('\n');
}

void fillArraySorted(int *array)
{

    for (int i = 0; i < SIZE; i++)
        array[i] = i;
}

int isSorted(int *array)
{
    for (int i = 1; i < SIZE; i++)
        if (array[i - 1] > array[i])
            return 0;

    return 1;
}

int biggestElement(int *array)
{
    int max = array[0];

    for (int i = 1; i < SIZE; i++)
        if (array[i] > max)
            max = array[i];

    return max;
}

// This function counts the binary digits of an unsigned int;
int nDigits(int number)
{

    int count = 0;
    while (number >> count)
        count++;
    return count;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int *createCopy(int *array)
{
    int *copy = malloc(sizeof(int) * SIZE);
    for (int i = 0; i < SIZE; i++)
        copy[i] = array[i];
    return copy;
}

int isConsistent(int *before, int *after)
{

    int count[SIZE];
    for (int i = 0; i < SIZE; i++)
        count[i] = 0;
    for (int i = 0; i < SIZE; i++)
    {
        count[before[i]]++;
        count[after[i]]--;
    }
    for (int i = 0; i < SIZE; i++)
        if (count[i] != 0)
            return 0;

    return 1;
}
