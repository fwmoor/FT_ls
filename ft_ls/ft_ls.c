#include	"./includes/ft_ls.h"

unsigned char		ls_flags(char **av, int ac)
{
	int				i;
	char			*str;
	unsigned char	flags;

	flags = 0;
	i = 1;
	while (i < ac)
	{
		str = ft_strdup(av[i]);
		while (*str == 'l' || *str == 'a' || *str == 'R' ||
			*str == 'r' || *str == 't' || *str == ' ' || *str == '-')
		{
			if (*str == 'l')
				flags |= 1;
			if (*str == 'a')
				flags |= 2;
			if (*str == 'R')
				flags |= 4;
			if (*str == 'r')
				flags |= 8;
			if (*str == 't')
				flags |= 16;
			(str)++;
		}
		i++;
	}
	return (flags);
}

int 				main(int ac, char **av)
{
	t_format tf;
	tf.flags = ls_flags(av, ac);
	struct dirent *de;
	DIR *dr = opendir("./");
	de = readdir(dr);
	ft_printf("%s", de->d_name);
    while ((de = readdir(dr)) != NULL)
	{
		ft_printf("%20s", de->d_name);
	}
	ft_putchar('\n');
	return 0;
}
