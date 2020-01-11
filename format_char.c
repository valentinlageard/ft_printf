/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:57:50 by vlageard          #+#    #+#             */
/*   Updated: 2020/01/11 15:59:26 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

char	*format_char(t_format *format, va_list valist)
{
	char	*str;
	char	va_c;
	
	va_c = (unsigned char)va_arg(valist, int);
	if (format->fieldwidth > 1)
	{
		if (!(str = (char *)malloc(sizeof(char) * format->fieldwidth + 1)))
			return (NULL);
		if (format->fieldwidth_mode == 2)
		{
			str[0] = va_c;
			ft_memset((void *)(str + 1), 32, format->fieldwidth - 1);
		}
		else
		{
			ft_memset((void *)str, 32, format->fieldwidth - 1);
			str[format->fieldwidth - 1] = va_c;
		}
		str[format->fieldwidth] = 0;
	}
	else
		str = ft_cdup(va_c);
	return (str);
}