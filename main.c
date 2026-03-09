#include "main.h"

int main(void)
{
    _printf("Char: %c\n", 'A');
    _printf("String: %s\n", "Hello");
    _printf("Percent: %%\n");
    _printf("Integer: %d, %i\n", 123, -456);
    _printf("Binary: %b\n", 98);
    _printf("Unsigned: %u\n", 300);
    _printf("Octal: %o\n", 300);
    _printf("Hex lowercase: %x\n", 300);
    _printf("Hex uppercase: %X\n", 300);
    _printf("%S\n", "Best\nSchool");
    return 0;
}
