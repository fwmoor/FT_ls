/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 09:17:47 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/22 18:26:15 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H
# include "../libft/includes/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <errno.h>
# include <time.h>

# define LONG 1
# define ALL 2
# define RECUR 4
# define REVE 8
# define TIM 16
# define DOT 32
# define NOSOR 64
# define PUT 128
# define COLO 256
# define NORM 512
# define UGNOM 1024
# define ONE 2048
# define ERROR 4096

typedef struct		s_dir
{
	int				type;
	int				block;
	int				max;
	int				maxs;
	char			*name;
	char			*uid;
	char			*gid;
	char			*path;
	off_t			size;
	time_t			mtime;
	time_t			ntime;
	mode_t			mode;
	nlink_t			nlink;
	struct s_dir	*next;
}					t_dir;

int					isdir(const char *path);
int					islink(const char *path);
int					long_size(t_dir *nodes, int flags);
int					check_arg(int ac, int flags, char **args);
int					long_nlink(t_dir *nodes, int flags);
int					get_flags(int ac, char **av);
int					ft_printf(const char *format, ...);
int					err_han(char *path, DIR *dp, int ierrno, int flag);
char				acl_print(t_dir *lst);
char				*convert_un(int uid, int flags);
char				*convert_gn(int gib, int flags);
int					add_args(char **args, int ac, char **av, int flags);
void				print_block(t_dir *ptr, int flags);
void				add_colo(t_dir *lst, int flags);
void				display_l(t_dir *lst, char *path, int flags);
void				print_link(t_dir *lst, char *path);
void				convert_date(char *str);
void				delete_list(t_dir **list);
void				ft_ls(char *path, int flags);
void				print_long(t_dir *list, int flags, char *path);
void				print_normal(t_dir *list, int flags);
void				print_output(t_dir *list, int flags, char *path);
void				merge_s(t_dir **head_ref, int flags);
void				recursion(t_dir *list, int flags, char *path);
void				check_nano(int flags, t_dir *a, t_dir *b, t_dir **result);
void				fb_split(t_dir *src, t_dir **front, t_dir **back);
void				basic_print(struct dirent *de, int flags, DIR *dr);
void				list_add(t_dir **ls, struct dirent *de, char *path, int f);
void				recursive_print(struct dirent *de, int flags, char *path);
t_dir				*s_merge(t_dir *a, t_dir *b, int flags);
t_dir				*merge_time(t_dir *a, t_dir *b, int flag);
t_dir				*set_list(struct dirent *de, char *path, int flags);

#endif
