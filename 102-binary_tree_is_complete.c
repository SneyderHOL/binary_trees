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
/**
 * binary_tree_is_full - function that checks if a binary tree is full
 * @tree: is a pointer to the root node of a tree to check
 *
 * Return: 1 if the tree is full, 0 otherwise or if is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left != NULL && tree->right != NULL)
		return (1 * binary_tree_is_full(tree->left) *
			binary_tree_is_full(tree->right));
	return (0);
}
int binary_check(const binary_tree_t *tree, int depth);
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree:  is a pointer to the root node of the tree to check
 *
 * Return: If tree is NULL, your function must return 0 otherwise return 1
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int balance = 0, level = 0;

	if (tree == NULL)
		return (0);
	balance = binary_tree_balance(tree);
	if (balance != 1 || balance != 0)
		return (0);
	if (binary_tree_is_full(tree->right) == 0)
		return (0);
	level = binary_tree_height(tree->left) - 2;
	if (binary_check(tree->left, level) == 1)
		return (1);
	return (0);
}
int binary_check(const binary_tree_t *tree, int depth)
{
	if (tree == NULL)
		return (NULL);
}
