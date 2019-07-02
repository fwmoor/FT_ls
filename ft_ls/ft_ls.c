#include	"./includes/ft_ls.h"
#include <stdio.h>

unsigned char		ft_flags(char **av, int ac)
{
	int				i;
	char			**str;
	unsigned char	flags;

	flags = 0;
	i = 1;
	while (i < ac)
	{
		str = &av[i];
		while (**str == 'l' || **str == 'a' || **str == 'R' ||
			**str == 'r' || **str == 't' || **str == ' ' || **str == '-')
		{
			if (**str == 'l')
				flags |= 1;
			if (**str == 'a')
				flags |= 2;
			if (**str == 'R')
				flags |= 4;
			if (**str == 'r')
				flags |= 8;
			if (**str == 't')
				flags |= 16;
			(*str)++;
		}
		i++;
	}
	return (flags);
}

int 				main(int ac, char **av)
{
	//t_format tf;
	//tf.flags = ft_flags(av, ac);
	int i = 0;
	struct dirent *de;
	DIR *dr = opendir("./");
    while ((de = readdir(dr)) != NULL)
	{
		printf("%s\n", de->d_name);
	}
	return 0;
}
