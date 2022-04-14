#include "binary_trees.h"
/**
 * array_to_bst - turn an unsorted array into a bst
 * @array: the array of values to use
 * @size: the number of values in the array
 * Return: the root node, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *new, *root;
	/* exit case */
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
