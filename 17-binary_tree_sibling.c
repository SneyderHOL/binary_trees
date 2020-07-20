#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_sibling - function that finds the sibling of a node
 * @node: is a pointer to the node to find the sibling
 *
 * Return: pointer to the sibling node, or NULL if the node is NULL, or the
 * parent is NULL, or the node has no sibling.
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *aux = NULL;

	if (node == NULL)
		return (NULL);
	if (node->parent == NULL)
		return (NULL);
	aux = node->parent;
	if (aux->left == node)
		return (aux->right);
	return (aux->left);
}
