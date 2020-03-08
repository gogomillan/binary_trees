#include "binary_trees.h"

size_t greater(size_t left, size_t right);
size_t count_nodes(const binary_tree_t *tree);
size_t _height(const binary_tree_t *tree);
size_t _exp(size_t x);

/**
* binary_tree_is_perfect - checks if a binary tree is perfect
* @tree:  pointer to the root node of the tree to check
* Return: 1 if tree is perfect and 0 if not or tree is NULL
**/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
size_t total_nodes, height;

	if (tree == NULL)
		return (0);

	height = _height(tree);
	total_nodes = count_nodes(tree);

	/* formula : 2 ^ level + 1 - 1 nodes*/
	if (total_nodes == _exp(height) - 1)
		return (1);
	return (0);
}

/**
* _exp - calculates the power of 2
* @x: exponent power of 2
* Return: 2^n
**/
size_t _exp(size_t x)
{
size_t result = 1;

	if (x == 0)
		return (result);
	while (x > 0)
	{
		result *= 2;
		x -= 1;
	}
	return (result);
}

/**
* _height - calculates height of a given binary tree, considering root
* at height 1.
* @tree: pointer to the root node of the tree to check
* Return: height of tree or 0
**/
size_t _height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + greater(_height(tree->left), _height(tree->right)));
}

/**
* count_nodes - counts total number of nodes of the tree
* @tree: pointer to root node of tree
* Return: total number of nodes or 0
**/
size_t count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
* greater - compares two ints to return the maximum of two
* @left: first number
* @right: second number
* Return: max of two
**/
size_t greater(size_t left, size_t right)
{
	if (left >= right)
		return (left);
	return (right);
}
