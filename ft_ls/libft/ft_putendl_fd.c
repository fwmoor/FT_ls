/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 08:38:19 by fremoor           #+#    #+#             */
/*   Updated: 2019/06/12 09:57:55 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	if (s == NULL)
		return ((void)NULL);
	while (*s != '\0')
		write(fd, &(*s++), 1);
	write(fd, "\n", 1);
}
