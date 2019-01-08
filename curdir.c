/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   curdir.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 07:21:00 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 05:21:38 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ls.h"

int ft_nofiles(t_ls *l)
{
	DIR *d;
	struct dirent *dir;
	t_files		*directories;
	char		*name;

	d = opendir(".");
	if (!d)
		return(1);
	directories = NULL;
	if (d) {
		while ((dir = readdir(d)) != NULL)
		{
			name = ft_strjoinfname(".", dir->d_name);
			addfile(l, &directories, dir->d_name, name);
			free(name);
		}
		closedir(d);
	}
	directories = to_sort(&directories, l);
	ft_show(l, &directories,  ".");
	free_files(&directories);
	return(0);
}
