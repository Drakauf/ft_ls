/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 01:38:01 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 03:50:54 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ls.h"

int		parsing_fil(char **ac, t_ls *l)
{
	int		i;
	t_list	*list;

	i = l->last_opt + 1;
	list = NULL;
	while (ac[i])
	{
		list = create_list_elem(ac[i]);
		if (!list)
			return (0);
		list_add(&l->files, list);
		i++;
	}
	return (1);
}

int		parsing_opt(char **av, t_ls *l)
{
	int i;
	int j;

	i = 0;
	while (av[++i])
	{
		j = 0;
		if (av[i][j] != '-')
			break ;
		if (j == 0 && av[i][j] == '-' && !av[i][j + 1])
			break ;
		if ((j == 0 && av[i][j + 1] == '-' && !av[i][j + 2]))
		{
			l->last_opt++;
			break ;
		}
		while (av[i][++j])
		{
			if (!put_in_table(av[i][j], l))
				return (0);
		}
		l->last_opt++;
	}
	return (1);
}

int		parsing_all(char **ac, t_ls *l)
{
	if (!parsing_opt(ac, l))
		return (0);
	if (!parsing_fil(ac, l))
		return (1);
	return (2);
}
