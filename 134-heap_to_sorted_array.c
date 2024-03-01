#include "binary_trees.h"

/**
 * tree_size - this is the tree size
 * @tree: this is the tree
 * Return: height or 0
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t res = 0;
	size_t res1 = 0;

	if (!tree)
		return (0);

	if (tree->left)
		res = 1 + tree_size(tree->left);

	if (tree->right)
		res1 = 1 + tree_size(tree->right);

	return (res + res1);
}

/**
 * heap_to_sorted_array - this sorts heap array
 * @heap: this is the heap
 * @size: this is the size
 * Return: array
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int ax, *mt = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	mt = malloc(sizeof(int) * (*size));

	if (!mt)
		return (NULL);

	for (ax = 0; heap; ax++)
		mt[ax] = heap_extract(&heap);

	return (mt);
}
