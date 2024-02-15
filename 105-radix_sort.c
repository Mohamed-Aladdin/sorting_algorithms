#include "sort.h"

/**
 * radix_sort_count - sorts digits.
 * @arr: The given array.
 * @size: The given array size.
 * @uni: The given digit.
 * @buf: The given buffer.
 *
 * Return: Void.
 */

void radix_sort_count(int *arr, size_t size, int uni, int *buf)
{
	int c[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		c[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		c[i] += c[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buf[c[(arr[i] / uni) % 10] - 1] = arr[i];
		c[(arr[i] / uni) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		arr[i] = buf[i];
}

/**
 * radix_sort - sorts an array of integers in
 * ascending order using the Radix sort algorithm.
 * @array: The given array.
 * @size: The given array size.
 *
 * Return: Void.
 */

void radix_sort(int *array, size_t size)
{
	int max, uni, *buf;

	if (!array || !size || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (!buf)
		return;

	max = get_max(array, size);
	for (uni = 1; max / uni > 0; uni *= 10)
	{
		radix_sort_count(array, size, uni, buf);
		print_array(array, size);
	}

	free(buf);
}
