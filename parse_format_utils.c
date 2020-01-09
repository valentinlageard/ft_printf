/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:03:48 by vlageard          #+#    #+#             */
/*   Updated: 2020/01/08 16:03:49 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft/libft.h"

t_format	*create_format()
{
	t_format *new_format;
	if (!(new_format = (t_format *)malloc(sizeof(t_format))))
		return (NULL);
	new_format->conversion = 0;
	new_format->fieldwidth = 0;
	new_format->fieldwidth_mode = 0;
	new_format->precision = -1;
	new_format->error = 0;
	return (new_format);
}

int			is_conversion(char c)
{
	char	conversions[] = "cspdiuxX";
	
	return (ft_iscinstr(c, conversions));
}