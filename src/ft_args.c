/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_args.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 00:38:32 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 03:42:17 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ls.h"

void	ft_arg_print(t_files **dir, t_files **file, t_ls *l)
{
	*dir = to_sort(dir, l);
	*file = to_sort(file, l);
	ft_error_show(l);
	print_arg_err(l->errors);
	ft_show(l, file, "");
	if ((*dir && *file))
		l->dir = 2;
	else
		l->dir = 1;
	ft_dirprint(dir, l);
	free_files(dir);
	free_files(file);
}

void	arg_opt(t_list **fi, t_ls *l)
{
	t_list	*tmp;
	t_files	*dir;
	t_files *file;
	int		i;

	tmp = *fi;
	dir = NULL;
	file = NULL;
	while (tmp)
	{
		if ((i = filetype(tmp->filename)) < 0)
			list_add(&l->errors, create_list_elem(tmp->filename));
		else if (i == 2)
			file_add(&dir, tmp->filename, tmp->filename);
		else
			file_add(&file, tmp->filename, tmp->filename);
		tmp = tmp->next;
	}
	ft_arg_print(&dir, &file, l);
}

void	arg_opt_d(t_list **fi, t_ls *l)
{
	t_list	*tmp;
	t_files	*dir;

	tmp = *fi;
	dir = NULL;
	while (tmp)
	{
		if (filetype(tmp->filename) < 0)
			list_add(&l->errors, create_list_elem(tmp->filename));
		else
			addfile(l, &dir, tmp->filename, tmp->filename);
		tmp = tmp->next;
	}
	dir = to_sort(&dir, l);
	ft_error_show(l);
	print_arg_err(l->errors);
	ft_show(l, &dir, "");
	free_files(&dir);
}

void	ft_argndle(t_list **files, t_ls *l)
{
	if (l->opts[OPT_100])
		arg_opt_d(files, l);
	else
		arg_opt(files, l);
}

void	print_arg_err(t_list *files)
{
	t_list *tmp;

	tmp = files;
	while (tmp)
	{
		ft_printf("ls: %s: No such file or directory\n", tmp->filename);
		tmp = tmp->next;
	}
}
