#include "./includes/ft_printf.h"

int				ft_print_sn(t_format *tf, char *str)
{
	long		len;
	long		max;
	int			i;

	i = 0;
	len = ft_strlen(str);
	if (*str != '-' && (tf->flags & 4 || tf->flags & 2) && ++i)
		tf->len > 0 ? tf->len-- : tf->len;
	if (*str == '-')
		tf->prec++;
	max = (tf->prec > len && (tf->prec != 0)) ? tf->prec : len;
	if (!(tf->flags & 8) & !(tf->flags & 1))
		while (tf->len-- > max)
		{
			ft_putchar(' ');
			i++;
		}
	if (*str != '-' && (tf->flags & 4))
		ft_putchar('+');
	else if (*str != '-' && (tf->flags & 2))
		ft_putchar(' ');
	else if (*str == '-')
	{
		ft_putchar('-');
		str++;
	}
	return (i + ft_after(tf, len, str));
}

int			ft_print_sc(t_format *tf, char *str)
{
	int		i;
	int		len;
	int		min;

	i = 0;
	len = ft_strlen(str);
	if (tf->prec < 0 || tf->t_form == 'c' || tf->t_form == '%')
		tf->prec = len;
	min = (len > tf->prec && !(tf->prec == 0)) ? tf->prec : len;
	if (!(tf->flags & 8) && !(tf->t_form == '%'))
		while (tf->len-- > min)
		{
			ft_putchar(' ');
			i++;
		}
	write(1, str, min);
	i += min;
	if (tf->flags & 8 && !(tf->t_form == '%'))
		while (tf->len-- > min)
		{
			ft_putchar(' ');
			i++;
		}
	return (i);
}
