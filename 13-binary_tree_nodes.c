#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_nodes - function that counts the nodes with at least 1 child in
 * a binary tree.
 * @tree: is a pointer to the root node of a tree to count the number of nodes
 *
 * Return: the number of node that have at least one child, or 0 there are none
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t number_of_child_l = 0, number_of_child_r = 0, index = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL || tree->right != NULL)
		index = 1;
	number_of_child_l = binary_tree_nodes(tree->left);
	number_of_child_r = binary_tree_nodes(tree->right);
	return (number_of_child_l + number_of_child_r + index);
}
