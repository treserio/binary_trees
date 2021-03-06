#ifndef BINARY_TREES_H_
#define BINARY_TREES_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s bst_t;

void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first,
	const binary_tree_t *second
);

/* =============== */
int binary_tree_is_complete(const binary_tree_t *tree);
bool node_idx_chk(const binary_tree_t *node, size_t idx, size_t sz);

/* complete testing */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
bool print_level(binary_tree_t *node, size_t level, size_t row, void (*func)(int));

/* binary search tree */
int binary_tree_is_bst(const binary_tree_t *tree);
bool is_bst(const binary_tree_t *node, int min, int max);
/* binary search tree insert */
bst_t *bst_insert(bst_t **tree, int value);
bool my_srch(bst_t *node, int value);
bst_t *bst_add(bst_t *run, bst_t *new);
/* array to bst */
bst_t *array_to_bst(int *array, size_t size);
void binary_tree_del(binary_tree_t *tree);
/* bst_search */
bst_t *bst_search(const bst_t *tree, int value);
bst_t *pntr_search(bst_t *node, int value);
/* remove a bst node */
bst_t *bst_remove(bst_t *root, int value);
bst_t *rm_node(bst_t *old_root, bst_t *del);
void parent_lt_rt(bst_t *del, bst_t *run);

#endif /* _BINARY_TREES_H_ */
