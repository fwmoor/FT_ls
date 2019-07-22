/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:41:37 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/22 08:44:05 by fremoor          ###   ########.fr       */
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

void		check_nano(int flags, t_dir *a, t_dir *b, t_dir **result)
{
	if (a->mtime > b->mtime && !(flags & REVE))
	{
		*result = a;
		(*result)->next = merge_time(a->next, b, flags);
	}
	else if (a->mtime < b->mtime && flags & REVE)
	{
		*result = a;
		(*result)->next = merge_time(a->next, b, flags);
	}
	else
	{
		*result = b;
		(*result)->next = merge_time(a, b->next, flags);
	}
}
