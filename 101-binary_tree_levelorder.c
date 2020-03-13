#include "binary_trees.h"

/**
* add_end - add a node at the end of a linkedlist
* @head: pointer to pointer to head of linkedlist
* @n: value to be stoerd in new node
* Return: pointer to new node
**/
node_l *add_end(node_l **head, int n)
{
node_l *tmp, *cur;

	tmp = malloc(sizeof(node_l));
	if (tmp == NULL)
		return (NULL);

	tmp->n = n;
	tmp->next = NULL;

	if (*head == NULL)
	{
		*head = tmp;
		return (tmp);
	}

	cur = *head;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = tmp;
	return (tmp);
}

/**
* add_tolist - add a new pointer to new linkedlist in list of list
* @head: pointer to pointer to head of list of list
* @node: pointer to head of new list
* Return: pointer to head of new list
**/
list_l *add_tolist(list_l **head, node_l *node)
{
list_l *tmp, *cur;

	tmp = malloc(sizeof(list_l));
	if (tmp == NULL)
		return (NULL);

	tmp->node = node;
	tmp->next = NULL;

	if (*head == NULL)
	{
		*head = tmp;
		return (tmp);
	}

	cur = *head;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = tmp;
	return (tmp);
}

/**
* get_node - returns a node at a given level
* @head_l: pointer to pointer to head of the list
* @level: the level at which node to be searched in the tree
* Return: found node or null
**/
node_l *get_node(list_l **head_l, int level)
{
int i;
list_l *tmp = *head_l;

	for (i = 0; i < level && tmp != NULL; i++)
	{
		if (i == level - 1)
			return (tmp->node);
		tmp = tmp->next;
	}
	return (NULL);
}

/**
* level_order_traversal - a utility function to traverse a binary tree
* using level-order traversal
* @tree: pointer to the root node of the tree to traverse
* @head_l: pointer to pointer to head of list of list
* @level: current depth of the tree
* Return: nothing
**/
void level_order_traversal(const binary_tree_t *tree, list_l **head_l,
							int level)
{
int count = 0;
list_l *tmp = *head_l;
node_l *head_n = NULL;

	if (tree == NULL)
		return;

	/* Get the list size */
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}

	/* level is not added in list of list, add it */
	if (level > count)
	{
		head_n = add_end(&head_n, tree->n);
		add_tolist(head_l, head_n);
	}
	else
	{
		/* level is in the list, retreive it to get the head */
		head_n = get_node(head_l, level);
		add_end(&head_n, tree->n);
	}

	level_order_traversal(tree->left, head_l, level + 1);
	level_order_traversal(tree->right, head_l, level + 1);
}

/**
* binary_tree_levelorder - traverses binary tree using level-order traversal
* @tree: pointer to the root node of the tree to traverse
* @func: pointer to a function to call for each node for printing
* Return: nothing
**/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
list_l *head_l = NULL;
list_l *walker;
node_l *cur, *tmp;

	if (tree == NULL || func == NULL)
		return;

	level_order_traversal(tree, &head_l, 1);

	while (head_l != NULL)
	{
		cur = head_l->node;
		while (cur != NULL)
		{
			func(cur->n);
			tmp = cur;
			cur = cur->next;
			free(tmp);
		}
		walker = head_l;
		head_l = head_l->next;
		free(walker);
	}
}
