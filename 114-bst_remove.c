#include "binary_trees.h"
/**
 * pntr_search - finds the value in the bst
 * @root: the root of the tree to search
 * @value: the value to search for
 * Return: pointer to the node containing the value, or NULL
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *target, *new_root;
	/* assume root is a node */
	if (root->n == value)
		return rm_node(root);
	target = bst_search(root, value);
	new_root = rm_node(target);
	if (new_root)
		return (new_root);
	return (NULL);
}

bst_t *rm_node(bst_t *del)
{
	bst_t *run;
	/* check if we're on a leaf */
	if (!del->left && !del->right)
	{
		free(del);
		/* return null to tell parent to return root */
		return (NULL);
	}
	/* head right, then left till null, use as new root */
	if (del->right)
		for (run = del->right; run->left; run = run->left)
		;
	else if (del->left)
		for (run = del->left; run->right; run = run->right)
		;
	/* run is the new root */
	if (del->left)
		del->left->parent = run;
	if (del->right)
		del->right->parent = run;
	/* no more left, but maybe right on run? */
	if (run->right)
	{
		run->parent->left = run->right;
		run->right->parent = run->parent;
	}
	/* set run's new values */
	run->parent = del->parent;
	run->left = del->left;
	run->right = del->right, free(del);
	return (run);
}

/**
 * bst_search - search a bst for a value
 * @tree: the root of the tree to search
 * @value: the value to search for
 * Return: pointer to the node containing the value, or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	return (pntr_search((bst_t *)tree, value));
}

/**
 * pntr_search - finds the value in the bst
 * @node: the root of the tree to search
 * @value: the value to search for
 * Return: pointer to the node containing the value, or NULL
 */
bst_t *pntr_search(bst_t *node, int value)
{
	bst_t *left, *right;
	/* exit case */
	if (!node)
		return (NULL);
	if (node->n == value)
		return (node);
	/* check left and right */
	left = pntr_search(node->left, value);
	right = pntr_search(node->right, value);
	/* figure out which to return */
	if (left)
		return (left);
	return (right);
}
