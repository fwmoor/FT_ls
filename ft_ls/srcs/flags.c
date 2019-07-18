/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:41:56 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/18 19:50:09 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			illegal_flags(char flag)
{
	ft_printf("ft_ls: illegal option -- %c\n", flag);
	ft_printf("usage: ft_ls [-Raflrt] [file ...]\n");
	exit (1);
}

int				check_flags(char c)
{
	if (c == 'l')
		return (LONG);
	else if (c == 'a')
		return (ALL);
	else if (c == 'R')
		return (RECUR);
	else if (c == 'r')
		return (REVE);
	else if (c == 't')
		return (TIM);
	else if (c == 'f')
		return (NOSOR);
	else
		return (256);
}

int				get_flags(int ac, char **av)
{
	int				i;
	int				j;
	int				flags;

	flags = 0;
	i = 0;
	while (++i < ac)
	{
		j = 0;
		if (av[i][j++] == '-' && ft_strlen(av[i]) > 1)
		{
			if (av[i][j] == '-' && av[i][j + 1] != '-')
				break ;
			while (av[i][j])
			{
				flags |= check_flags(av[i][j]);
				if (flags & 256 && !(flags & 512))
					illegal_flags(av[i][j]);
				else if (flags & 256 && flags & 512)
					ft_printf("ft_ls: %s: No such file or directory\n", av[i]);
				j++;
			}
		}
		else
			flags |= 512;
	}
	return (flags);
}
