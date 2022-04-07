#include "binary_trees.h"
/**
 * binary_tree_is_full - check to make sure the tree is full from root
 * @tree: root of the tree to check
 * Return: 1 if the tree is full, else 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	/* exit case */
	if (!tree)
		return (0);
	/* check that the node is a leaf */
	if (!tree->left && !tree->right)
		return (1);
	/* if a child exists return the and of it's children, if only one exists */
	/* the exit case for it's other child will occur. */
	return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}
