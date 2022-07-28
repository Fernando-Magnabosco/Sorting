#include "../hdr/algorithms.h"

void selection(int *array)
{

    for (int i = 0; i < SIZE; i++)
    {

        int min = i;
        for (int j = i + 1; j < SIZE; j++)
        {

            if (array[min] > array[j])
                min = j;
        }
        swap(&array[i], &array[min]);
    }
}

