#include "ft_printf.h"

static int	handle_format_specifier(t_format *fmt, va_list *args,
		const char **format)
{
	int	count;

	count = 0;
	if (fmt->type == 'c')
		count = print_char(args);
	else if (fmt->type == 's')
		count = print_string(args);
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

static int check_write_error(int fd, const char *buf, size_t count, int ret)
{
	if (write(fd, buf, count) < 0)
		return (-1);
	return (ret);
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
			if (*format++)
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
				count  = check_write_error(1, " ", 1, count);
				break ;
			}
		}
		else
		{
			if (write(1, format, 1) < 0)
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
