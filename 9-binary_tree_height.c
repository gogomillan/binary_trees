#include "binary_trees.h"

/**
 * binary_tree_height - function that measures the height of a binary tree.
 *
 * @tree: Pointer to the node
 * Return: The height of the tree starting at @node
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t hl; /* height of left subtree */
size_t hr; /* height of right subtree */

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		hl = 1 + binary_tree_height(tree->left);
	else
		hl = 0;

	if (tree->right != NULL)
		hr = 1 + binary_tree_height(tree->right);
	else
		hr = 0;

	if (hl > hr)
		return (hl);
	else
		return (hr);
}
