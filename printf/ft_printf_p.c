/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:00:13 by oabdelka          #+#    #+#             */
/*   Updated: 2024/08/14 15:00:13 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptr_len(unsigned long int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		len++;
		nb /= 16;
	}
	return (len);
}

char	*ft_printf_ptr(unsigned long int nb)
{
	char	*nbstr;
	int		len;
	int		mod;

	len = ptr_len(nb);
	nbstr = malloc((len + 1) * sizeof(char));
	if (!nbstr)
		return (NULL);
	nbstr[len] = '\0';
	len--;
	while (len != -1)
	{
		mod = nb % 16;
		if (mod < 10)
			nbstr[len] = mod + '0';
		else if (mod >= 10)
			nbstr[len] = mod - 10 + 'a';
		nb /= 16;
		len--;
	}
	return (nbstr);
}

int	ft_printf_p(void *p)
{
	unsigned long int	nb;
	int					count;
	char				*nbstr;

	count = 0;
	if (!p)
	{
		count += ft_printf_s(NULL_PTR);
		return (count);
	}
	nb = (unsigned long int) p;
	nbstr = ft_printf_ptr(nb);
	if (!nbstr)
		return (0);
	count += ft_printf_s("0x");
	count += ft_printf_s(nbstr);
	free(nbstr);
	return (count);
}
