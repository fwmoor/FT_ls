/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:42:21 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/23 09:48:31 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				rev_lst(t_dir **head)
{
	t_dir			*cur;
	t_dir			*next;
	t_dir			*prev;

	next = NULL;
	prev = NULL;
	cur = *head;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*head = prev;
}

void				merge_s(t_dir **first, int flags)
{
	t_dir			*head;
	t_dir			*a;
	t_dir			*b;

	head = *first;
	if (!(flags & NOSOR))
	{
		if ((head == NULL) || (head->next == NULL))
			return ;
		fb_split(head, &a, &b);
		merge_s(&a, flags);
		merge_s(&b, flags);
		if (flags & TIM)
			*first = merge_time(a, b, flags);
		else
			*first = s_merge(a, b, flags);
	}
	else
		rev_lst(first);
}

t_dir				*s_merge(t_dir *a, t_dir *b, int flags)
{
	t_dir			*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (!(flags & REVE) && ((ft_strcmp(a->name, b->name)) < 0))
	{
		result = a;
		result->next = s_merge(a->next, b, flags);
	}
	else if ((flags & REVE) && ((ft_strcmp(a->name, b->name)) > 0))
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

void				fb_split(t_dir *src, t_dir **front, t_dir **back)
{
	t_dir			*fast;
	t_dir			*slow;

	slow = src;
	fast = src->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front = src;
	*back = slow->next;
	slow->next = NULL;
}
