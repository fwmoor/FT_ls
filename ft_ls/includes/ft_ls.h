/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 07:43:25 by fremoor           #+#    #+#             */
/*   Updated: 2019/06/28 14:51:20 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "../libft/includes/libft.h"

typedef struct		s_format 
{
	int				l_form;
	int				R_form;
	int				a_form;
	int				r_form;
	int				t_form;
	char			*str_dir;
}					t_format;

t_format	*reset_tf(t_format *);

#endif