/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:13:58 by cgamora           #+#    #+#             */
/*   Updated: 2020/11/14 18:13:29 by sdonya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*str;

	len = 0;
	while (src[len])
		len++;
	str = (char*)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (len >= 0)
	{
		str[len] = src[len];
		len--;
	}
	return (str);
}
