/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 09:51:47 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/05 15:32:13 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

//# include <string.h> //remove
# include <stdio.h> //remove
# include <sys/errno.h> //might need to remove
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

typedef struct node
{
    char *name;
	int type;
	mode_t mode;
	nlink_t nlink;
	int uid;
	int gid;
	off_t size;
	time_t mtime;
	int	blocks;
    struct node *next;
} snode;

void ft_ls(char *path, unsigned int flag);
void FrontBackSplit(snode* source, snode** frontRef, snode** backRef);
void deleteList(snode** head_in);
snode *insert_node_last(struct dirent *ep, char *path);
snode* create_node(struct dirent *ep, char *path);
void mergeSort(snode** head_in, unsigned int flag);
snode* SortedMerge(snode* a, snode* b, unsigned int flag);
void display(snode *first, unsigned int flag);
int error_handle(char * path, DIR *dp, int ierrno, unsigned int flag);
void illegalFlags(char flag);

#endif
