#include "binary_trees.h"
/**
 * binary_tree_size - measures the size of a binary tree
 *@tree: tree to be measured
 *Return: number of nodes in the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	/* 1 for this node + 1 for each other */
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
