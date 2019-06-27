/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 08:36:26 by fremoor           #+#    #+#             */
/*   Updated: 2019/05/21 12:33:59 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *chr;

	if (len == 0)
		return (b);
	chr = (unsigned char *)b;
	while (len)
	{
		*chr = (unsigned char)c;
		len--;
		chr++;
	}
	return (b);
}
