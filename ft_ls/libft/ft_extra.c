/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 08:22:59 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/16 10:37:39 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int			ft_after(t_format *tf, long len, char *str, int fd)
{
	int		i;
	long	max;

	i = 0;
	if (*str == '-')
	{
		ft_putchar_fd('-', fd);
		(str)++;
	}
	while ((tf->flags & 1 && tf->len > len) || tf->prec-- > len)
	{
		ft_putchar_fd('0', fd);
		i++;
		tf->len > 0 ? tf->len-- : tf->len;
	}
	max = (tf->prec > len && (tf->prec != 0)) ? tf->prec : len;
	ft_putstr_fd(str, fd);
	i += len;
	if (tf->flags & 8)
		while (tf->len-- > max)
		{
			ft_putchar_fd(' ', fd);
			i++;
		}
	return (i);
}
