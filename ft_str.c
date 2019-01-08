/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 09:08:10 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 05:16:46 by shthevak    ###    #+. /#+    ###.fr     */
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

char	*ft_strdup(const char *s)
{
	size_t	l;
	char	*r;

	if (!(r = malloc(sizeof(*r) * (ft_strlen(s) + 1))))
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

char	*joinracine(char *s2)
{
	int i;
	char *ret;

	i = 0;
	if (!(ret = malloc(sizeof(char) * (ft_strlen(s2) + 2))))
		return (NULL);
	ret[0] = '/';
	while (s2[i])
	{
		ret[i + 1] = s2[i];
		i++;
	}
	ret[i+1] = '\0';
	return (ret);
}

char	*ft_strjoinfname(char *s1, char *s2)
{
	char	*ret;
	int i;
	int j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (ft_strcmp(s1, "/") == 0)
		return (joinracine(s2));
	if (!(ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2))))
		return (NULL);
	while (s1[i])
		ret[j++] = s1[i++];
	ret[j++]='/';
	i = 0;
	while(s2[i])
		ret[j++] = s2[i++];
	ret[j] = '\0';
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


