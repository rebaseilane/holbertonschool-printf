#include "main.h"

/**
 * print_char - prints a character
 * @args: list of arguments
 *
 * Return: 1
 */
int print_char(va_list args)
{
    char c;

    c = va_arg(args, int);
    write(1, &c, 1);

    return (1);
}

/**
 * print_string - prints a string
 * @args: list of arguments
 *
 * Return: length of string
 */
int print_string(va_list args)
{
    char *str;
    int len = 0;

    str = va_arg(args, char *);

    if (!str)
        str = "(null)";

    while (str[len])
        len++;

    write(1, str, len);

    return (len);
}

/**
 * print_percent - prints %
 *
 * Return: 1
 */
int print_percent(void)
{
    write(1, "%", 1);
    return (1);
}
