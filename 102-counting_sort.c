#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - counting sort algorithm
 * @array: the array
 * @size: the size
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int max, *count, *sorted_arr, i, n = (int)size;

	if (array == NULL)
		return;
	max = -1;
	for (i = 0; i < n; i++)
		if (max < array[i])
			max = array[i];

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;
	for (i = 0; i <= max; i++)
		count[i] = 0;

	for (i = 0; i < n; i++)
		count[array[i]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	sorted_arr = malloc(sizeof(int) * n);
	if (sorted_arr == NULL)
		return;
	for (i = 0; i < n; i++)
	{
		sorted_arr[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	print_array(count, max + 1);
	for (i = 0; i < n; i++)
		array[i] = sorted_arr[i];
	free(count);
	free(sorted_arr);
}
