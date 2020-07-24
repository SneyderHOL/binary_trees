#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: is a pointer to the root node of the tree to rotate
 *
 * Return:  return a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *change = tree->left, *help = NULL;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	/* Borrando las conecciones */
	tree->left = NULL;
	change->parent = NULL;

	if (change->right != NULL)
	{
		help = change->right;
		/* Borrando las conecciones */
		change->right = NULL;
		help->parent = NULL;
		/* make las conecciones */
		tree->left = help;
		help->parent = tree;
	}
	change->right = tree;
	tree->parent = change;
	return (change);
}
