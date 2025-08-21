/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:37:42 by radandri          #+#    #+#             */
/*   Updated: 2025/08/21 15:38:18 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> // va_list, va_start, va_end
# include <stddef.h> // size_t
# include <stdlib.h> // malloc, free
# include <unistd.h> // write

# if defined(__linux__)
#  define PTRNULL "(nil)"
#  define NPTRSIZE 5

# elif defined(__APPLE__)
#  define PTRNULL "0x0"
#  define NPTRSIZE 3
# endif

typedef struct s_format
{
	int		flag_minus;
	int		flag_plus;
	int		flag_space;
	int		flag_zero;
	int		flag_hash;
	char	type;
	int		width;
	int		precision;
}			t_format;

// core functions
int			ft_printf(const char *format, ...);

// specifier functions
int			print_char(t_format *fmt, va_list *args);
int			print_string(t_format *fmt, va_list *args);
int			print_integer(t_format *fmt, va_list *args);
int			print_unsigned(t_format *fmt, va_list *args);
int			print_hexadecimal(t_format *fmt, va_list *args);
int			print_pointer(t_format *fmt, va_list *args);
int			print_percent(t_format *fmt);

#endif // FT_PRINTF_H
