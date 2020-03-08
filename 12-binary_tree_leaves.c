#include "binary_trees.h"

/**
* binary_tree_leaves - function that counts the leaves in a binary tree.
* @tree: the node of the tree to count the leaves in
* Return: count of leaves or 0 if NULL
**/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
