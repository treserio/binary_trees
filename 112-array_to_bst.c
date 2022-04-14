#include "binary_trees.h"
/**
 * bst_insert - insert a value into a new binary search tree (bst) node
 * @tree: a pointer to a pointer of the bst_t tree root
 * @value: the value to insert
 * Return: the new node in the bst
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *new, *root;
	if (!array)
		return (NULL);
	/* set the root node */
	root = malloc(sizeof(bst_t));
	if (!root)
		return (NULL);
	root->parent = NULL;
	root->left = NULL;
	root->right = NULL;
	root->n = array[0];
	/* on failure free tree ... ugh */
	for (i = 1; i < size; ++i)
	{
		new = malloc(sizeof(bst_t));
		if (!new)
		{
			binary_tree_delete(root);
			return (NULL);
		}
		new->parent = NULL;
		new->left = NULL;
		new->right = NULL;
		new->n = array[i];
		bst_add(root, new);
	}
	return (root);
}

/**
 * binary_tree_delete - free a binary tree
 * @tree: root of the tree to delete
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}
