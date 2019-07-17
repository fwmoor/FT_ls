/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:41:56 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/17 20:28:37 by fwmoor           ###   ########.fr       */
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
	int				t;
	int				j;
	int				flags;

	flags = 0;
	i = 0;
	while (++i < ac && av[i][0] == '-')
	{
		j = 0;
		if (av[i][j++] == '-' && av[i][j] != '\0')
		{
			t = j;
			while (av[i][j])
				flags |= check_flags(av[i][j++]);
			if (flags & 256)
				illegal_flags(av[i][t]);
		}
		else if (av[i][j] == '\0')
			flags |= err_han4(av[i]);
		else
			break ;
	}
	return (flags);
}
