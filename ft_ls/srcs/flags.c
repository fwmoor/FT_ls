/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:41:56 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/11 10:31:43 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				check_flags(char c)
{
	if (c == 'l')
		return (1);
	else if (c == 'a')
		return (2);
	else if (c == 'R')
		return (4);
	else if (c == 'r')
		return (8);
	else if (c == 't')
		return (16);
	else if (c == '.')
		return (32);
	return (0);
}

unsigned char	get_flags(int ac, char **av)
{
	int				i;
	int				j;
	unsigned char	flags;

	flags = '\0';
	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j++] == '-')
			while (av[i][j] == 'l' || av[i][j] == 'a' || av[i][j] == 'R' ||
			av[i][j] == 'r' || av[i][j] == 't' || av[i][j] == '.')
				flags |= check_flags(av[i][j++]);
		i++;
	}
	return (flags);
}
