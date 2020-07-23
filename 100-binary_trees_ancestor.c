#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_depth -  measures the depth of a node in a binary tree
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
 * binary_trees_ancestor - search into the two nodes
 * @first:  is a pointer to the first node
 * @second: is a pointer to the second node
 *
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 * If no common ancestor was found, your function must return NULL
 */
binary_tree_t *search_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *) first);

	/*printf("first %d, second %d \n", first->n, second->n);*/

	return (search_ancestor(first->parent, second->parent));
}


/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first:  is a pointer to the first node
 * @second: is a pointer to the second node
 *
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 * If no common ancestor was found, your function must return NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	size_t depth_first = 0, depth_second = 0;

	if (first == NULL || second == NULL)
		return (NULL);

	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);

	if (depth_second != depth_first)
	{
		if (depth_first > depth_second)
		{
			while (depth_second != depth_first)
			{
				first = first->parent;
				depth_first--;
			}
		}
		else
		{
			while (depth_second != depth_first)
			{
				second = second->parent;
				depth_second--;
			}
		}
	}

	return (search_ancestor(first, second));

}
