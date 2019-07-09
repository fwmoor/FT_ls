/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:51:23 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/09 10:08:08 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	recursion(snode *list, unsigned char flag, char *path)
{
	snode *ptr;

	ptr = list;
	if (flag & 2)
	{
		while (ptr != NULL)
		{
			if ((ptr->type == 4) && (ft_strcmp(ptr->name, ".") != 0)
			&& (ft_strcmp(ptr->name, "..") != 0))
				ft_ls(ft_strjoin(path, ft_strjoin("/", ptr->name)), flag);
			ptr = ptr->next;
		}
	}
}

void ft_ls(char *path, unsigned int flag)
{
    DIR * dp = opendir(path);
    struct dirent * ep;
	snode *first = NULL;

	if (error_handle(path, dp, errno, flag) == 1)
		return;
    while((ep = readdir(dp)))
	{
		if (!first)
			first = insert_node_last(ep, path);
		else
			insert_node_last(ep, path);
	}
    closedir(dp);
	mergeSort(&first, flag);
	display(first, flag);
	recursion(first, flag, path);
	deleteList(&first);
}
