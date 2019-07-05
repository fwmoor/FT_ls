/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 08:24:38 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/05 08:00:51 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int			ft_num_len(intmax_t n, int base)
{
	int i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

int			ft_num_len_u(uintmax_t n, int base)
{
	int i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

char				*ft_itoa_base_u(uintmax_t n, int base)
{
	int				len;
	static char		*buf;
    static char		rep[] = "0123456789abcdef";

	len = ft_num_len_u(n, base);
	if (len == 0)
		len = 1;
	buf = ft_strnew(len);
    while (len)
    {
        buf[--len] = rep[n % base];
        n /= base;
    }
    return (buf);
}

char				*ft_itoa_base(intmax_t n, int base)
{
	int				len;
	char			*new;
	static char		rep[] = "0123456789abcdef";

	len = ft_num_len(n, base);
	new = ft_strnew(len);
	while (len > 0)
	{
		new[--len] = rep[n % base];
        n /= base;	
	}
	return (new);
}
