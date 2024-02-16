#include "sort.h"

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

/**
 * selection_sort - sorts an array of integers in
 * ascending order using the Selection sort algorithm.
 * @array: The given array.
 * @size: The given array size.
 *
 * Return: Void.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *tmp;

	if (!size || !array || size < 2)
		return;

	for (i = 1; i < size; i++)
	{
		tmp = array + i;

		for (j = i + 1; j < size; j++)
			tmp = (array[j] < *tmp) ? (array + j) : min;

		if ((array + i) != tmp)
		{
			swap_ints(array + i, tmp)
			print_array(array, size);
		}
	}
}
