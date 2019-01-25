/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_d.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 12:01:28 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 14:05:02 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

void			ft_putflagt(char **new, t_print *module, long long int nb)
{
	if (nb == 0 && module->p == 0 && module->fp && module->fm)
	{
		if (!ft_pstrlen(*new))
		{
			free(*new);
			*new = ft_pstrdup("+");
		}
		else
			(*new)[0] = '+';
	}
	else if (module->fz)
	{
		if (nb < 0)
			(*new)[0] = '-';
		else if (module->fp)
			(*new)[0] = '+';
		else if (module->fs && !module->fp)
			(*new)[0] = ' ';
	}
}

void			ft_putflag(char **new, t_print *module, long long int nb)
{
	int i;

	i = ft_pstrlen(*new) - 1;
	while (i >= 0 && (*new)[i] == ' ')
		i--;
	while (i >= 0 && (*new)[i] != ' ')
		i--;
	if (i >= 0 && nb < 0)
		(*new)[i--] = '-';
	else if (i >= 0 && nb >= 0 && module->fp)
		(*new)[i--] = '+';
	else if (nb == 0 && module->p == 0 && module->fp && !module->fm)
	{
		if (!ft_pstrlen(*new))
		{
			free(*new);
			*new = ft_pstrdup("+");
		}
		else
			(*new)[ft_pstrlen(*new) - 1] = '+';
	}
	else
		ft_putflagt(new, module, nb);
}

void			ft_addflag(char **str, t_print *module, long long int nb)
{
	char	*new;
	int		k;
	int		i;
	int		c;

	k = ft_pstrlen(*str);
	c = 0;
	if (module->fp || module->fs || nb < 0 || module->fz)
	{
		if (ft_addspace(k, str, module, nb))
		{
			k++;
			c++;
		}
		new = ft_creafill(' ', k--);
		i = ft_pstrlen(new) - 1;
		(c || ((*str)[k] == ' ' && (module->fm && nb < 0))
		|| (nb > 0 && module->fp && module->fm && (*str)[0] != ' ')) ? k-- : 0;
		while (i >= 0 && k >= 0)
			new[i--] = (*str)[k--];
		ft_putflag(&new, module, nb);
		ft_replace(str, new);
	}
}

long long int	va_to_n(t_print *module, va_list ap)
{
	if (module->sj)
		return (va_arg(ap, intmax_t));
	if (module->sz)
		return (va_arg(ap, size_t));
	if (module->shh)
		return ((signed char)va_arg(ap, int));
	if (module->sh)
		return ((short int)va_arg(ap, int));
	if (module->sll)
		return (va_arg(ap, long long int));
	if (module->sl)
		return (va_arg(ap, long));
	return (va_arg(ap, int));
}

void			ft_typed(va_list ap, t_print *module, char **print)
{
	long long int	nb;
	char			*new;

	ft_star(&module, ap);
	nb = va_to_n(module, ap);
	ft_addpre(&new, module, nb);
	if (new == NULL)
		return ;
	ft_addwid(&new, module);
	if (new == NULL)
		return ;
	ft_addflag(&new, module, nb);
	if (new == NULL)
		return ;
	*print = ft_pstrcat(*print, new);
	free(new);
}
