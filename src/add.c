/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   add.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 05:57:35 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 03:38:00 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ls.h"

void	addfile(t_ls *l, t_files **directories, char *dirname, char *fullname)
{
	if (ft_aopt(l, dirname))
		file_add(directories, dirname, fullname);
}

void	list_add(t_list **l, t_list *list)
{
	t_list	*tmp;

	if (*l == NULL)
		*l = list;
	else
	{
		tmp = *l;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = list;
	}
}

void	file_add(t_files **allfiles, char *filename, char *fullname)
{
	t_files	*tmp;

	if (*allfiles == NULL)
	{
		*allfiles = create_file_elem(filename, fullname);
		(*allfiles)->next = NULL;
	}
	else
	{
		tmp = *allfiles;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = create_file_elem(filename, fullname);
		(tmp->next)->next = NULL;
	}
}
