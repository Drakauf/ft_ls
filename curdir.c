/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   curdir.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 07:21:00 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 07:37:36 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ls.h"


void	ft_nofiledir(t_files **directories, char *str, struct stat *files)
{

	t_files		*directory;

	directory = create_file_elem(str);
	directory->filestats = files;
	file_add(directories, directory);
}

int ft_nofiles(t_ls *l)
{
	struct stat	files;
	DIR *d;
	struct dirent *dir;
	t_files		*directories;
	t_files		*normalfiles;

	d = opendir(".");
	if (!d)
		return(1);
	directories = NULL;
	normalfiles = NULL;
	if (d) {
		while ((dir = readdir(d)) != NULL) {
			stat(dir->d_name, &files);
						if (S_ISDIR(files.st_mode))
							ft_nofiledir(&directories, dir->d_name, &files);
						if (S_ISREG(files.st_mode))
							ft_nofiledir(&directories, dir->d_name, &files);
		}
		closedir(d);
	}
	//	directories = pre_sort(directories);
	t_files	*tmp;
	tmp = directories;
	while (tmp)
		{
			printf("%s\n", tmp->filename);
			tmp = tmp->next;
		}
	tmp = directories;
	while (directories)
	{
		tmp = directories->next;
		free(directories);
		directories = tmp;
	}
	return(0);
}
