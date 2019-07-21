/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:42:03 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/21 12:35:24 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				add_colo(t_dir *lst, int flags)
{
	if (flags & COLO)
	{
		if (S_ISLNK(lst->mode))
			ft_printf("\033[0;35");
		else if (S_ISDIR(lst->mode))
			ft_printf("\033[0;34m");
		else if (lst->mode & S_IXOTH)
			ft_printf("\033[0;31m");
		ft_printf("%s\n\033[0m", lst->name);
	}
	else
		ft_printf("%s\n", lst->name);
}

void				recursion(t_dir *list, int flags, char *path)
{
	t_dir			*ptr;
	char			*s1;
	char			*s2;

	ptr = list;
	if (flags & RECUR)
		while (ptr != NULL)
		{
			if ((ptr->type == 4) && (ft_strcmp(ptr->name, ".") != 0)
			&& (ft_strcmp(ptr->name, "..") != 0))
			{
				if (!(flags & ALL) && (ptr->name[0] == '.'))
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

void				ft_ls(char *path, int flags)
{
	struct dirent	*de;
	t_dir			*initial;
	DIR				*dr;

	initial = NULL;
	de = NULL;
	dr = opendir(path);
	if (err_han(path, dr, errno, flags) == 1)
		return ;
	while ((de = readdir(dr)))
	{
		if (!initial)
			initial = set_list(de, path, flags);
		else
			list_add(&initial, de, path, flags);
	}
	closedir(dr);
	merge_s(&initial, flags);
	print_output(initial, flags, path);
	recursion(initial, flags, path);
	delete_list(&initial);
}

int					main(int ac, char **av)
{
	int				flags;
	int				num_args;
	int				check;
	char			*args[ac];

	check = 0;
	num_args = 0;
	flags = get_flags(ac, av);
	if (ac == 1)
		ft_ls(".", flags);
	else
	{
		num_args = add_args(args, ac, av);
		check = check_arg(num_args, flags, args);
		if (check == 0)
			ft_ls(".", flags);
	}
	return (1);
}
