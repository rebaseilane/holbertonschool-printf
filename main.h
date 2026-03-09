#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);

int print_char(va_list args, char *buffer, int *buff_ind);
int print_string(va_list args, char *buffer, int *buff_ind);
int print_percent(char *buffer, int *buff_ind);
int print_int(va_list args, char *buffer, int *buff_ind);
int print_binary(va_list args, char *buffer, int *buff_ind);
int print_unsigned(va_list args, char *buffer, int *buff_ind);
int print_octal(va_list args, char *buffer, int *buff_ind);
int print_hex(va_list args, int uppercase, char *buffer, int *buff_ind);
int print_S(va_list args, char *buffer, int *buff_ind);
int print_pointer(va_list args, char *buffer, int *buff_ind);

void flush_buffer(char *buffer, int *buff_ind);

#endif
