#include "../hdr/algorithms.h"

void counting(int *array)
{

    int max = array[0];
    for (int i = 1; i < SIZE; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    int *aux = calloc(max + 1, sizeof(int));
    for (int i = 0; i < SIZE; i++)
    {

        aux[array[i]]++;
    }
    int j = 0;
    for (int i = 0; i <= max; i++)
    {
        while (aux[i])
        {
            array[j] = i;
            aux[i]--;
            j++;
        }
    }
}

