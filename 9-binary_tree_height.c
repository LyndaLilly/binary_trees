#include "binary_trees.h"
size_t binary_tree_height2(const binary_tree_t *tree);

/**
 * binary_tree_height2 - this is the height2
 * @tree: this is the tree node
 * Return: Null or tree
 */
size_t binary_tree_height2(const binary_tree_t *tree)
{
int x = 0, y = 0;

if (tree == NULL)
return (0);

if (tree->left != NULL)
x += binary_tree_height2(tree->left);

if (tree->right != NULL)
y += binary_tree_height2(tree->right);

if (x > y)
return (x + 1);
return (y + 1);
}

/**
 * binary_tree_height - this is the height
 * @tree: this is the tree node
 * Return: NULL or tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

return ((binary_tree_height2(tree)) - 1);
}
