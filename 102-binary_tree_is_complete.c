#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

int count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

int check_complete(const binary_tree_t *tree, int index, int number_nodes)
{
	if (tree == NULL)
		return (1);

	if (index >= number_nodes)
		return (0);

	return (check_complete(tree->left, 2 * index + 1, number_nodes) &&
		check_complete(tree->right, index, number_nodes));
}


/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree:  is a pointer to the root node of the tree to check
 *
 * Return: If tree is NULL, your function must return 0 otherwise return 1
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (check_complete(tree, 0, count_nodes(tree)));
}


