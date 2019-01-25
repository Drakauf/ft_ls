/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_nullpoint.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/25 13:01:35 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 20:50:19 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_npadd(char **str)
{
	char *s;

	s = ft_pstrmalloc(ft_pstrlen(*str) + 3);
	s[0] = '0';
	s[1] = 'x';
	s = ft_pstrcat(s, *str);
	free(*str);
	*str = ft_pstrdup(s);
	free(s);
}

void	ft_nullpoint(char **new, t_print *module)
{
	char	*str;

	ft_uaddpre(&str, module, 0);
	ft_npadd(&str);
	free(*new);
	*new = ft_pstrdup(str);
	free(str);
}
