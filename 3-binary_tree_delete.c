#include "binary_trees.h"

/**
 * binary_tree_delete - this deletes the binary tree
 * @tree: this points to the binary tree
 * Return: tree is NULL
 */
void binary_tree_delete(binary_tree_t *tree)
{
if (tree == NULL)
return;
binary_tree_delete(tree->left);
binary_tree_delete(tree->right);
free(tree);
}
