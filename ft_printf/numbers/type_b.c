/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_b.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 14:47:50 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 20:00:48 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_baddpre(char **str, t_print *module, unsigned long long int nb)
{
	char	*n;
	int		i;

	n = ft_utoa_base(nb, 2);
	if (!n)
		return ;
	i = ft_pstrlen(n);
	if (nb == 0 && module->p == 0)
		*str = ft_pstrdup("");
	else if (i > module->p)
		*str = ft_pstrdup(n);
	else
		ft_uprecisize(str, module, n);
	free(n);
}

void	ft_typeb(va_list ap, t_print *module, char **ret)
{
	unsigned long long int	nb;
	char					*new;

	ft_star(&module, ap);
	nb = va_to_u(module, ap);
	ft_baddpre(&new, module, nb);
	if (!new)
		return ;
	ft_uaddwid(&new, module);
	if (!new)
		return ;
	if (module->fd > 0)
		ft_oaddfla(&new, module);
	if (!new)
		return ;
	*ret = ft_pstrcat(*ret, new);
	free(new);
}
