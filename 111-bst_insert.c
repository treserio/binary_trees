#include "binary_trees.h"
/**
 * bst_insert - insert a value into a new binary search tree (bst) node
 * @tree: a pointer to a pointer of the bst_t tree root
 * @value: the value to insert
 * Return: the new node in the bst
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new;
	/* exit case */
	if (!tree)
		return (NULL);
	/* create new node to be inserted */
	new = malloc(sizeof(bst_t));
	if (!new)
		return (NULL);
	/* set new with NULL pointers */
	new->n = value;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	/* if tree points to NULL new is now root */
	if (!(*tree))
	{
		*tree = new;
		return (new);

	}
	/* check if value is in the tree */
	if (bst_search((*tree), value))
	{
		free(new);
		return (NULL);
	}
	/* add the node to the tree with recursive function */
	return (bst_add((*tree), new));
}
/**
 * bst_search - search for a value in a bst
 * @node: the node to begin searching at
 * @value: the value to find
 * Return: 1 if the value is present, else 0
 */
bool bst_search(bst_t *node, int value)
{
	if (!node)
		return (0);
	if (node->n == value)
		return (1);
	return (bst_search(node->left, value) || bst_search(node->right, value));
}
/**
 * bst_add - insert a value into a new binary search tree (bst) node
 * @run: the current node we're at in the bst
 * @new: a pointer to the new node to insert
 * Return: the new node once added to bst
 */
bst_t *bst_add(bst_t *run, bst_t *new)
{
	/* insert left method */
	if (new->n < run->n)
	{
		/* insert here? */
		if (!run->left)
		{
			new->parent = run;
			run->left = new;
			return (new);
		}
		return (bst_add(run->left, new));
	}
	/* insert right method */
	if (new->n > run->n)
	{
		/* insert here? */
		if (!run->right)
		{
			new->parent = run;
			run->right = new;
			return (new);
		}
		return (bst_add(run->right, new));
	}
	/* value is equal */
	free(new);
	return (NULL);
}
