/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   usefull.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 17:17:09 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/27 18:32:42 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_replace(char **str, char *new)
{
	free(*str);
	*str = ft_pstrdup(new);
	free(new);
}

char	*ft_pstrstr(const char *str, const char *tofind)
{
	size_t	j;
	char	*s;

	s = (char*)str;
	if (tofind[0] == '\0')
		return (s);
	while (*s)
	{
		j = 0;
		while (*(s + j) == tofind[j] && tofind[j])
			j++;
		if (tofind[j] == '\0')
			return (s);
		s++;
	}
	return (NULL);
}

int		ft_patoi(char *str)
{
	unsigned long	r;
	int				s;

	s = 1;
	r = 0;
	while ((*str == '\t' || *str == '\f' || *str == '\v' ||
				*str == '\n' || *str == '\r' || *str == ' ')
			&& *str != '\0')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			s = -1;
	while (*str >= '0' && *str <= '9')
	{
		r = r * 10 + *str - 48;
		str++;
	}
	if (r >= 9223372036854775807)
		return (s == 1 ? -1 : 0);
	return (s * (int)r);
}
