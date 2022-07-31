#include "../hdr/algorithms.h"

void radix_10(int *array)
{

    int max = biggestElement(array);

    int aux[SIZE];

    for (int i = 1; max / i > 0; i *= 10)
    {

        int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (int j = 0; j < SIZE; j++)
            count[(array[j] / i) % 10]++;

        for (int j = 1; j < 10; j++)
            count[j] = count[j] + count[j - 1];

        for (int j = SIZE - 1; j >= 0; j--)
        {
            int digit = (array[j] / i) % 10;
            count[digit]--;
            aux[count[digit]] = array[j];
        }

        for (int j = 0; j < SIZE; j++)
            array[j] = aux[j];
    }
}
