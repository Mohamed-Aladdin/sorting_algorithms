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
 * swap_ints - swaps two integers.
 * @n1: The first integer.
 * @n2: The second integer.
 *
 * Return: Void.
 */

void swap_ints(int *n1, int *n2)
{
	int tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}
