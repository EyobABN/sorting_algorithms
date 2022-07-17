#include "sort.h"

/**
 * bubble_sort - bubble sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	int temp, swap_counter = 1;
	size_t i;

	if (array == NULL || size < 2)
		return;
	while (swap_counter != 0)
	{
		swap_counter = 0;
		for (i = 0; i < size; i++)
		{
			if (i + 1 == size)
				break;
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swap_counter++;
				print_array(array, size);
			}
		}
	}
}
