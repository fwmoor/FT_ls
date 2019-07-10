/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <zmahomed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 08:53:30 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/10 11:22:21 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_ls.h"

void	recursion(t_dir *list, unsigned char flags, char *path)
{
	t_dir	*ptr;
	char	*s1;
	char	*s2;

	ptr = list;
	if (flags & 4)
		while (ptr != NULL)
		{
			if ((ptr->type == 4) && (ft_strcmp(ptr->name, ".") != 0)
			&& (ft_strcmp(ptr->name, "..") != 0))
			{
				if (!(flags & 2) && (ptr->name[0] == '.'))
				{
					ptr = ptr->next;
					continue ;
				}
				s1 = ft_strjoin("/", ptr->name);
				s2 = ft_strjoin(path, s1);
				free(s1);
				ft_ls(s2, flags);
				free(s2);
			}
			ptr = ptr->next;
		}
}

void	ft_ls(char *path, unsigned char flags)
{
	struct dirent	*de;
	t_dir			*initial;
	DIR				*dr;

	initial = NULL;
	de = NULL;
	dr = opendir(path);
	if (error_handle(path, dr, errno, flags) == 1)
		return ;
	while ((de = readdir(dr)))
	{
		if (!initial)
			initial = set_list(de, path);
		else
			list_add(&initial, de, path);
	}
	closedir(dr);
	merge_s(&initial, flags);
	print_output(initial, flags);
	recursion(initial, flags, path);
	delete_list(&initial);
}

int		execute_args(int ac, char **av, unsigned char flags)
{
	int i;
	int check;

	i = 1;
	check = 0;
	while (i < ac)
	{
		if (av[i][0] != '-')
		{
			ft_ls(av[i], flags);
			check = 1;
		}
		i++;
	}
	return (check);
}

int		main(int ac, char **av)
{
	unsigned char	flags;
	int				check;

	check = 0;
	flags = get_flags(ac, av);
	if (ac == 1)
		ft_ls(".", flags);
	else
	{
		check = execute_args(ac, av, flags);
		if (check == 0)
			ft_ls(".", flags);
	}
	ft_putchar('\n');
	return (0);
}
