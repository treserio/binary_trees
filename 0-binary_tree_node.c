#include "binary_trees.h"
/**
 * binary_tree_node - create a new binary tree node
 * @parent: node to use as the parent of the new node
 * @value: value to add to new node
 * Description - parent can be NULL for new ROOT node of tree
 * Return: new node or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = malloc(sizeof(binary_tree_t));

	if (!new)
		return (NULL);

	new->parent = parent;
	new->n = value;

	return (new);
}
