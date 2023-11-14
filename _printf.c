#include "main.h"
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr;
    char *str;

    va_start(args, format);

    for (ptr = format; *ptr; ++ptr)
    {
        if (*ptr != '%')
        {
            _putchar(*ptr);
            ++count;
        }
        else
        {
            ++ptr;
            switch (*ptr)
            {
            case 'c':
                _putchar(va_arg(args, int));
                ++count;
                break;
            case 's':
                str = va_arg(args, char *);
                while (*str)
                {
                    _putchar(*str);
                    ++str;
                    ++count;
                }
                break;
            case 'd':
            case 'i':
                count += print_number(va_arg(args, int));
                break;
            case '%':
                _putchar('%');
                ++count;
                break;
            default:
                _putchar('%');
                _putchar(*ptr);
                count += 2;
                break;
            }
        }
    }

    va_end(args);

    return count;
}

/**
 * print_number - Print an integer
 * @n: Integer to print
 *
 * Return: Number of characters printed
 */
int print_number(int n)
{
    // Implementation of the number printing logic
    // ...

    return 0;  // Placeholder, adjust accordingly
}

