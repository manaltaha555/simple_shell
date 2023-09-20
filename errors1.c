#include "shell.h"

/**
 * _erratoi - converts a string to an integer
 * @s: the string to be converted
 *
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _erratoi(const char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
	{
		s++;
	}
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
		{
			return (-1);
		}
	}
	return ((int)result);
}

/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 *
 * Return: void
 */
void print_error(const info_t *info, char *estr)
{
	if (info != NULL && info->fname != NULL && info->argv != NULL)
	{
		_eputs(info->fname);
		_eputs(": ");
		print_d(info->line_count, STDERR_FILENO);
		_eputs(": ");
		_eputs(info->argv[0]);
		_eputs(": ");
		_eputs(estr);
	}
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int count = 0;

	if (fd == STDERR_FILENO)
	{
		count += _putchar('-');
	}
	if (input < 0)
	{
		input = -input;
	}
	if (input / 10)
	{
		count += print_d(input / 10, fd);
	}
	count += _putchar('0' + (input % 10));
	return (count);
}

/**
 * convert_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char buffer[50];
	char *ptr;
	unsigned long n = num;
	char sign = 0;
	char upper[] = {"0123456789ABCDEF"};
	char lower[] = {"0123456789abcdef"};
	const char *array = (flags & CONVERT_LOWERCASE) ? lower : upper;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);
	if (sign)
	{
		*--ptr = sign;
	}
	return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf:address of the string to modify
 *
 * Return: void
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
	{
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
	}
}
