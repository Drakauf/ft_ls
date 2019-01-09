/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_col.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 02:27:42 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 03:43:35 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ls.h"

int				maxfilename(t_lsprint *i, t_ls *l)
{
	int					k;
	int					j;
	struct winsize		w;

	ioctl(0, TIOCGWINSZ, &w);
	k = i->name;
	if (l->opts[OPT_115])
		k += i->byte + 1;
	if (l->opts[OPT_105])
		k += i->inode;
	if (l->opts[OPT_112])
		k += 1;
	if (w.ws_col < k)
		return (1);
	j = w.ws_col / (k + 1);
	if (j == 0)
		return (1);
	return (j);
}

void			ft_show_column(t_ls *l, t_files **directories)
{
	t_files		*tmp2;
	t_lsprint	f;
	int			p;
	int			k;

	f = get_len_col(directories, l);
	tmp2 = *directories;
	p = maxfilename(&f, l);
	k = 0;
	while (tmp2)
	{
		ft_printname(tmp2, &f, l);
		k++;
		if ((!tmp2->next && k != 0) ||
				(k % p == 0 && !l->opts[OPT_109]) || (l->out_opt == '1'))
		{
			k = 0;
			ft_printf("\n");
		}
		tmp2 = tmp2->next;
	}
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
		j = ft_strlen(tmp->filename) + 1;
		(f.name < j) ? f.name = j : 0;
		j = ft_intlen(tmp->filelstats.st_ino);
		(f.inode < j) ? f.inode = j : 0;
		get_blocks(&f, tmp);
		tmp = tmp->next;
	}
	l->opts[OPT_112] ? f.name++ : 0;
	return (f);
}
