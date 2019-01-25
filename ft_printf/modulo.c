/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   modulo.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 14:27:28 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 15:03:05 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fakemodule(t_len **t, char **print, t_print *module)
{
	char	*c;

	if (module->t == '\0')
		return ;
	if (module->w)
	{
		if (module->fz && !module->fm)
			c = ft_creafill('0', module->w);
		else
			c = ft_creafill(' ', module->w);
		(*t)->c = 3;
		if (module->fm)
			c[0] = (*t)->t;
		else
			c[ft_pstrlen(c) - 1] = (*t)->t;
	}
	else
		c = ft_creafill((*t)->t, 1);
	*print = ft_pstrcat(*print, c);
	free(c);
	(*t)->c = 3;
}

void	ft_moduloverif(t_print **module)
{
	if ((*module)->t == 'c' && (*module)->sl > 0)
		(*module)->t = 'C';
	if ((*module)->t == 's' && (*module)->sl > 0)
		(*module)->t = 'S';
	if ((*module)->t == 'D' || (*module)->t == 'O' || (*module)->t == 'U')
	{
		(*module)->t = (*module)->t + 32;
		(*module)->sl++;
	}
}

void	ft_modulen(va_list ap, t_len *t)
{
	int *n;

	n = va_arg(ap, int *);
	*n = t->k + t->j;
}

void	ft_modulo(char *chain, va_list ap, char **print, t_len **t)
{
	char	*new;
	t_print	*module;

	new = ft_pstrdup(chain + 1);
	module = ft_structcrea(new);
	(*t)->t = module->t;
	ft_moduloverif(&module);
	if (module->t == 'd' || module->t == 'i' || module->t == 'o'
			|| module->t == 'x' || module->t == 'X' || module->t == 'p'
			|| module->t == 'u' || module->t == 'b')
		ft_typeint(ap, module, print);
	else if (module->t == 's')
		ft_types(ap, module, print);
	else if (module->t == 'c' || module->t == '%')
		ft_typec(ap, module, print, t);
	else if (module->t == 'n')
		ft_modulen(ap, *t);
	else if (module->t == 'k')
		ft_typek(ap, module, print);
	else if (module->t == 'S' || module->t == 'C')
		ft_typew(ap, module, print, t);
	else
		ft_fakemodule(t, print, module);
	free(module);
	free(new);
}
