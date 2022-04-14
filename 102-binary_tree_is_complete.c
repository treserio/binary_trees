#include "binary_trees.h"
/**
 * binary_tree_is_complete - check to make sure the tree is complete from root
 * @tree: root of the tree to check
 * Return: 1 if the tree is complete, else 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	/* exit case */
	if (!tree)
		return (0);

}

/* count number of nodes and compare to indexes
* if root = p
* root->left = 2*p + 1, maybe 2*p?
* root->right = 2*p + 2, maybe 2*p + 1?
* if index > total nodes, incomplete
*/



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
