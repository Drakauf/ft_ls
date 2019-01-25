/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   typeint.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 11:13:06 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 09:49:06 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_typeint(va_list ap, t_print *module, char **print)
{
	if (module->t == 'd' || module->t == 'i')
		ft_typed(ap, module, print);
	if (module->t == 'u')
		ft_typeu(ap, module, print);
	else if (module->t == 'o')
		ft_typeo(ap, module, print);
	else if (module->t == 'x' || module->t == 'X' || module->t == 'p')
		ft_typex(ap, module, print);
	if (module->t == 'b')
		ft_typeb(ap, module, print);
}
