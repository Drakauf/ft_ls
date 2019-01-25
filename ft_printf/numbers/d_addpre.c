/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   d_addpre.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 13:06:52 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 14:12:46 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_addwid(char **str, t_print *module)
{
	char	*new;

	if (module->w <= (int)ft_pstrlen(*str))
		return ;
	if (module->fz && module->p == -1
			&& !module->fm)
		new = ft_creafill('0', module->w);
	else
		new = ft_creafill(' ', module->w);
	ft_fillwid(str, &new, module);
	free(*str);
	*str = ft_pstrdup(new);
	free(new);
}

void	ft_addpre(char **str, t_print *module, long long int nb)
{
	char	*n;
	int		i;

	if (nb >= 0)
		n = ft_ntoa(nb);
	else
		n = ft_ntoa(nb * -1);
	i = ft_pstrlen(n);
	if (nb == 0 && module->p == 0)
		*str = ft_pstrdup("");
	else if ((nb >= 0 && i > module->p) || (nb < 0 && i > module->p - 1))
		*str = ft_pstrdup(n);
	else if (module->p > 0)
		ft_precisize(str, module, n);
	free(n);
}

void	ft_precisize(char **str, t_print *module, char *n)
{
	int i;
	int	j;

	*str = ft_creafill('0', module->p);
	if (*str == NULL)
		return ;
	j = ft_pstrlen(*str) - 1;
	i = ft_pstrlen(n) - 1;
	while (i > -1)
		(*str)[j--] = n[i--];
}

int		ft_addspace(int k, char **str, t_print *module, long long int nb)
{
	if (k <= 0 || (nb < 0 && (((*str)[0] != ' ' && (*str)[k - 1] != ' '
		&& !module->fz) || (module->fz && (*str)[0] != '0'
		&& (*str)[0] != ' ' && (*str)[k - 1] != ' '))) || ((*str)[0] != ' '
		&& (*str)[k - 1] != ' ' && module->p > module->w)
		|| ((int)ft_pstrlen(*str) <= ft_nlen_base(nb, 10)
		&& (module->fs || module->fp)))
		return (1);
	return (0);
}
