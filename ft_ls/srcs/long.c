#include "../includes/ft_ls.h"

char		display_type(t_dir *lst)
{
	if (S_ISREG(lst->mode))
		return ('-');
	if (S_ISDIR(lst->mode))
		return ('d');
	if (S_ISLNK(lst->mode))
		return ('l');
	if (S_ISBLK(lst->mode))
		return ('b');
	if (S_ISCHR(lst->mode))
		return ('c');
	if (S_ISSOCK(lst->mode))
		return ('s');
	if (S_ISFIFO(lst->mode))
		return ('p');
	return ('-');
}

void				print_block(t_dir *ptr, int flags)
{
	int				i;

	i = 0;
	ft_printf("total ");
	while (ptr)
	{
		if ((flags & ALL && ft_strncmp(ptr->name, ".", 1) == 0) ||
			ft_strncmp(ptr->name, ".", 1) != 0)
			i += ptr->block;
		ptr = ptr->next;
	}
	ft_printf("%d\n", i);
}

void		display_l(t_dir *lst, char *path, int flags)
{
	ft_putchar(display_type(lst));
	ft_putchar((lst->mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((lst->mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((lst->mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((lst->mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((lst->mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((lst->mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((lst->mode & S_IROTH) ? 'r' : '-');
	ft_putchar((lst->mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((lst->mode & S_IXOTH) ? 'x' : '-');
	ft_putchar(acl_print(path));
	ft_printf("%*d ", lst->max + 1, lst->nlink);
	ft_printf("%s  %s", lst->uid, lst->gid);
	ft_printf("%*d ", lst->maxs + 2, lst->size);
	convert_date(ctime(&lst->mtime));
	add_colo(lst, flags);
	if (S_ISLNK(lst->mode))
		print_link(lst, path);
}
