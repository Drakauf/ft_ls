/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   frees.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 05:40:34 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 06:15:03 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ls.h"

void	free_struct(t_ls *l)
{
	if (l)
	{
		if (l->opts)
			free(l->opts);
		if (l->files)
			free_list(&l->files);
		if (l->files)
			free(l->files);
		free(l);
	}
}

void	free_list(t_list **list)
{
	t_list *tmp;
	t_list *tmp2;

	tmp = *list;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	*list = NULL;
}
