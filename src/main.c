/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 05:31:11 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 03:49:48 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ls.h"

int	main(int ac, char **av)
{
	t_ls	*l;
	int		res;
	int		i;

	i = ac;
	if (!(l = create_struct()))
		return (0);
	if ((res = parsing_all(av, l)) == 0)
		return (ft_illegal_opt(l));
	if (!l->files && res != 1)
		res = ft_nofiles(l);
	if (l->files)
		ft_argndle(&l->files, l);
	free_struct(l);
	return (0);
}
