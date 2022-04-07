#include "binary_trees.h"
/**
 * binary_tree_levelorder - traverse a tree in level order, left -> right
 * @tree: the root of the tree to run func on
 * @func: the function to run on each value of the tree
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level = 1;
	/* exit case */
	if (!tree || !func)
		return;
	/* call helper with increasing level until it returns false */
	while (print_level((binary_tree_t *)tree, level, func))
		++level;
}
/**
 * print_level - recursive helper for level traversal
 * @node: the node to check for printing
 * @level: the higher the level the deeper we need to go recursively
 * @func: the function to run on each value of the tree
 * Return: true/false depending on print or null pointer
 */
bool print_level(binary_tree_t *node, size_t level, void (*func)(int))
{
	bool l_bool, r_bool;
	/* exit condition for non-node */
	if (!node)
		return (false);
	/* print the value if the level is correct */
	if (level == 1)
	{
		func(node->n);
		return (true);
	}
	/* recursively call the function with decreasing level */
	l_bool = print_level(node->left, level - 1, func);
	r_bool = print_level(node->right, level - 1, func);
	/* return the bool of left or right to continue function */
	return (l_bool || r_bool);
}
