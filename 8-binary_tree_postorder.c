#include "binary_trees.h"
/**
 * binary_tree_postorder - run a function on left most node then right and up
 * @tree: the root of the tree to run func on
 * @func: the function to run on each value of the tree
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	/* exit case */
	if (tree == NULL || func == NULL)
		return;
	/* first traverse left */
	binary_tree_preorder(tree->left, func);
	/* now recur on right subtree */
	binary_tree_preorder(tree->right, func);
	/* run the function on the node's value */
	func(tree->n);
}
