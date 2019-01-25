/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   o_add.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 13:51:49 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 12:45:41 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_oaddflagg(char **new, t_print *module, int i)
{
	int j;

	j = ft_pstrlen(*new) - 1;
	if (i > j && !module->fm)
		(*new)[j] = '0';
	else if (i < 0 || (i > j && module->fm))
		(*new)[0] = '0';
	else
		(*new)[i - 1] = '0';
}

void	ft_oaddfla(char **str, t_print *module)
{
	int		i;
	int		k;
	char	*new;

	k = ft_pstrlen(*str) - 1;
	i = 0;
	if ((!module->fm && (*str)[0] != ' ' && (*str)[0] != '0')
			|| (module->fm && (*str)[k] != ' '))
	{
		k++;
		i++;
	}
	new = ft_creafill(' ', k + 1);
	k = ft_pstrlen(*str) - 1;
	((*str)[k] == ' ') ? k-- : 0;
	i = ft_pstrlen(new) - 1;
	while (k >= 0)
		new[i--] = (*str)[k--];
	i = 0;
	while (i >= 0 && new[i] == ' ')
		i++;
	ft_oaddflagg(&new, module, i);
	free(*str);
	*str = ft_pstrdup(new);
	free(new);
}

void	ft_oaddpre(char **str, t_print *module, unsigned long long int nb)
{
	char	*n;
	int		i;

	n = ft_utoa_base(nb, 8);
	i = ft_pstrlen(n);
	if (nb == 0 && module->p == 0 && !module->fd)
		*str = ft_pstrdup("");
	else if (i > module->p)
		*str = ft_pstrdup(n);
	else
		ft_uprecisize(str, module, n);
	free(n);
}
