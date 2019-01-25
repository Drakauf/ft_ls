/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_k.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/17 00:59:12 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 09:49:59 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

char	**ft_monthtab(void)
{
	char **month;

	month = malloc(sizeof(char *) * 14);
	if (month)
	{
		month[0] = "mehh";
		month[1] = "Jan";
		month[2] = "Feb";
		month[3] = "Mar";
		month[4] = "Apr";
		month[5] = "May";
		month[6] = "Jun";
		month[7] = "Jul";
		month[8] = "Aug";
		month[9] = "Sep";
		month[10] = "Oct";
		month[11] = "Nov";
		month[12] = "Dec";
		month[13] = NULL;
	}
	return (month);
}

char	*ft_datise(long long int nb, int len)
{
	char *n;

	n = malloc(sizeof(char) * (len + 1));
	if (n)
	{
		if (len == 2)
		{
			n[0] = nb / 10 + 48;
			n[1] = nb % 10 + 48;
			n[2] = '\0';
		}
		else if (len == 4)
		{
			n[0] = nb / 1000 + 48;
			n[1] = ((nb / 100) % 10) + 48;
			n[2] = ((nb % 100) / 10) + 48;
			n[3] = nb % 10 + 48;
			n[4] = '\0';
		}
	}
	return (n);
}

void	ft_ksix(long long int nb, char **print, t_print *module, char **tab)
{
	if (module->fm)
	{
		if (nb / 10000 <= 12 && nb / 10000 >= 1)
			*print = ft_pstrcat(*print, tab[nb / 10000]);
		*print = ft_pstrcat(*print, " ");
		*print = ft_pstrcat(*print, ft_datise((nb / 100) % 100, 2));
		*print = ft_pstrcat(*print, " ");
		*print = ft_pstrcat(*print, ft_datise(nb % 100, 2));
		*print = ft_pstrcat(*print, "'");
	}
	else if (module->p == 0)
	{
		*print = ft_pstrcat(*print, ft_datise(nb / 10000, 2));
		*print = ft_pstrcat(*print, " ");
		*print = ft_pstrcat(*print, ft_datise((nb / 100) % 100, 2));
		*print = ft_pstrcat(*print, ":");
		*print = ft_pstrcat(*print, ft_datise(nb % 100, 2));
	}
	else
	{
		*print = ft_pstrcat(*print, ft_datise(nb / 100, 4));
		*print = ft_pstrcat(*print, " ");
		if (nb % 100 <= 12 && nb % 100 >= 1)
			*print = ft_pstrcat(*print, tab[nb % 100]);
	}
}

void	ft_keigh(long long int nb, char **print, t_print *module, char **tab)
{
	if (module->p == 0)
	{
		if (nb / 1000000 >= 1 && nb / 1000000 <= 12)
			*print = ft_pstrcat(*print, tab[nb / 1000000]);
		*print = ft_pstrcat(*print, " ");
		*print = ft_pstrcat(*print, ft_datise((nb / 10000) % 100, 2));
		*print = ft_pstrcat(*print, " ");
		*print = ft_pstrcat(*print, ft_datise((nb / 100) % 100, 2));
		*print = ft_pstrcat(*print, ":");
		*print = ft_pstrcat(*print, ft_datise(nb % 100, 2));
	}
	else
	{
		*print = ft_pstrcat(*print, ft_datise((nb / 10000), 4));
		*print = ft_pstrcat(*print, " ");
		if ((nb / 100) % 100 <= 12 && (nb / 100) % 100 >= 1)
			*print = ft_pstrcat(*print, tab[(nb / 100) % 100]);
		*print = ft_pstrcat(*print, " ");
		*print = ft_pstrcat(*print, ft_datise((nb % 100), 2));
	}
}

void	ft_typek(va_list ap, t_print *module, char **print)
{
	long long int	nb;
	char			**monthtab;

	ft_star(&module, ap);
	nb = va_to_u(module, ap);
	monthtab = ft_monthtab();
	if (!monthtab || !nb)
		return ;
	if (nb <= 9999)
		ft_kfour(nb, print, module, monthtab);
	else if (nb <= 999999)
		ft_ksix(nb, print, module, monthtab);
	else if (nb <= 99999999)
		ft_keigh(nb, print, module, monthtab);
	else if (nb <= 999999999999)
		ft_ktwel(nb, print, monthtab);
}
