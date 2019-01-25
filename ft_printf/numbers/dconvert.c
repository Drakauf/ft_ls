/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dconvert.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 12:24:57 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 14:13:33 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_ntoa(long long int n)
{
	return (ft_ntoa_base(n, 10));
}

char	ft_inttochar(int i)
{
	if (i < 10)
		return (i + 48);
	else
		return ('A' + i - 10);
}

int		ft_nlen_base(long long int n, int base)
{
	if (n < 0)
	{
		if (n / base)
			return (2 + ft_nlen_base(-(n / base), base));
		else
			return (1 + ft_nlen_base((n / base), base));
	}
	else if (n < base)
		return (1);
	return (1 + ft_nlen_base(n / base, base));
}

char	*ft_ntoa_base(long long int nb, int base)
{
	char			*r;
	int				j;
	long long int	n;

	j = ft_nlen_base(nb, base);
	if (!(r = malloc(sizeof(*r) * (j + 1))))
		return (NULL);
	r[j--] = '\0';
	n = nb;
	if (nb < 0)
		n = n * -1;
	while (j >= 0)
	{
		r[j] = ft_inttochar(n % base);
		n = n / base;
		j--;
	}
	if (nb < 0)
		r[0] = '-';
	return (r);
}
