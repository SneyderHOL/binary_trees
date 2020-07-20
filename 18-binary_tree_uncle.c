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

/**
 * binary_tree_is_branch - function that checks if a given node is a Branch
 * @node: is a pointer to the node to check
 *
 * Return: 1 if node is a Branch, otherwise 0
 */

int binary_tree_is_branch(const binary_tree_t *node)
{
	if (node->right != NULL && node->left != NULL)
		return (1);
	return (0);
}


/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: is a pointer to the node to find the uncle
 *
 * Return: pointer to the uncle node or NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
     int depth = 0;
     binary_tree_t *grand_parent = NULL, *n_parent = NULL;

     if (node == NULL)
          return (NULL);

     depth = binary_tree_depth(node);

     if (depth < 2)
          return (NULL);

     if (binary_tree_is_branch(node->parent->parent) == 0)
          return (NULL);

     grand_parent = node->parent->parent;
     n_parent = node->parent;

     if (grand_parent->right == n_parent)
          return (grand_parent->left);

     return (grand_parent->right);

}
