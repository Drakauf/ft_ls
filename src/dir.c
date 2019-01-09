/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dir.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 01:47:27 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 03:39:51 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ls.h"

void	ft_dirprint(t_files **dir, t_ls *l)
{
	t_files *tmp;
	int		i;

	tmp = *dir;
	i = 0;
	while (tmp)
	{
		if (l->dir == 2)
			ft_printf("\n%s:\n", tmp->filename);
		else if (tmp->next && l->dir != 0)
			ft_printf("%s:\n", tmp->filename);
		if (!getfileinfo(l, tmp->filename))
		{
			ft_printf("%s:\n", tmp->filename);
			ft_printf("ls: %s: Permission denied\n", tmp->filename);
		}
		tmp = tmp->next;
		i++;
	}
}
