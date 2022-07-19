#include "sort.h"

/**
 * partition - partitions an array
 * @arr: the array
 * @low: the low
 * @high: the high
 * @size: the size
 *
 * Return: i
 */
int partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = low - 1, j, temp;

	for (j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	print_array(arr, size);
	return (i + 1);
}

/**
 * quickSort - Lomuto's quicksort
 * @array: the array
 * @low: the low
 * @high: the high
 * @size: the size
 *
 * Return: void
 */
void quickSort(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);

		quickSort(array, low, pi - 1, size);
		quickSort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Lomuto's quicksort
 * @array: the array
 * @size: the size
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;

	quickSort(array, 0, ((int)size) - 1, size);
}
