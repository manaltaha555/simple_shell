#include "shell.h"

/**
 * _myenv - prints the current environment.
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0.
 */
int _myenv(info_t *info)
{
	list_t *node = info->env;

	while (node)
	{
		_printf("%s\n", node->str);
		node = node->next;
	}

	return (0);
}

/**
 * _getenv - gets the value of an environment variable.
 * @info: Structure containing potential arguments.
 * @name: The name of the environment variable.
 *
 * Return: The value of the environment variable or NULL if not found.
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	size_t name_len = _strlen(name);

	while (node)
	{
		if (_strncmp(node->str, name, name_len) == 0 && node->str[name_len] == '=')
			return (node->str + name_len + 1);
		node = node->next;
	}

	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable or modify an existing one.
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0.
 */
int _mysetenv(info_t *info)
{
	char *name, *value;
	int ret;

	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}

	name = info->argv[1];
	value = info->argv[2];

	ret = setenv(name, value, 1);

	if (ret == -1)
	{
		_eputs("Failed to set environment variable\n");
		return (1);
	}

	return (0);
}

/**
 * _myunsetenv - Remove an environment variable.
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0.
 */
int _myunsetenv(info_t *info)
{
	int i, ret;

	if (info->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}

	for (i = 1; i < info->argc; i++)
	{
		ret = unsetenv(info->argv[i]);

		if (ret == -1)
			_eputs("Failed to unset environment variable\n");
	}

	return (0);
}

/**
 * populate_env_list - populates env linked list.
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0.
 */
int populate_env_list(info_t *info)
{
	extern char **environ;
	char **env_ptr = environ;
	list_t *node = NULL;

	while (*env_ptr)
	{
		add_node_end(&node, *env_ptr, 0);
		env_ptr++;
	}

	info->env = node;

	return (0);
}
