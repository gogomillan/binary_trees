#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node
 * @parent: This is the parent
 * @value: This is the payload
 * Return: A pointer to the new node or NULL if failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->left = NULL;
	node->right = NULL;

	if (parent == NULL)
		node->parent = NULL;
	else
		node->parent = parent;

	return (node);
}
