#include <stdlib.h>
#include "binary_trees.h"

/**
 * find_num - find the bigger or the smallest number in a binary tree depending
 * of the operation integer
 * @tree: is a pointer to the root node of a tree to check
 * @op: operation to perform, 0 the smallest number, 1 the biggest number
 * @base: base number to compare
 *
 * Return: the found number
 */

int find_num(const binary_tree_t *tree, int op, int base)
{
	int left = 0, right = 0, num = base;

	if (tree == NULL)
		return (base);
	left = find_num(tree->left, op, tree->n);
	right = find_num(tree->right, op, tree->n);
	if (op == 0)
	{
		if (left < right)
			num = left;
		else
			num = right;
	}
	else
	{
		if (left > right)
			num = left;
		else
			num = right;
	}
	return (num);
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
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left != NULL)
	{
		if (tree->left->n < tree->n)
			left *= binary_tree_is_bst(tree->left);
		else
			return (0);
	}
	if (left == 0)
		return (0);
	if (tree->right != NULL)
	{
		if (tree->right->n > tree->n)
			right *= binary_tree_is_bst(tree->right);
		else
			return (0);
	}
	if (right == 0)
		return (0);
	if (tree->parent == NULL)
	{
		if (find_num(tree->left, 1, tree->n) > tree->n)
			left = 0;
		if (find_num(tree->right, 0, tree->n) < tree->n)
			right = 0;
	}
	return (left * right);
}
