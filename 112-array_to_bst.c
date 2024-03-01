#include "binary_trees.h"

/**
 * array_to_bst - the is array search
 * @array: this is the array
 * @size: the array size
 * Return: created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
size_t cnt = 0;
bst_t *dpe;

dpe = NULL;
for (cnt = 0; cnt < size; cnt++)
bst_insert(&dpe, array[cnt]);
return (dpe);
}
