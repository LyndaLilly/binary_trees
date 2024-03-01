#include "binary_trees.h"

/**
 * heap_insert - this is the heap inserts
 * @root: this is the root
 * @value: this is the value
 * Return: NULL
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *rt, *pr, *ret;
	int cru, axt, tyu, quo, aly, st;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	rt = *root;
	cru = binary_tree_size(rt);
	axt = cru;
	for (aly = 0, tyu = 1; axt >= tyu; tyu *= 2, aly++)
		axt -= tyu;
	/* subtract all nodes except for bottom-most aly */

	for (quo = 1 << (aly - 1); quo != 1; quo >>= 1)
		rt = axt & quo ? rt->right : rt->left;
	/*
	 * coverts the tree
	 * this repre number.
	 * Example - 12 nodes tree, there are 5 leaves on
	 * the 4th tier of the tree.
	 * right, 0 to left.
	 * empty node is 101 == RLR, *root->right->left->right
	 */

	pr = binary_tree_node(rt, value);
	axt & 1 ? (rt->right = pr) : (rt->left = pr);

	ret = pr;
	for (; ret->parent && (ret->n > ret->parent->n); ret = ret->parent)
	{
		st = ret->n;
		ret->n = ret->parent->n;
		ret->parent->n = st;
		pr = pr->parent;
	}
	/* ret values with parent until parent value exceeds pr value */

	return (pr);
}

/**
 * binary_tree_size - this is the tree size
 * @tree: this is the tree
 * Return: size or NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
