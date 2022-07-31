#include "../hdr/algorithms.h"

void _insertion(int *array, int low, int high)
{
    for (int i = low; i < high; i++)
    {
        int j = i;
        while (j > 0 && array[j - 1] > array[j])
        {
            swap(&array[j], &array[j - 1]);
            j--;
        }
    }
}

void insertion(int *array)
{
    _insertion(array, 0, SIZE);
}