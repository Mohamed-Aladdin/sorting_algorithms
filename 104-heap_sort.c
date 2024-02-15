#include "sort.h"

/**
 * max_heap - convert binary trees to heap.
 * @arr: The given array.
 * @size: The given array size.
 * @b: The given base.
 * @r: The given root.
 *
 * Return: Void.
 */

void max_heap(int *arr, size_t size, size_t b, size_t r)
{
	size_t left, right, large;

	left = 2 * r + 1;
	right = 2 * r + 2;
	large = r;

	if (left < b && arr[left] > arr[large])
		large = left;
	if (right < b && arr[right] > arr[large])
		large = right;

	if (large != r)
	{
		swap_ints(arr + r, arr + large);
		print_array(arr, size);
		max_heap(arr, size, b, large);
	}
}

/**
 * heap_sort - sorts an array of integers in
 * ascending order using the Heap sort algorithm.
 * @array: The given array.
 * @size: The given array size.
 *
 * Return: Void.
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || !size || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heap(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_ints(array, array + i);
		print_array(array, size);
		max_heap(array, size, i, 0);
	}
}
