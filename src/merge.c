#include "../hdr/array_utilities.h"

void merge_routine(int *array, int start, int end)
{

    if (start >= end)
        return;

    int half = (end + start) / 2;

    merge_routine(array, start, half);
    merge_routine(array, half + 1, end);

    merge(array, start, half, end);
}

void mergeSort(int *array)
{

    merge_routine(array, 0, SIZE - 1);
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int array[SIZE];

    fillArrayRandomly(array);

    printf("%.0lfms\n", timeElapsed(mergeSort, array));
    printf("%d\n", isSorted(array));

    return 0;
}
