/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:47:04 by radandri          #+#    #+#             */
/*   Updated: 2025/08/22 14:48:54 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexadecimal(t_format *fmt, va_list *args)
{
	unsigned int	n;
	char			buffer[16];
	int				i;
	int				count;
	const char		*base;
printf("\nI enteded the function.");
	if (fmt->type == 'x')
		base = HEX_BASE;
	else if (fmt->type == 'X')
		base = HEX_BASE_CAPITAL;
	else
		return (0);
	printf("\n%s", base);
	n = va_arg(*args, unsigned int);
	if (n == 0)
		return (write(1, "0", 1));
	i = 0;
	while (n > 0)
	{
		buffer[i++] = base[n % 16];
		n /= 16;
	}
	count = i;
	printf(" %d ", count);
	while (i-- > 0)
	{
		printf("%c", buffer[i]);
		write(1, &buffer[i], 1);
	}
	return (count);
}
