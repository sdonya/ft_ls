/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fit_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 01:44:08 by cgamora           #+#    #+#             */
/*   Updated: 2020/11/14 18:13:29 by sdonya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		recursiv(t_info *tmp_list, t_flags *flag)
{
	while (tmp_list)
	{
		if (tmp_list->dir && \
			ft_strcmp(tmp_list->name, ".") \
			&& ft_strcmp(tmp_list->name, ".."))
		{
			ft_putchar('\n');
			ft_start_ls(tmp_list->path, flag);
		}
		tmp_list = tmp_list->next;
	}
}

int				ft_isdir(const char *fd_name)
{
	struct stat		stata;

	if (stat(fd_name, &stata) != 0)
		return (0);
	return (S_ISDIR(stata.st_mode));
}

static int		count_name(char *fd_name)
{
	int i;

	i = 0;
	while (fd_name[i] && (fd_name[i] == '.' || fd_name[i] == '/'))
		i++;
	return (i);
}

static int		check_file(char *fd_name, t_flags *flag, \
t_info **tmp_list, int sub)
{
	DIR			*dir;
	int			i;

	errno = 0;
	i = count_name(fd_name);
	if (!(dir = opendir(fd_name)))
	{
		if (errno == 2)
			ft_printf("ft_ls: %s: %s\n", fd_name, strerror(errno));
		else if (errno == 13 && ft_isdir(fd_name))
		{
			if (sub && flag->br)
				ft_printf("\n%s\nft_ls: %s %s", \
				fd_name, &fd_name[i], strerror(errno));
			else
				ft_printf("ft_ls: %s: %s\n", &fd_name[i], strerror(errno));
		}
		else if (!(flag->br) && errno == 13)
			ft_printf("ft_ls: %s: %s\n", fd_name, strerror(errno));
		else
			add_file(tmp_list, fd_name);
		return (1);
	}
	closedir(dir);
	return (0);
}

int				ft_start_ls(char *fd_name, t_flags *flag)
{
	t_info		*info_list;
	t_info		*tmp_list;
	t_flagl		infrml;
	int			total;
	static int	sub;

	total = 0;
	tmp_list = NULL;
	if (check_file(fd_name, flag, &tmp_list, sub))
		return (0);
	total = dir_list(&tmp_list, fd_name, flag);
	list_sort(&tmp_list, flag);
	if (sub && flag->br)
		(!tmp_list) ? ft_printf("\n%s:", fd_name)
		: ft_printf("\n%s:\n", fd_name);
	if (tmp_list && flag->l)
		ft_printf("total %d\n", total);
	info_list = tmp_list;
	infrml = get_flagl(tmp_list);
	print_all(info_list, infrml, flag);
	sub = 1;
	if (flag->br)
		recursiv(info_list, flag);
	free_list(&tmp_list);
	return (0);
}
