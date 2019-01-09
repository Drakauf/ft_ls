/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/06 23:29:13 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 05:00:32 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ls.h"

void	print_user(t_ls *l, t_lsprint *f, t_files *directories)
{
	ft_rights(directories->filelstats.st_mode, directories);
	ft_printf("%*d ", f->links, directories->filelstats.st_nlink);
	ft_user_details(f, directories, l);
	ft_printf("%*d ", f->size, directories->filelstats.st_size);
}

char	*print_year(char *str, char c)
{
	char	*ret;
	int		i;
	int		j;

	if (!str || ft_strlen(str) < 4)
		return (NULL);
	ret = malloc(sizeof(char ) * 13);
	if (!ret)
		return (NULL);
	i = 4;
	j = 0;
	while (str[i])
	{
		if (i <= 10)
			ret[j++] = str[i];
		else if (i <= 15 && c == 't')
			ret[j++] = str[i];
		else if (i > 18 && c == 'y' && str[i] != '\n')
			ret[j++] = str[i];
		i++;
	}
	ret[j] = '\0';
	return (ret);
}

void	ft_printtime(t_files *directories)
{
	time_t	rawtime;
	char	*str;

	rawtime = time(NULL);
	if (rawtime - directories->filelstats.st_mtime >= 15638400)
		str = print_year(ctime(&directories->filelstats.st_mtime), 'y');
	else
		str = print_year(ctime(&directories->filelstats.st_mtime), 't');
	ft_printf("%s ", str);
	if (str)
		free(str);
}

void	ft_linkname(t_files *directories)
{
	char	link[1000];
	int		i;

	i = readlink(directories->fullname, link, 1000);
	link[i] = '\0';
	ft_printf("-> %s", link);
}

void	ft_show_line(t_ls *l, t_files **directories)
{
	t_files		*tmp;
	t_lsprint	f;

	f = get_len_line(directories, l);
	tmp = *directories;
	while (tmp)
	{
		print_s(l, &f, tmp);
		print_user(l, &f, tmp);
		ft_printtime(tmp);
		ft_printname(tmp, &f, l);
		if (S_ISLNK(tmp->filelstats.st_mode))
			ft_linkname(tmp);
		ft_printf("\n");
		tmp = tmp->next;
	}
}
