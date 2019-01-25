/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_s.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 10:54:48 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 19:59:39 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_strwidth(char **new, t_print *module)
{
	char *n;

	if (module->w <= (int)ft_pstrlen(*new))
		return ;
	if (module->fz && !module->fm)
		n = ft_creafill('0', module->w);
	else
		n = ft_creafill(' ', module->w);
	if (!n)
		return ;
	ft_fillwid(new, &n, module);
	free(*new);
	*new = ft_pstrdup(n);
	free(n);
}

void	ft_strpreci(char **new, char *str, t_print *module)
{
	int i;

	if (module->p == -1 || module->p >= (int)ft_pstrlen(str))
	{
		*new = ft_pstrdup(str);
		return ;
	}
	*new = ft_creafill(' ', module->p);
	if (!new)
		return ;
	i = 0;
	while ((*new)[i])
	{
		(*new)[i] = str[i];
		i++;
	}
}

void	ft_types(va_list ap, t_print *module, char **ret)
{
	char	*str;
	char	*new;
	char	*tmp;

	ft_star(&module, ap);
	str = va_arg(ap, char *);
	if (!str)
		tmp = ft_pstrdup("(null)");
	else
		tmp = ft_pstrdup(str);
	ft_strpreci(&new, tmp, module);
	ft_strwidth(&new, module);
	*ret = ft_pstrcat(*ret, new);
	free(new);
	free(tmp);
}
