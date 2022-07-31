#include "../hdr/algorithms.h"

void bubble(int *array)
{
    int swapped = 1;
    while (swapped)
    {
        swapped = 0;

        for (int i = 0; i < SIZE - 1; i++)
            if (array[i] > array[i + 1])
            {
                swap(&array[i], &array[i + 1]);
                swapped = 1;
            }
    }
}
