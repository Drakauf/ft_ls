/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 09:16:11 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 12:49:21 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ls.h"

void	sort_files(t_files	*files, t_files **sorted)
{
	t_files *tmp;

	if (*sorted == NULL)
	{
		*sorted = files;
		return ;
	}
	tmp = *sorted;
	if (!tmp->next && strcmp(tmp->filename, files->filename) <= 0)
		tmp->next = files;
	else if (!tmp->next && strcmp(tmp->filename, files->filename) >= 0)
	{
		files->next = tmp;
		*sorted = files;
	}
	else
	{
		while (tmp->next)
		{
			if (strcmp(tmp->next->filename, files->filename) >= 0)
			{
				files->next = tmp->next;
				tmp->next = files;
				return;
			}
			tmp = tmp->next;
		}
		tmp->next = files;
	}
}


void	rsort_files(t_files	*files, t_files **sorted)
{
	t_files *tmp;

	if (*sorted == NULL)
	{
		*sorted = files;
		return ;
	}
	tmp = *sorted;
	if (ft_strcmp(tmp->filename, files->filename) <= 0)
	{
		files->next = tmp;
		*sorted = files;
	}
	else if (!tmp->next && ft_strcmp(tmp->filename, files->filename) <= 0)
		tmp->next = files;
	else
	{
		while (tmp->next)
		{
			if (ft_strcmp(tmp->next->filename, files->filename) <= 0)
			{
				files->next = tmp->next;
				tmp->next = files;
				return;
			}
			tmp = tmp->next;
		}
		tmp->next = files;
	}
}


t_files	*pre_sort(t_files **files, t_ls *l)
{
	t_files	*sorted;
	t_files *tmp;
	t_files	*tosort;

	sorted = NULL;
	while (*files)
	{
		tmp = (*files)->next;
		if (!(tosort = duplicate_file(*files)))
			return (0);
		if (l->opts[OPT_r])
		rsort_files(tosort, &sorted);
		else
		sort_files(tosort, &sorted);
		free(*files);
		*files = tmp;
	}
	if (*files)
		free(*files);
	*files = NULL;
	return(sorted);
}

