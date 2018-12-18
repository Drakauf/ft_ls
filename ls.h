/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ls.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 04:07:09 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 07:11:00 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#define	OPTLIST "Ralrt" 
#define OPT_TOT	5

typedef	struct		s_list
{
	char			*filename;
	struct s_list	*next;
}					t_list;

typedef struct		s_ls
{
	int				last_opt;
	t_list			*files;
	int				*opts;
	int				d_;
	char			c_error;
}					t_ls;
