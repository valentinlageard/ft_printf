/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:09:16 by vlageard          #+#    #+#             */
/*   Updated: 2020/01/12 18:01:16 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

int		hex_get_str_size(t_format *format, char *h_str)
{
	int	p_pad;
	int	fw_pad;
	int	h_slen;
	int	str_size;
	
	h_slen = ft_strlen(h_str);
	if (format->precision == -1)
	{
		fw_pad = ft_max(0, format->fieldwidth - h_slen);
		str_size = fw_pad + h_slen;
	}
	else
	{
		p_pad = ft_max(0, format->precision - h_slen);
		fw_pad = ft_max(0, format->fieldwidth - (p_pad + h_slen));
		str_size = p_pad + fw_pad + h_slen;
	}
	return (str_size);
}

char	*hex_fill_no_precision(char *str, t_format *format, char *h_str)
{
	int	h_slen;
	int	fw_pad;
	
	h_slen = ft_strlen(h_str);
	fw_pad = ft_max(0, format->fieldwidth - h_slen);
	if (format->fieldwidth_mode == 0)
	{
		ft_memset((void *)str, 32, fw_pad);
		ft_memcpy((void *)(str + fw_pad), (void *)h_str, h_slen);
	}
	else if (format->fieldwidth_mode == 1)
	{
		ft_memset((void *)str, 48, fw_pad);
		ft_memcpy((void *)(str + fw_pad), (void *)h_str, h_slen);
	}
	else
	{
		ft_memcpy((void *)str, (void *)h_str, h_slen);
		ft_memset((void *)(str + h_slen), 32, fw_pad);
	}
	return (str);
}

char	*hex_fill_precision(char *str, t_format *format, char *h_str)
{
	int	h_slen;
	int	p_pad;
	int	fw_pad;
	
	h_slen = ft_strlen(h_str);
	p_pad = ft_max(0, format->precision - h_slen);
	fw_pad = ft_max(0, format->fieldwidth - (p_pad + h_slen));
	if (format->fieldwidth_mode != 2)
	{
		ft_memset((void *)str, 32, fw_pad);
		ft_memset((void *)(str + fw_pad), 48, p_pad);
		ft_memcpy((void *)(str + fw_pad + p_pad), (void *)h_str, h_slen);
	}
	else
	{
		ft_memset((void *)str, 48, p_pad);
		ft_memcpy((void *)(str + p_pad), (void *)h_str, h_slen);
		ft_memset((void *)(str + p_pad + h_slen), 32, fw_pad);
	}
	return (str);
}

char	*format_hex(t_format *format, va_list valist)
{
	int				str_size;
	unsigned int	va_hex;
	char			*h_str;
	char			*str;
	
	va_hex = va_arg(valist, unsigned int);
	h_str = format->conversion == 'x' ?
	ft_utoabase(va_hex, "0123456789abcdef") :
	ft_utoabase(va_hex, "0123456789ABCDEF");
	if (!h_str)
		return (NULL);
	if (format->precision == 0 && va_hex == 0)
		str_size = 0;
	else
		str_size =  hex_get_str_size(format, h_str);
	if (!(str = (char *)malloc(sizeof(char) * (str_size + 1))))
		return (NULL);
	if (format->precision == -1)
		str = hex_fill_no_precision(str, format, h_str);
	else if (format->precision > 0 || va_hex != 0)
		str = hex_fill_precision(str, format, h_str);
	str[str_size] = 0;
	free(h_str);
	return (str);
}