/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <zmahomed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:33:41 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/10 11:23:31 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_dir		*s_merge_time(t_dir *a, t_dir *b, unsigned int flag)
{
	t_dir *result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->mtime > b->mtime && !(flag & 8))
	{
		result = a;
		result->next = s_merge_time(a->next, b, flag);
	}
	else if (a->mtime < b->mtime && flag & 8)
	{
		result = a;
		result->next = s_merge_time(a->next, b, flag);
	}
	else
	{
		result = b;
		result->next = s_merge_time(a, b->next, flag);
	}
	return (result);
}

void		merge_s(t_dir **head_ref, unsigned char flags)
{
	t_dir *head;
	t_dir *a;
	t_dir *b;

	head = *head_ref;
	if ((head == NULL) || (head->next == NULL))
		return ;
	frontback_split(head, &a, &b);
	merge_s(&a, flags);
	merge_s(&b, flags);
	if (flags & 16)
		*head_ref = s_merge_time(a, b, flags);
	else
		*head_ref = s_merge(a, b, flags);
}

t_dir		*s_merge(t_dir *a, t_dir *b, unsigned char flags)
{
	t_dir *result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (!(flags & 8) && ((ft_strcmp(a->name, b->name)) < 0))
	{
		result = a;
		result->next = s_merge(a->next, b, flags);
	}
	else if ((flags & 8) && ((ft_strcmp(a->name, b->name)) > 0))
	{
		result = a;
		result->next = s_merge(a->next, b, flags);
	}
	else
	{
		result = b;
		result->next = s_merge(a, b->next, flags);
	}
	return (result);
}

void		frontback_split(t_dir *source, t_dir **front_ref, t_dir **back_ref)
{
	t_dir *fast;
	t_dir *slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front_ref = source;
	*back_ref = slow->next;
	slow->next = NULL;
}
