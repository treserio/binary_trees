#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t ht = 0, left_ht, right_ht;

	if (!tree)
		return (0);

	if (tree->left || tree->right)
		ht++;
	
	left_ht = binary_tree_height(tree->left);
	right_ht = binary_tree_height(tree->right);

	if (left_ht > right_ht)
		ht += left_ht;
	else
		ht += right_ht;

	return (ht);
}