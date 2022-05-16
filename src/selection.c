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

int maior(int a, int b, int c)
{

    if (a > b && a > c)
        return a;
    else if (b > a && b > c)
        return b;
    else
        return c;
}

int main(int argc, char const *argv[])
{

    int array[SIZE];
    fillArrayRandomly(array);
    selection(array);
    printf("%d\n", isSorted(array));

    return 0;
}
