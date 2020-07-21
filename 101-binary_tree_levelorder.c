#include <stdlib.h>
#include "binary_trees.h"

binary_tree_t *funcion(binary_tree_t *tree)
{
	if (tree == NULL)
		return (NULL);

}

/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * traversal
 * @tree: is a pointer to the root tree to traverse
 * @func: is a pointer to a function to call for each node.
 *
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *left = NULL, *right = NULL, *aux = NULL;

	if (tree == NULL || func == NULL)
		return;
	aux = tree;
	left = tree->left;
	right = tree->right;
	if (tree->parent == NULL)
		func(tree->n);
	while (left != NULL || right != NULL)
	{
		if (left != NULL)
			func(left->n);
			/*funcion(left);*/
		if (right != NULL)
			func(right->n);
			/*funcion(right);*/
		
	}
	/*binary_tree_preorder(tree->left, func);
	  binary_tree_preorder(tree->right, func);*/
}
