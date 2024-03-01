#include "binary_trees.h"

/**
 * binary_tree_rotate_left - this rotates the tree to left
 * @tree: tis is the tree
 * Return: root
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
binary_tree_t *sxt, *pye;

sxt = NULL;
if (tree == NULL || tree->right == NULL)
return (NULL);
if (tree->right->left != NULL)
sxt = tree->right->left;
pye = tree->right;
tree->right->left = tree;
tree->parent = tree->right;
tree->right->parent = NULL;
tree->right = sxt;
if (sxt != NULL)
sxt->parent = tree;
return (pye);
}
