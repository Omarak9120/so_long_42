/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:59:53 by oabdelka          #+#    #+#             */
/*   Updated: 2024/08/14 14:59:54 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"

int	ft_printf_c(char c);
int	ft_printf_d(int nb);
int	ft_printf_s(char *str);
int	ft_printf_p(void *p);
int	ft_printf_u(unsigned int nb);
int	ft_printf_x(unsigned int n, int is_upper);
int	ft_printf(const char *format, ...);

# define NULL_STR "(null)"
# define NULL_PTR "(nil)"

#endif