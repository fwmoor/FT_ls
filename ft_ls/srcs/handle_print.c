/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:59:48 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/05 15:31:01 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void convertDate(char *str)
{
	char ret[] = "000  0 00:00 ";
	int i = 4;
	int j = 0;
	while (i < 16)
	{
		ret[j] = str[i];
		j++;
		i++;
	}
	ft_putstr(ret);
	ft_putstr("\t");
}

char *getUser(uid_t uid)
{
	struct passwd *pws;
	pws = getpwuid(uid);
	return (pws->pw_name);
}

char *getGroup(gid_t gid)
{
	struct group *pws;
	pws = getgrgid(gid);
	return (pws->gr_name);
}

void display_l(mode_t mode, nlink_t nlink, int uid, int gid, off_t size)
{
	ft_putstr((S_ISDIR(mode)) ? "d" : "-");
	ft_putstr((mode & S_IRUSR) ? "r" : "-");
	ft_putstr((mode & S_IWUSR) ? "w" : "-");
	ft_putstr((mode & S_IXUSR) ? "x" : "-");
	ft_putstr((mode & S_IRGRP) ? "r" : "-");
	ft_putstr((mode & S_IWGRP) ? "w" : "-");
	ft_putstr((mode & S_IXGRP) ? "x" : "-");
	ft_putstr((mode & S_IROTH) ? "r" : "-");
	ft_putstr((mode & S_IWOTH) ? "w" : "-");
	ft_putstr((mode & S_IXOTH) ? "x\t" : "-\t");
	ft_putnbr(nlink);
	ft_putstr("\t");
	ft_putstr(getUser(uid));
	ft_putstr("\t");
	ft_putstr(getGroup(gid));
	ft_putstr("\t");
	ft_putnbr(size);
	ft_putstr("\t");
}

void display_blocks(snode *ptr)
{
	int i = 0;
	ft_putstr("total ");
	while (ptr)
	{
		i+=ptr->blocks;
		ptr = ptr->next;
	}
	ft_putnbr(i);
	ft_putstr("\n");
}

void display(snode *first, unsigned int flag)
{
	snode *ptr;
	ptr = first;
	if (flag & 1)
		display_blocks(ptr);
	while (ptr != NULL)
	{
		if (!(flag & 4) && ft_strncmp(ptr->name, ".", 1)) 
		{
			if (flag & 1)
			{
				display_l(ptr->mode, ptr->nlink, ptr->uid, ptr->gid, ptr->size);
				convertDate(ctime(&ptr->mtime));
			}
			ft_putstr(ptr->name);
			ft_putstr("\n");
		}
		else if (flag & 4)
		{
			ft_putstr(ptr->name);
			ft_putstr("\n");
		}
		ptr = ptr->next;
	}
}
