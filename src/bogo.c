#include "../hdr/array_utilities.h"

void bogo(int *array)
{

    while (!isSorted(array))
    {
        for (int i = 0; i < SIZE; i++)
        {

            swap(&array[i], &array[rand() % (SIZE)]);
        }
    }
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int *array = malloc(sizeof(int) * SIZE);
    fillArrayRandomly(array);

    printf("%.0lfms\n", timeElapsed(bogo, array));

    printArray(array);
    return 0;
}
