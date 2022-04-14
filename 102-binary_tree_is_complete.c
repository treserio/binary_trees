#include "binary_trees.h"
/**
 * binary_tree_is_complete - check to make sure the tree is complete from root
 * @tree: root of the tree to check
 * Return: 1 if the tree is complete, else 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t sz;
	/* exit case */
	if (!tree)
		return (0);
	/* find the size */
	sz = binary_tree_size(tree);
	/* check each node vs the total size */
	return (node_idx_chk(tree, 1, sz));
}

/**
 * node_idx_chk - check the index of the node vs the size of the tree
 * @node: root of the tree to check
 * @idx: the index of the node
 * @sz: the size of the tree
 * Return: 0 if the node's index is greater than the size of the tree
 */
bool node_idx_chk(const binary_tree_t *node, size_t idx, size_t sz)
{
	/* null are 1 by default */
	if (!node)
		return (1);
	/* false case */
	if (idx > sz)
		return 0;
	/* determin which nodes to run recursively on */
	if (node->left && node->right)
		return node_idx_chk(node->left, idx * 2, sz) &&
			node_idx_chk(node->right, idx * 2 + 1, sz);
	else if (node->left)
		return node_idx_chk(node->left, idx * 2, sz);
	else
		/* default run on right, on null node will return 1 */
		return node_idx_chk(node->right, idx * 2 + 1, sz);
}

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
