/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_az.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:33:06 by radandri          #+#    #+#             */
/*   Updated: 2025/08/21 17:07:18 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(t_format *fmt, va_list *args);
int	print_string(t_format *fmt, va_list *args);
int	print_percent(t_format *fmt);

int print_char(t_format *fmt, va_list *args)
{
    unsigned char c = (unsigned char)va_arg(*args, int);
    write(1, &c, 1);
	(void)fmt; // Suppress unused variable warning
    return (1);
}

int	print_string(t_format *fmt, va_list *args)
{
	char	*str;
	int		count;
	int		len;

	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	len = 0;
	while (str[len])
		len++;
	if (fmt->precision >= 0 && fmt->precision < len)
		len = fmt->precision;
	count = 0;
	if (fmt->flag_minus)
	{
		write(1, str, len);
		count += len;
		while (count < fmt->width)
		{
			write(1, " ", 1);
			count++;
		}
	}
	else
	{
		while (count < fmt->width - len)
		{
			write(1, " ", 1);
			count++;
		}
		write(1, str, len);
		count += len;
	}
	return (count);
}
int	print_percent(t_format *fmt)
{
	int count;

	count = 0;
	if (fmt->flag_minus)
	{
		write(1, "%", 1);
		count++;
		while (count < fmt->width)
		{
			write(1, " ", 1);
			count++;
		}
	}
	else
	{
		while (count < fmt->width - 1)
		{
			write(1, " ", 1);
			count++;
		}
		write(1, "%", 1);
		count++;
	}
	return (count);
}