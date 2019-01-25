/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ureplace.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/18 16:06:08 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 17:57:38 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_ureplace(char *str, char toreplace, char by)
{
	int i;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
		{
			if (str[i] == toreplace)
				str[i] = by;
			i++;
		}
	}
}
