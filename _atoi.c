#include "shell.h"

/**
 * interactive - Checks if the shell is in interactive mode.
 * @info: Pointer to the info_t struct.
 *
 * Return: 1 if the shell is in interactive mode, 0 otherwise.
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - Checks if a character is a delimiter.
 * @c: The character to check.
 * @delim: The delimiter string.
 *
 * Return: 1 if the character is a delimiter, 0 otherwise.
 */
int is_delim(char c, char *delim)
{
	for (int i = 0; delim[i] != '\0'; i++)
	{
		if (delim[i] == c)
			return (1);
	}
	return (0);
}

/**
 * _isalpha - Checks if a character is alphabetic.
 * @c: The character to check.
 *
 * Return: 1 if the character is alphabetic, 0 otherwise.
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: The converted number if the string contains numbers, 0 otherwise.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int result = 0;

	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while (*s != '\0')
	{
		if (*s >= '0' && *s <= '9')
		{
			result = result * 10 + (*s - '0');

		}
		else
		{
			break;
		}
		s++;
	}
	return (sign * result);
}
