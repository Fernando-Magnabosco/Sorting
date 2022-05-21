#include "../hdr/array_utilities.h"

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

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    int array[SIZE];
    fillArrayRandomly(array);

    printf("%.0lfms\n", timeElapsed(counting, array));
    printf("%d\n", isSorted(array));
    return 0;
}
