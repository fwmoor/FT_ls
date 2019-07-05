/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:51:23 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/05 15:31:01 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

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
    dp = opendir(path);
    while((ep = readdir(dp))) 
	{
		if (strncmp(ep->d_name, ".", 1)) 
		{
    	   	if (flag & 2 && ep->d_type == 4) 
			{
       	    	ft_ls(ft_strjoin(path, ft_strjoin("/",ep->d_name)), flag);
       		}
		}
		else
		{
    	   	if (flag & 2 && flag & 4 && ep->d_type == 4 && ft_strcmp(ep->d_name, ".") != 0 && ft_strcmp(ep->d_name, "..") != 0) 
			{
       	    	ft_ls(ft_strjoin(path, ft_strjoin("/",ep->d_name)), flag);
			}
		}
	}	
    closedir(dp);
	deleteList(&first);
}
