#include "../hdr/array_utilities.h"

void bubble(int *array){
    int swapped = 1;

    while(swapped){
        swapped = 0;
        
        for(int i = 0; i < SIZE - 1; i++){
            if(array[i] > array[i + 1]){
                swap(&array[i], &array[i + 1]);
                swapped = 1;
            }
        }
    }
}


int main(int argc, char const *argv[])
{
    
    int array[SIZE];
    fillArrayRandomly(array);
    time_t start, end;
    start = clock();
    bubble(array);
    end = clock();
    printf("%.0fms\n", (double)(end - start)*1000/CLOCKS_PER_SEC);
    printf("%d\n",isSorted(array));
    printArray(array);
    return 0;
}
