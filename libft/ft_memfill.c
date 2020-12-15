/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:42:27 by cgamora           #+#    #+#             */
/*   Updated: 2020/11/14 18:13:29 by sdonya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memfill(char const *str, char **tab, int i, int s)
{
	tab[i] = ft_strnew(s);
	if (tab[i] == 0)
	{
		ft_memdel((void**)tab);
		return (0);
	}
	ft_strncpy(tab[i], str, s);
	return (1);
}
