#include "../hdr/array_utilities.h"

void countingSort(int *array){

    int max = array[0];
    for(int i = 1; i < SIZE; i++){
        if(array[i]>max) max = array[i];
    }
    int *aux = calloc(max + 1, sizeof(int));
    for(int i = 0; i < SIZE; i++){

        aux[array[i]]++;
    }
    int j = 0;
    for(int i = 0; i <= max; i++){     
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
    time_t start, end;
    start = clock();

    int array[SIZE];
    fillArrayRandomly(array);
    //printArray(array);
    countingSort(array);

    printf("%d\n", isSorted(array));
    
    end = clock();
    printf("%.0f ms\n", (double)(end - start)*1000 / CLOCKS_PER_SEC);	
    return 0;
}



