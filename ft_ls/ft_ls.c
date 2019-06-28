#include	"./includes/ft_ls.h"

void		call_print(char *str, char *de_name)
{
	if (ft_strcmp(str, "-a") == 0)
		ft_putstr(de_name);
	ft_putstr("\t\t");
}

int 		main(int ac, char **av)
{
    struct dirent *de;
	//struct stat file_info;
    DIR *dr = opendir("/goinfre/fremoor/");
    while ((de = readdir(dr)) != NULL)
	{
		if (ac == 1)
		{
			if (de->d_name[0] != '.')
			{
				ft_putstr(de->d_name);
				ft_putstr("\t\t");
			}
		}
		else
			call_print(av[1], de->d_name);
	}
    ft_putchar('\n');
    closedir(dr);
    return 0;
}
