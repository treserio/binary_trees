#include "binary_trees.h"
/**
 * binary_tree_inorder - run a function on the left most node then up and right
 * @tree: the root of the tree to run func on
 * @func: the function to run on each value of the tree
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	/* exit case */
	if (tree == NULL || func == NULL)
		return;
	/* first traverse left */
	binary_tree_inorder(tree->left, func);
	/* run the function on the node's value */
	func(tree->n);
	/* now recur on right subtree */
	binary_tree_inorder(tree->right, func);
}
