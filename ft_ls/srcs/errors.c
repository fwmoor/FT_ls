/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:41:49 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/10 13:39:43 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	error_handle2(char *path)
{
	if (ft_strcmp(path, ".") != 0)
		ft_printf("\n%s:\n", path);
}

void	error_handle3(char *path)
{
	ft_printf("ft_ls: ");
	if (path[ft_strlen(path) - 1] != '/')
		ft_printf("%s", path);
	ft_printf(": Permission denied\n");
}

int		error_handle(char *path, DIR *dp, int ierrno, unsigned int flag)
{
	if (ierrno == 20)
	{
		ft_printf("%s", path);
		return (1);
	}
	else if (!dp)
	{
		if (ierrno == 13)
		{
			error_handle3(path);
			return (1);
		}
		ft_printf("ft_ls: %s: No such file or directory\n", path);
		return (1);
	}
	if (flag & 4)
	{
		error_handle2(path);
	}
	return (0);
}
