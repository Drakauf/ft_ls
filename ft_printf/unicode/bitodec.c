/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bitodec.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/18 18:49:02 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 18:44:08 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_power(int nb, int power)
{
	int r;

	if (power < 0)
		r = 0;
	if (power == 0)
		r = 1;
	if (power >= 1)
		r = nb * ft_power(nb, power - 1);
	return (r);
}

int		ft_bitodec(int dec)
{
	int i;
	int r;

	i = 0;
	r = 0;
	while (dec > 0)
	{
		r = r + ((dec % 10) * ft_power(2, i));
		dec = dec / 10;
		i++;
	}
	return (r);
}
