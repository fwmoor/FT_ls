/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:33:41 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/09 14:18:37 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_dir* SortedMergeTime(t_dir* a, t_dir* b, unsigned int flag)
{
    t_dir* result = NULL;

    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if (a->mtime > b->mtime && !(flag & 8))
	{
		result = a;
		result->next = SortedMergeTime(a->next, b, flag);
	}
    else if (a->mtime < b->mtime && flag & 8)
	{
		result = a;
		result->next = SortedMergeTime(a->next, b, flag);
	}
    else 
	{
        result = b;
        result->next = SortedMergeTime(a, b->next, flag);
    }
    return (result);
}

void MergeSort(t_dir** headRef, unsigned char flags)
{
	t_dir* head = *headRef;
	t_dir* a;
	t_dir* b;

	if ((head == NULL) || (head->next == NULL)) {
		return;
	}
	FrontBackSplit(head, &a, &b);
	MergeSort(&a, flags);
	MergeSort(&b, flags);
	if (flags & 16)
		*headRef = SortedMergeTime(a,b, flags);
	else
		*headRef = SortedMerge(a, b, flags);
}

t_dir* SortedMerge(t_dir* a, t_dir* b, unsigned char flags)
{
	t_dir* result = NULL;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (!(flags & 8) && ((ft_strcmp(a->name, b->name)) < 0)) {
		result = a;
		result->next = SortedMerge(a->next, b, flags);
	}
	else if ((flags & 8) && ((ft_strcmp(a->name, b->name)) > 0)) {
		result = a;
		result->next = SortedMerge(a->next, b, flags);
	}
	else {
		result = b;
		result->next = SortedMerge(a, b->next, flags);
	}
	return (result);
}

void FrontBackSplit(t_dir* source, t_dir** frontRef, t_dir** backRef)
{
	t_dir* fast;
	t_dir* slow;
	slow = source;
	fast = source->next;
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}