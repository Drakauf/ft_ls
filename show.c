/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   show.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/02 23:32:12 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 05:25:38 by shthevak    ###    #+. /#+    ###.fr     */
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

int maxfilename(t_lsprint *i, t_ls *l)
{
	int k;
	int	j;
	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);


	k = i->name;
	if (l->opts[OPT_s])
		k += i->byte + 1;
	if (l->opts[OPT_i])
		k += i->inode;
	if (l->opts[OPT_p])
		k += 1;
	if (w.ws_col < k)
		return (1);
	j = w.ws_col / (k + 1);
	if (j == 0)
		return (1);
	return (j);
}

int		ft_intlen(int n)
{
	if (n <= 9)
		return (1);
	return (1 + ft_intlen(n / 10));
}

t_lsprint		get_len_col(t_files **directories, t_ls *l)
{
	int			j;
	t_files		*tmp;
	t_lsprint	f;

	ft_create_lsprint(&f);
	tmp = *directories;
	while (tmp)
	{
		(f.name < (j = ft_strlen(tmp->filename) + 1)) ? f.name = j : 0;
		(f.inode < (j = ft_intlen(tmp->filelstats.st_ino))) ? f.inode = j: 0;
		get_blocks(&f, tmp);
		tmp = tmp->next;
	}
	l->opts[OPT_p] ? f.name++: 0;
	return (f);
}

void	print_s(t_ls *l, t_lsprint *f, t_files *directories)
{
	if (f->tbyte != -1 && (l->opts[OPT_s] || l->opts[OPT_l] || l->opts[OPT_g] || l->opts[OPT_n]))
	{	
		if (l->opts[OPT_k])
			ft_printf("total %d\n", f->tbyte/2);
		else
			(f->tbyte != -1) ? ft_printf("total %d\n", f->tbyte): 0;
		f->tbyte = -1;
	}	
	if (l->opts[OPT_i])
			ft_printf("%*d ", f->inode, directories->filelstats.st_ino);
	if (l->opts[OPT_s])
	{
		if (l->opts[OPT_k])
			ft_printf("%*d ", f->byte, directories->filelstats.st_blocks/2);
		else
			ft_printf("%*d ", f->byte, directories->filelstats.st_blocks);
	}
}

void	printf_p(t_files *directories, t_ls *l)
{
	if (l->opts[OPT_p])
		ft_printf("[cyan]{b}%s{/0}/", directories->filename);
	else
	ft_printf("[cyan]{b}%s{/0}",directories->filename);
}

void	ft_printname(t_files *directories, t_lsprint *f, t_ls *l)
{
	if (l->out_opt != 'l' && l->out_opt != 'g' && l->out_opt != 'n')
		print_s(l, f, directories);
	if (S_ISLNK(directories->filelstats.st_mode))
			ft_printf("[magenta]%s{/0}", directories->filename);
	else if (S_ISDIR(directories->filestats.st_mode))
	printf_p(directories, l);
	else if (S_IXUSR & directories->filelstats.st_mode)
		ft_printf("[red]%s{/0}", directories->filename);
	else
		ft_printf("%s",  directories->filename);
	if (l->opts[OPT_m])
		ft_printf(", ");
	else if (l->opts[OPT_p] && S_ISDIR(directories->filestats.st_mode))
		ft_printf("%*c", (f->name - ft_strlen(directories->filename)+1), '\0');
	else
		ft_printf("%*c", (f->name - ft_strlen(directories->filename)+1), '\0');
}

void	ft_show_column(t_ls *l, t_files **directories)
{
	t_files 	*tmp2;
	t_lsprint	f;
	int p;
	int k;

	f = get_len_col(directories, l);
	tmp2 = *directories;
	p = maxfilename(&f, l);
	k = 0;
	while (tmp2)
	{
		ft_printname(tmp2, &f, l);
			k++;
		if ((!tmp2->next && k != 0) || (k % p == 0 && !l->opts[OPT_m]) || (l->out_opt == '1'))
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
		l->dir == 0 ? ft_printf("\n%s:\n", curdirname): 0;
		l->dir != 0 ? l->dir = 0: 0;
		directories  = NULL;
		while ((dir = readdir(d)) != NULL)
		{
			fullname = ft_strjoinfname(curdirname, dir->d_name);
			dprintf(1, "%s + %s = %s\n", curdirname, dir->d_name, fullname);
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
	if (l->out_opt == 'l' || l->out_opt == 'g' || l->out_opt == 'n')
		ft_show_line(l, &test);
	else
		ft_show_column(l,&test);
	if (l->opts[OPT_R] && !l->opts[OPT_d])
		ft_recursive(l, directories, curdirname);
}
