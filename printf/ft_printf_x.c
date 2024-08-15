/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:00:02 by oabdelka          #+#    #+#             */
/*   Updated: 2024/08/14 15:00:02 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static char	*ft_nbrtostr(unsigned int n, int is_upper)
{
	char	*str;
	int		len;
	int		mod ;

	len = hex_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL_STR);
	str[len] = '\0';
	while (--len != -1)
	{
		mod = n % 16;
		if (mod < 10)
			str[len] = mod + '0';
		else
		{
			if (is_upper == 1)
				str[len] = mod - 10 + 'A';
			else if (is_upper == 0)
				str[len] = mod - 10 + 'a';
		}
		n = n / 16;
	}
	return (str);
}

int	ft_printf_x(unsigned int n, int is_upper)
{
	char	*str;
	int		count;

	count = 0;
	str = ft_nbrtostr(n, is_upper);
	if (!str)
		return (0);
	count += ft_printf_s(str);
	free(str);
	return (count);
}
