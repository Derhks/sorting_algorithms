#include "sort.h"

/**
 * insertion_sort_list - sort algorithm
 * @list: input doubly linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = NULL, *tmp_prv = NULL, *tmp_nxt = NULL;

	if (*list)
	{
		tmp = *list;
		while (tmp->next)
		{
			if (tmp->n > tmp->next->n)
			{
				if (tmp->prev)
				{
					tmp_nxt = tmp->next;
					tmp_nxt->prev->prev = tmp_prv;
					tmp_nxt->prev->next = tmp;
					tmp->prev = tmp->next->prev;
					tmp_nxt->prev = tmp;
					tmp_prv->next = tmp->prev;
				}
				print_list(*list);
			}
			tmp = tmp->next;
		}
	}
}
