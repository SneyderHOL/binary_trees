#include <stdio.h>
#include "binary_trees.h"

/**
 * max_value - checks the max of a binary tree
 * @tree: checks the max of a binary tree
 *
 * Return: the min of the binary tree
 */
int max_value(const binary_tree_t *tree)
{
	int number_left = 0, number_right = 0, max = tree->n;

	if (tree->left != NULL)
	{
		number_left = max_value(tree->left);
		if (max < number_left)
			max = number_left;
	}

	if (tree->right != NULL)
	{
		number_right = max_value(tree->right);
		if (max < number_right)
			max = number_right;
	}

	return (max);
}
/**
 * min_value - checks the max of a binary tree
 * @tree: checks the max of a binary tree
 *
 * Return: the min of the binary tree
 */
int min_value(const binary_tree_t *tree)
{
	int number_left = 0, number_right = 0, max = tree->n;

	if (tree->left != NULL)
	{
		number_left = min_value(tree->left);
		if (max > number_left)
			max = number_left;
	}

	if (tree->right != NULL)
	{
		number_right = min_value(tree->right);
		if (max > number_right)
			max = number_right;
	}

	return (max);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid
 * Binary Search Tree
 * @tree: checks if a binary tree is a valid Binary Search Tree
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int val = 1;

	if (tree != NULL)
	{

		if (tree->left != NULL && max_value(tree->left) > tree->n)
			return (0);

		if (tree->right != NULL && min_value(tree->right) < tree->n)
			return (0);

		val *= binary_tree_is_bst(tree->left);
		val *= binary_tree_is_bst(tree->right);
	}

	return (val);

}
