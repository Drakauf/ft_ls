/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_kk.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/17 17:46:42 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 15:43:46 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_ktwel(long long int nb, char **print, char **tab)
{
	*print = ft_pstrcat(*print, ft_datise(nb / 100000000, 4));
	*print = ft_pstrcat(*print, " ");
	if ((nb / 1000000) % 100 >= 1 && (nb / 1000000) % 100 <= 12)
		*print = ft_pstrcat(*print, tab[(nb / 1000000) % 100]);
	*print = ft_pstrcat(*print, " ");
	*print = ft_pstrcat(*print, ft_datise((nb / 10000) % 100, 2));
	*print = ft_pstrcat(*print, " ");
	*print = ft_pstrcat(*print, ft_datise((nb / 100) % 100, 2));
	*print = ft_pstrcat(*print, ":");
	*print = ft_pstrcat(*print, ft_datise(nb % 100, 2));
}

void	ft_kfour(long long int nb, char **print, t_print *module, char **tab)
{
	if (module->fp)
		*print = ft_pstrcat(*print, ft_datise(nb, 4));
	else if (module->fm)
	{
		*print = ft_pstrcat(*print, ft_datise(nb / 100, 2));
		*print = ft_pstrcat(*print, " ");
		*print = ft_pstrcat(*print, ft_datise(nb % 100, 2));
		*print = ft_pstrcat(*print, "'");
	}
	else if (module->p == 0)
	{
		*print = ft_pstrcat(*print, ft_datise(nb / 100, 2));
		*print = ft_pstrcat(*print, ":");
		*print = ft_pstrcat(*print, ft_datise(nb % 100, 2));
	}
	else
	{
		if (nb / 100 >= 1 && nb / 100 <= 12)
			*print = ft_pstrcat(*print, tab[nb / 100]);
		*print = ft_pstrcat(*print, " ");
		*print = ft_pstrcat(*print, ft_datise((nb % 100), 2));
	}
}
