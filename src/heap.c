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

	for (int i = high / 2 - 1; i >= low; i--)
		heapify(array, i, high);

	for (int i = high - 1; i >= low + 1; i--)
	{
		swap(&array[low], &array[i]);
		heapify(array, low, i);
	}
}

void heap(int *array)
{
	_heap(array, 0, SIZE);
}
