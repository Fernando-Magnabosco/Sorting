#include "../hdr/array_utilities.h"

void mergeSort(int *array, int start, int end)
{

    if (start >= end)
        return;

    int half = (end + start) / 2;

    mergeSort(array, start, half);
    mergeSort(array, half + 1, end);

    merge(array, start, half, end);
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int array[SIZE];
    fillArrayRandomly(array);

    clock_t start = clock();

    mergeSort(array, 0, SIZE - 1);

    printf("%.0lfms\n", (double)(clock() - start) * 1000 / CLOCKS_PER_SEC);
    printf("%d\n", isSorted(array));

    return 0;
}
