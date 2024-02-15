#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Helper Functions */
void swap_dlist_nodes(listint_t *n1, listint_t *n2);
void swap_ints(int *n1, int *n2);
int partition_array(int *array, int min, int max, size_t size);
void lomuto_quicksort(int *array, int min, int max, size_t size);
int get_higher(int *array, int size);
void merge_arr(int *arr, int *buf, size_t front, size_t mid,
		size_t back);
void merge_sort_rec(int *arr, int *buf, size_t front, size_t back);

/* Tasks Functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);

#endif /* SORT_H */
