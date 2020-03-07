#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	node->n = value;
	node->left = NULL;
	node->right = NULL;

	if (parent == NULL)
		node->parent = NULL;
	else
		node->parent = parent;

	return (node);
}
