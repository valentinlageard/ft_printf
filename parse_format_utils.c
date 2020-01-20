/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:03:48 by vlageard          #+#    #+#             */
/*   Updated: 2020/01/14 19:17:16 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft/libft.h"

int			percent_check(int *i, const char *fstr)
{
	int	j;
	
	j = *i;
	while (ft_iscinstr(fstr[j], "0123456789-.*"))
		j++;
	if (ft_iscinstr(fstr[j], "cspdiuxX"))
		return (0);
	if (fstr[j] == '%')
	{
		*i = j + 1;
		return (1);
	}
	return (0);
}

t_format	*create_format()
{
	t_format *new_format;
	if (!(new_format = (t_format *)malloc(sizeof(t_format))))
		return (NULL);
	new_format->conversion = 0;
	new_format->fieldwidth = 0;
	new_format->fieldwidth_mode = 0;
	new_format->precision = -1;
	return (new_format);
}

int			is_conversion(char c)
{
	char	conversions[] = "cspdiuxX";
	
	return (ft_iscinstr(c, conversions));
}