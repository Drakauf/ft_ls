/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_err.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 01:52:05 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 04:01:12 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ls.h"

void	sort_err(t_list *files, t_list **sorted)
{
	t_list *tmp;

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
