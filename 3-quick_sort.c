#include "sort.h"

/**
 * quick_sort - sorts an array of integers in
 * ascending order using the Quick sort algorithm.
 * @array: The given array.
 * @size: The given array size.
 *
 * Return: Void.
 */

void quick_sort(int *array, size_t size)
{
	lomuto_quicksort(array, 0, size - 1, size);
}

/**
 * lomuto_quicksort - sorts an array recuresively.
 * @array: The given array.
 * @min: The lower int.
 * @max: The higher int.
 * @size: The given array size.
 *
 * Return: Void.
 */

void lomuto_quicksort(int *array, int min, int max, size_t size)
{
	int n;

	if (min < max)
	{
		n = partition_array(array, min, max, size);
		lomuto_quicksort(array, min, n - 1, size);
		lomuto_quicksort(array, n + 1, max, size);
	}
}

/**
 * partition_array - partitions an array using pivots.
 * @array: The given array.
 * @min: The lower int.
 * @max: The higher int.
 * @size: The given array size.
 *
 * Return: Int.
 */

int partition_array(int *array, int min, int max, size_t size)
{
	int pvt = array[max];
	int i = min - 1, j;

	for (j = min; j <= max; j++)
	{
		if (array[j] <= pvt)
		{
			i++;

			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	return (i);
}
