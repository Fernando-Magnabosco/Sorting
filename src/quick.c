#include "../hdr/algorithms.h"
#include <math.h>

// OTIMIZATIONS:

#define RANDOM_PIVOT                          \
    int rvalue = rand() % (high - low) + low; \
    swap(&array[rvalue], &array[high - 1]);

#define SWITCH_TO_HEAP           \
    if (max_depth == 0)          \
    {                            \
        _heap(array, low, high); \
        return;                  \
    }

#define SWITCH_TO_INSERTION           \
    if (high - low < 16)              \
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

void _quick(int *array, int low, int high, int max_depth)
{

    SWITCH_TO_INSERTION; // comment this line to disable selection optimization
    SWITCH_TO_HEAP;      // comment this line to disable heap optimization

    int pivot = quick_sub_routine(array, low, high);

    if (pivot > low)
        _quick(array, low, pivot, max_depth - 1);

    if (high > pivot + 1)
        _quick(array, pivot + 1, high, max_depth - 1);
}

void quick(int *array)
{

    _quick(array, 0, SIZE, (int)log2(SIZE));
}