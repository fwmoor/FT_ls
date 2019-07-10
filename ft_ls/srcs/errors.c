/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <zmahomed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:57:58 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/10 11:21:53 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	error_handle2(char *path)
{
	if (ft_strcmp(path, ".") != 0)
	{
		ft_putstr("\n\n");
		ft_putstr(path);
		ft_putstr(":\n");
	}
}

void	error_handle3(char *path)
{
	ft_putstr("ft_ls: ");
	if (path[ft_strlen(path) - 1] != '/')
		ft_putstr(path);
	ft_putstr(": Permission denied\n");
}

int		error_handle(char *path, DIR *dp, int ierrno, unsigned int flag)
{
	if (ierrno == 20)
	{
		ft_putstr(path);
		return (1);
	}
	else if (!dp)
	{
		if (ierrno == 13)
		{
			error_handle3(path);
			return (1);
		}
		ft_putstr("ft_ls: ");
		ft_putstr(path);
		ft_putstr(": No such file or directory\n");
		return (1);
	}
	if (flag & 4)
	{
		error_handle2(path);
	}
	return (0);
}
