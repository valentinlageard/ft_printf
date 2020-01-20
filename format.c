/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:19:31 by vlageard          #+#    #+#             */
/*   Updated: 2020/01/11 15:35:18 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

char	*formatter(t_format *format, va_list valist)
{
	char *str;
	
	if (format->conversion == 'c')
		str = format_char(format, valist);
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
	return (str);
}