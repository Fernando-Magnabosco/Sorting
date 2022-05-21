#include "../hdr/array_utilities.h"

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

int main(int argc, char const *argv[])
{

    int array[SIZE];
    fillArrayRandomly(array);

    printf("%.0lfms\n", timeElapsed(selection, array));
    printf("%d\n", isSorted(array));

    return 0;
}
