#include "binary_trees.h"
/**
 * binary_tree_depth - find the height of the tree
 * @tree: root of the tree to measure
 * Return: a size_t of the number of levels below root
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0, parent;
	/* exit case */
	if (!tree)
		return (0);
	/* add to depth if parent exists */
	if (tree->parent)
		depth++;
	/* measure depth of parent */
	parent = binary_tree_depth(tree->parent);
	return (depth + parent);
}
