#include "binary_trees.h"
/**
 * binary_tree_preorder - run a function on the root node then left children
 * @tree: the root of the tree to run func on
 * @func: the function to run on each value of the tree
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	/* exit case */
	if (tree == NULL || func == NULL)
		return;
	/* run the function on the node's value */
	func(tree->n);
	/* then recur on left subtree */
	binary_tree_preorder(tree->left, func);
	/* now recur on right subtree */
	binary_tree_preorder(tree->right, func);
}
