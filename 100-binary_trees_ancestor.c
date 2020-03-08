#include "binary_trees.h"

int _depth(const binary_tree_t *node);

/**
* binary_trees_ancestor - finds the lowest common ancestor of two nodes.
* @first: the first node.
* @second: the second node.
* Return: the lowest common ancestor node of first and second.
* or NULL
**/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									const binary_tree_t *second)
{
int diff;
const binary_tree_t *node;

	/* compare both depths */
	diff = _depth(first) - _depth(second);
	/* make the first node the deeper */
	if (diff < 0)
	{
		node = second;
		second = first;
		first = node;
		diff *= -1;
	}
	/* make nodes at same level */
	while (diff--)
		first = first->parent;
	/* check for the same parent */
	while (first != NULL && second != NULL)
	{
		if (first->n == second->n)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return (NULL);
}

/**
* _depth - finds the depth of given node
* @node: pointer to given node
* Return: depth of node or 0 if node is NULL
**/
int _depth(const binary_tree_t *node)
{
const binary_tree_t *tmp = node;
int depth = -1;

	while (tmp != NULL)
	{
		++depth;
		tmp = tmp->parent;
	}
	return (depth);
}
