/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   creafill.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 16:30:25 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 13:58:56 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_creafill(char c, int nb)
{
	char	*str;
	int		i;

	if (!(str = malloc(sizeof(*str) * (nb + 1))))
		return (NULL);
	i = 0;
	while (i < nb)
		str[i++] = c;
	str[i] = '\0';
	return (str);
}

void	ft_fillwid(char **str, char **new, t_print *module)
{
	int i;
	int k;

	if (module->fm)
	{
		i = 0;
		k = 0;
		while ((*str)[k])
			(*new)[i++] = (*str)[k++];
	}
	else if (!module->fm)
	{
		k = ft_pstrlen(*str) - 1;
		i = ft_pstrlen(*new) - 1;
		while (k >= 0)
			(*new)[i--] = (*str)[k--];
	}
}
