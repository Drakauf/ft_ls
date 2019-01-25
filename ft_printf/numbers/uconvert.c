/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   uconvert.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 12:34:36 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 20:57:52 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_utoa(unsigned long long int n)
{
	return (ft_utoa_base(n, 10));
}

int		ft_ulen_base(unsigned long long int n, int base)
{
	if (n < (unsigned long long int)base)
		return (1);
	return (1 + ft_ulen_base(n / base, base));
}

char	*ft_utoa_base(unsigned long long int nb, int base)
{
	char					*r;
	int						j;
	unsigned long long int	n;

	j = ft_ulen_base(nb, base);
	if (!(r = malloc(sizeof(*r) * (j + 1))))
		return (NULL);
	r[j--] = '\0';
	n = nb;
	while (j >= 0)
	{
		r[j] = ft_inttochar(n % base);
		n = n / base;
		j--;
	}
	return (r);
}
