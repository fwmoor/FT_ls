/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 18:56:35 by fwmoor            #+#    #+#             */
/*   Updated: 2019/07/23 19:03:21 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				print_normal_sin(t_dir *list, int flags)
{
	t_dir			*ptr;

	ptr = list;
	if (ptr != NULL)
		add_colo(list, flags);
}

void				print_long_sin(t_dir *list, int flags, char *path)
{
	t_dir			*ptr;

	ptr = list;
	if (ptr != NULL)
	{
		ptr->max = ft_num_len(ptr->nlink, 10);
		ptr->maxs = ft_num_len(ptr->size, 10);
		ptr->maxu = ft_strlen(ptr->uid);
		ptr->maxg = ft_strlen(ptr->gid);
		display_l(ptr, path, flags);
	}
}

void				print_output_long(t_dir *list, int flags, char *path)
{
	if (flags & LONG || flags & UGNOM)
		print_long_sin(list, flags, path);
	else
		print_normal_sin(list, flags);
}
