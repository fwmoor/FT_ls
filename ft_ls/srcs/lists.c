/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <zmahomed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 12:09:38 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/10 11:22:27 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_dir	*set_list(struct dirent *de, char *path)
{
	t_dir		*new;
	struct stat	sb;
	char		*path2;
	char		*tmp;

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
	new->block = sb.st_blocks;
	new->next = NULL;
	free(tmp);
	free(path2);
	return (new);
}

void	delete_list(t_dir **list)
{
	t_dir *current;
	t_dir *next;

	current = *list;
	while (current)
	{
		next = current->next;
		free(current->name);
		free(current);
		current = next;
	}
	*list = NULL;
}

void	list_add(t_dir **alst, struct dirent *de, char *path)
{
	t_dir *new;

	new = set_list(de, path);
	new->next = *alst;
	*alst = new;
}
