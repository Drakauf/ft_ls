/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bitise.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/18 16:10:59 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 18:43:55 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

char	**ft_fillbits(char **tab, char *bits)
{
	int i;
	int j;
	int k;

	i = 0;
	k = ft_pstrlen(bits) - 1;
	if (tab == NULL)
		return (NULL);
	while (tab[i])
		i++;
	i--;
	while (i >= 0)
	{
		j = ft_pstrlen(tab[i]) - 1;
		while (j >= 0)
		{
			if (k >= 0 && tab[i][j] == 'z')
				tab[i][j] = bits[k--];
			j--;
		}
		i--;
	}
	while (tab[++i])
		ft_ureplace(tab[i], 'z', '0');
	return (tab);
}

char	**ft_onebitise(char *bits)
{
	char	**tab;

	tab = malloc(sizeof(char *) * 2);
	tab[0] = ft_pstrdup("0zzzzzzz");
	tab[1] = NULL;
	tab = ft_fillbits(tab, bits);
	return (tab);
}

char	**ft_twobitise(char *bits)
{
	char	**tab;

	tab = malloc(sizeof(char *) * 3);
	tab[0] = ft_pstrdup("110zzzzz");
	tab[1] = ft_pstrdup("10zzzzzz");
	tab[2] = NULL;
	tab = ft_fillbits(tab, bits);
	return (tab);
}

char	**ft_threebitise(char *bits)
{
	char	**tab;

	tab = malloc(sizeof(char *) * 4);
	tab[0] = ft_pstrdup("1110zzzz");
	tab[1] = ft_pstrdup("10zzzzzz");
	tab[2] = ft_pstrdup("10zzzzzz");
	tab[3] = NULL;
	tab = ft_fillbits(tab, bits);
	return (tab);
}

char	**ft_fourbitise(char *bits)
{
	char	**tab;

	tab = malloc(sizeof(char *) * 5);
	tab[0] = ft_pstrdup("11110zzz");
	tab[1] = ft_pstrdup("10zzzzzz");
	tab[2] = ft_pstrdup("10zzzzzz");
	tab[3] = ft_pstrdup("10zzzzzz");
	tab[4] = NULL;
	tab = ft_fillbits(tab, bits);
	return (tab);
}
