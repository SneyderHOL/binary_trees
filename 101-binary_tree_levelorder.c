#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * traversal
 * @tree: is a pointer to the root tree to traverse
 * @func: is a pointer to a function to call for each node.
 *
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{

	const binary_tree_t *queue[1024];
	const binary_tree_t *node_to_print = NULL;
	int front = 0, count = 0;

	if (tree == NULL || func == NULL)
		return;

	queue[front + count++] = tree;

	while (count--)
	{
		node_to_print = queue[front];
		front++;
		func(node_to_print->n);

		if (node_to_print->left)
			queue[front + count] = node_to_print->left, count++;
		if (node_to_print->right)
			queue[front + count] = node_to_print->right, count++;
	}
}
