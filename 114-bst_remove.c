#include "binary_trees.h"
/**
 * bst_remove - finds a value to delete from a bst
 * @root: the root of the tree to search
 * @value: the value to search for
 * Return: pointer to the root of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *target, *new_root;
	/* assume root is a node */
	if (root->n == value)
		return (rm_node(root, root));
	target = bst_search(root, value);
	new_root = rm_node(root, target);
	return (new_root);
}
/**
 * rm_node - removes the node and returns the root
 * @old_root: original root of the tree
 * @del: the node to delete from the tree
 * Return: the new root of the tree, if old_root was del
 */
bst_t *rm_node(bst_t *old_root, bst_t *del)
{
	bst_t *run;
	/* check if we're on a leaf */
	if (!del->left && !del->right)
	{
		parent_lt_rt(del, NULL);
		free(del);
		return (old_root);
	}
	if (del->right)
		for (run = del->right; run->left; run = run->left)
		;
	else if (del->left)
		for (run = del->left; run->right; run = run->right)
		;
	else
	{
		parent_lt_rt(del, NULL), free(del);
		return (old_root);
	}
	if (del->left && del->left != run)
		del->left->parent = run;
	if (del->right && del->right != run)
		del->right->parent = run;
	parent_lt_rt(del, run);
	run->parent = del->parent;
	run->left = del->left;
	run->right = del->right;
	if (old_root != del)
		run = old_root;
	free(del);
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
/**
 * parent_lt_rt - decide which side of del->parent del is on & change to run
 * Description: will also pull up run's ancestors to attach to it's parent
 * @del: the node to delete from the tree
 * @run: the replacement node for del
 */
void parent_lt_rt(bst_t *del, bst_t *run)
{
	if (del->parent && (del->parent->left == del))
		del->parent->left = run;
	else if (del->parent && (del->parent->right == del))
		del->parent->right = run;
	/* pull up any of run's ancestors */
	if (run && run->right)
	{
		run->parent->left = run->right;
		run->right->parent = run->parent;
	}
	else if (run && run->left)
	{
		run->parent->right = run->left;
		run->left->parent = run->parent;
	}
	/* NULL run->parent->left or right if == run */
	if (run && run->parent && run->parent->left && run->parent->left == run)
		run->parent->left = NULL;
	else if (run && run->parent && run->parent->right &&
		run->parent->right == run)
		run->parent->right = NULL;
}
