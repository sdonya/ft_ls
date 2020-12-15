/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:24:35 by cgamora           #+#    #+#             */
/*   Updated: 2020/11/14 18:13:29 by sdonya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_lest	*new_file(const int fd)
{
	t_lest *new;

	if ((new = (t_lest *)ft_memalloc(sizeof(t_lest))))
	{
		new->fd = fd;
		new->ost = NULL;
	}
	return (new);
}

static t_lest	*get_file(const int fd, t_lest **head)
{
	t_lest *lst;

	if (!(*head))
		return (*head = new_file(fd));
	lst = *head;
	while (lst->next && lst->fd != fd)
		lst = lst->next;
	return ((lst->fd == fd) ? lst : (lst->next = new_file(fd)));
}

static int		str_divide(char **str, char **line)
{
	char	*new;
	char	*div;

	if (!(*line = ft_strsubchr(*str, '\n')))
		return (-1);
	div = ft_strchrs(*str, '\n');
	div++;
	if (!ft_strlen(div))
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	new = ft_strdup(div);
	free(*str);
	*str = new;
	return ((new) ? 1 : -1);
}

int				get_next_line(const int fd, char **line)
{
	static t_lest	*head = NULL;
	t_lest			*f;
	char			buff[BUFF_SIZE + 1];
	ssize_t			size;
	char			*tmp;

	if (fd < 0 || !line || read(fd, buff, 0) < 0 || !(f = get_file(fd, &head)))
		return (-1);
	while (!ft_strchrs(f->ost, '\n'))
	{
		if (!(size = read(fd, buff, BUFF_SIZE)))
		{
			if (!(*line = f->ost))
				return (0);
			f->ost = NULL;
			return (1);
		}
		buff[size] = '\0';
		tmp = f->ost;
		f->ost = ft_strjoin(f->ost, buff);
		free(tmp);
		if (!f->ost)
			return (-1);
	}
	return (str_divide(&(f->ost), line));
}
