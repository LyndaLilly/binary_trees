#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - this is the tree height
 * @tree: this is the tree
 * Return: NULL or none
 */
size_t tree_height(const heap_t *tree)
{
	size_t ab = 0;
	size_t bx = 0;

	if (!tree)
		return (0);

	if (tree->left)
		ab = 1 + tree_height(tree->left);

	if (tree->right)
		bx = 1 + tree_height(tree->right);

	if (ab > bx)
		return (ab);
	return (bx);
}
/**
 * tree_size_h - this is the tree size
 * @tree: this is the tree
 * Return: height or 0
 */

size_t tree_size_h(const binary_tree_t *tree)
{
	size_t ab = 0;
	size_t bx = 0;

	if (!tree)
		return (0);

	if (tree->left)
		ab = 1 + tree_size_h(tree->left);

	if (tree->right)
		bx = 1 + tree_size_h(tree->right);

	return (ab + bx);
}

/**
 * _preorder - this is the proprder
 * @tree: this is the tree
 * @node: this is th node
 * @height: this is the height
 * Return: nothing
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	_preorder(tree->left, node, height);
	_preorder(tree->right, node, height);
}

/**
 * heapify - heaps node
 * @root: root
 */
void heapify(heap_t *root)
{
	int al;
	heap_t *res, *res1;

	if (!root)
		return;

	res = root;

	while (1)
	{
		if (!res->left)
			break;
		if (!res->right)
			res1 = res->left;
		else
		{
			if (res->left->n > res->right->n)
				res1 = res->left;
			else
				res1 = res->right;
		}
		if (res->n > res1->n)
			break;
		al = res->n;
		res->n = res1->n;
		res1->n = al;
		res = res1;
	}
}

/**
 * heap_extract - extracts heap
 * @root: this is the root
 * Return: node
 **/
int heap_extract(heap_t **root)
{
	int al;
	heap_t *heap_r, *lig;

	if (!root || !*root)
		return (0);
	heap_r = *root;
	al = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*root = NULL;
		free(heap_r);
		return (al);
	}

	_preorder(heap_r, &lig, tree_height(heap_r));

	heap_r->n = lig->n;
	if (lig->parent->right)
		lig->parent->right = NULL;
	else
		lig->parent->left = NULL;
	free(lig);
	heapify(heap_r);
	*root = heap_r;
	return (al);
}
