#include "binary_trees.h"
/**
 * binary_tree_sibling - return the sibling of the node
 * @node: the node to find the sibling of
 * Return: pointer to sibling if present, else NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/* exit case */
	if (!node || !node->parent)
		return (NULL);
	/* confirm which node we are and return accordingly */
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
