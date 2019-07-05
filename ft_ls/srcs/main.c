/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:56:23 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/05 15:31:01 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int main(int argc, char **argv)
{
	unsigned char flags = 0;
	int i = 1;
	int j = 0;
	int numFlags = 0;

	while (argv[i])
	{
		j = 1;
		if (strncmp(argv[i],"-",1) == 0)
		{
			while (argv[i][j])
			{
				if (argv[i][j] == 'l')
					flags |= 1;
				else if (argv[i][j] == 'R')
					flags |= 2;
				else if (argv[i][j] == 'a')
					flags |= 4;
				else if (argv[i][j] == 'r')
					flags |= 8;
				else if (argv[i][j] == 't')
					flags |= 16;
				else
					illegalFlags(argv[i][j]);
				if (j == 1)
					numFlags++;
				j++;
			}
		}
		else
			ft_ls(argv[i],flags);
		i++;
	}
	if (numFlags + 1 == argc)
		ft_ls(".",flags);

	return (0);
}
