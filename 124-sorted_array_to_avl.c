#include "binary_trees.h"

/**
 * create_tree - this creates tree
 * @node: this is the node
 * @array: this is the array
 * @size: this is the size
 * @mode: adding left and right
 * Return: nothing
 */
void create_tree(avl_t **node, int *array, size_t size, int mode)
{
	size_t md;

	if (size == 0)
		return;

	md = (size / 2);
	md = (size % 2 == 0) ? md - 1 : md;

	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, array[md]);
		create_tree(&((*node)->left), array, md, 1);
		create_tree(&((*node)->left), array + md + 1, (size - 1 - md), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[md]);
		create_tree(&((*node)->right), array, md, 1);
		create_tree(&((*node)->right), array + md + 1, (size - 1 - md), 2);
	}
}

/**
 * sorted_array_to_avl - this creates array sorted
 * @array: this is the array
 * @size: this is the size
 * Return: root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *rd;
	size_t md;

	rd = NULL;

	if (size == 0)
		return (NULL);

	md = (size / 2);

	md = (size % 2 == 0) ? md - 1 : md;

	rd = binary_tree_node(rd, array[md]);

	create_tree(&rd, array, md, 1);
	create_tree(&rd, array + md + 1, (size - 1 - md), 2);

	return (rd);
}
