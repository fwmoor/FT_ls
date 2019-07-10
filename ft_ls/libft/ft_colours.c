/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colours.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 08:14:39 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/10 11:11:39 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		print_col(char *str, long min, t_format *tf)
{
	char	*test;
	char	*temp;

	test = ft_strnew(min);
	ft_strncpy(test, str, min);
	if (tf->col == 1)
		temp = ft_strjoin(DEFAULT, test);
	else if (tf->col == 2)
		temp = ft_strjoin(RED, test);
	else if (tf->col == 3)
		temp = ft_strjoin(GREEN, test);
	else if (tf->col == 4)
		temp = ft_strjoin(YELLOW, test);
	else if (tf->col == 5)
		temp = ft_strjoin(BLUE, test);
	else if (tf->col == 6)
		temp = ft_strjoin(MAGENTA, test);
	else if (tf->col == 7)
		temp = ft_strjoin(CYAN, test);
	else
		temp = ft_strdup(test);
	write(1, temp, ft_strlen(temp));
	free(test);
	free(temp);
}

int			assign_col(char *str)
{
	int		i;
	char	*test;

	test = ft_strdup(str);
	free(str);
	if (ft_strcmp(ft_str_upper(test), "EOC") == 0)
		i = 1;
	else if (ft_strcmp(ft_str_upper(test), "RED") == 0)
		i = 2;
	else if (ft_strcmp(ft_str_upper(test), "GREEN") == 0)
		i = 3;
	else if (ft_strcmp(ft_str_upper(test), "YELLOW") == 0)
		i = 4;
	else if (ft_strcmp(ft_str_upper(test), "BLUE") == 0)
		i = 5;
	else if (ft_strcmp(ft_str_upper(test), "MAGENTA") == 0)
		i = 6;
	else if (ft_strcmp(ft_str_upper(test), "CYAN") == 0)
		i = 7;
	else if (ft_strcmp(ft_str_upper(test), "BLINK") == 0)
		i = 8;
	else
		i = 0;
	free(test);
	return (i);
}

int			ft_col(char **str)
{
	int		i;
	char	*test;

	i = 0;
	if (**str != '{')
	{
		ft_putchar(*(*str)++);
		return (0);
	}
	test = str[0];
	while (**str != '}')
	{
		(*str)++;
		i++;
	}
	test = ft_strsub(test, 1, i - 1);
	i = assign_col(test);
	(*str)++;
	return (i);
}
