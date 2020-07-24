#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_left_side - checks if a binary subtree is a valid Binary
 * Search Tree
 * @tree: is a pointer to the root node of a tree to check
 * @num: number of root node
 *
 * Return: 1 if binary subtree is a valid BST, or 0 otherwise
 */

int binary_tree_left_side(const binary_tree_t *tree, int num)
{
	int left = 1, right = 1;

	if (tree->left != NULL)
	{
		if (tree->left->n < tree->n)
			left *= binary_tree_left_side(tree->left, num);
		else
			return (0);
	}
	if (left == 0)
		return (0);
	if (tree->right != NULL)
	{
		if (tree->right->n > tree->n && tree->right->n < num)
			right *= binary_tree_left_side(tree->right, num);
		else
			return (0);
	}
	if (right == 0)
		return (0);
	return (1);
}
/**
 * binary_tree_right_side -  checks if a binary subtree is a valid Binary
 * Search Tree
 * @tree: is a pointer to the root node of a tree to check
 * @num: number of root node
 *
 * Return: 1 if binary subtree is a valid BST, or 0 otherwise
 */

int binary_tree_right_side(const binary_tree_t *tree, int num)
{
	int left = 1, right = 1;

	if (tree->left != NULL)
	{
		if (tree->left->n < tree->n && tree->left->n > num)
			left *= binary_tree_left_side(tree->left, num);
		else
			return (0);
	}
	if (left == 0)
		return (0);
	if (tree->right != NULL)
	{
		if (tree->right->n > tree->n)
			right *= binary_tree_left_side(tree->right, num);
		else
			return (0);
	}
	if (right == 0)
		return (0);
	return (1);
}

/**
 * binary_tree_is_bst -  checks if a binary tree is a valid Binary Search Tree
 * @tree: is a pointer to the root node of a tree to check
 *
 * Return: 1 if binary tree is a valid BST, or 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int left = 1, right = 1;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL && tree->right == NULL)
		return (0);
	if (tree->left != NULL)
	{
		if (tree->left->n < tree->n)
			left = binary_tree_left_side(tree->left, tree->n);
		else
			return (0);
	}
	if (left == 0)
		return (0);
	if (tree->right != NULL)
	{
		if (tree->right->n > tree->n)
			right = binary_tree_right_side(tree->right, tree->n);
		else
			return (0);
	}
	if (right == 0)
		return (0);
	return (1);
}
