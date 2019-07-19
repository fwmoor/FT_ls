/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:41:37 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/19 16:09:31 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*convert_un(int uid)
{
	struct passwd	*pwd;

	pwd = getpwuid(uid);
	if (pwd != NULL)
		return (ft_strdup(pwd->pw_name));
	return (ft_itoa(uid));
}

char		*convert_gn(int gib)
{
	struct group *grp;

	grp = getgrgid(gib);
	if (grp != NULL)
		return (ft_strdup(grp->gr_name));
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
	ft_printf("%s", ret);
}

void		display_l(t_dir *lst, char *path)
{
	if (S_ISLNK(lst->mode))
		ft_putstr("l");
	else
		ft_putstr((S_ISDIR(lst->mode)) ? "d" : "-");
	ft_putstr((lst->mode & S_IRUSR) ? "r" : "-");
	ft_putstr((lst->mode & S_IWUSR) ? "w" : "-");
	ft_putstr((lst->mode & S_IXUSR) ? "x" : "-");
	ft_putstr((lst->mode & S_IRGRP) ? "r" : "-");
	ft_putstr((lst->mode & S_IWGRP) ? "w" : "-");
	ft_putstr((lst->mode & S_IXGRP) ? "x" : "-");
	ft_putstr((lst->mode & S_IROTH) ? "r" : "-");
	ft_putstr((lst->mode & S_IWOTH) ? "w" : "-");
	ft_putstr((lst->mode & S_IXOTH) ? "x" : "-");
	ft_printf("%*d ", lst->max + 2, lst->nlink);
	ft_printf("%s  %s", lst->uid, lst->gid);
	ft_printf("%*d ", lst->maxs + 2, lst->size);
	convert_date(ctime(&lst->mtime));
	ft_printf("%s", lst->name);
	if (S_ISLNK(lst->mode))
		print_link(lst, path);
	ft_putchar('\n');
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
