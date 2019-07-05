/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 08:22:59 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/05 08:00:51 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int			ft_after(t_format *tf, long len, char *str)
{
	int		i;
	long	max;

	i = 0;
	while ((tf->flags & 1 && tf->len > len) || tf->prec-- > len)
	{
		ft_putchar('0');
		i++;
		tf->len > 0 ? tf->len-- : tf->len;
	}
	max = (tf->prec > len && (tf->prec != 0)) ? tf->prec : len;
	ft_putstr(str);
	i += len;
	if (tf->flags & 8)
		while (tf->len-- > max)
		{
			ft_putchar(' ');
			i++;
		}
	return (i);
}
