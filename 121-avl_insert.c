#include "binary_trees.h"
/**
 * insert - inserts a value in a Bianry Search Tree
 * @tree: double pointer to the root node of the tree
 * @value: value to store in the node
 * Return: pointer to the current node
 */

bst_t *insert(bst_t **tree, int value)
{
	binary_tree_t *new_node, *temp;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		new_node = binary_tree_node(*tree, value);
		*tree = new_node;
		return (new_node);
	}
	temp = *tree;
	while (temp)
	{
		if (value < temp->n)
		{
			if (temp->left == NULL)
			{
				new_node = binary_tree_node(temp, value);
				temp->left = new_node;
				return (new_node);
			}
			temp = temp->left;
		}
		else if (value > temp->n)
		{
			if (temp->right == NULL)
			{
				new_node = binary_tree_node(temp, value);
				temp->right = new_node;
				return (new_node);
			}
			temp = temp->right;
		}
		else
			return (NULL);
	}
	return (*tree);
}

/**
 * avl_insert - insert a value in an AVL tree
 * @tree: double pointer ot the root node of the AVL tree
 * @value: value to insert
 * Return: pointer to created node or NULL if failed
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node, *temp;
	int balance;

	if (tree == NULL)
		return (NULL);
	new_node = insert(tree, value);
	if (new_node == NULL)
		return (NULL);
	temp = new_node;
	while (new_node->parent)
	{
		balance = binary_tree_balance(new_node);
		if (balance > 1 && value > new_node->left->n)
		{
			new_node->left = binary_tree_rotate_left(new_node->left);
			new_node = binary_tree_rotate_right(new_node);
		}
		if (balance > 1 && value < new_node->left->n)
		{
			new_node = binary_tree_rotate_right(new_node);
		}
		if (balance < -1 && value > new_node->right->n)
		{
			new_node = binary_tree_rotate_left(new_node);
		}
		if (balance < -1 && value < new_node->right->n)
		{
			new_node->right = binary_tree_rotate_right(new_node->right);
			new_node = binary_tree_rotate_left(new_node);
		}
		new_node = new_node->parent;
	}
	return (temp);
}
