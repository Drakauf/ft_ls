void	sort_files(t_files	*files, t_files **sorted)
{
	t_files *tmp;

	if (*sorted == NULL)
	{
		dprintf(1,"yes\n");
		*sorted = files;
		return ;
	}
	tmp = *sorted;
	if (!tmp->next)
		dprintf(1,"no tmp next %d\n", ft_strcmp(tmp->filename, files->filename) );
	if (!tmp->next && strcmp(tmp->filename, files->filename) <= 0)
	{
		dprintf(1,"yes\n");
		tmp->next = files;
	}
	else if (!tmp->next && strcmp(tmp->filename, files->filename) >= 0)
	{
		dprintf(1,"yes\n");
		files->next = tmp;
		*sorted = files;
	}
	else
	{
		dprintf(1,"yes\n");
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
	dprintf(1,"yes");
}


void	rsort_files(t_files	*files, t_files **sorted)
{
	t_files *tmp;

	if (*sorted == NULL)
	{
		*sorted = files;
		return ;
	}
	tmp = *sorted;
	if (ft_strcmp(tmp->filename, files->filename) <= 0)
	{
		files->next = tmp;
		*sorted = files;
	}
	else if (!tmp->next && ft_strcmp(tmp->filename, files->filename) <= 0)
		tmp->next = files;
	else
	{
		while (tmp->next)
		{
			if (ft_strcmp(tmp->next->filename, files->filename) <= 0)
			{
				files->next = tmp->next;
				tmp->next = files;
				return;
			}
			tmp = tmp->next;
		}
		tmp->next = files;
	}
}


t_files	*pre_sort(t_files *files)
{
	t_files	*sorted;
	t_files *tmp;
	t_files	*tosort;

	sorted = NULL;
	while (files)
	{
		tmp = files->next;
		if (!(tosort = duplicate_file(files)))
			return (0);
		sort_files(tosort, &sorted);
		files = tmp;
	}
	return(sorted);
}

t_list	*duplicate_list(t_list *files)
{
	t_list	*new;

	new = create_list_elem(files->filename);
	if (!new)
		return (NULL);
	new->next = NULL;
	return (new);
}

void	ft_sort_list(t_list *to_sort, t_list **sorted)
{
	t_list *tmp;

	if (*sorted == NULL)
	{
		*sorted = to_sort;
		return;
	}
	tmp = *sorted;
	if (!tmp->next && ft_strcmp(tmp->filename, to_sort->filename) <= 0)
		tmp->next = to_sort;
	else if (!tmp->next && ft_strcmp(tmp->filename, to_sort->filename) >= 0)
	{
		to_sort->next = tmp;
		*sorted = to_sort;
	}
	else
	{
		while (tmp->next)
		{
			if (ft_strcmp(tmp->next->filename, to_sort->filename) >= 0)
			{
				to_sort->next = tmp->next;
				tmp->next = to_sort;
				return;
			}
			tmp = tmp->next;
		}
		tmp->next = to_sort;
	}
}

int	sort_argfiles(t_ls *l)
{
	t_list *to_sort;
	t_list *tmp;
	t_list *sorted;
	t_list *tmp2;

	sorted = NULL;
	tmp = l->files;
	while (tmp)
	{
		to_sort = duplicate_list(tmp);
		ft_sort_list(to_sort, &sorted);
		tmp = tmp->next;
	}
	l->files = sorted;
	return (1);
}
