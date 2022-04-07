#include "binary_trees.h"
/**
 * binary_tree_uncle - return the uncle of the node
 * @node: the node to find the uncle of
 * Return: pointer to uncle if present, else NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* exit case */
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);
	/* confirm which node the parent is and return accordingly */
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
