/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   curdir.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 07:21:00 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/05 00:28:25 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ls.h"

/*
   void	ft_nofiledir(t_files **directories, char *str, struct stat *files)
   {
   t_files		*directory;

   directory = create_file_elem(str);
   directory->filestats = files;
   file_add(directories, &directory);
   }
   */
/*
void	free_files(t_files **directories)
{
	t_files *tmp;
	t_files *tmp2;

	tmp = *directories;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	*directories = NULL;
}
*/

int ft_nofiles(t_ls *l)
{
	struct stat	files;
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
