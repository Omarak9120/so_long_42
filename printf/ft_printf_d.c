/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:00:19 by oabdelka          #+#    #+#             */
/*   Updated: 2024/08/14 15:00:19 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_d(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

void	ft_putnbr(int n)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_printf_c('-');
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		ft_putnbr((nbr / 10));
	}
	ft_printf_c ((nbr % 10) + '0');
}

int	ft_printf_d(int nb)
{
	int	count;

	count = 0;
	count += ft_len_d(nb);
	ft_putnbr(nb);
	return (count);
}
