/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:42:17 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/16 11:25:02 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_block(t_dir *ptr)
{
	int i;

	i = 0;
	ft_printf("total ");
	while (ptr)
	{
		i += ptr->block;
		ptr = ptr->next;
	}
	ft_printf("%d\n", i);
}

void	display_l(t_dir *lst)
{
	ft_putstr((S_ISDIR(lst->mode)) ? "d" : "-");
	ft_putstr((lst->mode & S_IRUSR) ? "r" : "-");
	ft_putstr((lst->mode & S_IWUSR) ? "w" : "-");
	ft_putstr((lst->mode & S_IXUSR) ? "x" : "-");
	ft_putstr((lst->mode & S_IRGRP) ? "r" : "-");
	ft_putstr((lst->mode & S_IWGRP) ? "w" : "-");
	ft_putstr((lst->mode & S_IXGRP) ? "x" : "-");
	ft_putstr((lst->mode & S_IROTH) ? "r" : "-");
	ft_putstr((lst->mode & S_IWOTH) ? "w" : "-");
	ft_putstr((lst->mode & S_IXOTH) ? "x " : "- ");
	ft_printf("%*d ", lst->max + 1, lst->nlink);
	ft_printf("%s %s\t%d\t", lst->uid, lst->gid, lst->size);
	convert_date(ctime(&lst->mtime));
	ft_printf("%s\n", lst->name);
}

void	print_long(t_dir *list, int flags)
{
	int   i;
	t_dir *ptr;
	t_dir *ptr2;
	t_dir *ptr3;

	ptr = list;
	ptr2 = list;
	ptr3 = list;
	if (flags & LONG)
		print_block(ptr2);
	i = long_nlink(ptr3);
	while (ptr != NULL)
	{
		ptr->max = i;
		if (flags & ALL)
			display_l(ptr);
		else if (ft_strncmp(ptr->name, ".", 1) != 0)
			display_l(ptr);
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

void	print_output(t_dir *list, int flags)
{
	if (flags & LONG)
		print_long(list, flags);
	else
		print_normal(list, flags);
}
