/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_w.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 17:00:22 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 14:18:33 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_chresize(char **str, int i)
{
	char	*new;
	int		j;

	new = malloc(sizeof(char) * (i + 1));
	new[i] = '\0';
	j = 0;
	while (i > j)
	{
		new[j] = (*str)[j];
		j++;
	}
	free(*str);
	*str = ft_pstrdup(new);
	free(new);
}

void	ft_wcharc(va_list ap, t_print *module, char **print, t_len **t)
{
	char	*n;
	char	*c;
	int		i;

	i = va_arg(ap, int);
	c = ft_wputchar(i);
	(i == 0) ? (*t)->f++ : 0;
	if (MB_CUR_MAX == 1 && ft_pstrlen(c) == 2)
		ft_chresize(&c, 1);
	if (MB_CUR_MAX == 1 && ft_pstrlen(c) > 2)
	{
		free(c);
		(*t)->k = -1;
		return ;
	}
	if (module->w > (int)ft_pstrlen(c))
	{
		n = ft_creafill(' ', module->w);
		ft_fillwid(&c, &n, module);
		free(c);
		c = ft_pstrdup(n);
		free(n);
	}
	*print = ft_pstrcat(*print, c);
	free(c);
}

void	ft_unico(char **new, char *str, t_len **t)
{
	*new = ft_pstrdup(str);
	if (!*new)
	{
		(*t)->k = -1;
		return ;
	}
}

void	ft_wchars(va_list ap, t_print *module, char **print, t_len **t)
{
	wchar_t *str;
	char	*new;
	char	*c;

	ft_star(&module, ap);
	str = va_arg(ap, wchar_t *);
	if (str)
		ft_wtoc(&str, &c, t, module);
	else
		c = ft_pstrdup("(null)");
	if (!c)
		return ;
	if (module->p >= 0 && module->p <= (int)ft_pstrlen(c))
		ft_unipreci(&new, str, t, module);
	else if (module->w > (int)ft_pstrlen(c))
		ft_uniwidth(&new, c, module, t);
	else
		ft_unico(&new, c, t);
	*print = ft_pstrcat(*print, new);
	free(new);
	free(c);
}

void	ft_typew(va_list ap, t_print *module, char **print, t_len **t)
{
	if (module->t == 'C')
		ft_wcharc(ap, module, print, t);
	if (module->t == 'S')
		ft_wchars(ap, module, print, t);
}
