/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:41:37 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/23 09:48:06 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*convert_un(int uid, int flags)
{
	struct passwd	*pwd;

	pwd = getpwuid(uid);
	if (pwd != NULL && (!(flags & UGNOM)))
		return (ft_strdup(pwd->pw_name));
	else
		return (ft_itoa(uid));
}

char		*convert_gn(int gib, int flags)
{
	struct group *grp;

	grp = getgrgid(gib);
	if (grp != NULL && (!(flags & UGNOM)))
		return (ft_strdup(grp->gr_name));
	else
		return (ft_itoa(gib));
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
	ft_putstr(ret);
}
