#include "binary_trees.h"

/**
 * array_to_heap - this is the array heap
 * @array: this is the array
 * @size: this is the size
 * Return: root or NULL
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int ax;
	heap_t *rt = NULL;

	for (ax = 0; ax < size; ax++)
		heap_insert(&rt, array[ax]);

	return (rt);
}
