/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 08:50:10 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/05 07:59:24 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s);
	str = (char*)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	return (ft_strcpy(str, s));
}
