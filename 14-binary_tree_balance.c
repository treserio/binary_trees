#include "binary_trees.h"
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: tree to be measured
 * Return: Balance tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * binary_tree_height - find the height of the tree
 * @tree: root of the tree to measure
 * Return: a size_t of the number of levels below root
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t ht = 1, left_ht, right_ht;
	/* exit case */
	if (!tree)
		return (0);
	/* measure height of children */
	left_ht = binary_tree_height(tree->left);
	right_ht = binary_tree_height(tree->right);
	/* add the greatest value to ht */
	if (left_ht > right_ht)
		ht += left_ht;
	else
		ht += right_ht;
	return (ht);
}
