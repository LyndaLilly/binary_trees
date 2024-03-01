#include "binary_trees.h"

/**
 * bal - this is the balance
 * @tree: this is the tree
 * Return: balance
 */
void bal(avl_t **tree)
{
	int tre;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	tre = binary_tree_balance((const binary_tree_t *)*tree);
	if (tre > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (tre < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * successor - this is the successor
 * @node: this is the node
 * Return: tree
 */
int successor(bst_t *node)
{
	int yt = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		yt = successor(node->yt);
		if (yt == 0)
		{
			return (node->n);
		}
		return (yt);
	}

}
/**
 * remove_type - this remove the tyoe
 * @root: this is the root
 * Return: 0 or 1
 */
int remove_type(bst_t *root)
{
	int res = 0;

	if (!root->yt && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->yt = NULL;
		free(root);
		return (0);
	}
	else if ((!root->yt && root->right) || (!root->right && root->yt))
	{
		if (!root->yt)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->yt = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->yt;
			else
				root->parent->yt = root->yt;
			root->yt->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		res = successor(root->right);
		root->n = res;
		return (res);
	}
}
/**
 * bst_remove - this remove bst
 * @root: this is the root
 * @value: this is the value
 * Return: tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int yrt = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->yt, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		yrt = remove_type(root);
		if (yrt != 0)
			bst_remove(root->right, yrt);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - remove a node from a AVL tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	bal(&root_a);
	return (root_a);
}
