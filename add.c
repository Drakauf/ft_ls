/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   add.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 05:57:35 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/03 05:05:12 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ls.h"

void	list_add(t_ls *l, t_list *list)
{
	t_list	*tmp;

	if (l->files == NULL)
		l->files = list;
	else
	{
		tmp = l->files;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = list;
	}
}

void	file_add(t_files **allfiles, char *str, struct stat files)
{
	t_files	*tmp;

	if (*allfiles == NULL)
	{
		*allfiles = create_file_elem(str);
		(*allfiles)->filestats = files;
		(*allfiles)->next = NULL;
	}
	else
	{
		tmp = *allfiles;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = create_file_elem(str);
		(tmp->next)->filestats = files;
		(tmp->next)->next = NULL;
	}
}
