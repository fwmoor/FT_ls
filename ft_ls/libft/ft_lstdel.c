/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 08:28:26 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/05 07:59:24 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;
	t_list *nxt_lst;

	lst = *alst;
	while (lst)
	{
		nxt_lst = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = nxt_lst;
	}
	*alst = NULL;
}
