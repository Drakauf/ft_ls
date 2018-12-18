/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 02:24:33 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 07:38:13 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./ls.h" 

t_ls	*create_struct()
{
	t_ls *l;

	if (!(l = malloc(sizeof(t_ls))))
		return (NULL);
	if (!(l->opts = malloc(sizeof(int) * OPT_TOT)))
		return (NULL);
	l->last_opt = 0;
	l->d_ = 1;
	l->files = NULL;
	int i;

	i = 0;
	while (i < OPT_TOT)
		l->opts[i++] = 0;
	return (l);
}

t_list	*create_list_elem(char *str)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list)
	{
		list->filename = str;
		list->next = NULL;
	}
	else
		return (NULL);
	return (list);
}

void	list_add(t_ls *l, t_list *list)
{
	t_list	*tmp;

	if (l->files == NULL)
		l->files = list;
	else
	{
		tmp = l->files;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = list;
	}
}

int	put_in_table(char c, t_ls *l)
{
	int 	i;

	i = 0;
	while (OPTLIST[i])
	{
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

/*
   int	parsing(int ac, char **av, t_ls *l)
   {
   int i;
   int j;

   i = 1;
   while (av[i])
   {
   j = 0;
   if (av[i][j++] == '-')
   {
   if (!av[i][j])
   break;
   if ((av[i][j] == '-' && !av[i][j+1]))
   {
   l->last_opt++;
   break ;
   }
   while (av[i][j])
   {
   if (!put_in_table(av[i][j], l))
   return (0);
   j++;
   }
   l->last_opt++;
   i++;
   }
   else
   break;
   }
   return (1);
   }
   */

int	parsing_fil(char **ac, t_ls *l)
{
	int		i;
	t_list	*list;

	i = l->last_opt + 1;
	while (ac[i])
	{
		list = create_list_elem(ac[i]);
		if (!list)
			return (0);
		list_add(l, list);
		i++;
	}
	free(list);
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

void	free_files(t_list *list)
{
	t_list *tmp;

	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	free(list);
}


void	free_struct(t_ls *l)
{
	if (l)
	{
		if (l->opts)
			free(l->opts);
		if (l->files)
		{
			free_files(l->files);
			free(l->files);
		}
		free(l);
	}
}


int		ft_illegal_opt(t_ls *l)
{
	printf("ls: illegal option -- %c\nusage: ls [-...] [file ...]\n", l->c_error);
	free_struct(l);
	return (0);
}


int		ft_error_occured(t_ls *l)
{
	printf("an error occured");
	free_struct(l);
	return (0);
}


void	print_files(t_ls *l)
{
	printf("printind l->files : \n");
	while (l->files)
	{
		printf("       %s\n", l->files->filename);
		l->files = (l->files)->next;
	}
}


int main(int ac, char **av)
{
	t_ls	*l;
	int		res;

	ac++;
	if (!(l = create_struct()))
		return (0);
	if ((res = parsing_all(av, l)) == 0)
		return(ft_illegal_opt(l));
	if (res == 1)
		return(ft_error_occured(l));

	int i;
	i = 0;
	while (i < OPT_TOT)
		printf("%d", l->opts[i++]);
	printf("\nlast opt : %d\n", l->last_opt);
	print_files(l);
	free_struct(l);
	return (0);
}
