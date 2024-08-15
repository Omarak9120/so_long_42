/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:00:06 by oabdelka          #+#    #+#             */
/*   Updated: 2024/08/14 15:00:06 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	unint_len(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_printf_utoa(unsigned int nb)
{
	char	*nbstr;
	int		len;

	len = unint_len(nb);
	nbstr = ft_calloc(len + 1, sizeof(char));
	if (!nbstr)
		return (0);
	len--;
	while (len)
	{
		nbstr[len] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	nbstr[0] = (nb % 10) + '0';
	return (nbstr);
}

int	ft_printf_u(unsigned int nb)
{
	int		count;
	char	*nbstr;

	count = 0;
	nbstr = ft_printf_utoa(nb);
	if (!nbstr)
		return (0);
	count += ft_printf_s(nbstr);
	free(nbstr);
	return (count);
}
