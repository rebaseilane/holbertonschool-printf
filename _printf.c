#include "main.h"

#define BUFFER_SIZE 1024

/**
 * _printf - produces output according to a format
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    char buffer[BUFFER_SIZE];
    int buff_ind = 0;
    int i = 0, count = 0;
    char c;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
            count++;

            if (buff_ind == BUFFER_SIZE)
                flush_buffer(buffer, &buff_ind);
        }
        else
        {
            i++;

            if (!format[i])
                return (-1);

            flush_buffer(buffer, &buff_ind);

            if (format[i] == 'c')
            {
                c = va_arg(args, int);
                count += write(1, &c, 1);
            }
            else if (format[i] == 's')
                count += print_string(args);
            else if (format[i] == '%')
                count += print_percent();
            else if (format[i] == 'd' || format[i] == 'i')
                count += print_int(args);
            else if (format[i] == 'b')
                count += print_binary(args);
            else if (format[i] == 'u')
                count += print_unsigned(args);
            else if (format[i] == 'o')
                count += print_octal(args);
            else if (format[i] == 'x')
                count += print_hex(args, 0);
            else if (format[i] == 'X')
                count += print_hex(args, 1);
            else
            {
                write(1, "%", 1);
                write(1, &format[i], 1);
                count += 2;
            }
        }
        i++;
    }

    flush_buffer(buffer, &buff_ind);

    va_end(args);

    return (count);
}
