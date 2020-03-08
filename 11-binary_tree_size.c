#include "binary_trees.h"

/**
 * binary_tree_size - function that measures the size of a binary tree.
 *
 * @tree: Pointer to the node
 * Return: The size of the tree starting at @node
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
size_t ql = 0; /* quantity of left subtree */
size_t qr = 0; /* quantity of right subtree */
static binary_tree_t *root; /* Node root */

	if (tree == NULL)
		return (0);

	if (root == NULL)
		root = (binary_tree_t *)tree;

	if (tree->left != NULL)
		ql = 1 + binary_tree_size(tree->left);

	if (tree->right != NULL)
		qr = 1 + binary_tree_size(tree->right);

	if (root == tree)
	{
		root = NULL;
		return (1 + ql + qr);
	}
	return (ql + qr);
}
