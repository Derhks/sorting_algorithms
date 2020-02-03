#include "sort.h"

/**
 * bubble_sort - bubble sort algorithm
 * @array: input unsorted array
 * @size: size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t itr = 0, co = 0;
	int tmp = 0;

	for (co = 0; co < size; co++)
	{
		for (itr = 0; itr < size; itr++)
		{
			if (array[itr] > array[itr + 1] && array[itr + 1])
			{
				tmp = array[itr];
				array[itr] = array[itr + 1];
				array[itr + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
