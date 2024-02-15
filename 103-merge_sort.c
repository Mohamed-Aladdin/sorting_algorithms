#include "sort.h"

/**
 * merge_arr - sorts an array of integers.
 * @arr: The given array.
 * @buf: The given buffer.
 * @front: The front index.
 * @mid: The mid index.
 * @back: The back index.
 *
 * Return: Void.
 */

void merge_arr(int *arr, int *buf, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(arr + front, mid - front);

	printf("[right]: ");
	print_array(arr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buf[k] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
	for (; i < mid; i++)
		buf[k++] = arr[i];
	for (; j < back; j++)
		buf[k++] = arr[j];
	for (i = front, k = 0; i < back; i++)
		arr[i] = buf[k++];

	printf("[Done]: ");
	print_array(arr + front, back - front);
}

/**
 * merge_sort_rec - sorts an array of integers recursively.
 * @arr: The given array.
 * @buf: The given buffer.
 * @front: The front index.
 * @back: The back index.
 *
 * Return: Void.
 */

void merge_sort_rec(int *arr, int *buf, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_rec(arr, buf, front, mid);
		merge_sort_rec(arr, buf, mid, back);
		merge_arr(arr, buf, front, mid, back);
	}
}

/**
 * merge_sort - sorts an array of integers in
 * ascending order using the Merge sort algorithm.
 * @array: The given array.
 * @size: The given array size.
 *
 * Return: Void.
 */

void merge_sort(int *array, size_t size)
{
	int *buf;

	if (!array || !size || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (!buf)
		return;

	merge_sort_rec(array, buf, 0, size);

	free(buf);
}
