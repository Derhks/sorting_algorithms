#include "sort.h"

void insert_beg(listint_t *tmp_aux, listint_t *tmp);
void insert_mid(listint_t *tmp, listint_t *tmp_nxt, listint_t *tmp_aux);
void insert_end(listint_t *tmp, listint_t *tmp_aux, listint_t *tmp_nxt);

/**
 * insertion_sort_list - sort algorithm
 * @list: input doubly linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	int sort = 0;
	listint_t *tmp = NULL, *tmp_aux = NULL, *tmp_nxt = NULL;

	if (!list)
		return;
	tmp = *list;
	while (*list && tmp->next)
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
					insert_beg(tmp_aux, tmp);
					*list = tmp_aux;
				}
				else
				{
					insert_mid(tmp, tmp_nxt, tmp_aux);
				}
				sort = 1;
			}
			else if (!tmp->next->next)
			{
				if (!tmp->prev)
				{
					insert_beg(tmp->next, tmp);
					*list = tmp->prev;
				}
				insert_end(tmp, tmp_aux, tmp_nxt);
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


/**
 * insert_beg - insert aux node at begining of the list
 * @tmp_aux: input noninserted node
 * @tmp: temporal pointer in the list
 * Return: void
 */
void insert_beg(listint_t *tmp_aux, listint_t *tmp)
{
	tmp_aux->prev = NULL;
	tmp_aux->next = tmp;
	tmp->prev = tmp_aux;
}

/**
 * insert_mid - insert aux node at middle of the list
 * @tmp: temporal pointer in the list
 * @tmp_nxt: pointer next to tmp
 * @tmp_aux: input noninserted node
 * Return: void
 */
void insert_mid(listint_t *tmp, listint_t *tmp_nxt, listint_t *tmp_aux)
{
	tmp = tmp->prev;
	tmp_nxt = tmp->next;
	tmp->next = tmp_aux;
	tmp_aux->prev = tmp;
	tmp_aux->next = tmp_nxt;
	tmp_nxt->prev = tmp_aux;
}

/**
 * insert_end - insert node at end of the list
 * @tmp: temporal pointer in the list
 * @tmp_aux: input noninserted node
 * @tmp_nxt: pointer next to tmp
 * Return: void
 */
void insert_end(listint_t *tmp, listint_t *tmp_aux, listint_t *tmp_nxt)
{
	tmp_aux = tmp->next;
	tmp->next = NULL;
	tmp = tmp->prev;
	tmp_nxt = tmp->next;
	tmp->next = tmp_aux;
	tmp_aux->prev = tmp;
	tmp_aux->next = tmp_nxt;
	tmp_nxt->prev = tmp_aux;
}
