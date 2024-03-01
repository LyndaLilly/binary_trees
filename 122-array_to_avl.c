#include "binary_trees.h"

/**
 * array_to_avl - this is the avl.
 * @array: this is the array
 * @size: this is the size
 * Return: or NULL
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t a, ba;

	if (array == NULL)
		return (NULL);

	for (a = 0; a < size; a++)
	{
		for (ba = 0; ba < a; ba++)
		{
			if (array[ba] == array[a])
				break;
		}
		if (ba == a)
		{
			if (avl_insert(&tree, array[a]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
