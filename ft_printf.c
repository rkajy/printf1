#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
    va_list args;
    t_format fmt;
    int count;

    va_start(args, format);
    count = 0;
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format) // Ensure there's a character after '%'
            {
                fmt.type = *format;
                // Parse the format specifier here (omitted for brevity)
                switch (fmt.type)
                {
                case 'c':
                    count += print_char(&fmt, &args);
                    break ;
                case 's':
                    count += print_string(&fmt, &args);
                    break ;
                case 'd':
                case 'i':
                    count += print_integer(&fmt, &args);
                    break ;
                case 'u':
                    count += print_unsigned(&fmt, &args);
                    break ;
                case 'x':
                case 'X':
                    count += print_hexadecimal(&fmt, &args);
                    break ;
                case 'p':
                    count += print_pointer(&fmt, &args);
                    break ;
                case '%':
                    count += print_percent(&fmt);
                    break ;
                default:
                    // Handle invalid specifier: print '%' and the invalid character
                    write(1, "%", 1);
                    write(1, format, 1);
                    count += 2;
                    break;
                }
                format++; // Increment after handling the specifier
            }
            else
            {
                // Handle case where '%' is the last character
                write(1, "%", 1);
                count++;
                break; // Exit the loop to avoid infinite loop
            }
        }
        else
        {
            write(1, format, 1);
            count++;
            format++; // Increment for normal characters
        }
    }
    va_end(args);
    return (count);
}