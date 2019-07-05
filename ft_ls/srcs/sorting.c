#include "../includes/ft_ls.h"

t_nodes				*sorted_list(t_nodes *a, t_nodes *b, t_form *tf)
{
	t_nodes			*ret = NULL;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);

	if (ft_strcmp(a->name, b->name) > 0 && (tf->flags & 8))
	{
		ret = a;
		ret->next = sorted_list(a->next, b, tf);
	}
	else if (ft_strcmp(a->name, b->name) < 0 && !(tf->flags & 8))
	{
		ret = a;
		ret->next = sorted_list(a->next, b, tf);
	}
	else
	{
		ret = b;
		ret->next = sorted_list(a, b->next, tf);
	}
	return (ret);
}

void				split_half(t_nodes *head, t_nodes **a, t_nodes **b)
{
	t_nodes			*first;
	t_nodes			*last;

	last = head;
	first = head->next;
	while (first != NULL)
	{
		first = first->next;
		if(first != NULL)
		{
			last = last->next;
			first = first->next;
		}
	}
	*a = head;
	*b = last->next;
	last->next = NULL;
}

void				sort_list(t_nodes **first,  t_form *tf)
{
	t_nodes			*head;
	t_nodes			*a;
	t_nodes			*b;

	head = *first;
	if (head == NULL || head->next == NULL)
		return ;
	split_half(head, &a, &b);
	sort_list(&a, tf);
	sort_list(&b, tf);
	*first = sorted_list(a, b, tf);
}

void				display(t_nodes *first, t_form *tf)
{
	t_nodes			*start;

	sort_list(&first, tf);
	start = first;
	while (start != NULL)
	{
		ft_printf("%s\n", start->name);
		start = start->next;
	}
}