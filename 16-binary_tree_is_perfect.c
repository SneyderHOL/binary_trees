#include <stdlib.h>
#include "binary_trees.h"

/**
 * leaf_depth - store the initial depth of the first leaf and compares with
 * other leafs
 * @depth_leaf: depth value of the leaf
 *
 * Return: 1 if the depths values are the same, 0 otherwise
 */

int leaf_depth(int depth_leaf)
{
	static int depth = -1;

	if (depth == -1)
		depth = depth_leaf;
	else
	{
		if (depth != depth_leaf)
			return (0);
	}
	return (1);
}
/**
 * binary_tree_depth -  measures the depth of a node in a binary tree
 * @tree: is the whole tree
 *
 * Return: tree is NULL, the function must return 0, otherwise return the num
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	const binary_tree_t *aux = NULL;
	size_t i = -1;

	if (tree == NULL)
		return (0);
	for (aux = tree; aux != NULL; aux = aux->parent, i++)
		;

	return (i);
}

/**
 * binary_tree_is_perfect -  checks if a binary tree is perfect
 * @tree: is a pointer to the root node of a tree to measure the height
 *
 * Return: 1 if binary tree is perfect, or 0 if tree is NULL or not perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left != NULL && tree->right != NULL)
	{
		return (1 * binary_tree_is_perfect(tree->left) *
			binary_tree_is_perfect(tree->right));
	}
	if (tree->left == NULL && tree->right == NULL)
		return (leaf_depth((int) binary_tree_depth(tree)));

	return (0);
}
