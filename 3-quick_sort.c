#include "sort.h"

/**
 * partition - This is a auxiliary function
 * @array: input unsorted array
 * @size: size of the array
 * @low: The lowest number in the array
 * @high: The number in the last position of the array
 * Return: Returns the next position in the array
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = 0;
	int tmp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (i != j)
				print_array(array, size);
		}
	}
	tmp = array[i + 1];
	array[i + 1] = array[j];
	array[j] = tmp;
	if (i + 1 != j)
		print_array(array, size);
	return (i + 1);
}

/**
 * quickSort - This is a auxiliary function
 * @array: input unsorted array
 * @size: size of the array
 * @low: The lowest number in the array
 * @high: The number in the last position of the array
 *
 */

void quickSort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = partition(array, low, high, size);

		quickSort(array, low, pi - 1, size);
		quickSort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - This is a auxiliary function
 * @array: input unsorted array
 * @size: size of the array
 *
 */

void quick_sort(int *array, size_t size)
{
	if (array != NULL && size != 0)
		quickSort(array, 0, size - 1, size);
}
