#include	"./includes/ft_ls.h"

void		call_print(char *str, char *de_name)
{
	if (ft_strcmp(str, "-a") == 0)
		ft_putstr(de_name);
	ft_putstr("\t\t");
}

int 		main()
{
    struct dirent *de;
	struct stat file_info;
    DIR *dr = opendir(".");
    while ((de = readdir(dr)) != NULL)
	{
		lstat(de->d_name, &file_info);
		if (de->d_name[0] != '.')
			if ((file_info.st_mode & S_IFMT)==S_IFDIR)
			{
				ft_putstr("directory: ");
				ft_putstr(de->d_name);
				ft_putchar('\n');
			}
		/*if (ac == 1)
		{
			if (de->d_name[0] != '.')
			{
				ft_putstr(de->d_name);
				ft_putstr("\t\t");
			}
		}
		else
			call_print(av[1], de->d_name);*/
	}
    ft_putchar('\n');
    closedir(dr);
    return 0;
}