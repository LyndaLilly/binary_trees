#include "binary_trees.h"

/**
 * bst_insert - this is the binary
 * @tree: this is the tree
 * @value: the value of the binary
 * Return: NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
if (tree == NULL || *tree == NULL)
return (*tree = binary_tree_node(NULL, value));
if ((*tree)->n == value)
return (NULL);
if ((*tree)->n > value)
{
if ((*tree)->left == NULL)
return (binary_tree_insert_left(*tree, value));
return (bst_insert(&((*tree)->left), value));
}
if ((*tree)->n < value)
{
if ((*tree)->right == NULL)
return (binary_tree_insert_right(*tree, value));
return (bst_insert(&((*tree)->right), value));
}
return (NULL);
}

/**
 * binary_tree_insert_left - binary tree left
 * @parent: the parent node
 * @value: the value
 * Return: or NULL
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
/**
 * binary_tree_insert_right - binary tree right
 * @parent: the parent node
 * @value: the value
 * Return: node or NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
binary_tree_t *aptr;

if (parent == NULL)
return (NULL);

aptr = calloc(1, sizeof(binary_tree_t));
if (aptr == NULL)
return (NULL);
if (parent->right == NULL)
{
parent->right = aptr;
aptr->parent = parent;
aptr->n = value;
aptr->right = NULL;
aptr->left = NULL;
}
else
{
aptr->right = parent->right;
parent->right->parent = aptr;
parent->right = aptr;
aptr->n = value;
aptr->parent = parent;
aptr->left = NULL;
}
return (aptr);
}
