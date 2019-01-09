/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_t.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 02:35:00 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 03:57:41 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ls.h"

void	sort_c(t_files *files, t_files **sorted)
{
	t_files *tmp;

	if (*sorted == NULL)
	{
		*sorted = files;
		return ;
	}
	tmp = *sorted;
	if (tmp->filelstats.st_ctime < files->filelstats.st_ctime)
	{
		files->next = tmp;
		*sorted = files;
		return ;
	}
	while (tmp->next)
	{
		if ((tmp->next)->filelstats.st_ctime < files->filelstats.st_ctime)
		{
			files->next = tmp->next;
			tmp->next = files;
			return ;
		}
		tmp = tmp->next;
	}
	tmp->next = files;
}

void	sort_u(t_files *files, t_files **sorted)
{
	t_files *tmp;

	if (*sorted == NULL)
	{
		*sorted = files;
		return ;
	}
	tmp = *sorted;
	if (tmp->filelstats.st_atime < files->filelstats.st_atime)
	{
		files->next = tmp;
		*sorted = files;
		return ;
	}
	while (tmp->next)
	{
		if ((tmp->next)->filelstats.st_atime < files->filelstats.st_atime)
		{
			files->next = tmp->next;
			tmp->next = files;
			return ;
		}
		tmp = tmp->next;
	}
	tmp->next = files;
}

void	sort_t(t_files *files, t_files **sorted)
{
	t_files *tmp;

	if (*sorted == NULL)
	{
		*sorted = files;
		return ;
	}
	tmp = *sorted;
	if (tmp->filelstats.st_mtime < files->filelstats.st_mtime)
	{
		files->next = tmp;
		*sorted = files;
		return ;
	}
	while (tmp->next)
	{
		if ((tmp->next)->filelstats.st_mtime < files->filelstats.st_mtime)
		{
			files->next = tmp->next;
			tmp->next = files;
			return ;
		}
		tmp = tmp->next;
	}
	tmp->next = files;
}

void	sort_size(t_files *files, t_files **sorted)
{
	t_files *tmp;

	if (*sorted == NULL)
	{
		*sorted = files;
		return ;
	}
	tmp = *sorted;
	if (tmp->filelstats.st_size < files->filelstats.st_size)
	{
		files->next = tmp;
		*sorted = files;
		return ;
	}
	while (tmp->next)
	{
		if ((tmp->next)->filelstats.st_size < files->filelstats.st_size)
		{
			files->next = tmp->next;
			tmp->next = files;
			return ;
		}
		tmp = tmp->next;
	}
	tmp->next = files;
}

void	sort_files(t_files *files, t_files **sorted)
{
	t_files *tmp;

	if (*sorted == NULL)
	{
		*sorted = files;
		return ;
	}
	tmp = *sorted;
	if (ft_strcmp(tmp->filename, files->filename) >= 0)
	{
		files->next = tmp;
		*sorted = files;
		return ;
	}
	while (tmp->next)
	{
		if (ft_strcmp(tmp->next->filename, files->filename) >= 0)
		{
			files->next = tmp->next;
			tmp->next = files;
			return ;
		}
		tmp = tmp->next;
	}
	tmp->next = files;
}
