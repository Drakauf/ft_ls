/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 05:31:11 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 05:21:15 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ls.h"

int	put_in_table(char c, t_ls *l)
{
	int 	i;

	i = 0;
	while (OPTLIST[i])
	{
		if (c == 'C' || c == '1' || c == 'l' || c == 'm' || c == 'g' || c == 'n')
			l->out_opt = c;
		if (c == 'u' || c == 'c')
			l->time_opt = c;
		if (OPTLIST[i] == c)
		{
			l->opts[i] = 1;
			return (1);
		}
		i++;
	}
	l->c_error = c;
	return(0);
}

int	parsing_fil(char **ac, t_ls *l)
{
	int		i;
	t_list	*list;

	i = l->last_opt + 1;
	list = NULL;
	while (ac[i])
	{
		list = create_list_elem(ac[i]);
		if (!list)
			return (0);
		list_add(&l->files, list);
		i++;
	}
	return (1);
}

int	parsing_opt(char **av, t_ls *l)
{
	int i;
	int j;

	i = 0;
	while (av[++i])
	{
		j = 0;
		if (av[i][j] != '-')
			break;
		if (j == 0 && av[i][j] == '-' && !av[i][j+1])
			break;
		if ((j == 0 && av[i][j + 1] == '-' && !av[i][j+2]))
		{
			l->last_opt++;
			break ;
		}
		while (av[i][++j])
		{
			if (!put_in_table(av[i][j], l))
				return (0);
		}
		l->last_opt++;
	}
	return (1);
}

int		parsing_all(char **ac, t_ls *l)
{
	if (!parsing_opt(ac,l))
		return (0);
	if (!parsing_fil(ac, l))
		return (1);
	return (2);
}

/********************/

void	print_arg_err(t_list *files)
{
	t_list *tmp;

	tmp = files;
	while (tmp)
	{
		ft_printf("ls: %s: No such file or directory\n", tmp->filename);
		tmp = tmp->next;
	}
}

/********************/

int		filetype(char *name)
{
	int i;
	int j;
	struct stat	files;
	struct stat	lfiles;

	i = stat(name, &files);
	j = lstat(name, &lfiles);
	if (i < 0 || j < 0)
		return (-1);
	if (S_ISDIR(files.st_mode))
		return (2);
	return (1);
}

void	sort_err(t_list *files, t_list **sorted)
{
	t_list *tmp;

	if (*sorted == NULL)
	{
		*sorted = files;
		return ;
	}
	tmp = *sorted;
	if (strcmp(tmp->filename, files->filename) >= 0)
	{
		files->next = tmp;
		*sorted = files;
		return ;
	}
	while (tmp->next)
	{
		if (strcmp(tmp->next->filename, files->filename) >= 0)
		{
			files->next = tmp->next;
			tmp->next = files;
			return;
		}
		tmp = tmp->next;
	}
	tmp->next = files;
}

void	ft_error_show(t_ls *l)
{
	t_list	*tmp;
	t_list	*sorted;
	t_list	*tosort;
	t_list	*list;

	list = l->errors;
	if (!l->opts[OPT_f])
	{
		sorted = NULL;
		while (list)
		{
			tmp = list->next;
			tosort = list;
			tosort->next = NULL;
			sort_err(tosort, &sorted);
			list = tmp;
		}
		l->errors = sorted;
	}
}

void	ft_dirprint(t_files **dir, t_ls *l)
{
	t_files *tmp;
	int		i;

	tmp = *dir;
	i = 0;
	while (tmp)
	{
		if(l->dir == 2)
			ft_printf("\n%s:\n", tmp->filename);
		else if (tmp->next && l->dir != 0)
			ft_printf("%s:\n", tmp->filename);
	if (!getfileinfo(l, tmp->filename))
			printf("%s:\nls: %s: Permission denied", tmp->filename, tmp->filename);
		tmp = tmp->next;
		i++;
	}
}

void	ft_arg_print(t_files **dir, t_files **file, t_ls *l)
{
		*dir = to_sort(dir, l);
	*file = to_sort(file, l);
	ft_error_show(l);
	print_arg_err(l->errors);
	ft_show(l, file, "");
	if ((*dir && *file))
		l->dir = 2;
	else
		l->dir = 1;
	ft_dirprint(dir, l);
	free_files(dir);
	free_files(file);
}

void	arg_opt(t_list **fi, t_ls *l)
{
	t_list	*tmp;
	t_files	*dir;
	t_files *file;
	int i;

	tmp = *fi;
	dir = NULL;
	file = NULL;
	while (tmp)
	{
		if ((i =filetype(tmp->filename)) < 0)
			list_add(&l->errors, create_list_elem(tmp->filename));
		else if (i == 2) 
			addfile(l, &dir, tmp->filename, tmp->filename);
		else
			addfile(l, &file, tmp->filename, tmp->filename);
		tmp = tmp->next;
	}
	ft_arg_print(&dir, &file, l);
}

void	arg_opt_d(t_list **fi, t_ls *l)
{
	t_list	*tmp;
	t_files	*dir;

	tmp = *fi;
	dir = NULL;
	while (tmp)
	{
		if (filetype(tmp->filename) < 0)
			list_add(&l->errors, create_list_elem(tmp->filename));
		else
			addfile(l, &dir, tmp->filename, tmp->filename);
		tmp = tmp->next;
	}
	dir = to_sort(&dir, l);
	ft_error_show(l);
	print_arg_err(l->errors);
	ft_show(l, &dir, "");
	free_files(&dir);
}

void	ft_argndle(t_list **files, t_ls *l)
{
	if (l->opts[OPT_d])
		arg_opt_d(files, l);
	else
		arg_opt(files, l);
}

int main(int ac, char **av)
{
	t_ls	*l;
	int		res;
	//	int i;

	ac++;
	if (!(l = create_struct()))
		return (0);
	if ((res = parsing_all(av, l)) == 0)
		return(ft_illegal_opt(l));
	if (!l->files && res != 1)
		res = ft_nofiles(l);
	if (l->files)
	{
		//		ft_printfiles(l->files);
		ft_argndle(&l->files, l);
	}
	//	if (l->files)
	//		res = sort_argfiles(l);
	//		else if (res != 1)
	//		res = ft_files_read(l);
	//	else
	//		return(ft_error_occured(l));
	//	i = 0;
	//	while (i < OPT_TOT)
	//		printf("%d", l->opts[i++]);
	//	printf("\nlast opt : %d\n", l->last_opt);
	//			print_files(l);
	free_struct(l);
	return (0);
}
