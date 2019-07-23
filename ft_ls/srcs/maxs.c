/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:24:21 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/23 12:38:44 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					long_size(t_dir *nodes, int flags)
{
	int				i;
	t_dir			*temp;

	i = 0;
	temp = nodes;
	while (temp)
	{
		if ((flags & ALL && ft_strncmp(temp->name, ".", 1) == 0) ||
			ft_strncmp(temp->name, ".", 1) != 0)
			if (ft_num_len(temp->size, 10) >= i)
				i = ft_num_len(temp->size, 10);
		temp = temp->next;
	}
	return (i);
}

int					long_nlink(t_dir *nodes, int flags)
{
	int				i;
	t_dir			*temp;

	i = 0;
	temp = nodes;
	while (temp)
	{
		if ((flags & ALL && ft_strncmp(temp->name, ".", 1) == 0) ||
			ft_strncmp(temp->name, ".", 1) != 0)
            if (ft_num_len(temp->nlink, 10) > i)
                i = ft_num_len(temp->nlink, 10);
        temp = temp->next;
    }
    return (i);
}

int                 long_gmax(t_dir *nodes, int flags)
{
	t_dir			*temp;
	size_t			i;

	i = 0;
	temp = nodes;
	while (temp)
	{
		if ((flags & ALL && ft_strncmp(temp->name, ".", 1) == 0) ||
		ft_strncmp(temp->name, ".", 1) != 0)
			if (ft_strlen(temp->gid) > i)
				i = ft_strlen(temp->gid);
		temp = temp->next;
	}
	return (i);
}

int					long_umax(t_dir *nodes, int flags)
{
	t_dir			*temp;
	size_t			i;

	i = 0;
	temp = nodes;
	while (temp)
	{
		if ((flags & ALL && ft_strncmp(temp->name, ".", 1) == 0) ||
		ft_strncmp(temp->name, ".", 1) != 0)
			if (ft_strlen(temp->uid) > i)
				i = ft_strlen(temp->uid);
		temp = temp->next;
	}
	return (i);
}
