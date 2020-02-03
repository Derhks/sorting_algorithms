#include "sort.h"

/**
 * insertion_sort_list - sort algorithm
 * @list: input doubly linked list
 * Return: void
 */

void sort_beg(listint_t *tmp_aux, listint_t *tmp)
{
	tmp_aux->prev = NULL;
	tmp_aux->next = tmp;
	tmp->prev = tmp_aux;
}

void insertion_sort_list(listint_t **list)
{
	int sort = 0;
	listint_t *tmp = NULL, *tmp_aux = NULL, *tmp_nxt = NULL;

	if (*list)
	{
		tmp = *list;
		while (tmp->next)
		{
			if (tmp->n > tmp->next->n)
			{
				if (tmp->next->next)
				{
					tmp_aux = tmp->next;
					tmp_nxt = tmp->next->next;
					tmp->next = tmp_nxt;
					tmp_nxt->prev = tmp;
					if (!tmp->prev)
					{
						sort_beg(tmp_aux, tmp);
						*list = tmp_aux;
					}
					else
					{
						tmp = tmp->prev;
						tmp_nxt = tmp->next;
						tmp->next = tmp_aux;
						tmp_aux->prev = tmp;
						tmp_aux->next = tmp_nxt;
						tmp_nxt->prev = tmp_aux;
					}
					sort = 1;
				}
				else if (!tmp->next->next)
				{
					tmp_aux = tmp->next;
					tmp->next = NULL;
					tmp = tmp->prev;
					tmp_nxt = tmp->next;
					tmp->next = tmp_aux;
					tmp_aux->prev = tmp;
					tmp_aux->next = tmp_nxt;
					tmp_nxt->prev = tmp_aux;
					sort = 1;
					}
				print_list(*list);
			}
			if (sort)
			{
				tmp = *list;
				sort = 0;
			}
			else
				tmp = tmp->next;
		}
	}
}
