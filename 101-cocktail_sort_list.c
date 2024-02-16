#include "sort.h"

/**
 * swap_dlist_nodes - swaps two nodes of a doubly linked list.
 * @n1: The first node.
 * @n2: The second node.
 *
 * Return: Void.
 */

void swap_dlist_nodes(listint_t *n1, listint_t *n2)
{
	if (n1->prev)
		n1->prev->next = n2;
	if (n2->next)
		n2->next->prev = n1;

	n1->next = n2->next;
	n2->prev = n1->prev;
	n1->prev = n2;
	n2->next = n1;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm.
 * @list: The given doubly linked list.
 *
 * Return: Void.
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *ls;
	int sort = 1;

	if (!(list && *list))
		return;
	ls = *list;
	while (sort)
	{
		sort = 0;
		while (ls && ls->next)
		{
			if (ls->n > ls->next->n)
			{
				swap_dlist_nodes(ls, ls->next);

				if (ls->prev->prev == NULL)
					*list = ls->prev;
				print_list(*list);
				sort = 1;
			}
			else
				ls = ls->next;
		}
		if (!sort)
			break;
		sort = 0;
		while (ls->prev)
		{
			if (ls->prev->n > ls->n)
			{
				swap_dlist_nodes(ls->prev, ls);
				if (ls->prev == NULL)
					*list = ls;
				print_list(*list);
				sort = 1;
			}
			else
				ls = ls->prev;
		}
	}
}
