#include "sort.h"

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
	size_t i, j, k;
	int tmp;

	if (!size || !array || size < 2)
		return;

	for (i = 1; i < size; i++)
	{
		for (j = size - 1, k = i + 1; j > i; j--)
		{
			if (array[j] < array[k])
				k = j;
		}

		if (array[i] > array[k])
		{
			tmp = array[i];
			array[i] = array[k];
			array[k] = tmp;

			print_array(array, size);
		}
	}
}
