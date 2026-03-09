#include "main.h"

/**
 * flush_buffer - writes buffer to stdout
 */
void flush_buffer(char *buffer, int *buff_ind)
{
    if (*buff_ind > 0)
    {
        write(1, buffer, *buff_ind);
        *buff_ind = 0;
    }
}

/**
 * print_char - prints a character
 */
int print_char(va_list args, char *buffer, int *buff_ind)
{
    char c = va_arg(args, int);

    buffer[(*buff_ind)++] = c;

    if (*buff_ind == BUFFER_SIZE)
        flush_buffer(buffer, buff_ind);

    return (1);
}

/**
 * print_percent - prints %
 */
int print_percent(char *buffer, int *buff_ind)
{
    buffer[(*buff_ind)++] = '%';

    if (*buff_ind == BUFFER_SIZE)
        flush_buffer(buffer, buff_ind);

    return (1);
}

/**
 * print_string - prints string
 */
int print_string(va_list args, char *buffer, int *buff_ind)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (!str)
        str = "(null)";

    while (*str)
    {
        buffer[(*buff_ind)++] = *str++;
        count++;

        if (*buff_ind == BUFFER_SIZE)
            flush_buffer(buffer, buff_ind);
    }

    return count;
}

/**
 * print_S - prints string with non-printables as \xHH
 */
int print_S(va_list args, char *buffer, int *buff_ind)
{
    char *str = va_arg(args, char *);
    int count = 0;
    char hex[3];
    int i;

    if (!str)
        str = "(null)";

    while (*str)
    {
        if ((*str > 0 && *str < 32) || *str >= 127)
        {
            buffer[(*buff_ind)++] = '\\';
            buffer[(*buff_ind)++] = 'x';
            hex[0] = "0123456789ABCDEF"[*str / 16];
            hex[1] = "0123456789ABCDEF"[*str % 16];
            hex[2] = '\0';

            for (i = 0; i < 2; i++)
            {
                buffer[(*buff_ind)++] = hex[i];
                if (*buff_ind == BUFFER_SIZE)
                    flush_buffer(buffer, buff_ind);
            }

            count += 4; /* \xHH */
        }
        else
        {
            buffer[(*buff_ind)++] = *str;
            count++;
            if (*buff_ind == BUFFER_SIZE)
                flush_buffer(buffer, buff_ind);
        }
        str++;
    }

    return count;
}

/**
 * print_int - prints integer
 */
int print_int(va_list args, char *buffer, int *buff_ind)
{
    int n = va_arg(args, int);
    unsigned int num;
    char temp[12];
    int i = 0, count = 0;

    if (n < 0)
    {
        buffer[(*buff_ind)++] = '-';
        count++;

        if (*buff_ind == BUFFER_SIZE)
            flush_buffer(buffer, buff_ind);

        num = -((unsigned int)n);
    }
    else
        num = n;

    if (num == 0)
    {
        buffer[(*buff_ind)++] = '0';

        if (*buff_ind == BUFFER_SIZE)
            flush_buffer(buffer, buff_ind);

        return (count + 1);
    }

    while (num)
    {
        temp[i++] = (num % 10) + '0';
        num /= 10;
    }

    while (i--)
    {
        buffer[(*buff_ind)++] = temp[i];
        count++;

        if (*buff_ind == BUFFER_SIZE)
            flush_buffer(buffer, buff_ind);
    }

    return (count);
}

/**
 * print_binary - prints binary
 */
int print_binary(va_list args, char *buffer, int *buff_ind)
{
    unsigned int n = va_arg(args, unsigned int);
    char temp[32];
    int i = 0, count = 0;

    if (n == 0)
    {
        buffer[(*buff_ind)++] = '0';

        if (*buff_ind == BUFFER_SIZE)
            flush_buffer(buffer, buff_ind);

        return (1);
    }

    while (n)
    {
        temp[i++] = (n % 2) + '0';
        n /= 2;
    }

    while (i--)
    {
        buffer[(*buff_ind)++] = temp[i];
        count++;

        if (*buff_ind == BUFFER_SIZE)
            flush_buffer(buffer, buff_ind);
    }

    return (count);
}

/**
 * print_unsigned - prints unsigned int
 */
int print_unsigned(va_list args, char *buffer, int *buff_ind)
{
    unsigned int n = va_arg(args, unsigned int);
    char temp[20];
    int i = 0, count = 0;

    if (n == 0)
    {
        buffer[(*buff_ind)++] = '0';

        if (*buff_ind == BUFFER_SIZE)
            flush_buffer(buffer, buff_ind);

        return (1);
    }

    while (n)
    {
        temp[i++] = (n % 10) + '0';
        n /= 10;
    }

    while (i--)
    {
        buffer[(*buff_ind)++] = temp[i];
        count++;

        if (*buff_ind == BUFFER_SIZE)
            flush_buffer(buffer, buff_ind);
    }

    return (count);
}

/**
 * print_octal - prints octal
 */
int print_octal(va_list args, char *buffer, int *buff_ind)
{
    unsigned int n = va_arg(args, unsigned int);
    char temp[20];
    int i = 0, count = 0;

    if (n == 0)
    {
        buffer[(*buff_ind)++] = '0';

        if (*buff_ind == BUFFER_SIZE)
            flush_buffer(buffer, buff_ind);

        return (1);
    }

    while (n)
    {
        temp[i++] = (n % 8) + '0';
        n /= 8;
    }

    while (i--)
    {
        buffer[(*buff_ind)++] = temp[i];
        count++;

        if (*buff_ind == BUFFER_SIZE)
            flush_buffer(buffer, buff_ind);
    }

    return (count);
}

/**
 * print_hex - prints hexadecimal
 */
int print_hex(va_list args, int uppercase, char *buffer, int *buff_ind)
{
    unsigned int n = va_arg(args, unsigned int);
    char temp[20];
    char *hex = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    int i = 0, count = 0;

    if (n == 0)
    {
        buffer[(*buff_ind)++] = '0';

        if (*buff_ind == BUFFER_SIZE)
            flush_buffer(buffer, buff_ind);

        return (1);
    }

    while (n)
    {
        temp[i++] = hex[n % 16];
        n /= 16;
    }

    while (i--)
    {
        buffer[(*buff_ind)++] = temp[i];
        count++;

        if (*buff_ind == BUFFER_SIZE)
            flush_buffer(buffer, buff_ind);
    }

    return (count);
}
