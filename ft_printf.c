#include "ft_printf.h"

static int	handle_format_specifier(t_format *fmt, va_list *args,
		const char **format)
{
	int	count;

	count = 0;
	if (fmt->type == 'c')
		count = print_char(args);
	else if (fmt->type == 's')
		count = print_string(fmt, args);
	else if (fmt->type == 'd' || fmt->type == 'i')
		count = print_integer(args);
	else if (fmt->type == 'u')
		count = print_unsigned(args);
	else if (fmt->type == 'x' || fmt->type == 'X')
		count = print_hexadecimal(fmt, args);
	else if (fmt->type == 'p')
		count = print_pointer(args);
	else if (fmt->type == '%')
		count = print_percent(fmt);
	else
	{
		write(1, "%", 1);
		write(1, *format, 1);
		count = 2;
	}
	return (count);
}

static int	write_count(char c, int count)
{
	write(1, &c, 1);
	count++;
	return (count);
}

static int	process_format(const char *format, va_list *args, int count,
		t_format *fmt)
{
	int	result;

	result = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format)
			{
				fmt->type = *format;
				result = handle_format_specifier(fmt, args, &format);
				if (result < 0)
					return (-1);
				count += result;
				format++;
			}
			else
			{
				result = write_count(' ', count);
				if (result < 0)
					return (-1);
				count = result;
				break ;
			}
		}
		else
		{
			result = write(1, format, 1);
			if (result < 0)
				return (-1);
			count++;
			format++;
		}
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;
	t_format	fmt;

	count = 0;
	va_start(args, format);
	count = process_format(format, &args, count, &fmt);
	return (va_end(args), count);
}
