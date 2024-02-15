#include "sort.h"

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
