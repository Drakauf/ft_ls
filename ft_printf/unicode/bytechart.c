/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bytechart.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/18 15:19:11 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 19:35:52 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_charise(char **tab)
{
	int		i;
	char	j;
	char	*uni;

	i = 0;
	while (tab[i])
		i++;
	uni = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (tab[i])
	{
		j = (char)ft_bitodec(ft_patoi(tab[i]));
		uni[i] = 0x00 + j;
		i++;
	}
	uni[i] = '\0';
	return (uni);
}

int		ft_sqchart(int nb)
{
	if (nb >= 0x00000000 && nb <= 0x0000007F)
		return (1);
	if (nb >= 0x00000080 && nb <= 0x000007FF)
		return (2);
	if (nb >= 0x00000800 && nb <= 0x0000FFFF)
		return (3);
	if (nb >= 0x00010000 && nb <= 0x001FFFFF)
		return (4);
	return (0);
}

void	ft_freetab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	*ft_bitise(char *bits, int y)
{
	char **ret;
	char *uni;

	if (y == 1)
		ret = ft_onebitise(bits);
	else if (y == 2)
		ret = ft_twobitise(bits);
	else if (y == 3)
		ret = ft_threebitise(bits);
	else if (y == 4)
		ret = ft_fourbitise(bits);
	else
		ret = NULL;
	uni = ft_charise(ret);
	ft_freetab(ret);
	return (uni);
}
