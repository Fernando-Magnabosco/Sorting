#include "../hdr/algorithms.h"

void merge_routine(int *array, int start, int end)
{

	if (start >= end)
		return;

	int half = (end + start) / 2;

	merge_routine(array, start, half);
	merge_routine(array, half + 1, end);

	merge_sub_routine(array, start, half, end);
}

void merge(int *array)
{

	merge_routine(array, 0, SIZE - 1);
}
