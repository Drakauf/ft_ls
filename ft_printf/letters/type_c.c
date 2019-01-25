/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_c.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 16:22:01 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 11:45:54 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_typec(va_list ap, t_print *module, char **print, t_len **t)
{
	char	*new;
	char	c;

	ft_star(&module, ap);
	if (module->t == '%')
		c = '%';
	else
		c = va_arg(ap, int);
	if (module->w <= 1)
		new = ft_creafill(c, 1);
	else
	{
		if (module->fz && !module->fm)
			new = ft_creafill('0', module->w);
		else
			new = ft_creafill(' ', module->w);
		if (module->fm)
			new[0] = c;
		else
			new[ft_pstrlen(new) - 1] = c;
	}
	c == 0 ? (*t)->f++ : 0;
	*print = ft_pstrcat(*print, new);
	free(new);
}
