/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ls.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 04:07:09 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 03:37:25 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <stdio.h>
#include "ft_printf/ft_printf.h"


#define	OPTLIST "ARalrt" 

#define OPT_TOT	6
#define OPT_A	0
#define OPT_R	1
#define OPT_a	2
#define OPT_l	3
#define OPT_r	4
#define OPT_t	5



typedef	struct		s_list
{
	char			*filename;
	struct s_list	*next;
}					t_list;

typedef	struct		s_files
{
	char			*filename;
	struct stat		filestats;
	struct s_files	*next;
}					t_files;

typedef struct		s_ls
{
	int				last_opt;
	t_list			*files;
	int				*opts;
	int				d_;
	char			c_error;
	t_files			*dirnofil;
	t_list			*filnofil;
}					t_ls;

t_ls	*create_struct();
void	free_struct(t_ls *l);
void	free_list(t_list **list);
int		ft_illegal_opt(t_ls *l);
t_files	*create_file_elem(char *str);
t_list	*create_list_elem(char *str);
void	list_add(t_ls *l, t_list *list);
void	file_add(t_files **allfiles, char *str, struct stat file);
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
void	ft_show_l(t_ls *l, t_files **directories, char *curdirname);
void	ft_show_nl(t_ls *l, t_files **directories, char *curdirname);
void	ft_recursive(t_ls *l, t_files **directories, char *curdirname);
int		ft_strlen(const char *str);
char	*ft_strjoinfname(char *s1, char *s2);
char	*ft_strcat(char *dest, char *src);
void	ft_strdel(char **str);
char	*ft_strdup(const char *s);
