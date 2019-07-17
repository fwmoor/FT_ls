/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:41:56 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/17 15:27:57 by fremoor          ###   ########.fr       */
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
	else if (c == '.')
		return (DOT);
	else if (c == '-')
		return (256);
	return (0);
}

int				get_flags(int ac, char **av)
{
	int				i;
	int				j;
	int				flags;
	int				temp;

	flags = 0;
	i = 0;
	while (++i < ac && av[i][0] == '-')
	{
		temp = 0;
		j = 0;
		if (av[i][j++] == '-')
		{
			while ((av[i][j] == 'l' || av[i][j] == 'a' || av[i][j] == 'R' ||
			av[i][j] == 'r' || av[i][j] == 't' || av[i][j] == '.' ||
			av[i][j] == 'f' || av[i][j] == '-') && !(flags & 128))
				temp |= check_flags(av[i][j++]);
			if ((temp == 0 || temp & 128))
				temp |= err_han4(av[i]);
			if (temp == 0)
				illegal_flags(av[i][j]);
		}
		flags += temp;
	}
	return (flags);
}
