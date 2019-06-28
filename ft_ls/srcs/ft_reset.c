#include "../includes/ft_ls.h"

t_format	*reset_tf(t_format *tf)
{
	tf->a_form = 0;
	tf->l_form = 0;
	tf->R_form = 0;
	tf->r_form = 0;
	tf->t_form = 0;
	tf->str_dir = "./";
	return (tf);
}