#include "binary_trees.h"
/**
 * bst_search - search a bst for a value
 * @tree: the root of the tree to search
 * @value: the value to search for
 * Return: pointer to the node containing the value, or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return NULL;
	return (pntr_search((bst_t *)tree, value));
}

bst_t *pntr_search(bst_t *node, int value)
{
	bst_t *left, *right;
	/* exit case */
	if (!node)
		return (NULL);
	if (node->n == value)
		return (node);
	/* check left and right */
	left = pntr_search(node->left, value);
	right = pntr_search(node->right, value);
	/* figure out which to return */
	if (left)
		return (left);
	return (right);
}
