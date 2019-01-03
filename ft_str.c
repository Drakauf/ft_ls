/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 09:08:10 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/03 04:19:03 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ls.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char	*ft_strcat(char *dest, char *str)
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

void	ft_strdel(char **as)
{
	if (as == NULL || *as == NULL)
		return ;
	free(*as);
	*as = NULL;
}

char	*ft_strjoinfname(char const *s1, char const *s2)
{
	char	*ret;

	dprintf(1, "joining :[%s] and [%s]\n", s1, s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2))))
		return (NULL);
	ret[0] = '\0';
	ret = ft_strcat(ret, (char *)s1);
	ret = ft_strcat(ret, "/");
	ret = ft_strcat(ret, (char *)s2);
	return (ret);
}

int		ft_strlen(const char *str)
{
	int	s;

	s = 0;
	if (str == NULL)
		return (s);
	while (str[s])
		s++;
	return (s);
}
