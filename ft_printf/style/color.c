/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 14:35:02 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 14:51:52 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

char	**ft_colortab(void)
{
	char	**tab;

	tab = malloc(sizeof(tab) * 19);
	if (!tab)
		return (NULL);
	tab[0] = "[black]";
	tab[1] = "[red]";
	tab[2] = "[green]";
	tab[3] = "[yellow]";
	tab[4] = "[blue]";
	tab[5] = "[magenta]";
	tab[6] = "[cyan]";
	tab[7] = "[white]";
	tab[8] = "[eoc]";
	tab[9] = "[ublack]";
	tab[10] = "[ured]";
	tab[11] = "[ugreen]";
	tab[12] = "[uyellow]";
	tab[13] = "[ublue]";
	tab[14] = "[umagenta]";
	tab[15] = "[ucyan]";
	tab[16] = "[uwhite]";
	tab[17] = "[eou]";
	tab[18] = NULL;
	return (tab);
}

char	**ft_colorcodetab(void)
{
	char	**tab;

	tab = malloc(sizeof(tab) * 19);
	if (!tab)
		return (NULL);
	tab[0] = "\033[30m";
	tab[1] = "\033[31m";
	tab[2] = "\033[32m";
	tab[3] = "\033[33m";
	tab[4] = "\033[34m";
	tab[5] = "\033[35m";
	tab[6] = "\033[36m";
	tab[7] = "\033[97m";
	tab[8] = "\033[39m";
	tab[9] = "\033[40m";
	tab[10] = "\033[41m";
	tab[11] = "\033[42m";
	tab[12] = "\033[43m";
	tab[13] = "\033[44m";
	tab[14] = "\033[45m";
	tab[15] = "\033[46m";
	tab[16] = "\033[107m";
	tab[17] = "\033[49m";
	tab[18] = NULL;
	return (tab);
}

char	*ft_colorcode(char *color)
{
	char	*code;
	char	**tabcolor;
	char	**tabcode;
	int		i;

	tabcolor = ft_colortab();
	tabcode = ft_colorcodetab();
	if (!tabcode || !tabcolor)
		return (NULL);
	i = 0;
	while (tabcolor[i] != NULL)
	{
		if (ft_pstrcmp(tabcolor[i], color) == 0)
			break ;
		i++;
	}
	if (tabcode[i] != NULL)
		code = ft_pstrdup(tabcode[i]);
	else
		code = NULL;
	free(color);
	free(tabcolor);
	free(tabcode);
	return (code);
}

char	*ft_colorget(char *chain)
{
	int		i;
	char	*str;

	i = 0;
	while (chain[i] && chain[i] != ']')
		i++;
	if (chain[i])
		i++;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (chain[i] && chain[i] != ']')
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

void	ft_color(char *chain, t_len **t, char **print)
{
	char	*color;
	char	*codec;

	color = ft_colorget(chain);
	if (!color)
		return ;
	codec = ft_colorcode(color);
	if (codec == NULL)
	{
		*print = ft_pstrcat(*print, "[");
		(*t)->c = 2;
		return ;
	}
	*print = ft_pstrcat(*print, codec);
	free(codec);
}
