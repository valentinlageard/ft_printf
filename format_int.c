/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:03:32 by vlageard          #+#    #+#             */
/*   Updated: 2020/01/09 13:13:50 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

char	*format_int(t_format *format, va_list valist)
{
	char	*str;
	int		va_int;
	char	*iasa;
	
	va_int = va_arg(valist, int);
	iasa = ft_itoa(va_int);
	if
}
