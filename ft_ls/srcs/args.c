/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:08:19 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/22 18:52:38 by fwmoor           ###   ########.fr       */
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

void			sort_args(char **args)
{
	int			i;
	char		*temp;

	i = 0;
	while ((args[i] != NULL) && (args[i + 1] != NULL))
	{
		if (ft_strcmp(args[i], args[i + 1]) <= 0)
			i++;
		else
		{
			temp = args[i];
			args[i] = args[i + 1];
			args[i + 1] = temp;
		}
	}
}

int				check_arg(int ac, int flags, char **args)
{
	int			i;
	int			check;

	i = 0;
	check = 0;
	while (args[i] != NULL)
	{
		if (ac > 2)
			ft_printf("%s:\n", args[i]);
		ft_ls(args[i], flags);
		if (i < ac)
			ft_putchar('\n');
		check = 1;
		i++;
	}
	return (check);
}

int				add_args(char **args, int ac, char **av, int flags)
{
	int			i;
	int			j;
	DIR			*dr;

	i = 1;
	j = 0;
	while (i < ac)
	{
		if ((av[i][0] == '-') && (ft_strlen(av[i]) > 1) && (av[i][1] != '-'))
			i++;
		else if (av[i][0] == '-' && av[i][1] == '-')
		{
			i++;
			break ;
		}
		else
			break;
	}
	while (i < ac)
	{
		dr = opendir(av[i]);
		if (err_han(av[i], dr, errno, flags) != 1)
			args[j++] = av[i];
		i++;
	}
	args[j] = NULL;
	sort_args(args);
	return (j);
}
