/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_opt.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 02:18:30 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 03:51:48 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ls.h"

void	print_s(t_ls *l, t_lsprint *f, t_files *directories)
{
	if (f->tbyte != -1 && (l->opts[OPT_115] || l->opts[OPT_108]
				|| l->opts[OPT_103] || l->opts[OPT_110]))
	{
		if (l->opts[OPT_107])
			ft_printf("total %d\n", f->tbyte / 2);
		else
			(f->tbyte != -1) ? ft_printf("total %d\n", f->tbyte) : 0;
		f->tbyte = -1;
	}
	if (l->opts[OPT_105])
		ft_printf("%*d ", f->inode, directories->filelstats.st_ino);
	if (l->opts[OPT_115])
	{
		if (l->opts[OPT_107])
			ft_printf("%*d ", f->byte, directories->filelstats.st_blocks / 2);
		else
			ft_printf("%*d ", f->byte, directories->filelstats.st_blocks);
	}
}

void	printf_p(t_files *directories, t_ls *l)
{
	if (l->opts[OPT_112])
		ft_printf("[cyan]{b}%s{/0}/", directories->filename);
	else
		ft_printf("[cyan]{b}%s{/0}", directories->filename);
}
