/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:58:16 by vlageard          #+#    #+#             */
/*   Updated: 2020/01/09 14:02:01 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

int		str_get_str_size(t_format *format, char *va_str)
{
	int	str_size;
	int	va_strlen;
	
	va_strlen = ft_strlen(va_str);
	if (format->precision == -1)
		str_size = va_strlen + ft_max(0, format->fieldwidth - va_strlen);
	else
	{
		str_size = ft_min(va_strlen, format->precision) +
		ft_max(0, format->fieldwidth - ft_min(va_strlen, format->precision));
	}
	return (str_size);
}

char	*str_fill_str(char *str, t_format *format, char *va_str, int str_size)
{
	int	crop;
	int	pad;
	
	crop = format->precision == -1 ?
	(int)ft_strlen(va_str) :
	ft_min(ft_strlen(va_str), format->precision);
	pad = ft_max(0, format->fieldwidth - crop);
	if (format->fieldwidth_mode == 2)
	{
		ft_memcpy((void *)str, (void *)va_str, crop);
		ft_memset((void *)(str + crop), 32, pad);
	}
	else
	{
		ft_memset((void *)str, 32, pad);
		ft_memcpy((void *)(str + pad), (void *)va_str, crop);
	}
	str[str_size] = 0;
	return (str);
}

char	*format_str(t_format *format, va_list valist)
{
	char	*str;
	char	*va_str;
	int		str_size;

	va_str = va_arg(valist, char *);
	str_size = str_get_str_size(format, va_str);
	if (!(str = (char *)malloc(sizeof(char) * (str_size + 1))))
		return (NULL);
	str = str_fill_str(str, format, va_str, str_size);
	return (str);
}