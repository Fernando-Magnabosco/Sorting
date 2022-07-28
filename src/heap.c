#include "../hdr/algorithms.h"

void heapify(int *array, int root, int n)
{

    int left = root * 2 + 1;
    int right = root * 2 + 2;

    int bigger = root;

    if (left < n && array[left] > array[root])
        bigger = left;

    if (right < n && array[right] > array[bigger])
        bigger = right;

    if (bigger != root)
    {
        swap(&array[root], &array[bigger]);
        heapify(array, bigger, n);
    }
}

void heap(int *array)
{
    for (int i = SIZE / 2 - 1; i >= 0; i--)
        heapify(array, i, SIZE);

    for (int i = SIZE - 1; i >= 1; i--)
    {
        swap(&array[0], &array[i]);
        heapify(array, 0, i);
    }
}

