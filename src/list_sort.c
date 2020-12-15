/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 05:57:07 by cgamora           #+#    #+#             */
/*   Updated: 2020/11/14 18:13:29 by sdonya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			timecmp(t_info *a, t_info *b)
{
	if (b->info.st_mtime == a->info.st_mtime)
		return (b->info.st_mtimespec.tv_nsec - a->info.st_mtimespec.tv_nsec);
	else
		return (b->info.st_mtime - a->info.st_mtime);
}

void		split(t_info *head, t_info **a, t_info **b)
{
	t_info *first;
	t_info *second;

	first = head;
	second = head->next;
	while (second)
	{
		second = second->next;
		if (second)
		{
			first = first->next;
			second = second->next;
		}
	}
	*a = head;
	*b = first->next;
	first->next = NULL;
	return ;
}

void		make_sort(t_info **tmp_list, t_flags *flag)
{
	t_info *head;
	t_info *a;
	t_info *b;

	head = *tmp_list;
	if (!head || !head->next)
		return ;
	split(head, &a, &b);
	make_sort(&a, flag);
	make_sort(&b, flag);
	*tmp_list = ascii_sort(a, b, flag);
}

void		make_revers_sort(t_info **tmp_list)
{
	t_info	*prev;
	t_info	*current;
	t_info	*next;

	prev = NULL;
	current = *tmp_list;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*tmp_list = prev;
}

void		list_sort(t_info **tmp_list, t_flags *flag)
{
	make_sort(tmp_list, flag);
	if (flag->r)
		make_revers_sort(tmp_list);
}
