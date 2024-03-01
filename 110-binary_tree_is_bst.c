#include "binary_trees.h"
#include <limits.h>
/**
 * binary_tree_check - this is the tree check
 * @node: this is the nod
 * @min: this is the min
 * @max: this is the max
 * Return: 0 or 1
 */
int binary_tree_check(const binary_tree_t *node, int min, int max)
{
if (node == NULL)
return (1);
if (node->n < min || node->n > max)
return (0);
return (binary_tree_check(node->left, min, node->n - 1) &&
binary_tree_check(node->right, node->n + 1, max));
}
/**
 * binary_tree_is_bst - this is the binary tree
 * @tree: this is the tree
 * Return: 1 or 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);
return (binary_tree_check(tree, INT_MIN, INT_MAX));
}
