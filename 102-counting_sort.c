#include "sort.h"

/**
 * get_higher - gets the max of an array of ints.
 * @array: The given array.
 * @size: The given array size.
 *
 * Return: Void.
 */

int get_higher(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - sorts an array of integers in
 * ascending order using the Counting sort algorithm.
 * @array: The given array.
 * @size: The given array size.
 *
 * Return: Void.
 */

void counting_sort(int *array, size_t size)
{
	int *c, *sort, max, i;

	if (!array || !size || size < 2)
		return;

	sort = malloc(sizeof(int) * size);
	if (!sort)
		return;
	max = get_higher(array, size);
	c = malloc(sizeof(int) * (max + 1));
	if (!c)
	{
		free(sort);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		c[i] = 0;
	for (i = 0; i < (int)size; i++)
		c[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		c[i] += c[i - 1];
	print_array(c, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sort[c[array[i]] - 1] = array[i];
		c[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sort[i];

	free(sort);
	free(c);
}
