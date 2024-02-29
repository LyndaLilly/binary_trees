#include "binary_trees.h"

/**
 * binary_tree_size - this is the tree size
 * @tree: this is the tree
 * Return: size of tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t w = 0;

	if (tree)
	{
		w += 1;
		w += binary_tree_size(tree->left);
		w += binary_tree_size(tree->right);
	}
	return (w);
}
