#include "main.h"

/**
 * print_char - prints a character
 * @args: list of arguments
 * Return: 1
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);
    write(1, &c, 1);
    return (1);
}

/**
 * print_string - prints a string
 * @args: list of arguments
 * Return: length of string
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int len = 0;

    if (!str)
        str = "(null)";

    while (str[len])
        len++;

    write(1, str, len);
    return (len);
}

/**
 * print_percent - prints '%'
 * Return: 1
 */
int print_percent(void)
{
    write(1, "%", 1);
    return (1);
}

/**
 * print_int - prints an integer
 * @args: list of arguments
 * Return: number of characters printed
 */
int print_int(va_list args)
{
    int n = va_arg(args, int);
    char buffer[12]; /* enough for -2147483648 + '\0' */
    int i = 0, j, count = 0;
    unsigned int num;

    if (n < 0)
    {
        write(1, "-", 1);
        count++;
        num = -n;
    }
    else
        num = n;

    if (num == 0)
    {
        write(1, "0", 1);
        return count + 1;
    }

    while (num > 0)
    {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    }

    for (j = i - 1; j >= 0; j--)
        count += write(1, &buffer[j], 1);

    return count;
}

/**
 * print_binary - prints an unsigned int in binary
 * @args: list of arguments
 * Return: number of characters printed
 */
int print_binary(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    char buffer[32];
    int i = 0, count = 0;

    if (n == 0)
    {
        write(1, "0", 1);
        return 1;
    }

    while (n > 0)
    {
        buffer[i++] = (n % 2) + '0';
        n /= 2;
    }

    for (i = i - 1; i >= 0; i--)
        count += write(1, &buffer[i], 1);

    return count;
}
