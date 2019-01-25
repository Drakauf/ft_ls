/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   t_printget.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 15:02:28 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 10:16:46 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_get_size(char *str, t_print **mystruct)
{
	int i;
	int h;
	int l;

	i = 0;
	l = 0;
	h = 0;
	while (str[i])
	{
		if (str[i] == 'h' && str[i + 1] != 'h' && str[i - 1] != 'h')
			(*mystruct)->sh++;
		if (str[i] == 'l' && str[i + 1] != 'l' && str[i - 1] != 'l')
			(*mystruct)->sl++;
		i++;
	}
	if (ft_pstrstr(str, "hh"))
		(*mystruct)->shh++;
	if (ft_pstrstr(str, "ll"))
		(*mystruct)->sll++;
	if (ft_pstrstr(str, "j"))
		(*mystruct)->sj++;
	if (ft_pstrstr(str, "z"))
		(*mystruct)->sz++;
}

void	ft_getflags(char *str, t_print **mystruct)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == '0' || str[i] == '+' ||
				str[i] == '-' || str[i] == '#' || str[i] == ' '))
	{
		if (str[i] == '0')
			(*mystruct)->fz++;
		if (str[i] == '+')
			(*mystruct)->fp++;
		if (str[i] == '-')
			(*mystruct)->fm++;
		if (str[i] == '#')
			(*mystruct)->fd++;
		if (str[i] == ' ')
			(*mystruct)->fs++;
		i++;
	}
}

void	ft_getwidth(char *str, t_print **mystruct)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == '0' || str[i] == '+' ||
				str[i] == '-' || str[i] == '#' || str[i] == ' '))
		i++;
	if (str[i] == '*')
	{
		(*mystruct)->w = -2;
		str[i] = '1';
	}
	else if (str[i] >= '0' && str[i] <= '9')
		(*mystruct)->w = ft_patoi(str + i);
}

void	ft_getpreci(char *str, t_print **mystruct)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == '0' || str[i] == '+' ||
				str[i] == '-' || str[i] == '#' || str[i] == ' '))
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '*')
		(*mystruct)->p = -2;
	else if (str[i] == '.')
	{
		i++;
		if (str[i] >= '0' && str[i] <= '9')
			(*mystruct)->p = ft_patoi(str + i);
		else if (str[i] == '*')
			(*mystruct)->p = -2;
		else
			(*mystruct)->p = 0;
	}
}

void	ft_get_type(char *str, t_print **mystruct)
{
	int i;

	if (str[0] == '\0')
		(*mystruct)->t = '\0';
	else
	{
		i = ft_pstrlen(str) - 1;
		(*mystruct)->t = str[i];
	}
}
