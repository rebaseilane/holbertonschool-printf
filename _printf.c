#include "main.h"

/**
 * _printf - produces output according to a format
 */
int _printf(const char *format, ...)
{
    va_list args;
    char buffer[BUFFER_SIZE];
    int buff_ind = 0;
    int i = 0, count = 0;

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

            switch (format[i])
            {
                case 'c':
                    count += print_char(args, buffer, &buff_ind);
                    break;
                case 's':
                    count += print_string(args, buffer, &buff_ind);
                    break;
                case '%':
                    count += print_percent(buffer, &buff_ind);
                    break;
                case 'd':
                case 'i':
                    count += print_int(args, buffer, &buff_ind);
                    break;
                case 'b':
                    count += print_binary(args, buffer, &buff_ind);
                    break;
                case 'u':
                    count += print_unsigned(args, buffer, &buff_ind);
                    break;
                case 'o':
                    count += print_octal(args, buffer, &buff_ind);
                    break;
                case 'x':
                    count += print_hex(args, 0, buffer, &buff_ind);
                    break;
                case 'X':
                    count += print_hex(args, 1, buffer, &buff_ind);
                    break;
                case 'S':  /* Custom specifier */
                    count += print_S(args, buffer, &buff_ind);
                    break;
                default:
                    if (buff_ind == BUFFER_SIZE)
                        flush_buffer(buffer, &buff_ind);

                    buffer[buff_ind++] = '%';

                    if (buff_ind == BUFFER_SIZE)
                        flush_buffer(buffer, &buff_ind);

                    buffer[buff_ind++] = format[i];
                    count += 2;
            }
        }
        i++;
    }

    flush_buffer(buffer, &buff_ind);
    va_end(args);

    return (count);
}
