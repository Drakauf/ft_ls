/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_ws.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/25 12:39:24 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 12:43:05 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_validuni(wchar_t *str)
{
	int i;

	i = 0;
	if (MB_CUR_MAX == 1)
	{
		while (str[i])
		{
			if ((int)str[i] > 127)
				return (0);
			i++;
		}
	}
	return (1);
}

void	ft_unipwidth(char **new, t_len **t, t_print *module)
{
	char	*n;

	n = ft_creafill(' ', module->w);
	if (!n)
	{
		(*t)->k = -1;
		return ;
	}
	ft_fillwid(new, &n, module);
	free(*new);
	*new = ft_pstrdup(n);
	free(n);
}

void	ft_unipreci(char **new, wchar_t *str, t_len **t, t_print *module)
{
	int		i;
	char	*c;
	char	*ret;

	c = ft_pstrmalloc(PRINT_BUFF_SIZE);
	if (!c)
	{
		(*t)->k = -1;
		return ;
	}
	i = 0;
	while (str[i])
	{
		ret = ft_wputchar(str[i]);
		if ((int)ft_pstrlen(c) + (int)ft_pstrlen(ret) <= module->p)
			c = ft_pstrcat(c, ret);
		else
			break ;
		free(ret);
	}
	*new = ft_pstrdup(c);
	free(c);
	if (module->w > (int)ft_pstrlen(*new))
		ft_unipwidth(new, t, module);
}

void	ft_uniwidth(char **new, char *str, t_print *module, t_len **t)
{
	char	*n;

	n = ft_creafill(' ', module->w);
	if (!n)
	{
		(*t)->k = -1;
		return ;
	}
	ft_fillwid(&str, &n, module);
	*new = ft_pstrdup(n);
	free(n);
}

void	ft_wtoc(wchar_t **str, char **c, t_len **t, t_print *module)
{
	int i;

	if (*str)
	{
		*c = ft_pstrmalloc(PRINT_BUFF_SIZE);
		if (!ft_validuni(*str) && module->p != 0)
		{
			free(*c);
			(*t)->k = -1;
			*c = NULL;
			return ;
		}
	}
	i = 0;
	while ((*str)[i])
		*c = ft_pstrcat(*c, ft_wputchar((*str)[i++]));
}
