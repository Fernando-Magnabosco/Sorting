#include "../hdr/array_utilities.h"

void bubble(int *array)
{
    int swapped = 1;

    while (swapped)
    {
        swapped = 0;

        for (int i = 0; i < SIZE - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap(&array[i], &array[i + 1]);
                swapped = 1;
            }
        }
    }
}

int main(int argc, char const *argv[])
{

    int array[SIZE];
    fillArrayRandomly(array);

    printf("%.0lfms\n", timeElapsed(bubble, array));
    printf("%d\n", isSorted(array));
    printArray(array);
    return 0;
}
