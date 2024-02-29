#include "binary_trees.h"

size_t binary_tree_height2(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - this is the binary perfect tree
 * @tree: thisis the tree
 * Return: 1 or 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
size_t mxt = 0, mxt2 = 2, i = 0;

if (tree == NULL)
return (0);

mxt = binary_tree_height(tree);
for (m = 1; m < mxt; m++)
mxt2 = mxt2 * 2;
if (binary_tree_leaves(tree) == mxt2)
return (1);
return (0);
}

/**
 * binary_tree_leaves - this is the binary perfect tree
 * @tree: this is the tree
 * Return: 1 or 0
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
int abt = 0;

if (tree == NULL)
return (0);

if (tree->left == NULL && tree->right == NULL)
return (abt + 1);

if (tree->left != NULL)
abt += binary_tree_leaves(tree->left);

if (tree->right != NULL)
abt += binary_tree_leaves(tree->right);

return (abt);
}


/**
 * binary_tree_height2 - this is the height
 * @tree: this is the tree
 * Return: 1 or 0
 */

size_t binary_tree_height2(const binary_tree_t *tree)
{
int abt = 0, abt2 = 0;

if (tree == NULL)
return (0);

if (tree->left != NULL)
abt += binary_tree_height2(tree->left);

if (tree->right != NULL)
abt2 += binary_tree_height2(tree->right);

if (abt > abt2)
return (abt + 1);
return (abt2 + 1);
}

/**
 * binary_tree_height - this is the height
 * @tree: this is the tree
 * Return: height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

return ((binary_tree_height2(tree)) - 1);
}
