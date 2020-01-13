/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:04:06 by vlageard          #+#    #+#             */
/*   Updated: 2020/01/13 15:28:32 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
//#include <stdio.h>

// FOR DEBUGGING PURPOSES

/*void		print_t_format(t_format *format)
{
	printf("conversion : %c\n", format->conversion);
	printf("fieldwidth : %i\n", format->fieldwidth);
	printf("fieldwidth_mode : %i\n", format->fieldwidth_mode);
	printf("precision : %i\n", format->precision);
	printf("error : %i\n", format->error);
}*/

// THIS IS WHERE THE PARSING HAPPEN

void		parse_left_fieldwidth(int *i, const char *fstr, t_format *format, va_list valist)
{
	if (!ft_isdigit(fstr[*i]) && fstr[*i] != '*')
		return ;
	if (fstr[*i] == '0')
	{
		format->fieldwidth_mode = 1;
		(*i)++;
	}
	if (fstr[*i] == '*')
	{
		format->fieldwidth = va_arg(valist, int);
		(*i)++;
	}
	else
	{
		format->fieldwidth = ft_atoi(fstr + *i);
		while (ft_isdigit(fstr[*i]) && fstr[*i])
			(*i)++;
	}
}

void		parse_right_fieldwidth(int *i, const char *fstr, t_format *format, va_list valist)
{
	if (fstr[*i] != '-')
		return ;
	(*i)++;
	if ((!ft_isdigit(fstr[*i]) && fstr[*i] != '*') || format->fieldwidth > 0)
	{
		format->error = 1;
		return ;
	}
	format->fieldwidth_mode = 2;
	if (fstr[*i] == '*')
	{
		format->fieldwidth = va_arg(valist, int);
		(*i)++;
	}
	else
	{
		format->fieldwidth = ft_atoi(fstr + *i);
		while (ft_isdigit(fstr[*i]) && fstr[*i])
			(*i)++;
	}
}

void		parse_precision(int *i, const char *fstr, t_format *format, va_list valist)
{
	if (fstr[*i] != '.')
		return ;
	(*i)++;
	if (!ft_isdigit(fstr[*i]) && fstr[*i] != '*')
	{
		format->error = 1;
		return ;
	}
	if (fstr[*i] == '*')
	{
		format->precision = va_arg(valist, int);
		(*i)++;
	}
	else
	{
		format->precision = ft_atoi(fstr + *i);
		while (ft_isdigit(fstr[*i]) && fstr[*i])
			(*i)++;
	}
}

void		parse_conversion(int *i, const char *fstr, t_format *format)
{
	if (!(is_conversion(fstr[*i])))
	{
		format->error = 1;
		return ;
	}
	format->conversion = fstr[*i];
	(*i)++;
}

char		*parse_format(int *i, const char *fstr, va_list valist)
{
	t_format	*format;
	char		*str;
	
	if (percent_check(i, fstr))
		return (ft_strdup("%"));
	if (!(format = create_format()))
	 	return (NULL);
	parse_left_fieldwidth(i, fstr, format, valist);
	parse_right_fieldwidth(i, fstr, format, valist);
	parse_precision(i, fstr, format, valist);
	parse_conversion(i, fstr, format);
	str = formatter(format, valist);
	//print_t_format(format); // Debugging
	free(format);
	return (str);
}