/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_details.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 02:06:06 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 03:49:27 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ls.h"

void		get_blocks(t_lsprint *f, t_files *d)
{
	int j;

	j = ft_intlen(d->filelstats.st_blocks);
	if (f->byte < j)
		f->byte = j;
	f->tbyte += d->filelstats.st_blocks;
	j = ft_intlen(d->filelstats.st_size);
	if (f->size < j)
		f->size = j;
}

void		get_user(t_lsprint *f, t_files *directories, t_ls *l)
{
	struct passwd	*usr;
	struct group	*grp;
	int				j;
	int				i;

	usr = getpwuid(directories->filelstats.st_uid);
	grp = getgrgid(directories->filelstats.st_gid);
	if (l->opts[OPT_110])
	{
		j = ft_intlen(directories->filelstats.st_uid);
		i = ft_intlen(directories->filelstats.st_gid);
	}
	else
	{
		j = ft_strlen(usr->pw_name);
		i = ft_strlen(grp->gr_name);
	}
	if (j > f->name)
		f->name = j;
	if (i > f->groups)
		f->groups = i;
}

void		ft_user_details(t_lsprint *f, t_files *directories, t_ls *l)
{
	struct passwd	*usr;
	struct group	*grp;

	usr = getpwuid(directories->filelstats.st_uid);
	grp = getgrgid(directories->filelstats.st_gid);
	if (!l->opts[OPT_103])
	{
		if (l->opts[OPT_110])
			ft_printf("%*d  ", f->name, directories->filelstats.st_uid);
		else
			ft_printf("%*s  ", f->name, usr->pw_name);
	}
	if (l->opts[OPT_110])
		ft_printf("%*d  ", f->groups, directories->filelstats.st_gid);
	else
		ft_printf("%*s  ", f->groups, grp->gr_name);
}

t_lsprint	get_len_line(t_files **directories, t_ls *l)
{
	int			j;
	t_files		*tmp;
	t_lsprint	f;

	ft_create_lsprint(&f);
	tmp = *directories;
	while (tmp)
	{
		j = ft_intlen(tmp->filelstats.st_ino);
		(f.inode < j) ? f.inode = j : 0;
		get_blocks(&f, tmp);
		j = ft_intlen(tmp->filelstats.st_nlink);
		(f.links < j) ? f.links = j : 0;
		get_user(&f, tmp, l);
		tmp = tmp->next;
	}
	return (f);
}
