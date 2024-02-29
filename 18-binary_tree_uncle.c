#include "binary_trees.h"

/**
 * binary_tree_sibling - this is the tree sibling
 * @node:this is the node
 * Return: NULL or pointer
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
if (node == NULL || node->parent == NULL)
return (NULL);
if (node == node->parent->right)
return (node->parent->left);
return (node->parent->right);
}

/**
 * binary_tree_uncle - this is the uncle
 * @node: point to node
 * Return: NULL or pointer
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
if (node == NULL || node->parent == NULL)
return (NULL);

return (binary_tree_sibling(node->parent));
}
