#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts the binary at the right side
 * @value: this is the value of the node
 * @parent: this is the parent node
 * Return:  pointer to the created node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
binary_tree_t *rt;

if (parent == NULL)
return (NULL);

rt = binary_tree_node(parent, value);
if (rt == NULL)
return (NULL);
if (parent->right)
{
parent->right->parent = rt;
rt->right = parent->right;
}
parent->right = rt;
return (rt);
}
