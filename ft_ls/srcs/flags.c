/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:27:28 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/09 12:23:44 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

unsigned char	get_flags(int ac, char **av)
{
	int				i;
	char			*str;
	unsigned char	flags;

	flags = 0;
	i = 1;
	while (i < ac)
	{
		str = ft_strdup(av[i]);
		while (*str == 'l' || *str == 'a' || *str == 'R' ||
			*str == 'r' || *str == 't' || *str == ' ' || *str == '-')
		{
			if (*str == 'l')
				flags |= 1;
			if (*str == 'a')
				flags |= 2;
			if (*str == 'R')
				flags |= 4;
			if (*str == 'r')
				flags |= 8;
			if (*str == 't')
				flags |= 16;
			(str)++;
		}
		i++;
		if (!str)
			free(str);
	}
	return (flags);
}
