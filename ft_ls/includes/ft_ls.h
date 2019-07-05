/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 07:43:25 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/05 12:32:10 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/dir.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

typedef struct			s_form 
{
	unsigned char		flags;
}						t_form;

typedef struct			s_nodes
{
	char				*name;
	struct s_nodes		*next;
}						t_nodes;

void					display(t_nodes *first, t_form *tf);
t_nodes					*insert_node(struct dirent *de);
void					delete_list(t_nodes **head_in);

#endif