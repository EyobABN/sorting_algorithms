#include "sort.h"

/**
 * shell_sort - shell sort Knuth algorithm
 * @array: the array
 * @size: the size
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	int gap, interval, temp, i, j, n = (int)size;

	if (array == NULL)
		return;
	gap = 1;
	while (gap < (int)size)
		gap = gap * 3 + 1;

	for (interval = gap; interval > 0; interval /= 3)
	{
		for (i = interval; i < n; i += 1)
		{
			temp = array[i];
			for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
				array[j] = array[j - interval];
			array[j] = temp;
		}
		if (interval != gap)
			print_array(array, size);
	}
}
