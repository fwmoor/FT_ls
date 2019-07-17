/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:42:17 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/17 11:22:48 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_block(t_dir *ptr, int flags)
{
	int i;

	i = 0;
	ft_printf("total ");
	while (ptr)
	{
		if ((flags & ALL && ft_strncmp(ptr->name, ".", 1) == 0) ||
			ft_strncmp(ptr->name, ".", 1) != 0)
			i += ptr->block;
		ptr = ptr->next;
	}
	ft_printf("%d\n", i);
}

void	print_link(t_dir *lst, char *path)
{
	char		buffer[1025];
	char		*tpath;
	char		*tmp;

	ft_bzero(&buffer, 1025);
	tmp = ft_strjoin(path, "/");
	tpath = ft_strjoin(tmp, lst->name);
	ft_strdel(&tmp);
	readlink(tpath, buffer, 1024);
	ft_printf(" -> %s", buffer);
	ft_strdel(&tpath);
}

void	print_long(t_dir *list, int flags, char *path)
{
	t_dir *ptr;
	t_dir *ptr2;
	t_dir *ptr3;
	t_dir *ptr4;

	ptr = list;
	ptr2 = list;
	ptr3 = list;
	ptr4 = list;
	if (flags & LONG)
		print_block(ptr2, flags);
	while (ptr != NULL)
	{
		ptr->max = long_nlink(ptr3, flags);
		ptr->maxs = long_size(ptr4, flags);
		if (flags & ALL)
			display_l(ptr, path);
		else if (ft_strncmp(ptr->name, ".", 1) != 0)
			display_l(ptr, path);
		ptr = ptr->next;
	}
}

void	print_normal(t_dir *list, int flags)
{
	t_dir *ptr;

	ptr = list;
	while (ptr != NULL)
	{
		if (flags & ALL || flags & NOSOR)
		{
			ft_printf("%s\n", ptr->name);
			ptr = ptr->next;
		}
		else
		{
			if (ptr->name[0] != '.')
				ft_printf("%s\n", ptr->name);
			ptr = ptr->next;
		}
	}
}

void	print_output(t_dir *list, int flags, char *path)
{
	if (flags & LONG)
		print_long(list, flags, path);
	else
		print_normal(list, flags);
}
