/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   structcrea.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 16:51:34 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 10:17:18 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_star(t_print **module, va_list ap)
{
	if ((*module)->w == -2)
	{
		(*module)->w = va_arg(ap, int);
		if ((*module)->w < 0)
		{
			(*module)->fm++;
			(*module)->w = (*module)->w * -1;
		}
	}
	if ((*module)->p == -2)
	{
		(*module)->p = va_arg(ap, int);
		if ((*module)->w < 0)
			(*module)->w = (*module)->w * -1;
	}
}

char	*ft_structrecup(char *c)
{
	int		j;
	int		i;
	char	*ret;

	ret = ft_pstrmalloc(300);
	i = 0;
	j = 0;
	while (c[i] && (c[i] == ' ' || c[i] == '+' || c[i] == '-' || c[i] == '#'
				|| c[i] == '0'))
		ret[j++] = c[i++];
	while ((c[i] && c[i] <= '9' && c[i] >= '0') || c[i] == '*')
		ret[j++] = c[i++];
	if (c[i] == '.')
		ret[j++] = c[i++];
	while ((c[i] && c[i] <= '9' && c[i] >= '0') || c[i] == '*')
		ret[j++] = c[i++];
	while (c[i] && (c[i] == 'h' || c[i] == 'l' || c[i] == 'j' || c[i] == 'z'))
		ret[j++] = c[i++];
	if (c[i] == ' ' || c[i] == '+' || c[i] == '-' || c[i] == '#' || (c[i] >= 0
				&& c[i] <= 9) || c[i] == '.' || c[i] == 'h' || c[i] == 'l' ||
			c[i] == 'j' || c[i] == 'z')
		ret[0] = '\0';
	else
		ret[j] = c[i];
	return (ret);
}

t_print	*ft_structini(void)
{
	t_print *mystruct;

	mystruct = malloc(sizeof(t_print));
	if (mystruct)
	{
		mystruct->fm = 0;
		mystruct->fp = 0;
		mystruct->fz = 0;
		mystruct->fs = 0;
		mystruct->fd = 0;
		mystruct->w = 0;
		mystruct->p = -1;
		mystruct->shh = 0;
		mystruct->sh = 0;
		mystruct->sl = 0;
		mystruct->sll = 0;
		mystruct->sj = 0;
		mystruct->sz = 0;
		mystruct->mp = 0;
	}
	return (mystruct);
}

t_print	*ft_structcrea(char *chain)
{
	char	*toconv;
	t_print	*module;

	toconv = ft_structrecup(chain);
	module = ft_structini();
	if (module)
	{
		ft_get_type(toconv, &module);
		if (module->t != '0')
		{
			ft_getflags(toconv, &module);
			ft_getwidth(toconv, &module);
			ft_getpreci(toconv, &module);
			ft_get_size(toconv, &module);
		}
	}
	if (toconv)
		free(toconv);
	return (module);
}
