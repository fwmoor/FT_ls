#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>

typedef struct		s_format
{
	char			t_form;
	va_list			*ap;
	unsigned char	flags;
	unsigned char	p_len;
	long			prec;
	long			len;
	int				neg;
}					t_format;

int					ft_getstr_all(t_format *tf);
char				*ft_getstr_d(t_format *tf);
char				*ft_getstr_u(t_format *tf, int base);

int					ft_print_sc(t_format *tf, char *str);
int					ft_print_sn(t_format *tf, char *str);

int					ft_after(t_format *tf, long len, char *str);

int					ft_format_all(const char *format, va_list ap);
int					ft_format(char **str, va_list ap);
int					ft_width(char **str);
unsigned char		ft_flags(char **str);
unsigned char		ft_p_len(char **str);

int					ft_num_len(intmax_t n, int base);
int					ft_num_len_u(uintmax_t n, int base);
char				*ft_itoa_base_u(uintmax_t n, int base);
char				*ft_itoa_base(intmax_t n, int base);

int					ft_middle_n(t_format *tf);
char				*ft_middle_c(t_format *tf);
char				*ft_middle_s(t_format *tf);

int					ft_printf(const char *format, ...);
#endif
