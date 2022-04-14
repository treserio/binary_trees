#include "binary_trees.h"
/**
 * binary_tree_is_bst - confirm that the tree is a Binary Search Tree
 * @tree: the root of the tree to run func on
 * Return: 1 if Binary Search, else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	/* INT_MIN INT_MAX */
	return (is_bst(tree, INT_MIN, INT_MAX));
}

/**
 * is_bst - run the actual recursive check for Binary Search
 * @node: the root of the tree to run func on
 * @min: the minimum value for this node
 * @max: the maximum value for this node
 * Return: true of node and children are a Binary Search, else 0
 */
bool is_bst(const binary_tree_t *node, int min, int max)
{
	/* null nodes are true by default */
	if (!node)
		return (1);

	/* false conditions for left */
	if (node->left && (node->left->n >= node->n ||
		node->left->n <= min))
		return (0);

	/* false conditions for right */
	if (node->right && (node->right->n <= node->n ||
		node->right->n >= max))
		return (0);

	return (is_bst(node->left, min, node->n) &&
			is_bst(node->right, node->n, max));
}

