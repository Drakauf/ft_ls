/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 05:47:47 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 07:21:15 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ls.h"

int		ft_illegal_opt(t_ls *l)
{
	printf("ls: illegal option -- %c\n", l->c_error);
	printf("usage: ls [-...] [file ...]\n");
	free_struct(l);
	return (0);
}

int		ft_error_occured(t_ls *l)
{
	printf("an error occured");
	free_struct(l);
	return (0);
}

void	print_files(t_ls *l)
{
	printf("printind l->files : \n");
	while (l->files)
	{
		printf("       %s\n", l->files->filename);
		l->files = (l->files)->next;
	}
}
