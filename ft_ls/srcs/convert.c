/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:17:49 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/09 11:52:34 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*convert_un(int uid)
{
	struct passwd *pwd;

	pwd = getpwuid(uid);
	if (pwd == NULL)
		perror("getpwuid");
	else
		return (pwd->pw_name);
	return (NULL);
}

char	*convert_gn(int gib)
{
	struct group *grp;

	grp = getgrgid(gib);
	if (grp == NULL)
		perror("getgigid");
	else
		return (grp->gr_name);
	return (NULL);
}

void convertDate(char *str)
{
	char ret[] = "000  0 00:00 ";
	int i = 4;
	int j = 0;
	while (i < 16)
	{
		ret[j] = str[i];
		j++;
		i++;
	}
	ft_putstr(ret);
	ft_putstr("\t");
}