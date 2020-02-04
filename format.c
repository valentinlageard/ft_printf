/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:19:31 by vlageard          #+#    #+#             */
/*   Updated: 2020/02/04 18:18:56 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

char	*formatter(t_format *format, va_list valist, int *nullchar)
{
	char *str;

	str = NULL;
	if (format->conversion == 'c')
		str = format_char(format, valist, nullchar);
	else if (format->conversion == 's')
		str = format_str(format, valist);
	else if (format->conversion == 'u')
		str = format_uint(format, valist);
	else if (format->conversion == 'd' || format->conversion == 'i')
		str = format_int(format, valist);
	else if (format->conversion == 'p')
		str = format_pointer(format, valist);
	else if (format->conversion == 'x' || format->conversion == 'X')
		str = format_hex(format, valist);
	else if (format->conversion == '%')
		str = format_percent(format);
	return (str);
}
