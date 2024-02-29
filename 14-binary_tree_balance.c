#include "binary_trees.h"

/**
 * binary_tree_balance - this is the balance tree.
 * @tree: points to a tree.
 * Return: NULL or 0, else return balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - this is the binary height.
 * @tree: points to a tree.
 * Return: NULL or 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t a = 0, b = 0;

		a = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		b = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((a > b) ? a : b);
	}
	return (0);
}
