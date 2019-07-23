/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 10:00:15 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/23 13:48:26 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				islink(const char *path)
{
	struct stat	s;

	lstat(path, &s);
	return (S_ISLNK(s.st_mode));
}

int				isdir(const char *path)
{
	struct stat	s;

	stat(path, &s);
	return (S_ISDIR(s.st_mode));
}

int					bg_colo(t_dir *lst)
{
	int				i;

	i = 0;
	if (lst->mode & S_IWUSR && lst->mode & S_IWGRP && lst->mode & S_IWOTH)
	{
		if (lst->mode & S_ISVTX && !(S_ISDIR(lst->mode)))
			ft_putstr("\033[30;41m");
		else if (lst->mode & S_ISVTX && S_ISDIR(lst->mode))
			ft_putstr("\033[30;42m");
		else
			ft_putstr("\033[30;43m");
		i = 1;
	}
	return (i);
}

void				add_colo(t_dir *lst, int flags)
{
	if (flags & COLO)
	{
		if (!(bg_colo(lst)))
		{
			if (S_ISLNK(lst->mode))
				ft_putstr("\033[0;35m");
			else if (S_ISDIR(lst->mode))
				ft_putstr("\033[0;34m");
			else if (lst->mode & S_IXOTH)
				ft_putstr("\033[0;31m");
		}
		ft_putstr(lst->name);
		if (S_ISDIR(lst->mode) && flags & PUT)
			ft_putstr("/\033[0m");
		else
			ft_putstr("\033[0m");
	}
	else
	{
		ft_printf("%s", lst->name);
		if (S_ISDIR(lst->mode) && flags & PUT)
			ft_putchar('/');
	}
	if (!(S_ISLNK(lst->mode)) || !(flags & LONG))
		ft_putchar('\n');
}