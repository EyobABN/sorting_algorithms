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
	int min, temp;
	size_t i, j, min_index;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		min = array[i];
		min_index = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				min_index = j;
			}
		}
		temp = array[i];
		array[i] = array[min_index];
		array[min_index] = temp;
		print_array(array, size);
	}
}
