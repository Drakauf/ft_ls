/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   strfunc.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 12:28:48 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 11:45:18 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_pstrdup(char *s)
{
	size_t	l;
	char	*r;

	if (!(r = malloc(sizeof(char) * (ft_pstrlen(s) + 1))))
		return (NULL);
	l = 0;
	while (s[l])
	{
		r[l] = s[l];
		l++;
	}
	r[l] = '\0';
	return (r);
}

size_t	ft_pstrlen(char *str)
{
	size_t s;

	s = 0;
	if (str == NULL)
		return (s);
	while (str[s])
		s++;
	return (s);
}

char	*ft_pstrmalloc(size_t size)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (!(ret = malloc(sizeof(char) * size)))
		return (NULL);
	while (i < size - 1)
		ret[i++] = '\0';
	ret[i] = '\0';
	return (ret);
}

int		ft_pstrcmp(const char *str, const char *s2)
{
	while (*str && *str == *s2)
	{
		str++;
		s2++;
	}
	return ((unsigned char)*str - (unsigned char)*s2);
}

char	*ft_pstrcat(char *dest, char *str)
{
	size_t i;
	size_t j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (str[j] != '\0')
	{
		dest[i] = str[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
