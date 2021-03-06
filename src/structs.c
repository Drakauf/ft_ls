/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   structs.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 05:36:55 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 03:58:22 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ls.h"

t_files	*duplicate_file(t_files *files)
{
	t_files *new;

	new = create_file_elem(files->filename, files->fullname);
	if (!new)
		return (NULL);
	new->filestats = files->filestats;
	new->filelstats = files->filelstats;
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

t_files	*create_file_elem(char *str, char *fname)
{
	t_files		*file;
	struct stat files;
	struct stat lfiles;

	file = malloc(sizeof(t_files));
	if (file)
	{
		stat(fname, &files);
		lstat(fname, &lfiles);
		file->filename = ft_strdup(str);
		file->fullname = ft_strdup(fname);
		file->filestats = files;
		file->filelstats = lfiles;
		file->d = 0;
		file->next = NULL;
		return (file);
	}
	return (NULL);
}

t_ls	*create_struct(void)
{
	t_ls	*l;
	int		i;

	if (!(l = malloc(sizeof(t_ls))))
		return (NULL);
	if (!(l->opts = malloc(sizeof(int) * OPT_TOT)))
		return (NULL);
	l->last_opt = 0;
	l->d_ = 1;
	l->dir = 0;
	l->files = NULL;
	l->errors = NULL;
	i = 0;
	while (i < OPT_TOT)
		l->opts[i++] = 0;
	return (l);
}

void	ft_create_lsprint(t_lsprint *f)
{
	f->name = 0;
	f->byte = 0;
	f->tbyte = 0;
	f->inode = 0;
	f->links = 0;
	f->groups = 0;
	f->size = 0;
}
