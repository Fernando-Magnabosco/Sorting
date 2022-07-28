#include "./hdr/algorithms.h"

int main(int argc, char const *argv[])
{

    srand(time(NULL));
    int *array = malloc(SIZE * sizeof(int));
    fillArrayRandomly(array);

    printf("%.0lfms\n", timeElapsed(bubble, array));
    printf("%d\n", isSorted(array));
    return 0;
}
