#include "sort.h"

/**
 * insertion_sort_list - sort algorithm
 * @list: input doubly linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t **tmp = NULL, **tmp_prv = NULL **tmp_nxt = NULL;

	if (*list)
	{
		*tmp = *list;
		while (tmp->next)
		{
			if (tmp->n > tmp->next->n)
			{
				if (tmp->prev)
				{
				        
				}
			}
		}
	}
}
