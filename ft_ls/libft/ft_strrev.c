/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:25:11 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/05 07:59:24 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	char	*ret;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	ret = ft_strnew(len);
	if (ret == NULL)
		return (NULL);
	while (len--)
		ret[i++] = str[len];
	return (ret);
}
