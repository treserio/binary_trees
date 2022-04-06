#include "binary_trees.h"
/**
 * binary_tree_is_leaf - check if the node is a leaf
 * @tree: the node to check
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node || node->left || node->right)
		return (0);
	return 1;
}
