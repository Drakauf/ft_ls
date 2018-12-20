/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   curdir.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 07:21:00 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 12:49:23 by shthevak    ###    #+. /#+    ###.fr     */
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
void	free_files(t_files **directories)
{
	t_files *tmp;
	t_files *tmp2;
		
	printf("\n\nGoing to Free : \n\n");
	tmp = *directories;
	while (tmp)
	{
		printf("%s\n", tmp->filename);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	*directories = NULL;
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
							file_add(&directories, dir->d_name, &files);
						if (S_ISREG(files.st_mode))
							file_add(&directories, dir->d_name, &files);
		}
		closedir(d);
	}
	directories = pre_sort(&directories, l);
	t_files	*tmp;
	tmp = directories;
	while (tmp)
		{
			printf("%s\n", tmp->filename);
			tmp = tmp->next;
		}
//if (directories)
		free_files(&directories);
//free(directories);
	return(0);
}