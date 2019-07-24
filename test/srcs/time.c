/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 09:48:09 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/23 10:18:04 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_dir				*merge_time(t_dir *a, t_dir *b, int flag)
{
	t_dir			*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->mtime > b->mtime && !(flag & REVE))
	{
		result = a;
		result->next = merge_time(a->next, b, flag);
	}
	else if (a->mtime < b->mtime && flag & REVE)
	{
		result = a;
		result->next = merge_time(a->next, b, flag);
	}
	else if (a->mtime == b->mtime)
		check_nano(flag, a, b, &result);
	else
	{
		result = b;
		result->next = merge_time(a, b->next, flag);
	}
	return (result);
}

void				nano_same(t_dir *a, t_dir *b, int flags, t_dir **result)
{
	if (ft_strcmp(a->name, b->name) < 0 && !(flags & REVE))
	{
		*result = a;
		(*result)->next = merge_time(a->next, b, flags);
	}
	else if (ft_strcmp(a->name, b->name) > 0 && flags & REVE)
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

void				check_nano(int flags, t_dir *a, t_dir *b, t_dir **result)
{
	if (a->ntime > b->ntime && !(flags & REVE))
	{
		*result = a;
		(*result)->next = merge_time(a->next, b, flags);
	}
	else if (a->ntime < b->ntime && flags & REVE)
	{
		*result = a;
		(*result)->next = merge_time(a->next, b, flags);
	}
	else if (a->ntime == b->ntime)
		nano_same(a, b, flags, result);
	else
	{
		*result = b;
		(*result)->next = merge_time(a, b->next, flags);
	}
}
