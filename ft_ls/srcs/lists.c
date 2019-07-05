#include "../includes/ft_ls.h"

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

void                delete_list(t_nodes **head)
{
	t_nodes         *current = *head;
	t_nodes         *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}