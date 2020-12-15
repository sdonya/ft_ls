/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 06:32:31 by cgamora           #+#    #+#             */
/*   Updated: 2020/11/14 18:13:29 by sdonya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_info				*ascii_sort_dop(t_info *a, t_info *b)
{
	t_info			*itog;

	itog = NULL;
	if (!a)
		return (b);
	if (!b)
		return (a);
	if (ft_strcmp(a->name, b->name) < 0)
	{
		itog = a;
		itog->next = ascii_sort_dop(a->next, b);
	}
	else
	{
		itog = b;
		itog->next = ascii_sort_dop(a, b->next);
	}
	return (itog);
}

t_info				*ascii_sort(t_info *a, t_info *b, t_flags *flag)
{
	t_info			*itog;

	itog = NULL;
	if (!a)
		return (b);
	if (!b)
		return (a);
	if (flag->t)
	{
		if (timecmp(a, b) < 0)
		{
			itog = a;
			itog->next = ascii_sort(a->next, b, flag);
		}
		else
		{
			itog = b;
			itog->next = ascii_sort(a, b->next, flag);
		}
	}
	else
		itog = ascii_sort_dop(a, b);
	return (itog);
}

int					get_termcolom(void)
{
	struct winsize	size;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	return (size.ws_col);
}

static void			rev_av(int ac, char ***av, int begin)
{
	char			*tmp;

	while (begin < ac - 1)
	{
		tmp = (*av)[ac - 1];
		(*av)[ac - 1] = (*av)[begin];
		(*av)[begin] = tmp;
		ac--;
		begin++;
	}
}

void				sort_av(int ac, char ***av, int begin, t_flags *flags)
{
	int				end;
	int				i;
	char			*tmp;

	end = ac - 1;
	while (end > begin)
	{
		i = begin;
		while (i < end)
		{
			if (ft_strcmp((*av)[i], (*av)[i + 1]) > 0)
			{
				tmp = (*av)[i];
				(*av)[i] = (*av)[i + 1];
				(*av)[i + 1] = tmp;
			}
			i++;
		}
		end--;
	}
	if (flags->r)
		rev_av(ac, av, begin);
}
