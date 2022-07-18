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
	int *p, min, temp;
	size_t i, j, min_index, true_size = 0;

	if (array == NULL)
		return;
	for (p = array; p != NULL; p++)
		true_size++;
	if (size > true_size)
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
