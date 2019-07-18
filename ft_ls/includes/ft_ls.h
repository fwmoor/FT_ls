/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 09:17:47 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/18 19:47:35 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H
# include "../libft/includes/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <stdio.h>
# include <sys/types.h>
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

typedef struct		s_dir
{
	int				type;
	int				block;
	int				max;
	int				maxs;
	char			*name;
	char			*uid;
	char			*gid;
	off_t			size;
	time_t			mtime;
	mode_t			mode;
	nlink_t			nlink;
	struct s_dir	*next;
}					t_dir;

int					long_size(t_dir *nodes, int flags);
int					long_nlink(t_dir *nodes, int flags);
int					get_flags(int ac, char **av);
int					ft_printf(const char *format, ...);
int					err_han(char *path, DIR *dp, int ierrno, int flag);
char				*convert_un(int uid);
char				*convert_gn(int gib);
void				display_l(t_dir *lst, char *path);
void				print_link(t_dir *lst, char *path);
void				convert_date(char *str);
void				delete_list(t_dir **list);
void				ft_ls(char *path, int flags);
void				print_long(t_dir *list, int flags, char *path);
void				print_normal(t_dir *list, int flags);
void				print_output(t_dir *list, int flags, char *path);
void				merge_s(t_dir **head_ref, int flags);
void				recursion(t_dir *list, int flags, char *path);
void				fb_split(t_dir *src, t_dir **front, t_dir **back);
void				basic_print(struct dirent *de, int flags, DIR *dr);
void				list_add(t_dir **alst, struct dirent *de, char *path);
void				recursive_print(struct dirent *de, int flags, char *path);
t_dir				*s_merge(t_dir *a, t_dir *b, int flags);
t_dir				*set_list(struct dirent *de, char *path);

#endif
