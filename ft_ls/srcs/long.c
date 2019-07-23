/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 08:44:38 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/23 12:29:38 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char				display_type(t_dir *lst)
{
	if (S_ISREG(lst->mode))
		return ('-');
	if (S_ISDIR(lst->mode))
		return ('d');
	if (S_ISLNK(lst->mode))
		return ('l');
	if (S_ISBLK(lst->mode))
		return ('b');
	if (S_ISCHR(lst->mode))
		return ('c');
	if (S_ISSOCK(lst->mode))
		return ('s');
	if (S_ISFIFO(lst->mode))
		return ('p');
	return ('-');
}

void				display_perms(t_dir *lst)
{
	ft_putchar((lst->mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((lst->mode & S_IWUSR) ? 'w' : '-');
	if (lst->mode & S_ISUID)
		ft_putchar((lst->mode & S_IXUSR) ? 's' : 'S');
	else
		ft_putchar((lst->mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((lst->mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((lst->mode & S_IWGRP) ? 'w' : '-');
	if (lst->mode & S_ISGID)
		ft_putchar((lst->mode & S_IXGRP) ? 's' : 'S');
	else
		ft_putchar((lst->mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((lst->mode & S_IROTH) ? 'r' : '-');
	ft_putchar((lst->mode & S_IWOTH) ? 'w' : '-');
	if (lst->mode & S_ISVTX)
		ft_putchar((lst->mode & S_IXOTH) ? 't' : 'T');
	else
		ft_putchar((lst->mode & S_IXOTH) ? 'x' : '-');
}

void				print_block(t_dir *ptr, int flags)
{
	int				i;
	t_dir			*temp;

	i = 0;
	temp = ptr;
	ft_printf("total ");
	while (temp)
	{
		if ((flags & ALL && ft_strncmp(temp->name, ".", 1) == 0) ||
			ft_strncmp(temp->name, ".", 1) != 0)
			i += temp->block;
		temp = temp->next;
	}
	ft_printf("%d\n", i);
}

void				display_l(t_dir *lst, char *path, int flags)
{
	ft_putchar(display_type(lst));
	display_perms(lst);
	ft_putchar(acl_print(lst));
	ft_printf("%*d ", lst->max + 1, lst->nlink);
	ft_printf("%-*s  %-*s", lst->maxu, lst->uid, lst->maxg, lst->gid);
	ft_printf("%*d ", lst->maxs + 2, lst->size);
	convert_date(ctime(&lst->mtime));
	add_colo(lst, flags);
	if (S_ISLNK(lst->mode))
		print_link(lst, path);
}

char				acl_print(t_dir *lst)
{
	acl_t			acl;

	if ((listxattr(lst->path, 0, 0, XATTR_NOFOLLOW) > 0))
		return ('@');
	if ((acl = acl_get_link_np(lst->path, ACL_TYPE_EXTENDED)))
	{
		free(acl);
		return ('+');
	}
	return (' ');
}
