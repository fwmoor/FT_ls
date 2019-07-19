/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:41:56 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/19 14:28:10 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			illegal_flags(char flag)
{
	ft_printf("ft_ls: illegal option -- %c\n", flag);
	ft_printf("usage: ./ft_ls [-Raflrt1] [file ...]\n");
	exit(1);
}

int				check_flags(char c)
{
	if (c == 'l')
		return (LONG);
	if (c == 'a')
		return (ALL);
	if (c == 'R')
		return (RECUR);
	if (c == 'r')
		return (REVE);
	if (c == 't')
		return (TIM);
	if (c == 'f')
		return (NOSOR);
	if (c == '1')
		return (ONE);
	return (ERROR);
}

int				get_flags(int ac, char **av)
{
	int			i;
	int			j;
	int			flags;

	flags = 0;
	i = 0;
	while (++i < ac)
	{
		j = 0;
		if (av[i][j++] == '-')
		{
			if (av[i][j] == '-' && av[i][j + 1] != '-')
				break ;
			while (av[i][j])
			{
				flags |= check_flags(av[i][j]);
				if (flags & ERROR)
					illegal_flags(av[i][j]);
				j++;
			}
		}
		else
			break ;
	}
	return (flags);
}
