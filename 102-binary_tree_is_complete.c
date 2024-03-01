#include "binary_trees.h"
#include "11-binary_tree_size.c"
/**
 * complete - this is the complete node
 * @tree: this is the tree
 * @index: this is the index
 * @count: this is the size
 * Return: 1 or 0
 */
int complete(const binary_tree_t *tree, int index, int count)
{
if (tree == NULL)
return (1);
if (index >= count)
return (0);
return (complete(tree->left, 2 * index + 1, count) &&
complete(tree->right, 2 * index + 2, count));
}
/**
 * binary_tree_is_complete - this is the complete tree
 * @tree: this is the tree
 * Return: 1 or 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
int cnt = binary_tree_size(tree);
int ab = 0;

if (tree == NULL)
return (0);
return (complete(tree, ab, cnt));
}
