/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 12:12:46 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 15:02:59 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *str, ...)
{
	va_list	ap;
	int		i;
	char	*chain;

	chain = ft_pstrdup(str);
	va_start(ap, str);
	i = ft_analyse(chain, ap);
	va_end(ap);
	free(chain);
	return (i);
}

int		ft_analyse(char *chain, va_list ap)
{
	char	*print;
	t_len	*t;

	if (!(t = ft_t_lencrea()))
		return (0);
	print = ft_pstrmalloc(PRINT_BUFF_SIZE);
	while (chain[t->i])
	{
		if (print == NULL)
			return (t->k + t->j);
		while (chain[t->i] && chain[t->i] != '[' && chain[t->i] != '%'
				&& chain[t->i] != '{')
			print[t->k++] = chain[t->i++];
		if (chain[t->i])
			ft_mod(chain + t->i, ap, &print, &t);
		chain[t->i] ? t->i++ : 0;
		ft_verif(chain, &t, &print);
	}
	t->k != -1 ? write(1, print, t->k) : 0;
	free(print);
	free(t);
	return (t->k + t->j + t->f);
}

void	ft_mod(char *chain, va_list ap, char **print, t_len **t)
{
	if (chain[0] == '{' || chain[0] == '[')
	{
		(*t)->c = 1;
		if (chain[0] == '{')
			ft_format(chain, t, print);
		else
			ft_color(chain, t, print);
	}
	else
	{
		(*t)->c = 0;
		ft_modulo(chain, ap, print, t);
	}
}

void	ft_verif(char *chain, t_len **t, char **print)
{
	if ((*t)->c == 2)
		return ;
	if ((*t)->c == 3)
	{
		while (chain[(*t)->i] && chain[(*t)->i] != (*t)->t)
			(*t)->i++;
	}
	if ((*t)->c == 1)
	{
		while (chain[(*t)->i] != '\0' && chain[(*t)->i] != ']'
				&& chain[(*t)->i] != '}')
			(*t)->i++;
	}
	else if ((*t)->c == 0)
	{
		while (chain[(*t)->i] != '\0' && chain[(*t)->i] != (*t)->t)
			(*t)->i++;
	}
	ft_verifbuff(print, t);
	if (chain[(*t)->i])
		(*t)->i++;
}

void	ft_verifbuff(char **str, t_len **t)
{
	unsigned int i;

	i = ft_pstrlen(*str);
	if ((*t)->k == -1)
	{
		(*t)->j = 0;
		return ;
	}
	if (i > PRINT_BUFF_SIZE)
	{
		write(1, *str, i);
		(*t)->j = (*t)->j + i;
		(*t)->k = 0;
		free(*str);
		*str = ft_pstrmalloc(PRINT_BUFF_SIZE);
	}
	else
		(*t)->k = i;
}
