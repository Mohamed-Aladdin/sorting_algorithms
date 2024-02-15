#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence.
 * @array: The given array.
 * @size: The given array size.
 *
 * Return: Void.
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, g;

	if (!array || !size || size < 2)
		return;

	for (g = 1; g < (size / 3);)
		g = (g * 3) + 1;

	for (; g >= 1; g /= 3)
	{
		for (i = g; i < size; i++)
		{
			j = i;

			while (j >= g && array[j - g] > array[j])
			{
				swap_ints(array + j, array + (j - g));
				j -= g;
			}
		}
		print_array(array, size);
	}
}
