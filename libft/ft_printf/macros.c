/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:57:22 by fallard           #+#    #+#             */
/*   Updated: 2020/11/14 18:13:29 by sdonya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			dec_mod(intmax_t n)
{
	return ((n < 0) ? -1 : 1);
}

int			f_mod(t_double_l n)
{
	return ((n < 0) ? -1 : 1);
}

int			ft_zero(int n)
{
	return ((n < 0) ? 0 : n);
}

intmax_t	dec_abs(intmax_t n)
{
	return ((n < 0) ? -n : n);
}

t_double_l	f_abs(t_double_l n)
{
	return ((n < 0) ? -n : n);
}
