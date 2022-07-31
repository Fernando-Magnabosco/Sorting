#include "./hdr/algorithms.h"

int main(int argc, char const *argv[])
{

    srand(time(NULL));

    sorting_method *method;
    int *array = malloc(SIZE * sizeof(int));

    for (int i = 0; i < 9; i++)
    {
        fillArrayBackwards(array);

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
            puts("counting: ");
            method = &counting;
            break;
        case 3:
            puts("heap: ");
            method = &heap;
            break;
        case 4:
            puts("merge: ");
            method = &merge;
            break;
        case 5:
            puts("merget: ");
            method = &merge_t;
            break;
        case 6:
            puts("radix_2: ");
            method = &radix_2;
            break;
        case 7:
            puts("radix_10: ");
            method = &radix_10;
            break;
        case 8:
            puts("quick: ");
            method = &quick;
            break;
        }
        printf("%.0lfms", timeElapsed(quick, array));
        printf(" %d\n", isSorted(array));
        if (!isSorted(array))
            printArray(array);
    }
    return 0;
}