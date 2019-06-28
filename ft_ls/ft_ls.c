#include	"./includes/ft_ls.h"

void		call_print(char *str, t_format *tf)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'a')
			tf->a_form = 1;
		i++;
	}
}

int 		main(int ac, char **av)
{
	(void)ac;
	t_format *tf = NULL;
    struct dirent *de;
	//struct stat file_info;
    DIR *dr = opendir("./");
	tf = reset_tf(tf);
	call_print(av[1], tf);
    while ((de = readdir(dr)) != NULL)
	{
		if (de->d_name[0] == '.')
		{
			if (tf->a_form == 1)
				ft_putstr(de->d_name);
		}
		else
			ft_putstr(de->d_name);
	}
    closedir(dr);
    return 0;
}
