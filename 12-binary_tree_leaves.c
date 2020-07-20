#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: is a pointer to the node to check
 *
 * Return: 1 if node is a leaf, otherwise 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->right == NULL && node->left == NULL)
		return (1);
	else
		return (0);
}

/**
 * total - Is the total of the leaf
 * @tree: is the whole tree
 * @result: is a pointer to the total of the leafs
 *
 */

void total(const binary_tree_t *tree, int *result)
{
	if (tree == NULL)
		return;

	*result += binary_tree_is_leaf(tree);
	total(tree->right, result);
	total(tree->left, result);
}

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: is the whole tree
 *
 * Return: tree is NULL, the function must return 0, otherwise return the num
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	int result = 0;

	total(tree, &result);

	return (result);
}
