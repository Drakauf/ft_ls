/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ls.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 04:07:09 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/25 15:48:13 by shthevak    ###    #+. /#+    ###.fr     */
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
# include "../ft_printf/ft_printf.h"

/*
********************************************************************************
**                                                                     Defines *
********************************************************************************
*/

# define OPTLIST		"1ACRSacdfgiklmnprstu"
# define OPT_TOT		20
# define OPT_1			0
# define OPT_65			1
# define OPT_67			2
# define OPT_82			3
# define OPT_83			4
# define OPT_97			5
# define OPT_99			6
# define OPT_100		7
# define OPT_102		8
# define OPT_103		9
# define OPT_105		10
# define OPT_107		11
# define OPT_108		12
# define OPT_109		13
# define OPT_110		14
# define OPT_112		15
# define OPT_114		16
# define OPT_115		17
# define OPT_116		18
# define OPT_117		19

/*
********************************************************************************
**                                                                      Struct *
********************************************************************************
*/

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
********************************************************************************
**                                                                    Function *
********************************************************************************
*/

/*
** add.c
*/

void				addfile(t_ls *l, t_files **dir, char *c, char *f);
void				file_add(t_files **dir, char *c, char *f);
void				list_add(t_list **l, t_list *list);

/*
** curdir.c
*/

int					ft_nofiles(t_ls *l);

/*
** dir.c
*/

void				ft_dirprint(t_files **dir, t_ls *l);

/*
** error.c
*/

int					ft_illegal_opt(t_ls *l);
int					ft_error_occured(t_ls *l);
void				print_files(t_ls *l);
void				ft_error_show(t_ls *l);

/*
** free.c
*/

void				ft_strdel(char **str);
void				free_struct(t_ls *l);
void				free_list(t_list **list);
void				free_files(t_files **list);

/*
** ft_args.c
*/

void				ft_arg_print(t_files **d, t_files **f, t_ls *l);
void				arg_opt(t_list **f, t_ls *l);
void				arg_opt_d(t_list **f, t_ls *l);
void				ft_argndle(t_list **f, t_ls *l);
void				print_arg_err(t_list *files);

/*
** ft_print_col.c
*/

void				ft_show_column(t_ls *l, t_files **directories);
t_lsprint			get_len_col(t_files **d, t_ls *l);
int					maxfilename(t_lsprint *i, t_ls *l);

/*
** ft_print_line.c
*/

void				print_user(t_ls *l, t_lsprint *f, t_files *d);
char				*print_year(char *str, char c);
void				ft_printtime(t_files *d);
void				ft_linkname(t_files *d);
void				ft_show_line(t_ls *l, t_files **d);

/*
** ft_str.c
*/

int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *s);
char				*ft_strjoinfname(char *s1, char *s2);
char				*joinracine(char *s1);
int					ft_strlen(const char *str);

/*
** get_details.c
*/

void				get_blocks(t_lsprint *f, t_files *files);
void				get_user(t_lsprint *f, t_files *d, t_ls *l);
void				ft_user_details(t_lsprint *f, t_files *d, t_ls *l);
t_lsprint			get_len_line(t_files **directories, t_ls *l);

/*
** others.c
*/

int					put_in_table(char c, t_ls *l);
int					filetype(char *c);
int					ft_intlen(int nb);

/*
** parsing.c
*/

int					parsing_fill(char **ac, t_ls *l);
int					parsing_opt(char **av, t_ls *l);
int					parsing_all(char **ac, t_ls *l);

/*
** print_opt.c
*/

void				print_s(t_ls *l, t_lsprint *f, t_files *d);
void				printf_p(t_files *d, t_ls *l);

/*
** print_rights.c
*/

char				ft_filetype(int mode);
void				right_cpy(char *bits, char *rights);
void				ft_acess(t_files *d);
void				ft_rights(int mode, t_files *d);

/*
** show.c
*/

void				ft_printname(t_files *file, t_lsprint *f, t_ls *ls);
int					getfileinfo(t_ls *l, char *curdirname);
void				ft_recursive(t_ls *l, t_files **directories, char *c);
void				ft_show(t_ls *l, t_files **directories, char *curdirname);

/*
** sort.c
*/

int					ft_aopt(t_ls *l, char *str);
void				sort_opt(t_ls *l, t_files **d, t_files **f);
t_files				*sort_r(t_files **f);
t_files				*pre_sort(t_files **f, t_ls *l);
t_files				*to_sort(t_files **files, t_ls *l);

/*
** sort_err.c
*/

void				sort_err(t_list *files, t_list **sorted);

/*
** sort_t.c
*/

void				sort_files(t_files	*files, t_files **sorted);
void				sort_c(t_files	*files, t_files **sorted);
void				sort_u(t_files	*files, t_files **sorted);
void				sort_t(t_files	*files, t_files **sorted);
void				sort_size(t_files	*files, t_files **sorted);

/*
** struct.c
*/

t_files				*duplicate_file(t_files *files);
t_files				*create_file_elem(char *str, char *fullname);
t_list				*create_list_elem(char *str);
t_ls				*create_struct(void);
void				ft_create_lsprint(t_lsprint *f);

#endif
