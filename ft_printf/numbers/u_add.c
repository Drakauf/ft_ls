/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   u_add.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 14:36:24 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 12:46:09 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_uaddwid(char **str, t_print *module)
{
	char	*new;

	if (module->w <= (int)ft_pstrlen(*str) && !module->mp)
		return ;
	else if (module->w <= (int)ft_pstrlen(*str))
		new = ft_creafill(' ', module->w + (int)ft_pstrlen(*str));
	else if (module->fz && module->p == -1 && !module->fm)
		new = ft_creafill('0', module->w);
	else
		new = ft_creafill(' ', module->w);
	ft_fillwid(str, &new, module);
	free(*str);
	*str = ft_pstrdup(new);
	free(new);
}

void	ft_uaddpre(char **str, t_print *module, unsigned long long int nb)
{
	char	*n;
	int		i;

	n = ft_utoa(nb);
	i = ft_pstrlen(n);
	if (nb == 0 && module->p == 0)
		*str = ft_pstrdup("");
	else if (i > module->p)
		*str = ft_pstrdup(n);
	else
		ft_uprecisize(str, module, n);
	free(n);
}

void	ft_uprecisize(char **str, t_print *module, char *n)
{
	int i;
	int	j;

	*str = ft_creafill('0', module->p);
	j = ft_pstrlen(*str) - 1;
	i = ft_pstrlen(n) - 1;
	while (i > -1)
		(*str)[j--] = n[i--];
}
