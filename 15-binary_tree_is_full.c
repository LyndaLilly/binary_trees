#include "binary_trees.h"
/**
 * binary_tree_is_full - this is binary full tree
 * @tree: points to tree
 * Return: 1 or 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
int mxt = 0, mxt2 = 0;

if (tree == NULL)
return (0);

if (tree->left == NULL && tree->right == NULL)
return (1);
if (tree->left != NULL)
mxt = binary_tree_is_full(tree->left);
if (tree->right != NULL)
mxt2 = binary_tree_is_full(tree->right);
return (mxt && mxt2);
}
