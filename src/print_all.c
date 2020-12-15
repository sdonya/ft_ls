/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 08:12:20 by cgamora           #+#    #+#             */
/*   Updated: 2020/11/14 18:13:29 by sdonya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				free_list(t_info **list)
{
	t_info			*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->name);
		free((*list)->path);
		free(*list);
		*list = tmp;
	}
}

int					get_line_capacity(int naml, int winc)
{
	int				n;

	n = 1;
	while ((naml + 6) * n < winc - 2)
		n++;
	if (n - 2 > 1)
		return (n - 1);
	return (1);
}

int					print_all(t_info *info_list, t_flagl infrml, t_flags *flag)
{
	int				checked;
	int				col_num;

	checked = 0;
	col_num = get_line_capacity(infrml.f_name, infrml.w_cols);
	while (info_list)
	{
		if (!flag->l && checked >= col_num && !(checked % col_num))
			ft_putchar('\n');
		print_list(info_list, infrml, flag);
		if (flag->l && info_list->next)
			ft_putchar('\n');
		else if (!(info_list->next))
			info_list->next = NULL;
		else
			ft_putchar(' ');
		info_list = info_list->next;
		checked++;
	}
	return (checked);
}

void				print_premissions_dop(t_info *info_list)
{
	acl_t		tmp;

	tmp = acl_get_link_np(info_list->path, ACL_TYPE_EXTENDED);
	if (listxattr(info_list->path, NULL, 0, XATTR_NOFOLLOW) > 0)
		ft_putchar('@');
	else if (tmp != NULL)
		ft_putchar('+');
	else
		ft_putchar(' ');
	free(tmp);
}

void				print_permissions(t_info *info_list)
{
	ft_putchar((info_list->info.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((info_list->info.st_mode & S_IWUSR) ? 'w' : '-');
	if (S_ISUID & info_list->info.st_mode)
		ft_putchar((info_list->info.st_mode & S_IXUSR) ? 's' : 'S');
	else
		ft_putchar((info_list->info.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((info_list->info.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((info_list->info.st_mode & S_IWGRP) ? 'w' : '-');
	if (S_ISGID & info_list->info.st_mode)
		ft_putchar((info_list->info.st_mode & S_IXUSR) ? 's' : 'S');
	else
		ft_putchar((info_list->info.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((info_list->info.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((info_list->info.st_mode & S_IWOTH) ? 'w' : '-');
	if (S_ISVTX & info_list->info.st_mode)
		ft_putchar((info_list->info.st_mode & S_IXUSR) ? 't' : 'T');
	else
		ft_putchar((info_list->info.st_mode & S_IXOTH) ? 'x' : '-');
	print_premissions_dop(info_list);
}
