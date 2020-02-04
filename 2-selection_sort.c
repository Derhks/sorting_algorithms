#include "sort.h"

/**
 * selection_sort - selection sort algorithm
 * @array: input unsorted array
 * @size: input size of array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t itr_1 = 0, itr_2 = 0, aux = 0, tmp = 0;

	for (itr_1 = 0; itr_1 < size; itr_1++)
	{
		aux = itr_1;
		for (itr_2 = itr_1 + 1; itr_2 < size; itr_2++)
		{
			if (array[itr_2] < array[aux])
			{
				aux = itr_2;
			}
		}
		if (aux != itr_1)
		{
			tmp = array[itr_1];
			array[itr_1] = array[aux];
			array[aux] = tmp;
			print_array(array, size);
		}
	}
}
