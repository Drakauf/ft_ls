/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 09:16:11 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 04:00:24 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ls.h"

int		ft_aopt(t_ls *l, char *files)
{
	if (l->opts[OPT_100] && l->files == NULL)
	{
		if (ft_strcmp(files, ".") == 0)
			return (1);
		return (0);
	}
	if (l->opts[OPT_102])
		return (1);
	if (files[0] == '.')
	{
		if (!l->opts[OPT_65] && !l->opts[OPT_97])
			return (0);
		if (ft_strcmp(files, ".") == 0 && !l->opts[OPT_97])
			return (0);
		if (ft_strcmp(files, "..") == 0 && !l->opts[OPT_97])
			return (0);
	}
	return (1);
}

void	sort_opt(t_ls *l, t_files **tosort, t_files **sorted)
{
	if (l->opts[OPT_83])
		sort_size(*tosort, sorted);
	else if (l->opts[OPT_99] && l->time_opt == 'c' && l->opts[OPT_116])
		sort_c(*tosort, sorted);
	else if (l->opts[OPT_117] && l->time_opt == 'u' && l->opts[OPT_116])
		sort_u(*tosort, sorted);
	else if (l->opts[OPT_116])
		sort_t(*tosort, sorted);
	else
		sort_files(*tosort, sorted);
}

t_files	*sort_r(t_files **files)
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
	return (sorted);
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
	return (sorted);
}

t_files	*to_sort(t_files **files, t_ls *l)
{
	if (!l->opts[OPT_102])
		*files = pre_sort(files, l);
	if (l->opts[OPT_114])
		*files = sort_r(files);
	return (*files);
}
