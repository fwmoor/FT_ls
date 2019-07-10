/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <zmahomed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:48:22 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/10 11:22:32 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	display_blocks(t_dir *ptr)
{
	int i;

	i = 0;
	ft_putstr("total ");
	while (ptr)
	{
		i += ptr->block;
		ptr = ptr->next;
	}
	ft_putnbr(i);
	ft_putstr("\n");
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
	ft_putnbr(lst->nlink);
	ft_putstr("\t");
	ft_putstr(lst->uid);
	ft_putstr("\t");
	ft_putstr(lst->gid);
	ft_putstr("\t");
	ft_putnbr(lst->size);
	ft_putstr("\t");
	convert_date(ctime(&lst->mtime));
	ft_putstr(lst->name);
	ft_putchar('\n');
}

void	print_list(t_dir *list, unsigned char flags)
{
	t_dir *ptr;
	t_dir *ptr2;

	ptr = list;
	ptr2 = list;
	if (flags & 1)
		display_blocks(ptr2);
	while (ptr != NULL)
	{
		if (flags & 2)
			display_l(ptr);
		else if (ft_strncmp(ptr->name, ".", 1) != 0)
			display_l(ptr);
		ptr = ptr->next;
	}
}

void	print_normal(t_dir *list, unsigned char flags)
{
	t_dir *ptr;

	ptr = list;
	while (ptr != NULL)
	{
		if (flags & 2)
		{
			ft_putstr(ptr->name);
			ft_putstr("\t\t");
			ptr = ptr->next;
		}
		else
		{
			if (ptr->name[0] != '.')
			{
				ft_putstr(ptr->name);
				ft_putstr("\t\t");
			}
			ptr = ptr->next;
		}
	}
}

void	print_output(t_dir *list, unsigned char flags)
{
	if (flags & 1)
		print_list(list, flags);
	else
		print_normal(list, flags);
}
