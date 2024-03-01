#include "binary_trees.h"
#include "9-binary_tree_height.c"
/**
 * print_level - this prints the level
 * @func: this is the function
 * @level: this is the level
 * @node: this is the pointer
 * Return: void
 */
void print_level(binary_tree_t *node, void (*func)(int), int level)
{
if (node != NULL && func != NULL)
{
if (level == 1)
func(node->n);
if (level > 1)
{
print_level(node->left, func, level - 1);
print_level(node->right, func, level - 1);
}
}
}
/**
 *binary_tree_levelorder - this is the tree level order
 *@tree: this is the tree
 *@func: this is the function
 *Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
size_t mw = 0;
size_t cnt;
binary_tree_t *copy_tree = (binary_tree_t *)tree;

if (tree == NULL || func == NULL)
return;
mw = binary_tree_height(tree);
for (cnt = 0; cnt <= mw + 1; cnt++)
print_level(copy_tree, func, cnt);
}
