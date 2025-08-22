/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:34:34 by radandri          #+#    #+#             */
/*   Updated: 2025/08/22 18:50:17 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_utoa(unsigned int n);
int			print_integer(t_format *fmt, va_list *args);
int			print_unsigned(t_format *fmt, va_list *args);
int			print_pointer(t_format *fmt, va_list *args);

static char	*ft_utoa(unsigned int n)
{
	char	buffer[11];
	int		i;
	char	*str;

	i = 10;
	buffer[i] = '\0';
	if (n == 0)
		buffer[--i] = '0';
	while (n > 0)
	{
		buffer[--i] = (n % 10) + '0';
		n /= 10;
	}
	str = ft_strdup(&buffer[i]);
	return (str);
}

int	print_integer(t_format *fmt, va_list *args)
{
	int		n;
	int		count;
	char	*str;

	if (fmt->type != 'd' && fmt->type != 'i')
		return (0);
	n = va_arg(*args, int);
	str = ft_itoa(n);
	if (!str)
		return (0);
	count = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (count);
}

int	print_unsigned(t_format *fmt, va_list *args)
{
	unsigned int	n;
	int				count;
	char			*str;
	int i;

	if (fmt->type != 'u')
		return (0);
	n = va_arg(*args, unsigned int);
	count = 0;
	str = ft_utoa(n);
	if (!str)
		return (0);
	count = ft_strlen(str);
	i = 0;
	while (str[i])
	{
		if (write(1, &str[i], 1) < 0)
		{
			free(str);
			return (-1);
		}
		i++;
	}
	//ft_putstr_fd(str, 1);
	free(str);
	return (count);
}

int	print_pointer(t_format *fmt, va_list *args)
{
	uintptr_t	ptr;
	int			count;
	char		buffer[16];
	int			i;

	count = 0;
	if (fmt->type != 'p')
		return (0);
	ptr = (uintptr_t)va_arg(*args, void *);
	if (!ptr)
		return (ft_putstr_fd(PTRNULL, 1), NPTRSIZE);
	ft_putstr_fd("0x", 1);
	count = count + 2;
	if (ptr == 0)
		return (write(1, "0", 1), count + 1);
	i = 0;
	while (ptr)
	{
		buffer[i++] = HEX_BASE[ptr % 16];
		ptr /= 16;
	}
	count += i;
	while (--i >= 0)
		if(write(1, &buffer[i], 1) < 0)
			return (-1);
	return (count);
}
