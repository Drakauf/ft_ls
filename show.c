/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   show.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/02 23:32:12 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/05 04:24:20 by shthevak    ###    #+. /#+    ###.fr     */
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

int maxfilename(t_lsprint i, t_ls *l)
{
	int k;
	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);

	k = i.name;
	if (l->opts[OPT_s])
		k += i.byte + 1;
	if (w.ws_col < k)
		return (1);
	return ( w.ws_col / (k + 1));
}

int		ft_intlen(int n)
{
	if (n == 0)
			return (1);
	return (1 + ft_intlen(n / 10));
}

t_lsprint		get_len(t_files **directories, t_ls *l)
{
	int			i;
	int			j;
	t_files		*tmp;
	t_lsprint	f;


	f.name = 0;
	f.byte = 0;
	f.tbyte = 0;
	tmp = *directories;
	while (tmp)
	{
		(f.name < (j = ft_strlen(tmp->filename) + 1)) ? f.name = j : 0;
		if (l->opts[OPT_k])
		(f.byte < (j = ft_intlen(tmp->filelstats.st_blocks/2))) ? f.byte = j: 0;
		else
		(f.byte < (j = ft_intlen(tmp->filelstats.st_blocks))) ? f.byte = j: 0;
		f.tbyte += tmp->filelstats.st_blocks;
		tmp = tmp->next;
	}
	return (f);
}

void	print_s(t_ls *l, t_lsprint *f, t_files *directories)
{
	if (l->opts[OPT_s])
	{
		if (l->opts[OPT_k])
		{
			(f->tbyte != -1) ? ft_printf("total %d\n", f->tbyte/2): 0;
			ft_printf("%*d ", f->byte, directories->filelstats.st_blocks/2);
		}
		else
		{
			(f->tbyte != -1) ? ft_printf("total %d\n", f->tbyte): 0;
			ft_printf("%*d ", f->byte, directories->filelstats.st_blocks);
		}
		f->tbyte = -1;
	}
}

int	ft_getcolor(t_files *directories, t_lsprint *f, t_ls *l)
{
	print_s(l, f, directories);
	if (S_ISLNK(directories->filelstats.st_mode))
	{
	ft_printf("[magenta]%-*s[white]", f->name, directories->filename);
	return (1);
	}
	if (S_ISDIR(directories->filestats.st_mode))
	{
		ft_printf("[cyan]{b}%-*s[white]{/0}", f->name, directories->filename);
		return (1);
	}
	if (S_IXUSR & directories->filelstats.st_mode)
	{
		ft_printf("[red]%-*s[white]", f->name, directories->filename);
		return (1);
	}
	return (0);
}

void	ft_show_nl(t_ls *l, t_files **directories, char *curdirname)
{
	t_files 	*tmp2;
	t_lsprint	f;
	int p;
	int k;
	char *c;

	f = get_len(directories, l);
	tmp2 = *directories;
	p = maxfilename(f, l);
	k = 0;
	while (tmp2)
	{
		if (!ft_getcolor(tmp2, &f, l))
			ft_printf("%-*s", (f.name),tmp2->filename);
		k++;
		if ((!tmp2->next && k != 0) || k % p == 0)
		{
			k = 0;
			ft_printf("\n");
		}
		tmp2 = tmp2->next;
	}
}


void	addfile(t_ls *l, t_files **directories, char *dirname, char *fullname)
{
	if (ft_aopt(l, dirname))
		file_add(directories, dirname, fullname);
}

int	getfileinfo(t_ls *l, char *curdirname)
{
	DIR *d;
	struct dirent *dir;
	t_files	*directories;
	char	*fullname;

	d = opendir(curdirname);
	if (d)
	{
		ft_printf("\n%s:\n", curdirname);
		directories  = NULL;
		while ((dir = readdir(d)) != NULL)
		{
			fullname = ft_strjoinfname(curdirname, dir->d_name);
			addfile(l, &directories, dir->d_name, fullname);
			free(fullname);
		}
		closedir(d);
		directories = to_sort(&directories, l);
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
