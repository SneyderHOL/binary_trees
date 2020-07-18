#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_size - function that measures the size of a binary tree
 * @tree: is a pointer to the root node of a tree to measure the size
 *
 * Return: the size of the tree, or 0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t height_l = 0, height_r = 0, index = 1;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		height_l = binary_tree_size(tree->left);
	if (tree->right != NULL)
		height_r = binary_tree_size(tree->right);
	return (height_l + height_r + index);
}
