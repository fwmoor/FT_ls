/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 09:16:50 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/05 15:31:01 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int error_handle(char * path, DIR *dp, int ierrno, unsigned int flag)
{
	if (ierrno == 20)
	{
		ft_putstr(path);
		return (1);
	}
    else if(!dp)
	{
		if (ierrno == 13)
		{
			ft_putstr("ft_ls: ");
			if (path[ft_strlen(path) - 1] != '/')
				ft_putstr(path);
			ft_putstr(": Permission denied\n");
			return (1);
		}
		ft_putstr("ft_ls: ");
		ft_putstr(path);
		ft_putstr(": No such file or directory\n");
        return (1);
    }
	if (flag & 2)
	{
		ft_putstr("\n\n");
		ft_putstr(path);
		ft_putstr(":\n");
	}
	return (0);
}

void illegalFlags(char flag)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(flag);
	ft_putstr("\nusage: ft_ls [-Ralrt] [file ...]\n");
	exit(0);
}
