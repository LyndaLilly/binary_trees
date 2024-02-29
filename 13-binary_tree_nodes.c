#include "binary_trees.h"

/**
 * binary_tree_nodes - this binary node
 * @tree: this is binary tree
 * Return: node
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
size_t cnt = 0;

if (tree == NULL)
return (0);
if (tree->right != NULL || tree->left != NULL)
cnt += binary_tree_nodes(tree->left) + 1
+ binary_tree_nodes(tree->right);
return (cnt);
}
