#include "binary_trees.h"

/**
 * bst_search - the binary search
 * @tree: this is the tree
 * @value: this is the value
 * Return: NULL or  value.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
