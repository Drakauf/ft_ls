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
