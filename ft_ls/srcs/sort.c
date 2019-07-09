/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:33:41 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/08 15:08:27 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

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