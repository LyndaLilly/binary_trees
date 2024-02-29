#include "binary_trees.h"
/**
 * binary_tree_node - this create a binary tree node
 * @parent: this is the parent binary
 * Return: it returns node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *aptr;

aptr = malloc(sizeof(binary_tree_t));
if (aptr == NULL)
return (NULL);
aptr->n = value
aptr->parent = parent;
aptr->left = NULL;
aptr->right = NULL;
return (aptr);
}
