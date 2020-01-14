/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:19:18 by vlageard          #+#    #+#             */
/*   Updated: 2020/01/14 19:04:12 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int parse_fstr(const char *fstr, va_list valist)
{
	int i;
	int count;
	char *str;
	
	i = 0;
	count = 0;
	str = NULL;
	while (fstr[i])
	{
		if (fstr[i] != '%')
		{
			ft_putchar_fd(fstr[i], 1);
			i++;
			count++;
		}
		else
		{
			i++;
			if (format_is_valid(i, fstr))
			{
				str = parse_format(&i, fstr, valist);
				if (!str)
					return (-1);
				ft_putstr_fd(str, 1);
				count += ft_strlen(str);
				free(str);
			}
			else
				ft_putchar_fd('%', 1);
		}
	}
	return (count);
}

int	ft_printf(const char *fstr, ...)
{
	va_list valist;
	int count;
	
	count = 0;
	va_start(valist, fstr);
	count = parse_fstr(fstr, valist);
	va_end(valist);
	return (count);
}