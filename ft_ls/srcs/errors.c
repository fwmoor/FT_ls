/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:41:49 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/22 14:48:42 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	err_han2(char *path)
{
	if (ft_strcmp(path, ".") != 0)
		ft_printf("\n%s:\n", path);
}

void	err_han3(char *path)
{
	ft_putstr("ft_ls: ");
	if (path[ft_strlen(path) - 1] != '/')
		ft_putstr(path);
	ft_printf(": Permission denied\n");
}

int		err_han(char *path, DIR *dp, int ierrno, int flag)
{
	if (!dp)
	{
		if (ierrno == 20)
		{
			ft_putendl(path);
			return (1);
		}
		else if (ierrno == 13)
		{
			err_han3(path);
			return (1);
		}
		else if (flag & RECUR)
			err_han2(path);
		ft_printf("ft_ls: %s: No such file or directory\n", path);
		return (1);
	}
	return (0);
}
