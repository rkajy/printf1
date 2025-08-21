/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:34:34 by radandri          #+#    #+#             */
/*   Updated: 2025/08/21 15:48:21 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer(t_format *fmt, va_list *args);
int	print_unsigned(t_format *fmt, va_list *args);
int	print_hexadecimal(t_format *fmt, va_list *args);
int	print_pointer(t_format *fmt, va_list *args);

int	print_integer(t_format *fmt, va_list *args)
{
	int		num;
	int		count;
	char	sign;

	num = va_arg(*args, int);
	count = 0;
	sign = (num < 0) ? '-' : '+';
	if (num < 0)
		num = -num;
	if (fmt->flag_plus && sign == '+')
		write(1, &sign, 1);
	else if (fmt->flag_space && sign == '+')
		write(1, " ", 1);
	count += (sign == '-') ? 1 : 0;
	// Convert and print the number here (omitted for brevity)
	// ...
	return (count);
}

int	print_unsigned(t_format *fmt, va_list *args)
{
	unsigned int	num;
	int				count;

	num = va_arg(*args, unsigned int);
	count = 0;
    (void)fmt; // Suppress unused variable warning
	// Convert and print the unsigned number here (omitted for brevity)
	// ...
	return (count);
}
int	print_hexadecimal(t_format *fmt, va_list *args)
{
	unsigned int	num;
	int				count;

	num = va_arg(*args, unsigned int);
	count = 0;
    (void)fmt; // Suppress unused variable warning
	// Convert and print the hexadecimal number here (omitted for brevity)
	// ...
	return (count);
}

int	print_pointer(t_format *fmt, va_list *args)
{
	void *ptr;
	int count;

	ptr = va_arg(*args, void *);
	count = 0;
    (void)fmt; // Suppress unused variable warning

	if (!ptr)
	{
		write(1, PTRNULL, NPTRSIZE);
		return (NPTRSIZE);
	}

	// Convert and print the pointer address here (omitted for brevity)
	// ...

	return (count);
}