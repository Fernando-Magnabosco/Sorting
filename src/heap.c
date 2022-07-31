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

void _heap(int *array, int low, int high)
{

	int *aux = array + low;
	int n = high - low;

	for (int i = (n / 2 - 1); i >= 0; i--)
		heapify(aux, i, n);

	for (int i = n - 1; i >= 1; i--)
	{
		swap(&aux[0], &aux[i]);
		heapify(aux, 0, i);
	}
}

void heap(int *array)
{
	_heap(array, 0, SIZE);
}
