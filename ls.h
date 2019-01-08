/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ls.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 04:07:09 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 05:44:14 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/ioctl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <string.h>
# include <dirent.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>
# include <sys/acl.h>
# include <time.h>
# include "ft_printf/ft_printf.h"

/*
********************************************************************************
**                                                                     Defines *
********************************************************************************
*/

# define OPTLIST	"1ARaklrstCdcguSpmifn"
# define OPT_TOT	20
# define OPT_1		0
# define OPT_A		1
# define OPT_R		2
# define OPT_a		3
# define OPT_k		4
# define OPT_l		5
# define OPT_r		6
# define OPT_s		7
# define OPT_t		8
# define OPT_C		9
# define OPT_d		10
# define OPT_c		11
# define OPT_g		12
# define OPT_u		13
# define OPT_S		14
# define OPT_p		15
# define OPT_m		16
# define OPT_i		17
# define OPT_f		18
# define OPT_n		19

typedef	struct		s_list
{
	char			*filename;
	struct s_list	*next;
}					t_list;

typedef	struct		s_lsprint
{
	int				name;
	int				byte;
	int				tbyte;
	int				inode;
	int				links;
	int				groups;
	int				size;
}					t_lsprint;

typedef	struct		s_files
{
	char			*filename;
	char			*fullname;
	struct stat		filestats;
	struct stat		filelstats;
	int				d;
	struct s_files	*next;
}					t_files;

typedef struct		s_ls
{
	int				last_opt;
	t_list			*files;
	int				*opts;
	int				d_;
	char			c_error;
	t_list			*errors;
	char			out_opt;
	char			time_opt;
	int				dir;
}					t_ls;

/*
t_ls				*create_struct();
void				free_struct(t_ls *l);
void				free_list(t_list **list);
int					ft_illegal_opt(t_ls *l);
t_files	*create_file_elem(char *str, char *fullname);
t_list	*create_list_elem(char *str);
void	list_add(t_list **l, t_list *list);
void	file_add(t_files **allfiles, char *str, char *fulname);
int		ft_error_occured(t_ls *l);
void	print_files(t_ls *l);
int		ft_nofiles(t_ls *l);
void	ft_nofiledir(t_files **directories, char *str, struct stat *files);
int		ft_strcmp(const char *s1, const char *s2);
t_files *duplicate_file(t_files *files);
void	sort_files(t_files	*files, t_files **sorted);
void	rsort_files(t_files	*files, t_files **sorted);
t_files	*pre_sort(t_files **files, t_ls *l);
void	free_files(t_files **list);
void	ft_show(t_ls *l, t_files **directories, char *curdirname);
void	ft_show_line(t_ls *l, t_files **directories);
void	ft_show_column(t_ls *l, t_files **directories);
void	ft_recursive(t_ls *l, t_files **directories, char *curdirname);
int		ft_strlen(const char *str);
char	*ft_strjoinfname(char *s1, char *s2);
char	*ft_strcat(char *dest, char *src);
void	ft_strdel(char **str);
char	*ft_strdup(const char *s);
int		ft_aopt(t_ls *l, char *str);
void	addfile(t_ls *l, t_files **directories, char *dirname, char *fullname);
t_files	*to_sort(t_files **files, t_ls *l);
void	print_s(t_ls *l, t_lsprint *f, t_files *directories);
int		ft_intlen(int n);
void	get_blocks(t_lsprint *f, t_files *files);
void	ft_create_lsprint(t_lsprint *f);
void	ft_printname(t_files *file, t_lsprint *f, t_ls *ls);
int		getfileinfo(t_ls *l, char *curdirname);*/
#endif
