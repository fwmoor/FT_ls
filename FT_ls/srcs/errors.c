/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:41:49 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/23 19:07:22 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	recur_han(char *path)
{
	if (ft_strcmp(path, ".") != 0)
		ft_printf("\n%s:\n", path);
}

void	err_perm(char *path)
{
	ft_putstr("ft_ls: ");
	if (path[ft_strlen(path) - 1] != '/')
		ft_putstr(path);
	ft_printf(": Permission denied\n");
}

void	arg_test(char *path, int flags)
{
	t_dir			*new;
	struct stat		sb;

	new = (t_dir *)malloc(sizeof(*new));
	new->name = ft_strdup(path);
	islink(path) ? lstat(path, &sb) : stat(path, &sb);
	new->nlink = sb.st_nlink;
	new->uid = convert_un(sb.st_uid, flags);
	new->gid = convert_gn(sb.st_gid, flags);
	new->size = sb.st_size;
	new->mode = sb.st_mode;
	new->mtime = sb.st_mtime;
	new->ntime = sb.st_mtimespec.tv_nsec;
	new->block = sb.st_blocks;
	print_output_long(new, flags, path);
	free(new->name);
	free(new->uid);
	free(new->gid);
	free(new);
}

int		err_han(char *path, DIR *dp, int ierrno, int flag)
{
	if (!dp)
	{
		if (ierrno == 20)
		{
			arg_test(path, flag);
			return (1);
		}
		else if (ierrno == 13)
		{
			err_perm(path);
			return (1);
		}
		else if (flag & RECUR)
			recur_han(path);
		ft_printf("ft_ls: %s: No such file or directory\n", path);
		return (1);
	}
	return (0);
}
