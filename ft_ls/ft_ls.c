#include	"./includes/ft_ls.h"

t_nodes				*sorted_list(t_nodes *a, t_nodes *b)
{
	t_nodes			*ret = NULL;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);

	if (ft_strcmp(a->name, b->name) <= 0)
	{
		ret = a;
		ret->next = sorted_list(a->next, b);
	}
	else
	{
		ret = b;
		ret->next = sorted_list(a, b->next);
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

void				sort_list(t_nodes **first)
{
	t_nodes			*head;
	t_nodes			*a;
	t_nodes			*b;

	head = *first;
	if (head == NULL || head->next == NULL)
		return ;
	split_half(head, &a, &b);
	sort_list(&a);
	sort_list(&b);
	*first = sorted_list(a, b);
}

void				display(t_nodes *first)
{
	t_nodes			*start;

	sort_list(&first);
	start = first;
	while (start != NULL)
	{
		ft_printf("%s\n", start->name);
		start = start->next;
	}
}

t_nodes				*create_node(struct dirent *de)
{
	t_nodes			*new;

	new = (t_nodes *)malloc(sizeof(t_nodes));
	new->name = de->d_name;
	new->next = NULL;
	return (new);
}

t_nodes				*insert_node(struct dirent *de)
{
	static t_nodes	*first;
	static t_nodes	*last;
	t_nodes			*new;

	new = create_node(de);
	if (first == last && last == NULL)
	{
		first = last = new;
		first->next = NULL;
		last->next = NULL;
	}
	else
	{
		last->next = new;
		last = new;
		last->next = NULL;
	}
	return (new);
}

unsigned char		ls_flags(char **av, int ac)
{
	int				i;
	char			*str;
	unsigned char	flags;

	flags = 0;
	i = 1;
	while (i < ac)
	{
		str = ft_strdup(av[i]);
		while (*str == 'l' || *str == 'a' || *str == 'R' ||
			*str == 'r' || *str == 't' || *str == ' ' || *str == '-')
		{
			if (*str == 'l')
				flags |= 1;
			if (*str == 'a')
				flags |= 2;
			if (*str == 'R')
				flags |= 4;
			if (*str == 'r')
				flags |= 8;
			if (*str == 't')
				flags |= 16;
			(str)++;
		}
		i++;
	}
	return (flags);
}

int 				main(int ac, char **av)
{
	t_form			tf;
	t_nodes			*test = NULL;
	struct dirent	*de;
	DIR				*dr = opendir("./");

	tf.flags = ls_flags(av, ac);
    while ((de = readdir(dr)) != NULL)
	{
		if (!test)
			test = insert_node(de);
		else
			insert_node(de);
	}
	closedir(dr);
	display(test);
	return 0;
}
