/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 09:16:11 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/05 01:36:47 by shthevak    ###    #+. /#+    ###.fr     */
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
if (strcmp(tmp->filename, files->filename) >= 0)
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

int		ft_aopt(t_ls *l, char *files)
{
	if (files[0] == '.')
	{
		if (!l->opts[OPT_A] && !l->opts[OPT_a])
			return (0);
		if (ft_strcmp(files, ".") == 0 && !l->opts[OPT_a])
			return(0);
		if (ft_strcmp(files, "..") == 0 && !l->opts[OPT_a])
			return(0);
	}
	return (1);
}

void	sort_opt(t_ls *l, t_files **tosort, t_files **sorted)
{
}

t_files	*sort_r(t_files **files, t_ls *l)
{
	t_files	*sorted;
	t_files *tmp;

	sorted = NULL;
	while (*files)
	{
		tmp = (*files)->next;
		(*files)->next = sorted;
		sorted = *files;
		*files = tmp;
	}
	return(sorted);
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
		tosort = *files;
		tosort->next = NULL;
		sort_opt(l, &tosort, &sorted);
		*files = tmp;
	}
	return(sorted);
}

t_files *to_sort(t_files **files, t_ls *l)
{
//	if (l->opts[OPT_r])
//		*files = pre_sort(files, l);
	if (l->opts[OPT_r])
		*files = sort_r(files, l);
	return (*files);
}
