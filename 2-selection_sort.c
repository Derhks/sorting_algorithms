#include "sort.h"

/**
 * selection_sort - selection sort algorithm
 * @array: input unsorted array
 * @size: input size of array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx, aux, sort;

	for (i = 0; i < size; i++)
	{

		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
				sort = 1;
			}
		}
		aux = array[min_idx];
		array[min_idx] = array[i];
		array[i] = aux;
		if (sort)
		{
			print_array(array, size);
			sort = 0;
		}
	}
}
