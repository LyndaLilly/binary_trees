#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"
/**
 * check_max - this is the check max
 * @tree: this is the tree
 * Return: 1 or 0 in other cases
 **/
int check_max(const binary_tree_t *tree)
{
	int res = 1, res2 = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		res = check_max(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		res2 = check_max(tree->right);
	}
	return (res && res2);
}
/**
 * binary_tree_is_heap - this is the binary heap
 * @tree: this is the tree
 * Return: 1 or 0 otherwise
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int resp;

	if (!tree)
		return (0);

	resp = binary_tree_is_complete(tree);
	if (!resp)
		return (0);
	return (check_max(tree));
}
