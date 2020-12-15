/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:24:54 by cgamora           #+#    #+#             */
/*   Updated: 2020/11/14 18:13:29 by sdonya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*kud;
	unsigned char	*otk;
	size_t			i;

	i = 0;
	kud = (unsigned char*)dst;
	otk = (unsigned char*)src;
	if (src == dst)
		return (dst);
	while (n > i)
	{
		kud[i] = otk[i];
		i++;
	}
	return (dst);
}
