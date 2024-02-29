#include "binary_trees.h"

/**
 * binary_tree_node - this is the binary tree node
 * @parent: this is the parent node
 * @value: this is the value of the node
 * Return:  pointer to the created node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
binary_tree_t *aptr;

if (parent == NULL)
return (NULL);

aptr = calloc(1, sizeof(binary_tree_t));
if (aptr == NULL)
return (NULL);
if (parent->left == NULL)
{
parent->left = aptr;
aptr->parent = parent;
aptr->n = value;
aptr->right = NULL;
aptr->left = NULL;
}
else
{
aptr->left = parent->left;
parent->left->parent = aptr;
parent->left = aptr;
aptr->n = value;
aptr->parent = parent;
aptr->right = NULL;
}
return (aptr);
}
