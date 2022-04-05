#include "binary_trees.h"
/**
 * binary_tree_insert_left - create a new left node to a parent on binary tree
 * @parent: node to use as the parent of the new node
 * @value: value to add to new node
 * Description - parent can not be NULL
 * Return: new node or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;
	/* check if parent exists */
	if (!parent)
		return (NULL);
	/* malloc new tree node */
	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);
	/* set values and pointers */
	new->parent = parent;
	new->n = value;
	new->right = NULL;
	/* check for existing parent->left */
	if (parent->left)
		new->left = parent->left;
	else
		new->left = NULL;

	parent->left = new;

	return (new);
}
