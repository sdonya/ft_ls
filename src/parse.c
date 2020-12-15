/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 23:59:58 by cgamora           #+#    #+#             */
/*   Updated: 2020/11/14 18:13:29 by sdonya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_direc_error(char *s)
{
	ft_printf("ft_ls: %s: No such file or directory\n", s);
	exit(1);
}

int			ft_flag_error(char **argv, int i)
{
	if (argv[g_parser][0] == '-' && !argv[g_parser][1])
		ft_direc_error(&argv[g_parser][0]);
	if (argv[g_parser][1] == '-' && !argv[g_parser][2])
		return (0);
	ft_printf("ft_ls: illegal option -- %c\n", argv[g_parser][i]);
	ft_printf("usage: ft_ls [-Ralrt] [file ...]\n");
	exit(1);
}

int			get_flags(int argc, char **argv, t_flags *flag)
{
	int i;

	i = 1;
	if (g_parser >= argc || argv[g_parser][0] != '-')
		return (-1);
	while (argv[g_parser][i])
	{
		if (argv[g_parser][i] == 'l')
			flag->l = 1;
		else if (argv[g_parser][i] == 'a')
			flag->a = 1;
		else if (argv[g_parser][i] == 'R')
			flag->br = 1;
		else if (argv[g_parser][i] == 'r')
			flag->r = 1;
		else if (argv[g_parser][i] == 't')
			flag->t = 1;
		else if (ft_flag_error(argv, i) == 0)
			return (-2);
		i++;
	}
	if (i == 1)
		ft_flag_error(argv, i);
	return (1);
}

int			parse_to_struct(t_flags *flag, int argc, char **argv)
{
	int error;

	g_parser = 1;
	while ((error = get_flags(argc, argv, flag)) != -1)
	{
		if (error == -2)
		{
			g_parser++;
			break ;
		}
		g_parser++;
	}
	return (1);
}
