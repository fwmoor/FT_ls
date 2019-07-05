/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_middle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 08:26:34 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/05 08:02:19 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int				ft_middle_n(t_format *tf)
{
	int			i;
	char		*str;

	i = 0;
	str = ft_getstr_d(tf);
	i += ft_print_sn(tf, str);
	free(str);
	return (i);
}

char			*ft_middle_c(t_format *tf)
{
	char	*str;
	char	arg;

	if (tf->t_form == 'c')
	{
		arg = (char)va_arg(*tf->ap, int);
		str = ft_strnew(2);
		str[0] = arg;
		return (str);
	}
	else
		return (ft_strdup("%"));
}

char			*ft_middle_s(t_format *tf)
{
	char		*str;
	
	str = ft_strdup(va_arg(*tf->ap, char *));
	if (!(str))
		return (ft_strdup("(null)"));	
	return (str);
}
