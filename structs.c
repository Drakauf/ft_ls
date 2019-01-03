/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   structs.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 05:36:55 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/03 05:11:41 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ls.h"

t_files *duplicate_file(t_files *files)
{
	t_files *new;

	new = create_file_elem(files->filename);
	if (!new)
		return (NULL);
	new->filestats = files->filestats;
	new->next = NULL;
	return (new);
}

t_list	*create_list_elem(char *str)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list)
	{
		list->filename = ft_strdup(str);
		list->next = NULL;
	}
	else
		return (NULL);
	return (list);
}

t_files	*create_file_elem(char *str)
{
	t_files	*file;

	file = malloc(sizeof(t_files));
	if (file)
	{
		file->filename = ft_strdup(str);
		file->next = NULL;
	return (file);
	}
		return (NULL);
}

t_ls	*create_struct()
{
	t_ls *l;

	if (!(l = malloc(sizeof(t_ls))))
		return (NULL);
	if (!(l->opts = malloc(sizeof(int) * OPT_TOT)))
		return (NULL);
	l->last_opt = 0;
	l->d_ = 1;
	l->files = NULL;
	l->dirnofil = NULL;
	l->filnofil = NULL;
	int i;

	i = 0;
	while (i < OPT_TOT)
		l->opts[i++] = 0;
	return (l);
}
