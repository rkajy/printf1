/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_az.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:33:06 by radandri          #+#    #+#             */
/*   Updated: 2025/08/22 13:17:51 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(t_format *fmt, va_list *args);
int	print_string(t_format *fmt, va_list *args);
int	print_percent(t_format *fmt);

int	print_char(t_format *fmt, va_list *args)
{
	unsigned char	c;

	if (fmt->type != 'c')
		return (0);
	c = (unsigned char)va_arg(*args, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	print_string(t_format *fmt, va_list *args)
{
	char	*str;
	int		count;

	str = va_arg(*args, char *);
	if (fmt->type != 's')
		return (0);
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	count = ft_strlen(str);
	return (count);
}

int	print_percent(t_format *fmt)
{
	if (fmt->type != '%')
		return (0);
	write(1, "%", 1);
	return (1);
}
