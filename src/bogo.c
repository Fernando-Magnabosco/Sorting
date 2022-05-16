#include "../hdr/array_utilities.h"

void bogoSort(int *array){

    while (!isSorted(array)){
        for(int i = 0; i < SIZE; i++){

            swap(&array[i], &array[rand()%(SIZE)]);
        }
    }

}



int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int *array = malloc(sizeof(int)*SIZE);
    fillArrayRandomly(array);
    time_t start, end;
    start = clock();
    bogoSort(array);
    end = clock();
    printf("%.0fms\n", (double)(end - start)*1000/CLOCKS_PER_SEC);
    printArray(array);
    return 0;
}
