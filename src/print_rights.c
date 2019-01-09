/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_rights.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 02:13:22 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 04:59:49 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ls.h"

char	ft_filetype(int mode)
{
	if (S_ISREG(mode))
		return ('-');
	if (S_ISDIR(mode))
		return ('d');
	if (S_ISBLK(mode))
		return ('b');
	if (S_ISCHR(mode))
		return ('c');
	if (S_ISFIFO(mode))
		return ('p');
	if (S_ISLNK(mode))
		return ('l');
	if (S_ISSOCK(mode))
		return ('s');
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
	char		list[1000];
	ssize_t		ret;
	acl_t		acl;
	acl_entry_t	dummy;

	acl = NULL;
	ret = listxattr(directories->fullname, list, 1000, 0);
	if (ret > 0)
		ft_printf("@ ");
	else if (ret == 0)
	{
		acl = acl_get_link_np(directories->fullname, ACL_TYPE_EXTENDED);
		if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
		{
			acl_free(acl);
			acl = NULL;
		}
		if (acl != NULL)
			ft_printf("+ ");
		else
			ft_printf("  ");
		free(acl);
	}
	else
		ft_printf("  ");
}

void	ft_rights(int mode, t_files *directories)
{
	static	char	*rwx[] = {"---", "--x", "-w-", "-wx",
		"r--", "r-x", "rw-", "rwx"};
	char			bits[11];

	bits[0] = ft_filetype(mode);
	right_cpy(&bits[1], rwx[(mode >> 6) & 7]);
	right_cpy(&bits[4], rwx[(mode >> 3) & 7]);
	right_cpy(&bits[7], rwx[(mode & 7)]);
	if (mode & S_ISUID)
		bits[3] = (mode & S_IXUSR) ? 's' : 'S';
	if (mode & S_ISGID)
		bits[6] = (mode & S_IXGRP) ? 's' : 'l';
	if (mode & S_ISVTX)
		bits[9] = (mode & S_IXOTH) ? 't' : 'T';
	bits[10] = '\0';
	ft_printf("%s", bits);
	ft_acess(directories);
}
