/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:59:57 by oabdelka          #+#    #+#             */
/*   Updated: 2024/08/14 14:59:57 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	is_a_specifier(char c)
{
	if (c == '%' || c == 'c' || c == 's' || c == 'd'
		|| c == 'i' || c == 'x' || c == 'X' || c == 'u' || c == 'p')
		return (c);
	return (0);
}

int	parse_specifier(char *str, int i, va_list args)
{
	int	count;

	count = 0;
	if (str[i] == 'd' || str[i] == 'i')
		count += ft_printf_d(va_arg(args, int));
	else if (str[i] == '%')
		count += ft_printf_c('%');
	else if (str[i] == 'c')
		count += ft_printf_c(va_arg(args, int));
	else if (str[i] == 's')
		count += ft_printf_s(va_arg(args, char *));
	else if (str[i] == 'u')
		count += ft_printf_u(va_arg(args, unsigned int));
	else if (str[i] == 'x')
		count += ft_printf_x(va_arg(args, unsigned int), 0);
	else if (str[i] == 'X')
		count += ft_printf_x(va_arg(args, unsigned int), 1);
	else if (str[i] == 'p')
		count += ft_printf_p(va_arg(args, void *));
	return (count);
}

int	parse_str(char *str, va_list args)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			if (is_a_specifier(str[i]))
				count += parse_specifier(str, i, args);
		}
		else
			count += ft_printf_c(str[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*str;
	int		count;

	count = 0;
	if (!format || *format == '\0')
		return (0);
	str = ft_strdup(format);
	if (!str || *str == '\0')
		return (0);
	va_start(args, format);
	count = parse_str(str, args);
	va_end(args);
	free(str);
	return (count);
}
