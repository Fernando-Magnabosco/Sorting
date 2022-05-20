#include "../hdr/array_utilities.h"

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

void merge(int *array, int start, int half, int end)
{

    int aux[end - start];

    int i = start,
        j = half + 1,
        k = 0;

    while (i <= half && j <= end)
    {
        // int *ptr = &j;
        // if (array[i] < array[j])
        //     ptr = &i;
        // aux[k] = array[*ptr];
        // (*ptr)++;

        if (array[i] < array[j])
        {
            aux[k] = array[i];
            i++;
        }
        else
        {
            aux[k] = array[j];
            j++;
        }
        k++;
    }

    while (i <= half)
    {

        aux[k] = array[i];
        i++;
        k++;
    }

    while (j <= end)
    {

        aux[k] = array[j];
        j++;
        k++;
    }

    for (int l = start; l <= end; l++)
    {

        array[l] = aux[l - start];
    }
}
