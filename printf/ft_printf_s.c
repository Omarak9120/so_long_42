/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:00:09 by oabdelka          #+#    #+#             */
/*   Updated: 2024/08/14 15:00:09 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count += ft_printf_c(str[count]);
	return (count);
}

int	ft_printf_s(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		count += ft_putstr(NULL_STR);
		return (count);
	}
	count += ft_putstr(str);
	return (count);
}
