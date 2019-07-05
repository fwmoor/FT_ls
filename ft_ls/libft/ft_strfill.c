#include "./includes/ft_printf.h"

char				*ft_getstr_d(t_format *tf)
{
	char			*str;

	if (tf->p_len & 4 || tf->t_form == 'D') //l
		str = ft_itoa(va_arg(*tf->ap, long));
	else if (tf->p_len & 1)
		str = ft_itoa((short)va_arg(*tf->ap, int));
	else if (tf->p_len & 2)
		str = ft_itoa((char)va_arg(*tf->ap, int));
	else if (tf->p_len & 8) //ll
		str = ft_itoa(va_arg(*tf->ap, long long));
	else if (tf->p_len & 16)
		str = ft_itoa(va_arg(*tf->ap, intmax_t));
	else if (tf->p_len & 32) //z
		str = ft_itoa(va_arg(*tf->ap, size_t));
	else 
		str = ft_itoa(va_arg(*tf->ap, int));
	return (str);
}

char				*ft_getstr_u(t_format *tf, int base)
{
	char			*str;
	if (tf->p_len & 4 || tf->t_form == 'O' || tf->t_form == 'U') //l
		str = ft_itoa_base_u(va_arg(*tf->ap, unsigned long), base);
	else if (tf->p_len & 1)
		str = ft_itoa_base_u((unsigned short)va_arg(*tf->ap, int), base);
	else if (tf->p_len & 2)
		str = ft_itoa_base_u((unsigned char)va_arg(*tf->ap, int), base);
	else if (tf->p_len & 8) //ll
		str = ft_itoa_base_u(va_arg(*tf->ap, unsigned long long), base);
	else if (tf->p_len & 16)
		str = ft_itoa_base_u(va_arg(*tf->ap, uintmax_t), base);
	else if (tf->p_len & 32) //z
		str = ft_itoa_base_u(va_arg(*tf->ap, size_t), base);
	else 
		str = ft_itoa_base_u(va_arg(*tf->ap, unsigned int), base);
	return (str);
}

int					ft_getstr_all(t_format *tf)
{
	int				i;
	char			*str;
	
	i = 0;
	if (tf->t_form == 's'|| tf->t_form == 'c' || tf->t_form == '%')
	{
		if (tf->t_form == 's')
			str = ft_middle_s(tf);
		else
			str = ft_middle_c(tf);
		i += ft_print_sc(tf, str);
	}
	else if (tf->t_form == 'd' || tf->t_form == 'i' || tf->t_form == 'D')
		i = ft_middle_n(tf);
	return (i);
}


