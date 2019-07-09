/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:27:28 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/09 13:43:16 by mimeyer          ###   ########.fr       */
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
	return (0);
}

unsigned char	get_flags(int ac, char **av)
{
	int				i;
	int				j;
	unsigned char	flags;

	flags = '\0';
	i = 1;
	j = 0;
	while (i < ac)
	{
		if (av[i][j] == '-')
		{
			j++;
			while (av[i][j] == 'l' || av[i][j] == 'a' || av[i][j] == 'R' ||
			av[i][j] == 'r' || av[i][j] == 't')
			{
				flags |= check_flags(av[i][j]);
				j++;
			}
		}
		i++;
	}
	return (flags);
}
