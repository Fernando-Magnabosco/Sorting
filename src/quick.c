#include "../hdr/algorithms.h"

// OTIMIZATIONS:

#define RANDOM_PIVOT                          \
    int rvalue = rand() % (high - low) + low; \
    swap(&array[rvalue], &array[high - 1]);

#define SWITCH_TO_HEAP(l, h) \
    else _heap(array, l, h);

#define SWITCH_TO_INSERTION           \
    if (high - low < 18)              \
    {                                 \
        _insertion(array, low, high); \
        return;                       \
    }

int quick_sub_routine(int *array, int low, int high)
{

    RANDOM_PIVOT; // comment this line for deterministic pivot

    int pivot = high - 1;

    int i = low;
    int j = high - 2;

    while (j >= i)
    {
        while (array[i] < array[pivot])
            i++;
        while (array[j] > array[pivot])
            j--;

        if (i <= j)
        {
            swap(&array[i], &array[j]);
            i++;
            j--;
        }
    }

    swap(&array[i], &array[pivot]);
    return i;
}

void _quick(int *array, int low, int high)
{

    SWITCH_TO_INSERTION; // comment this line to disable selection optimization

    int pivot = quick_sub_routine(array, low, high);

    if (pivot > low)
        _quick(array, low, pivot);
    SWITCH_TO_HEAP(low, pivot); // comment this line to disable heap optimization

    if (high > pivot + 1)
        _quick(array, pivot + 1, high);
    SWITCH_TO_HEAP(pivot + 1, high); // comment this line to disable heap optimization
}

void quick(int *array)
{
    _quick(array, 0, SIZE);
}