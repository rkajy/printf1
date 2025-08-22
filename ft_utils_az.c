/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_az.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:33:06 by radandri          #+#    #+#             */
/*   Updated: 2025/08/22 22:47:38 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * print_char - Prints a single character to the standard output.
 * @args: A pointer to a va_list containing the arguments. The function
 *        expects the next argument in the list to be an integer, which
 *        will be cast to an unsigned char and printed.
 *
 * Return: On success, returns 1 indicating one character was written.
 *         On failure, returns -1 if the write operation fails.
 *
 * Description: This function retrieves the next argument from the
 *              variable argument list, casts it to an unsigned char,
 *              and writes it to the standard output using the write
 *              system call.
 */
int	print_char(va_list *args)
{
	unsigned char	c;

	c = (unsigned char)va_arg(*args, int);
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

/**
 * print_string - Prints a string to the standard output.
 * @args: A pointer to a va_list containing the arguments.
 *
 * This function retrieves a string from the provided va_list, and writes
 * it to the standard output character by character. If the string is NULL,
 * it defaults to printing "(null)". The function returns the number of
 * characters printed, or -1 if a write error occurs.
 *
 * Return: The number of characters printed, or -1 on error.
 */
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

/**
 * @brief Prints a percent symbol ('%') to the standard output.
 *
 * This function checks if the format type in the provided `t_format` structure
 * is a percent symbol ('%'). If so, it writes the percent symbol to the
 * standard output. If the write operation fails, it returns -1. Otherwise, it
 * returns 1 to indicate success.
 *
 * @param fmt A pointer to a `t_format` structure containing the format type.
 * 
 * @return int Returns 1 if the percent symbol is successfully written,
 *         0 if the format type is not '%',
 *         or -1 if the write operation fails.
 */
int	print_percent(t_format *fmt)
{
	if (fmt->type != '%')
		return (0);
	if (write(1, "%", 1) == -1)
		return (-1);
	return (1);
}
