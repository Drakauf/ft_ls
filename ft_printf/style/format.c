/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 16:10:29 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 15:03:25 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

char	**ft_formattab(void)
{
	char	**tab;

	tab = malloc(sizeof(tab) * 14);
	if (!tab)
		return (NULL);
	tab[0] = "{b}";
	tab[1] = "{d}";
	tab[2] = "{u}";
	tab[3] = "{bl}";
	tab[4] = "{r}";
	tab[5] = "{h}";
	tab[6] = "{/0}";
	tab[7] = "{/b}";
	tab[8] = "{/d}";
	tab[9] = "{/u}";
	tab[10] = "{/bl}";
	tab[11] = "{/r}";
	tab[12] = "{/h}";
	tab[13] = NULL;
	return (tab);
}

char	**ft_formatcodetab(void)
{
	char	**tab;

	tab = malloc(sizeof(tab) * 14);
	if (!tab)
		return (NULL);
	tab[0] = "\033[1m";
	tab[1] = "\033[2m";
	tab[2] = "\033[4m";
	tab[3] = "\033[5m";
	tab[4] = "\033[7m";
	tab[5] = "\033[8m";
	tab[6] = "\033[0m";
	tab[7] = "\033[21m";
	tab[8] = "\033[22m";
	tab[9] = "\033[24m";
	tab[10] = "\033[25m";
	tab[11] = "\033[27m";
	tab[12] = "\033[28m";
	tab[13] = NULL;
	return (tab);
}

char	*ft_formatcode(char *format)
{
	char	*code;
	char	**tabformat;
	char	**tabcode;
	int		i;

	tabformat = ft_formattab();
	tabcode = ft_formatcodetab();
	if (!tabcode || !tabformat)
		return (NULL);
	i = 0;
	while (tabformat[i] != NULL)
	{
		if (ft_pstrcmp(tabformat[i], format) == 0)
			break ;
		i++;
	}
	if (tabcode[i] != NULL)
		code = ft_pstrdup(tabcode[i]);
	else
		code = NULL;
	free(format);
	free(tabformat);
	free(tabcode);
	return (code);
}

char	*ft_formatget(char *chain)
{
	int		i;
	char	*str;

	i = 0;
	while (chain[i] && chain[i] != '}')
		i++;
	if (chain[i])
		i++;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (chain[i] && chain[i] != '}')
	{
		str[i] = chain[i];
		i++;
	}
	if (chain[i])
	{
		str[i] = chain[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_format(char *chain, t_len **t, char **print)
{
	char *format;
	char *formacode;

	format = ft_formatget(chain);
	if (!format)
		return ;
	formacode = ft_formatcode(format);
	if (formacode == NULL)
	{
		*print = ft_pstrcat(*print, "{");
		(*t)->c = 2;
		return ;
	}
	*print = ft_pstrcat(*print, formacode);
	free(formacode);
}
