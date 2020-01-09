#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
//#include <stdio.h>

/*char *ft_print_format(int *i, const char *fstr, va_list valist)
{
	// THIS FUNCTION MUST BE REPLACED BY parse_format() !
	char *str;

	if (fstr[*i] == 'i' || fstr[*i] == 'd')
		str = ft_itoa(va_arg(valist, int));
	else if (fstr[*i] == 's')
		str = ft_strdup(va_arg(valist, char *));
	else if (fstr[*i] == '%')
		str = ft_strdup("%");
	else
		return (NULL);
	*i++;
	return (str);
}*/

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
			// Ici, il faut aussi récupérer la taille du format afin
			// d'itérer sur i correctement.
			i++;
			str = parse_format(&i, fstr, valist);
			// str is NULL if an error in encountered.
			if (!str)
				return (-1);
			ft_putstr_fd(str, 1);
			free(str);
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