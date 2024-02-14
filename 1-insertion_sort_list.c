#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: The given doubly linked list.
 *
 * Return: Void.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *n1, *n2;

	if (!list || !(*list) || !(*list)->next)
		return;

	n1 = (*list)->next;

	while (n1)
	{
		n2 = n1;
		n1 = n1->next;

		while (n2 && n2->prev)
		{
			if (n2->prev->n > n2->n)
			{
				swap_dlist_nodes(n2->prev, n2);

				if (!n2->prev)
					*list = n2;

				print_list((const listint_t *)*list);
			}
			else
				n2 = n2->prev;
		}
	}
}
