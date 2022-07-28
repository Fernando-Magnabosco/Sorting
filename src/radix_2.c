#include "../hdr/algorithms.h"

void radix_2(int *array)
{

    int digits = nDigits(biggestElement(array));
    int aux[SIZE];

    for (int i = 0; i < digits; i++)
    {

        int count[2] = {0, 0};

        for (int j = 0; j < SIZE; j++)
            count[array[j] >> i & 1]++;

        count[1] += count[0];

        for (int j = SIZE - 1; j >= 0; j--)
        {
            int digit = array[j] >> i & 1;
            count[digit]--;
            aux[count[digit]] = array[j];
        }

        for (int i = 0; i < SIZE; i++)
            array[i] = aux[i];
    }
}
