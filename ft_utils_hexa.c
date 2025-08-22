/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:47:04 by radandri          #+#    #+#             */
/*   Updated: 2025/08/22 20:00:26 by radandri         ###   ########.fr       */
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

	base = HEX_BASE;
	if (fmt->type == 'X')
		base = HEX_BASE_CAPITAL;
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
	while (i-- > 0)
		if (write(1, &buffer[i], 1) < 0)
			return (-1);
	return (count);
}
