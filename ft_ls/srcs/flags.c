/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:41:56 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/12 10:20:04 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

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
	return (0);
}

int				get_flags(int ac, char **av)
{
	int				i;
	int				j;
	int				flags;

	flags = 0;
	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j++] == '-')
		{
			while (av[i][j] == 'l' || av[i][j] == 'a' || av[i][j] == 'R' ||
			av[i][j] == 'r' || av[i][j] == 't' || av[i][j] == '.' ||
			av[i][j] == 'f')
				flags |= check_flags(av[i][j++]);
			if ((flags == 0 || flags & 128))
				flags |= err_han4(av[i]);
		}
		i++;
	}
	return (flags);
}
