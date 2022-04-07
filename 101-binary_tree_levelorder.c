#include "binary_trees.h"
/**
 * binary_tree_levelorder - traverse a tree in level order, left -> right
 * @tree: the root of the tree to run func on
 * @func: the function to run on each value of the tree
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	/* exit case */
	if (tree == NULL || func == NULL)
		return;
	/* run the function on the node's value */
	if (!tree->parent)
		func(tree->n);
	func(tree->left->n);
	func(tree->right->n);

	/* first traverse left */
	if (tree->left->left || tree->left->right)
		binary_tree_levelorder(tree->left, func);

	/* now recur on right subtree */
	if (tree->right->left || tree->right->right)
		binary_tree_levelorder(tree->right, func);
}

