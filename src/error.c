/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 05:47:47 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 03:40:38 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ls.h"

int		ft_illegal_opt(t_ls *l)
{
	ft_printf("ls: illegal option -- %c\n", l->c_error);
	ft_printf("usage: ls [-...] [file ...]\n");
	free_struct(l);
	return (0);
}

int		ft_error_occured(t_ls *l)
{
	ft_printf("an error occured");
	free_struct(l);
	return (0);
}

void	print_files(t_ls *l)
{
	ft_printf("printind l->files : \n");
	while (l->files)
	{
		ft_printf("       %s\n", l->files->filename);
		l->files = (l->files)->next;
	}
}

void	ft_error_show(t_ls *l)
{
	t_list	*tmp;
	t_list	*sorted;
	t_list	*tosort;
	t_list	*list;

	list = l->errors;
	if (!l->opts[OPT_102])
	{
		sorted = NULL;
		while (list)
		{
			tmp = list->next;
			tosort = list;
			tosort->next = NULL;
			sort_err(tosort, &sorted);
			list = tmp;
		}
		l->errors = sorted;
	}
}
