#include "binary_trees.h"
#include "limits.h"

size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * height - this is the height
 * @tree: this is the tree
 * Return: NULL or height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t st = 0, abt = 0;

		st = tree->left ? 1 + height(tree->left) : 1;
		abt = tree->right ? 1 + height(tree->right) : 1;
		return ((st > abt) ? st : abt);
	}
	return (0);
}

/**
 * is_avl_helper - this is the avl helper
 * @tree: this is the tree
 * @lo: this is the lowest
 * @hi: this is the highest
 * Return: 1 otherwise 0.
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t ptr, sib, cru;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		ptr = height(tree->left);
		sib = height(tree->right);
		cru = ptr > sib ? ptr - sib : sib - ptr;
		if (cru > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - this is the binary tree avl
 * @tree: this is the tree
 * Return: 1 or 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
