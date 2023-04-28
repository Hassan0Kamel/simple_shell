#include "shell.h"

/**
 * add_node - adding a
 * @head: address of po head node
 * @str: str field
 * @num: nodex used by history
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * add_node_end - he end of the list
 * @head: address of pointer to head node
 * @str: strof node
 * @num: node index usory
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * print_list_str - prints onlyt linked list
 * @x: pointer t node
 * Return: size of list
 */
size_t print_list_str(const list_t *x)
{
	size_t c = 0;

	while (x)
	{
		_puts(x->str ? x->str : "(nil)");
		_puts("\n");
		x = x->next;
		c++;
	}
	return (c);
}

/**
 * delete_node_at_index - deletes node atndex
 * @headed: a pointer to first node
 * @index: index o
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **headed, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!headed || !*headed)
		return (0);

	if (!index)
	{
		node = *headed;
		*headed = (*headed)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *headed;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees all na list
 * @head_pointer: addre
 * Return: voidd
 */
void free_list(list_t **head_pointer)
{
	list_t *node, *next_node, *head;

	if (!head_pointer || !*head_pointer)
		return;
	head = *head_pointer;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_pointer = NULL;
}
