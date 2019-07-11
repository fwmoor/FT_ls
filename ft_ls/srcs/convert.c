/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:41:37 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/11 10:30:40 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*convert_un(int uid)
{
	struct passwd	*pwd;

	pwd = getpwuid(uid);
	if (pwd == NULL)
		perror("getpwuid");
	else
		return (pwd->pw_name);
	return (NULL);
}

char		*convert_gn(int gib)
{
	struct group *grp;

	grp = getgrgid(gib);
	if (grp == NULL)
		perror("getgigid");
	else
		return (grp->gr_name);
	return (NULL);
}

void		convert_date(char *str)
{
	char	ret[14];
	int		i;
	int		j;

	j = 0;
	i = 4;
	ft_strcpy(ret, "000  0 00:00 ");
	while (i < 16)
		ret[j++] = str[i++];
	ft_printf("%s", ret);
}
