/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 08:23:24 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/16 10:37:17 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

unsigned char		ft_p_len(char **str)
{
	unsigned char	p_len;

	p_len = 0;
	while (**str == 'h' || **str == 'l' || **str == 'j' || **str == 'z')
	{
		if (**str == 'h')
		{
			(*str)++;
			p_len |= (**str == 'h') ? 64 : 2;
		}
		if (**str == 'l')
		{
			(*str)++;
			p_len |= (**str == 'l') ? 8 : 4;
		}
		if (**str == 'j' || **str == 'z')
		{
			p_len |= (**str == 'j') ? 16 : 32;
			(*str)++;
		}
	}
	return (p_len);
}

unsigned char		ft_flags(char **str)
{
	unsigned char	flags;

	flags = 0;
	while (**str == '0' || **str == ' ' || **str == '+' || **str == '-' ||
		**str == '#')
	{
		if (**str == '0')
			flags |= 1;
		if (**str == ' ')
			flags |= 2;
		if (**str == '+')
			flags |= 4;
		if (**str == '-')
			flags |= 8;
		if (**str == '#')
			flags |= 16;
		(*str)++;
	}
	if (flags & 8 && flags & 1)
		flags &= ~(1);
	return (flags);
}

int					ft_width(char **str, va_list ap, t_format *tf)
{
	int				i;
	int				temp;

	i = 0;
	if (**str == '*')
	{
		(*str)++;
		temp = va_arg(ap, int);
		i = (temp >= 0) ? temp : 0;
		if (temp < 0)
			tf->flags |= 1;
	}
	if (ft_isdigit(**str))
		i = ft_atoi(*str);
	while (**str <= '9' && **str >= '0')
		(*str)++;
	return (i);
}

int					ft_format(char **str, va_list ap, int fd)
{
	int				i;
	t_format		tf;

	tf.prec = 0;
	tf.flags = ft_flags(str);
	tf.len = ft_width(str, ap, &tf);
	if (**str == '.')
	{
		(*str)++;
		tf.flags &= ~(1);
		tf.prec = ft_width(str, ap, &tf);
		tf.flags |= 32;
	}
	tf.p_len = ft_p_len(str);
	tf.ap = (va_list *)ap;
	if (ft_correct_form(**str) != 1)
		return (0);
	tf.t_form = *(*str)++;
	i = ft_getstr_all(&tf, fd);
	return (i);
}

int					ft_format_all(const char *format, va_list ap, int fd)
{
	int				i;
	char			**str;

	i = 0;
	str = (char **)&format;
	while (**str)
	{
		if (**str == '%')
		{
			*str += 1;
			i += ft_format(str, ap, fd);
		}
		else
		{
			ft_putchar_fd(*((*str)++), fd);
			i++;
		}
	}
	va_end(ap);
	return (i);
}
