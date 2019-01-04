/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   show.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/02 23:32:12 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 06:36:22 by shthevak    ###    #+. /#+    ###.fr     */
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
	t_files *tmp2;

	tmp2 = *directories;
	while (tmp2)
	{
		tmp2 = tmp2->next;
	}
}

int maxfilename(int i)
{
	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);

	if (w.ws_col < i)
		return (1);
	return ( w.ws_col / (i + 1));
}

int		lfname(t_files **directories)
{
	int i;
	int j;
	t_files *tmp;

	i = 0;
	tmp = *directories;
	while (tmp)
	{
		j = ft_strlen(tmp->filename);
		if (i < j)
			i = j;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_getcolor(t_files *directories)
{

//	struct stat files;
	struct stat lfiles;

//	stat(directories->fullname, &files);
	lstat(directories->fullname, &lfiles);
	if (S_ISLNK(lfiles.st_mode))
	{
		ft_printf("[magenta]");
		return (1);
	}
	if (S_ISDIR(directories->filestats.st_mode))
	{
		ft_printf("{b}[cyan]");
		return (1);
	}
	if (S_IXUSR & lfiles.st_mode)
	{
		ft_printf("[red]");
		return (1);
	}
	return (0);
}

void	ft_show_nl(t_ls *l, t_files **directories, char *curdirname)
{
	t_files *tmp2;
	int		f;
	int p;
	int k;
	char *c;

	f = lfname(directories);
	tmp2 = *directories;
	p = maxfilename(f);
	k = 0;
	while (tmp2)
	{
/*/		if (S_ISDIR(tmp2->filestats.st_mode))
		{
	//		ft_printf("is dir");
//			if ((tmp2->d))
	//		{
				ft_printf("{b}[cyan]%-*s[white]{/0}", (f + 1),tmp2->filename);
	//		}
		}		
		else 
			ft_printf("%-*s", (f + 1),tmp2->filename);*/
		if (ft_getcolor(tmp2))
				ft_printf("%-*s[white]{/0}", (f + 1),tmp2->filename);
		else
				ft_printf("%-*s", (f + 1),tmp2->filename);
		k++;
		if ((!tmp2->next && k != 0) || k % p == 0)
		{
			k = 0;
			ft_printf("\n");
		}
		tmp2 = tmp2->next;
	}
}


int	getfileinfo(t_ls *l, char *curdirname)
{
	struct stat files;
	DIR *d;
	struct dirent *dir;
	t_files	*directories;
	char	*name;

	d = opendir(curdirname);
	if (d)
	{
		ft_printf("\n%s:\n", curdirname);
		directories  = NULL;
		while ((dir = readdir(d)) != NULL)
		{
			name = ft_strjoinfname(curdirname, dir->d_name);
			stat(name, &files);
			file_add(&directories, dir->d_name, files, name);
			free(name);
		}
		closedir(d);
		directories = pre_sort(&directories, l);
		ft_show(l, &directories, curdirname);
		free_files(&directories);
		return (1);
	}
	return (0);
}

void	ft_recursive(t_ls *l, t_files **directories, char *curdirname)
{
	t_files *tmp;
	char	*nextdirname;
	struct stat files;
	DIR *d;

	tmp = *directories;
	while (tmp)
	{
		if (S_ISDIR(tmp->filestats.st_mode) && ft_strcmp(".", tmp->filename) != 0 && ft_strcmp("..", tmp->filename) != 0)
		{
			nextdirname = ft_strjoinfname(curdirname, tmp->filename);
			lstat(nextdirname, &files);
		if (!S_ISLNK(files.st_mode))
			if (!getfileinfo(l,nextdirname))
					ft_printf("\n%s:\nls: %s: Permission denied\n", nextdirname, tmp->filename);
			ft_strdel(&nextdirname);
		}
		tmp = tmp->next;
	}
}

void	ft_show(t_ls *l, t_files **directories, char *curdirname)
{
	t_files *test;

	test = *directories;
	if (l->opts[OPT_l])
		ft_show_l(l, &test, curdirname);
	else
		ft_show_nl(l,&test, curdirname);
	if (l->opts[OPT_R])
		ft_recursive(l, directories, curdirname);
}
