#include "binary_trees.h"
/**
 * binary_tree_inorder - this is th etree inorder
 * @tree: this is the tree node
 * @func: this is the function
 * Return: tree or func is NULL
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree != NULL && func != NULL)
{
if (tree->left != NULL)
binary_tree_inorder(tree->left, func);

func(tree->n);

if (tree->right != NULL)
binary_tree_inorder(tree->right, func);
}
}
