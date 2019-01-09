/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   others.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 01:53:28 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 03:50:24 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ls.h"

int		put_in_table(char c, t_ls *l)
{
	int	i;

	i = 0;
	while (OPTLIST[i])
	{
		if (c == 'C' || c == '1' || c == 'l' || c == 'm'
				|| c == 'g' || c == 'n')
			l->out_opt = c;
		if (c == 'u' || c == 'c')
			l->time_opt = c;
		if (OPTLIST[i] == c)
		{
			l->opts[i] = 1;
			return (1);
		}
		i++;
	}
	l->c_error = c;
	return (0);
}

int		filetype(char *name)
{
	int			i;
	int			j;
	struct stat	files;
	struct stat	lfiles;

	i = stat(name, &files);
	j = lstat(name, &lfiles);
	if (i < 0 || j < 0)
		return (-1);
	if (S_ISDIR(files.st_mode))
		return (2);
	return (1);
}

int		ft_intlen(int n)
{
	if (n <= 9)
		return (1);
	return (1 + ft_intlen(n / 10));
}
