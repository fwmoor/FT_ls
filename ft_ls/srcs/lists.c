/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:42:13 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/19 16:10:05 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_dir				*set_list(struct dirent *de, char *path)
{
	t_dir			*new;
	struct stat		sb;
	char			*path2;
	char			*tmp;

	if (!(new = (t_dir *)malloc(sizeof(*new))))
		return (NULL);
	tmp = ft_strjoin(path, "/");
	path2 = ft_strjoin(tmp, de->d_name);
	lstat(path2, &sb);
	new->name = ft_strdup(de->d_name);
	new->nlink = sb.st_nlink;
	new->uid = convert_un(sb.st_uid);
	new->gid = convert_gn(sb.st_gid);
	new->size = sb.st_size;
	new->type = de->d_type;
	new->mode = sb.st_mode;
	new->mtime = sb.st_mtime;
	new->ntime = sb.st_mtimespec.tv_nsec;
	new->block = sb.st_blocks;
	new->next = NULL;
	free(tmp);
	free(path2);
	return (new);
}

int					long_nlink(t_dir *nodes, int flags)
{
	int				i;

	i = 0;
	while (nodes)
	{
		if ((flags & ALL && ft_strncmp(nodes->name, ".", 1) == 0) ||
			ft_strncmp(nodes->name, ".", 1) != 0)
			if (ft_num_len(nodes->nlink, 10) > i)
				i = ft_num_len(nodes->nlink, 10);
		nodes = nodes->next;
	}
	return (i);
}

int					long_size(t_dir *nodes, int flags)
{
	int				i;

	i = 0;
	while (nodes)
	{
		if ((flags & ALL && ft_strncmp(nodes->name, ".", 1) == 0) ||
			ft_strncmp(nodes->name, ".", 1) != 0)
			if (ft_num_len(nodes->size, 10) >= i)
				i = ft_num_len(nodes->size, 10);
		nodes = nodes->next;
	}
	return (i);
}

void				delete_list(t_dir **list)
{
	t_dir			*current;
	t_dir			*next;

	current = *list;
	while (current)
	{
		next = current->next;
		free(current->name);
		free(current->uid);
		free(current->gid);
		free(current);
		current = next;
	}
	*list = NULL;
}

void				list_add(t_dir **alst, struct dirent *de, char *path)
{
	t_dir			*new;

	new = set_list(de, path);
	new->next = *alst;
	*alst = new;
}
