#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
int balance(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * height - this is the height
 * @tree: the tree
 * Return: NULL or 0
 */
size_t height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t mn = 0, xn = 0;

		mn = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		xn = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((mn > xn) ? mn : xn);
	}
	return (0);
}

/**
 * balance - this is the balance
 * @tree: this is the tree
 * Return: 0 or 1
 */
int balance(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * avl_insert_recursive - this inserts recursive
 * @tree: this is the tree
 * @parent: this is the parent
 * @new: this is the new
 * @value: this is the value
 * Return: 0 or 1.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int tny;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	tny = balance(*tree);
	if (tny > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (tny < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (tny > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (tny < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - this is the inserts
 * @tree: this is the tree
 * @value: this is the value
 * Return: 0 or NULL
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *txt = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &txt, value);
	return (txt);
}
