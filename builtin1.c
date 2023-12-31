#include "shell.h"

/**
 * _myhistory - displays the history list, one command per line, preceded
 *              by line numbers starting at 0.
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0.
 */
int _myhistory(info_t *info)
{
	list_t *node = info->history;
	int line_number = 0;

	while (node)
	{
		printf("%d %s\n", line_number, node->str);
		line_number++;
		node = node->next;
	}

	return (0);
}

/**
 * unset_alias - removes an alias from the alias list.
 * @info: Structure containing potential arguments.
 * @str: The string representing the alias.
 *
 * Return: Always 0 on success, 1 on error.
 */
int unset_alias(info_t *info, char *str)
{
	int ret;

	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));

	return (ret);
}

/**
 * set_alias - sets an alias in the alias list.
 * @info: Structure containing potential arguments.
 * @str: The string representing the alias.
 *
 * Return: Always 0 on success, 1 on error.
 */
int set_alias(info_t *info, char *str)
{
	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string.
 * @node: The alias node.
 *
 * Return: Always 0.
 */
int print_alias(list_t *node)
{
	char *p;

	if (node)
	{
		p = _strchr(node->str, '=');
		printf("%.*s'%s'\n", (int)(p - node->str), node->str, p + 1);
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias).
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0.
 */
int _myalias(info_t *info)
{
	int i;
	char *p;
	list_t *node;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}

	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
