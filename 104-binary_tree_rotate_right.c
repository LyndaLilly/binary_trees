#include "binary_trees.h"

/**
 * binary_tree_rotate_right - this the tree rotate right
 * @tree: this is the tree
 * Return: root
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
binary_tree_t *sxt, *pye;

sxt = NULL;
if (tree == NULL || tree->left == NULL)
return (NULL);
if (tree->left->right != NULL)
sxt = tree->left->right;
pye = tree->left;
tree->left->right = tree;
tree->parent = tree->left;
tree->left->parent = NULL;
tree->left = sxt;
if (sxt != NULL)
sxt->parent = tree;
return (pye);
}
