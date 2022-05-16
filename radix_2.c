#include "array_utilities.h"

void radixSort(int *array)
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

int main(int argc, char const *argv[])
{

    srand(time(NULL));
    int *array = malloc(SIZE * sizeof(int));
    fillArrayRandomly(array);

    clock_t start = clock();
    radixSort(array);

    printf("%.0lfms\n", (double)(clock() - start) * 1000 / CLOCKS_PER_SEC);
    printf("%d\n", isSorted(array));
    return 0;
}
