/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   unicode.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/18 15:17:16 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 19:35:14 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_wputchar(wchar_t u)
{
	char	*b;
	char	*c;
	int		y;

	b = ft_ntoa_base(u, 2);
	y = ft_sqchart(u);
	c = ft_bitise(b, y);
	free(b);
	return (c);
}
