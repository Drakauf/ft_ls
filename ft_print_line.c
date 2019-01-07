/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/06 23:29:13 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/07 05:23:12 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ls.h"

void	get_blocks(t_lsprint *f, t_files *d, t_ls *l)
{
	int j;

	j = ft_intlen(d->filelstats.st_blocks);
	if (f->byte < j)
		f->byte = j;
	f->tbyte += d->filelstats.st_blocks;
	j = ft_intlen(d->filelstats.st_size);
	if (f->size < j)
		f->size = j;
}

void	ft_create_lsprint(t_lsprint *f)
{
	f->name = 0;
	f->byte = 0;
	f->tbyte = 0;
	f->inode = 0;
	f->links = 0;
	f->groups = 0;
	f->size = 0;
}

void	get_user(t_lsprint *f, t_files *directories, t_ls *l)
{
	struct passwd *usr;
	struct group *grp;
	int j;
	int i;

	usr = getpwuid(directories->filelstats.st_uid);
 	grp = getgrgid(directories->filelstats.st_gid);
	if (l->opts[OPT_n])
	{
		j = ft_intlen(directories->filelstats.st_uid);
		i = ft_intlen(directories->filelstats.st_gid);
	}
	else
	{
		j = ft_strlen(usr->pw_name);
		i = ft_strlen(grp->gr_name);
	}
	if (j > f->name)
		f->name = j;
	if (i > f->groups)
		f->groups = i;
}


void	ft_user_details(t_lsprint *f, t_files *directories, t_ls *l)
{
	struct passwd *usr;
	struct group *grp;
	int j;
	int i;

	usr = getpwuid(directories->filelstats.st_uid);
 	grp = getgrgid(directories->filelstats.st_gid);
	if (!l->opts[OPT_g])
	{
		if (l->opts[OPT_n])
			ft_printf("%*d  ", f->name, directories->filelstats.st_uid);
		else
			ft_printf("%*s  ", f->name, usr->pw_name);
	}
	if (l->opts[OPT_n])
			ft_printf("%*d  ", f->groups, directories->filelstats.st_gid);
	else
			ft_printf("%*s  ", f->groups, grp->gr_name);

}

t_lsprint get_len_line(t_files **directories, t_ls *l)
{
	int i;
	int j;
	t_files *tmp;
	t_lsprint	f;

	ft_create_lsprint(&f);
	tmp = *directories;
	while (tmp)
	{
		(f.inode < (j = ft_intlen(tmp->filelstats.st_ino))) ? f.inode = j : 0;
		get_blocks(&f, tmp, l);
		(f.links < (j = ft_intlen(tmp->filelstats.st_nlink))) ? f.links = j : 0;
		get_user(&f, tmp, l);
		tmp = tmp->next;
	}
	return (f);
}

char	ft_filetype(int	mode)
{
	if (S_ISREG(mode))
		return('-');
	if (S_ISDIR(mode))
		return('d');
	if (S_ISBLK(mode))
		return('b');
	if (S_ISCHR(mode))
		return('c');
	if (S_ISFIFO(mode))
		return('p');
	if (S_ISLNK(mode))
		return('l');
	if (S_ISSOCK(mode))
		return('s');
	return ('?');
}

void	right_cpy(char *bits, char *rights)
{
	int j;

	j = 0;
	while (rights[j])
	{
		bits[j] = rights[j];
		j++;
	}
}

void	ft_acess(t_files *directories)
{
	char	list[1000];
	ssize_t	ret;
	acl_t	acl;
	acl_entry_t dummy;


	acl = NULL;
	ret = listxattr(directories->fullname, list, 1000, 0);
	if (ret > 0)
		ft_printf("@ ");
	if (ret == 0)
	{
		acl = acl_get_link_np(directories->fullname, ACL_TYPE_EXTENDED);
		if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1) {
			acl_free(acl);
			acl = NULL;
		}
		if (acl != NULL)
			ft_printf("+ ");
		else
			ft_printf("  ");
		free(acl);
	}
}

void	ft_rights(int mode, t_files *directories)
{
	static	char	*rwx[] = {"---", "--x", "-w-", "-wx",
		"r--", "r-x", "rw-", "rwx"};
	char			bits[11];

	bits[0] = ft_filetype(mode);
	right_cpy(&bits[1], rwx[(mode >> 6)& 7]);
	right_cpy(&bits[4], rwx[(mode >> 3)& 7]);
	right_cpy(&bits[7], rwx[(mode & 7)]);
	if (mode & S_ISUID)
		bits[3] = (mode & S_IXUSR) ? 's' : 'S';
	if (mode & S_ISGID)
		bits[6] = (mode & S_IXGRP) ? 's' : 'l';
	if (mode & S_ISVTX)
		bits[9] = (mode & S_IXOTH) ? 't' : 'T';
	bits[10] = '\0';
	ft_printf("%s",bits);
	ft_acess(directories);
}

void	print_user(t_ls *l, t_lsprint *f, t_files *directories)
{
	ft_rights(directories->filelstats.st_mode, directories);
	ft_printf("%*d ", f->links, directories->filelstats.st_nlink);
	ft_user_details(f, directories, l);
	ft_printf("%*d ", f->size, directories->filelstats.st_size);
}

char	*print_year(char *str, char c)
{
	char *ret;
	int	 i;
	int	 j;

	if (!str || ft_strlen(str) < 4)
		return (NULL);
	ret = malloc(sizeof(char )* 13);
	if (!ret)
		return (NULL);
	i = 4;
	j = 0;
	while (str[i])
	{
		if (i <= 10)
			ret [j++] = str[i];
		else if (i <= 15 && c == 't')
			ret [j++] = str[i];
		else if (i > 18 && c == 'y' && str[i] != '\n')
			ret [j++] = str[i];
		i++;
	}
	ret[j] = '\0';
	return (ret);
}

void	ft_printtime(t_files *directories)
{
	time_t rawtime;
	char *str;

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

void ft_show_line(t_ls *l, t_files **directories)
{
	t_files	*tmp;
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
		printf("\n");
		tmp = tmp->next;
	}
}
