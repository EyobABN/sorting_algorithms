#include "sort.h"

/**
 * selection_sort - selection sort algorithm
 * @array: the array
 * @size: the size
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int min, temp, tbs = 0;
	size_t i, j, min_index;

	if (array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		min_index = i;
		tbs = 0;
		for (j = i; j < size; j++)
		{
			if (array[j] < min)
			{
				tbs = 1;
				min = array[j];
				min_index = j;
			}
		}
		temp = array[i];
		array[i] = array[min_index];
		array[min_index] = temp;
		if (tbs)
			print_array(array, size);
	}
}
