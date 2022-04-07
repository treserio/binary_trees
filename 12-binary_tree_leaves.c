#include "binary_trees.h"
/**
 * binary_tree_leaves - count number of leaves
 * @tree: tree to be counted
 * Return: the number of leaves from the root, *tree
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf = 0;
	/* exit case */
	if (!tree)
		return (0);
	/* if node is a leaf */
	if (!tree->left && !tree->right)
		++leaf;
	/* run recursively */
	return (leaf + binary_tree_leaves(tree->left)
			+ binary_tree_leaves(tree->right));
}
