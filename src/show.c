/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   show.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/02 23:32:12 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 03:54:14 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ls.h"

void	ft_printname(t_files *d, t_lsprint *f, t_ls *l)
{
	if (l->out_opt != 'l' && l->out_opt != 'g' && l->out_opt != 'n')
		print_s(l, f, d);
	if (S_ISLNK(d->filelstats.st_mode))
		ft_printf("[magenta]%s{/0}", d->filename);
	else if (S_ISDIR(d->filestats.st_mode))
		printf_p(d, l);
	else if (S_IXUSR & d->filelstats.st_mode)
		ft_printf("[red]%s{/0}", d->filename);
	else
		ft_printf("%s", d->filename);
	if (l->opts[OPT_109])
		ft_printf(", ");
	else if (l->opts[OPT_112] && S_ISDIR(d->filestats.st_mode))
		ft_printf("%*c", (f->name - ft_strlen(d->filename) + 1), '\0');
	else
		ft_printf("%*c", (f->name - ft_strlen(d->filename) + 1), '\0');
}

int		getfileinfo(t_ls *l, char *curdirname)
{
	DIR				*d;
	struct dirent	*dir;
	t_files			*directories;
	char			*fullname;

	d = opendir(curdirname);
	if (d)
	{
		l->dir == 0 ? ft_printf("\n%s:\n", curdirname) : 0;
		l->dir != 0 ? l->dir = 0 : 0;
		directories = NULL;
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
	t_files		*tmp;
	char		*n;
	struct stat	files;

	tmp = *directories;
	while (tmp)
	{
		if (S_ISDIR(tmp->filestats.st_mode)
				&& ft_strcmp(".", tmp->filename) != 0
				&& ft_strcmp("..", tmp->filename) != 0)
		{
			n = ft_strjoinfname(curdirname, tmp->filename);
			lstat(n, &files);
			if (!S_ISLNK(files.st_mode))
				if (!getfileinfo(l, n))
				{
					ft_printf("\n%s:\n", n);
					ft_printf("ls: %s: Permission denied\n", tmp->filename);
				}
			ft_strdel(&n);
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
		ft_show_column(l, &test);
	if (l->opts[OPT_82] && !l->opts[OPT_100])
		ft_recursive(l, directories, curdirname);
}
