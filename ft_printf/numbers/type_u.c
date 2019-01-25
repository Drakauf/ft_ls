/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_u.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 13:33:53 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 20:06:11 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned long long int	va_to_u(t_print *module, va_list ap)
{
	if (module->t == 'k')
		return (va_arg(ap, long long int));
	if (module->t == 'p')
		return (unsigned long long int)(va_arg(ap, void *));
	if (module->sj != 0)
		return (va_arg(ap, uintmax_t));
	if (module->sz)
		return (va_arg(ap, size_t));
	if (module->shh)
		return ((unsigned char)va_arg(ap, unsigned int));
	if (module->sh && !module->sl)
		return ((unsigned short int)va_arg(ap, unsigned int));
	if (module->sll)
		return (va_arg(ap, unsigned long long int));
	if (module->sl)
		return (va_arg(ap, unsigned long int));
	return (va_arg(ap, unsigned int));
}

void					ft_typeu(va_list ap, t_print *module, char **ret)
{
	unsigned long long int	nb;
	char					*new;

	ft_star(&module, ap);
	nb = va_to_u(module, ap);
	ft_uaddpre(&new, module, nb);
	ft_uaddwid(&new, module);
	*ret = ft_pstrcat(*ret, new);
	free(new);
}

void					ft_strlowcase(char **new)
{
	int i;

	i = 0;
	while ((*new)[i])
	{
		if ((*new)[i] <= 'Z' && (*new)[i] >= 'A')
			(*new)[i] += 32;
		i++;
	}
}

void					ft_typex(va_list ap, t_print *module, char **ret)
{
	unsigned long long int	nb;
	char					*new;

	ft_star(&module, ap);
	nb = va_to_u(module, ap);
	if (module->t == 'p')
	{
		module->mp = 1;
		module->t = 'x';
		module->fd++;
	}
	ft_xaddpre(&new, module, nb);
	ft_uaddwid(&new, module);
	if (module->fd > 0 && nb != 0)
		ft_xaddfla(&new, module);
	if (module->mp && nb == 0)
		ft_nullpoint(&new, module);
	if (module->t == 'x')
		ft_strlowcase(&new);
	*ret = ft_pstrcat(*ret, new);
	free(new);
}

void					ft_typeo(va_list ap, t_print *module, char **ret)
{
	unsigned long long int	nb;
	char					*new;

	ft_star(&module, ap);
	nb = va_to_u(module, ap);
	ft_oaddpre(&new, module, nb);
	ft_uaddwid(&new, module);
	if (module->fd > 0)
		ft_oaddfla(&new, module);
	*ret = ft_pstrcat(*ret, new);
	free(new);
}
