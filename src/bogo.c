#include "../hdr/algorithms.h"

void bogo(int *array)
{

    while (!isSorted(array))
        for (int i = 0; i < SIZE; i++)
            swap(&array[i], &array[rand() % (SIZE)]);
}
