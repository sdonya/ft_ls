/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:45:55 by cgamora           #+#    #+#             */
/*   Updated: 2020/11/14 18:13:29 by sdonya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../libft/ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdint.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <time.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <sys/acl.h>
# include <uuid/uuid.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <limits.h>

# define MAX(x, y) x > y ? x : y

typedef struct		s_flags
{
	int				l;
	int				br;
	int				a;
	int				r;
	int				t;
}					t_flags;

typedef struct		s_info
{
	char			*name;
	char			*path;
	struct stat		info;
	int				dir;
	int				total;
	struct s_info	*next;
}					t_info;

typedef struct		s_flagl
{
	int				nlink;
	int				pw_name;
	int				gr_name;
	int				st_size;
	int				major;
	int				minor;
	int				device;
	int				f_name;
	int				w_cols;
}					t_flagl;

int					g_parser;
int					g_amount;
int					parse_to_struct(t_flags *flag, int argc, char **argv);
int					ft_start_ls(char *dir_name, t_flags *flag);
int					add_file(t_info **info_list, char *fd_name);
int					dir_list(t_info **info_list, char *fd_name, t_flags *flag);
int					timecmp(t_info *a, t_info *b);
void				list_sort(t_info **tmp_list, t_flags *flag);
t_info				*ascii_sort(t_info *a, t_info *b, t_flags *flag);
t_flagl				get_flagl(t_info *tmp_list);
int					get_termcolom(void);
int					print_all(t_info *info_list, t_flagl infrml, t_flags *flag);
void				print_list(t_info *info_list, t_flagl informl,\
t_flags *flag);
void				print_permissions(t_info *info_list);
int					add_direct(t_info **info_list, char *fd_name,\
struct dirent *direct);
void				sort_av(int ac, char ***av, int begin, t_flags *flags);
int					ft_isdir(const char *fd_name);
char				*control_path(char *fd_name, char *dir_name);
void				free_list(t_info **list);
void				printf_informl(t_info *info_list, t_flagl informl);

#endif
