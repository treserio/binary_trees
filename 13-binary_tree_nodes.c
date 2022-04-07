#include "binary_trees.h"
/**
 * binary_tree_nodes - counts the nodes parent nodes of a tree
 * @tree: tree to be counted
 * Return: number of parent nodes in the tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t parent = 0;
	/* exit case */
	if (!tree)
		return (0);
	/* am I a parent? */
	if (tree->left || tree->right)
		parent = 1;
	return (parent + binary_tree_nodes(tree->left)
			+ binary_tree_nodes(tree->right));
}
