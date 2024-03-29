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
