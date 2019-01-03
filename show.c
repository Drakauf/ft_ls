/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   show.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/02 23:32:12 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/03 05:11:38 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ls.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while ((str[i]))
	{
		write(1, &(str[i]), 1);
		i++;
	}
}

void	ft_show_l(t_ls *l, t_files **directories, char *curdirname)
{
	printf("show l");
}


void	ft_show_nl(t_ls *l, t_files **directories, char *curdirname)
{
	t_files *tmp2;

	tmp2 = *directories;
	while (tmp2)
	{
		ft_putstr(tmp2->filename);
		ft_putstr("  ");
/*

PRINTF POSE PROBLEME !!!!!

//		printf("%10s", tmp2->filename);

*/
		if (!tmp2->next)
			ft_putstr("\n");

		tmp2 = tmp2->next;
	}
	ft_putstr("\n");
}

void	getfileinfo(t_ls *l, char *curdirname)
{
	struct stat files;
	DIR *d;
	struct dirent *dir;
	t_files	*directories;

//	dprintf(1, "dir name : %s\n", curdirname);
	d = opendir(curdirname);
	if (d)
	{
		directories  = NULL;
		while ((dir = readdir(d)) != NULL) {
				stat(dir->d_name, &files);
//				dprintf(1, "file got : %s\n", dir->d_name);
				file_add(&directories, dir->d_name, files);
				}
		closedir(d);
	directories = pre_sort(&directories, l);
	ft_show(l, &directories, curdirname);
	free_files(&directories);
	}
}

void	ft_recursive(t_ls *l, t_files **directories, char *curdirname)
{
	t_files *tmp;
	char	*nextdirname;

	tmp = *directories;
	while (tmp)
	{
		if (S_ISDIR(tmp->filestats.st_mode) && ft_strcmp(".", tmp->filename) != 0 && ft_strcmp("..", tmp->filename) != 0)
		{
//			dprintf(1, "%s\n", tmp->filename);
			nextdirname = ft_strjoinfname(curdirname, tmp->filename);
//			dprintf(1, "%s\n", nextdirname);
			getfileinfo(l,nextdirname);
			ft_strdel(&nextdirname);
		}
//		else
	//		printf("file : %s\n", tmp->filename);
		tmp = tmp->next;
	}
}

void	ft_show(t_ls *l, t_files **directories, char *curdirname)
{
	t_files *test;

	test = *directories;
	if (l->opts[OPT_R] && ft_strcmp(".", curdirname) != 0)
		dprintf(1, "%s:\n", curdirname);
//	if (l->opts[OPT_l])
//		ft_show_l(l, &test, curdirname);
//	else
		ft_show_nl(l,&test, curdirname);
	if (l->opts[OPT_R])
		ft_recursive(l, directories, curdirname);
}
