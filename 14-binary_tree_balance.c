#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: is a pointer to the root node of a tree to measure the height
 *
 * Return: the height of the tree, or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0, height_r = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		height_l = 1 + binary_tree_height(tree->left);
	if (tree->right != NULL)
		height_r = 1 + binary_tree_height(tree->right);
	if (height_l > height_r)
		return (height_l);
	return (height_r);
}


/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the
 * balance factor
 *
 * Return: the balance number to the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left = 1;
	if (tree->right)
		right = 1;

	left += binary_tree_height(tree->left);
	right += binary_tree_height(tree->right);

	return (left - right);
}
