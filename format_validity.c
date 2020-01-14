/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_validity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:40:04 by vlageard          #+#    #+#             */
/*   Updated: 2020/01/14 17:20:30 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void check_padding(int *j, const char *fstr)
{
	if (fstr[*j] == '0')
		(*j)++;
	if (fstr[*j] == '*')
		(*j)++;
	else
	{
		while (ft_isdigit(fstr[*j]))
			(*j)++;
	}
	if (fstr[*j] == '-')
	{
		(*j)++;
		if (fstr[*j] == '*')
			(*j)++;
		else
		{
			while (ft_isdigit(fstr[*j]))
				(*j)++;
		}
	}
}

void check_precision(int *j, const char *fstr)
{
	if (fstr[*j] == '.')
	{
		(*j)++;
		if (fstr[*j] == '*')
			(*j)++;
		else
		{
			while (ft_isdigit(fstr[*j]))
				(*j)++;
		}
	}
}

int	format_is_valid(int i, const char *fstr)
{
	int	j;
	
	j = i;
	check_padding(&j, fstr); // This needs to take into account that if fw is 0, then it is a malformed format
	check_precision(&j, fstr);
	if (is_conversion(fstr[j]) || fstr[j] == '%')
		return (1);
	else
		return (0);
}