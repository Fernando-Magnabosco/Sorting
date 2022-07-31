#include "../hdr/algorithms.h"

// OTIMIZATIONS:

#define RANDOM_PIVOT                          \
    int rvalue = rand() % (high - low) + low; \
    swap(&array[rvalue], &array[high - 1]);

#define SWITCH_TO_HEAP(l, h) \
    else _heap(array, l, h);

#define SWITCH_TO_SELECTION           \
    if (high - low < 32)              \
    {                                 \
        _selection(array, low, high); \
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
        if (array[i] > array[pivot])
            swap(&array[i], &array[j--]);

        else
            i++;
    }

    swap(&array[i], &array[pivot]);
    return i;
}

void _quick(int *array, int low, int high)
{

    SWITCH_TO_SELECTION; // comment this line to disable selection optimization

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