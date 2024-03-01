#include "binary_trees.h"

/**
 * binary_trees_ancestor - this is the tree ancestor
 * @first: this is the first node
 * @second: this is the second node
 * Return: pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *wop, *pret;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	wop = first->parent, pret = second->parent;
	if (first == pret || !wop || (!wop->parent && pret))
		return (binary_trees_ancestor(first, pret));
	else if (wop == second || !pret || (!pret->parent && wop))
		return (binary_trees_ancestor(wop, second));
	return (binary_trees_ancestor(wop, pret));
}
