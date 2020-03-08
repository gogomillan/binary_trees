#include "binary_trees.h"

int greater(int left, int right);
int _height(const binary_tree_t *tree);

/**
* binary_tree_balance - measures the balance factor of a binary tree.
* @tree: the node of the tree to measure the balance factor of
* Return: balance factor or 0
**/
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (_height(tree->left) - _height(tree->right));
}

/**
* _height - calculates height of root
* @tree: pointer to root node of tree to count height of
* Return: height or 0
**/
int _height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + greater(_height(tree->left), _height(tree->right)));
}

/**
* greater - returns max between two numbers
* @left: number 1
* @right: number 2
* Return: the maximum
**/
int greater(int left, int right)
{
	if (left > right)
		return (left);
	return (right);
}
