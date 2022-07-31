#include "./hdr/algorithms.h"

int main(int argc, char const *argv[])
{

    srand(time(NULL));

    sorting_method *method;
    int *array = malloc(SIZE * sizeof(int));

    for (int i = 0; i < 10; i++)
    {
        fillArrayRandomly(array);

        switch (i)
        {
        case 0:
            puts("selection: ");
            method = &selection;
            break;
        case 1:
            puts("bubble: ");
            method = &bubble;
            break;
        case 2:
            puts("insertion: ");
            method = &insertion;
            break;
        case 3:
            puts("quick: ");
            method = &quick;
            break;
        case 4:
            puts("heap: ");
            method = &heap;
            break;
        case 5:
            puts("merge: ");
            method = &merge;
            break;
        case 6:
            puts("merget: ");
            method = &merge_t;
            break;
        case 7:
            puts("radix_2: ");
            method = &radix_2;
            break;
        case 8:
            puts("radix_10: ");
            method = &radix_10;
            break;
        case 9:
            puts("counting: ");
            method = &counting;
            break;
        }
        printf("%.0lfms", timeElapsed(method, array));
        printf(" %d\n", isSorted(array));
        if (!isSorted(array))
            printArray(array);
    }
    return 0;
}