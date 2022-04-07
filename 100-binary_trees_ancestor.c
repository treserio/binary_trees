#include "binary_trees.h"
/**
 * binary_trees_ancestor - find the lowest common ancestor
 * @first: first node to find the common ancestor of
 * @second: second node to find the common ancestor of
 * Return: pointer to common ancestor if present, else NULL
 */
binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first,
	const binary_tree_t *second
)
{
	binary_tree_t *f_run, *s_run;
	int found = 0;

	/* exit case */
	if (!first || !second)
		return NULL;

	for (f_run = (binary_tree_t *)first;
		f_run && !found;
		f_run = f_run->parent)
	{
		for (s_run = (binary_tree_t *)second; s_run; s_run = s_run->parent)
		{
			if (s_run == f_run)
			{
				++found;
				break;
			}
		}
	}
	return (s_run);
}
