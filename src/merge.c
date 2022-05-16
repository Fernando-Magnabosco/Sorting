#include "../hdr/array_utilities.h"

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
