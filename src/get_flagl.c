/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flagl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 07:02:52 by cgamora           #+#    #+#             */
/*   Updated: 2020/11/14 18:13:29 by sdonya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					get_digits(int64_t n)
{
	int				count;

	if (n)
		count = 0;
	else
		count = 1;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void			set_device(t_info *tmp_list, t_flagl *inform)
{
	int				tmp;

	tmp = major(tmp_list->info.st_rdev);
	if (tmp > inform->major)
		inform->major = tmp;
	tmp = minor(tmp_list->info.st_rdev);
	if (tmp > inform->minor)
		inform->minor = tmp;
	inform->device = 1;
}

static void			set_digit(t_flagl *inform)
{
	inform->nlink = get_digits(inform->nlink);
	inform->major = get_digits(inform->major);
	inform->minor = get_digits(inform->minor);
	inform->st_size = get_digits(inform->st_size);
	if (inform->device)
		inform->st_size = MAX(2 + inform->major \
		+ inform->minor, inform->st_size);
}

static t_flagl		init_information(void)
{
	t_flagl			inf;

	inf.nlink = 0;
	inf.device = 0;
	inf.f_name = 0;
	inf.gr_name = 0;
	inf.major = 0;
	inf.minor = 0;
	inf.pw_name = 0;
	inf.st_size = 0;
	inf.w_cols = get_termcolom();
	return (inf);
}

t_flagl				get_flagl(t_info *tmp_list)
{
	t_flagl			inform;
	int				tmp;

	inform = init_information();
	while (tmp_list)
	{
		if (tmp_list->info.st_nlink > inform.nlink)
			inform.nlink = tmp_list->info.st_nlink;
		tmp = ft_strlen(getpwuid(tmp_list->info.st_uid)->pw_name);
		if (tmp > inform.pw_name)
			inform.pw_name = tmp;
		tmp = ft_strlen(getgrgid(tmp_list->info.st_gid)->gr_name);
		if (tmp > inform.gr_name)
			inform.gr_name = tmp;
		if (tmp_list->info.st_size > inform.st_size)
			inform.st_size = tmp_list->info.st_size;
		tmp = ft_strlen(tmp_list->name);
		if (tmp > inform.f_name)
			inform.f_name = tmp;
		if (S_ISBLK(tmp_list->info.st_mode) || S_ISCHR(tmp_list->info.st_mode))
			set_device(tmp_list, &inform);
		tmp_list = tmp_list->next;
	}
	set_digit(&inform);
	return (inform);
}
