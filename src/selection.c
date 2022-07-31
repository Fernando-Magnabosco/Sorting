#include "../hdr/algorithms.h"

void _selection(int *array, int low, int high)
{

    for (int i = low; i < high; i++)
    {
        int min = i;
        for (int j = i + 1; j < high; j++)
            if (array[min] > array[j])
                min = j;
        swap(&array[i], &array[min]);
    }
}

void selection(int *array)
{

    _selection(array, 0, SIZE);
}
