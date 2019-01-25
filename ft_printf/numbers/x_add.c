/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   x_add.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 14:02:29 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 13:44:50 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_xcreafl(char **str, t_print *module, int *k, int *j)
{
	*j = 2;
	*k = ft_pstrlen(*str) - 1;
	if (module->fm)
	{
		if ((*str)[*k] == ' ')
			(*j)--;
		if ((*str)[*k - 1] == ' ')
			(*j)--;
	}
	if ((*str)[0] == ' ' || (*str)[0] == '0')
		(*j)--;
	if ((*str)[1] == ' ' || (*str)[1] == '0')
		(*j)--;
}

void	ft_xfilfla(char **new, int *j)
{
	if (*j <= 0)
	{
		(*new)[0] = '0';
		(*new)[1] = 'X';
	}
	else if (*j <= (int)ft_pstrlen(*new))
	{
		(*new)[(*j)--] = 'X';
		(*new)[(*j)--] = '0';
	}
}

void	ft_xputfla(char **new, int *k, int *j, char **str)
{
	if (*k > 2)
	{
		*j = ft_pstrlen(*new) - 1;
		while (*j >= 2)
			(*new)[(*j)--] = (*str)[(*k)--];
	}
	else
	{
		*j = 2;
		while ((*new)[(*j)])
			(*new)[(*j)++] = (*str)[(*k)++];
	}
	*j = 0;
	while ((*str)[*j])
	{
		if ((*str)[*j] && (*str)[*j] != ' ')
			break ;
		(*j)++;
	}
	(*j)--;
	ft_xfilfla(new, j);
	free(*str);
	*str = ft_pstrdup(*new);
	free(*new);
}

void	ft_xaddfla(char **str, t_print *module)
{
	char	*new;
	int		k;
	int		j;

	ft_xcreafl(str, module, &k, &j);
	new = ft_creafill(' ', (k + j + 1));
	if (module->fm)
	{
		if ((*str)[k] == ' ')
			k--;
		if ((*str)[k] == ' ')
			k--;
	}
	else
	{
		k = 0;
		if ((*str)[k] == ' ' || (*str)[k] == '0')
			k++;
		if ((*str)[k] == ' ' || (*str)[k] == '0')
			k++;
	}
	ft_xputfla(&new, &k, &j, str);
}

void	ft_xaddpre(char **str, t_print *module, unsigned long long int nb)
{
	char	*n;
	int		i;

	n = ft_utoa_base(nb, 16);
	i = ft_pstrlen(n);
	if (nb == 0 && module->p == 0)
		*str = ft_pstrdup("");
	else if (i > module->p)
		*str = ft_pstrdup(n);
	else
		ft_uprecisize(str, module, n);
	free(n);
}
