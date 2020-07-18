#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_postorder -  measures the depth of a node in a binary tree
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
