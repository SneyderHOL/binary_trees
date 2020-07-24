#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: is the whole tree
 *
 * Return: tree is NULL, the function must return 0, otherwise return the num
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *change = tree->right, *help = NULL;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	/* Borrando las conecciones */
	tree->right = NULL;
	change->parent = NULL;

	if (change->left != NULL)
	{
		help = change->left;
		/* Borrando las conecciones */
		change->left = NULL;
		help->parent = NULL;
		/* make las conecciones */
		tree->right = help;
		help->parent = tree;
	}
	change->left = tree;
	tree->parent = change;
	return (change);
}
