/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 08:17:29 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/10 11:49:24 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include "./ft_ls.h"
# include <stdio.h>
# include <errno.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <ctype.h>

# define DEFAULT "\x1b[0m"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"

typedef struct		s_format
{
	char			t_form;
	va_list			*ap;
	unsigned char	flags;
	unsigned char	p_len;
	long			prec;
	long			len;
	int				neg;
	int				col;
}					t_format;

int					ft_getstr_all(t_format *tf);
char				*ft_getstr_d(t_format *tf);
char				*ft_getstr_u(t_format *tf, int base);
char				*ft_getstr_p(t_format *tf);
int					ft_print_sc(t_format *tf, char *str);
int					ft_print_sn(t_format *tf, char *str);
int					ft_print_un(t_format *tf, char *str);
int					ft_print_ux(t_format *tf, char *str);
int					ft_print_up(t_format *tf, char *str);
int					ft_after(t_format *tf, long len, char *str);
int					ft_format_all(const char *format, va_list ap);
int					ft_format(char **str, va_list ap, int col);
int					ft_width(char **str);
unsigned char		ft_flags(char **str);
unsigned char		ft_p_len(char **str);
int					ft_num_len(intmax_t n, int base);
int					ft_num_len_u(uintmax_t n, int base);
char				*ft_itoa_base_u(uintmax_t n, int base);
char				*ft_itoa_base(intmax_t n, int base);
int					ft_middle_n(t_format *tf);
int					ft_middle_u(t_format *tf);
int					ft_middle_x(t_format *tf);
int					ft_middle_p(t_format *tf);
char				*ft_middle_c(t_format *tf);
char				*ft_middle_s(t_format *tf);
char				*ft_appendwchar(wchar_t wc, char *str);
int					ft_correct_form(char c);
int					ft_col(char **str);
void				print_col(char *str, long min, t_format *tf);
int					ft_printf(const char *format, ...);

#endif
