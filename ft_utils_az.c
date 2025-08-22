/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_az.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:33:06 by radandri          #+#    #+#             */
/*   Updated: 2025/08/22 20:17:04 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list *args);
int	print_string(va_list *args);
int	print_percent(t_format *fmt);

int	print_char(va_list *args)
{
	unsigned char	c;

	c = (unsigned char)va_arg(*args, int);
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	print_string(va_list *args)
{
	char	*str;
	int		count;
	int		i;

	i = 0;
	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	count = ft_strlen(str);
	return (count);
}

int	print_percent(t_format *fmt)
{
	if (fmt->type != '%')
		return (0);
	if (write(1, "%", 1) == -1)
		return (-1);
	return (1);
}
