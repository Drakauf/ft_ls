/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 05:31:11 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 12:42:57 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ls.h"

int	put_in_table(char c, t_ls *l)
{
	int 	i;

	i = 0;
	while (OPTLIST[i])
	{
		if (OPTLIST[i] == c)
		{
			l->opts[i] = 1;
			return (1);
		}
		i++;
	}
	l->c_error = c;
	return(0);
}

int	parsing_fil(char **ac, t_ls *l)
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
		list_add(l, list);
		i++;
	}
	return (1);
}

int	parsing_opt(char **av, t_ls *l)
{
	int i;
	int j;

	i = 0;
	while (av[++i])
	{
		j = 0;
		if (av[i][j] != '-')
			break;
		if (j == 0 && av[i][j] == '-' && !av[i][j+1])
			break;
		if ((j == 0 && av[i][j + 1] == '-' && !av[i][j+2]))
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
	if (!parsing_opt(ac,l))
		return (0);
	if (!parsing_fil(ac, l))
		return (1);
	return (2);
}

int main(int ac, char **av)
{
	t_ls	*l;
	int		res;
	//	int i;

	ac++;
	if (!(l = create_struct()))
		return (0);
	if ((res = parsing_all(av, l)) == 0)
		return(ft_illegal_opt(l));
		if (!l->files && res != 1)
			res = ft_nofiles(l);
	//	if (l->files)
	//		res = sort_argfiles(l);
	//		else if (res != 1)
	//		res = ft_files_read(l);
	//	else
	//		return(ft_error_occured(l));
	//	i = 0;
	//	while (i < OPT_TOT)
	//		printf("%d", l->opts[i++]);
	//	printf("\nlast opt : %d\n", l->last_opt);
	//			print_files(l);
	free_struct(l);
	return (0);
}
