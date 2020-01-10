/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:04:06 by vlageard          #+#    #+#             */
/*   Updated: 2020/01/10 14:50:15 by vlageard         ###   ########.fr       */
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

void		parse_left_fieldwidth(int *i, const char *fstr, t_format *format)//, va_list valist)
{
	if (!ft_isdigit(fstr[*i]))
		return ;
	if (fstr[*i] == '0')
	{
		format->fieldwidth_mode = 1;
		(*i)++;
	}
	// Ajouter la wildcard *
	format->fieldwidth = ft_atoi(fstr + *i);
	while (ft_isdigit(fstr[*i]) && fstr[*i])
	{
		(*i)++;
	}
}

void		parse_right_fieldwidth(int *i, const char *fstr, t_format *format)//, va_list valist)
{
	if (fstr[*i] != '-')
		return ;
	(*i)++;
	if (!ft_isdigit(fstr[*i]) || format->fieldwidth > 0)
	{
		format->error = 1;
		return ;
	}
	format->fieldwidth_mode = 2;
	// Ajouter la wildcard *
	format->fieldwidth = ft_atoi(fstr + *i);
	while (ft_isdigit(fstr[*i]) && fstr[*i])
		(*i)++;
}

void		parse_precision(int *i, const char *fstr, t_format *format)//, va_list valist)
{
	if (fstr[*i] != '.')
		return ;
	(*i)++;
	if (!ft_isdigit(fstr[*i]))
	{
		format->error = 1;
		return ;
	}
	// Ajouter la wildcard *
	format->precision = ft_atoi(fstr + *i);
	while (ft_isdigit(fstr[*i]) && fstr[*i])
		(*i)++;
}

void		parse_conversion(int *i, const char *fstr, t_format *format)//, va_list valist)
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
	
	if (fstr[*i] == '%')
	{
		(*i)++;
		return (ft_strdup("%"));
	}
	if (!(format = create_format()))
	 	return (NULL);
	parse_left_fieldwidth(i, fstr, format);
	parse_right_fieldwidth(i, fstr, format);
	parse_precision(i, fstr, format);
	parse_conversion(i, fstr, format);//, valist);
	// Ajouter le support des wildcard dans les fonctions de parsing.
	// Mais laisser la récupération du vararg central par la fonction de format
	str = formatter(format, valist);
	//print_t_format(format); // Debugging
	free(format);
	//if (!str)
	//	*i = start;
	return (str);
}