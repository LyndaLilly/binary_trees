#include "binary_trees.h"
size_t binary_tree_depth2(const binary_tree_t *tree);
/**
 * binary_tree_depth2 - this is the depth2
 * @tree: this is the tree node
 * Return: tree or NULL
 */
size_t binary_tree_depth2(const binary_tree_t *tree)
{
	int x = 0;

	if (tree == NULL)
		return (0);
	if (tree->parent != NULL)
		x += binary_tree_depth2(tree->parent);
	return (x + 1);
}
/**
 * binary_tree_depth - this is the depth
 * @tree: this points to the tree
 * Return: tree or NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_depth2(tree) - 1);
}
