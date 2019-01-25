/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 14:38:24 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 13:56:16 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>

/*
********************************************************************************
**                                                                     Defines *
********************************************************************************
*/

# define PRINT_BUFF_SIZE 4096

/*
********************************************************************************
**                                                                  Structures *
********************************************************************************
*/

typedef struct				s_print
{
	int		fm;
	int		fp;
	int		fz;
	int		fs;
	int		fd;
	int		w;
	int		p;
	char	*s;
	char	t;
	int		shh;
	int		sh;
	int		sll;
	int		sl;
	int		sj;
	int		sz;
	int		mp;
}							t_print;

typedef	struct				s_len
{
	int		i;
	int		j;
	int		k;
	int		c;
	int		f;
	char	t;
}							t_len;

/*
********************************************************************************
**                                                       Fonction obligatoires *
********************************************************************************
*/

/*
** A
*/

int							ft_analyse(char *chain, va_list ap);
int							ft_patoi(char *str);
int							ft_addspace(int k, char **str, t_print *module,\
							long long int nb);

/*
** B
*/

char						**fillbits(char **tab, char *bits);
char						**ft_onebitise(char *bits);
char						**ft_twobitise(char *bits);
char						**ft_threebitise(char *bits);
char						**ft_fourbitise(char *bits);
int							ft_bitodec(int dec);
char						*ft_charise(char **tab);
int							ft_sqchart(int nb);
char						*ft_bitise(char *bits, int y);
int							ft_validuni(wchar_t *str);
void						ft_unipwidth(char **n, t_len **t, t_print *m);
void						ft_unipreci(char **n, wchar_t *str,\
							t_len **t, t_print *module);
void						ft_uniwidth(char **n, char *str, t_print *module,\
							t_len **t);

/*
** C
*/

char						*ft_creafill(char c, int nb);
void						ft_color(char *chain, t_len **t, char **print);

/*
** D
*/

char						*ft_datise(long long int nb, int len);

/*
** F
*/

void						ft_fillwid(char **str, char **ne, t_print *module);
void						ft_format(char *chain, t_len **t, char **print);
void						ft_putflagt(char **ew, t_print *module,\
							long long int nb);
void						ft_putflag(char **ne, t_print *module,\
							long long int nb);
void						ft_addflag(char **str, t_print *module,\
							long long int nb);
/*
** G
*/

void						ft_get_size(char *str, t_print **mystruct);
void						ft_getflags(char *str, t_print **mystruct);
void						ft_getwidth(char *str, t_print **mystruct);
void						ft_getpreci(char *str, t_print **mystruct);
void						ft_get_type(char *str, t_print **mystruct);

/*
** I
*/

char						ft_inttochar(int i);

/*
** K
*/

void						ft_kfour(long long int nb, char **print,\
							t_print *module, char **tab);
void						ft_keigh(long long int nb, char **print,\
							t_print *module, char **tab);
void						ft_ksix(long long int nb, char **print,\
							t_print *module, char **tab);
void						ft_ktwel(long long int nb, char **print,\
							char **tab);

/*
** M
*/

void						ft_mod(char *chain, va_list ap, char **print,\
							t_len **t);
void						ft_modulo(char *chain, va_list ap, char **print,\
							t_len **t);
void						ft_moduloverif(t_print **module);
void						ft_modulen(va_list ap, t_len *t);
char						**ft_monthtab(void);
/*
** N
*/

void						ft_nullpoint(char **ne, t_print *module);
char						*ft_ntoa(long long int n);
int							ft_nlen_base(long long int n, int base);
char						*ft_ntoa_base(long long int nb, int base);

/*
** O
*/

void						ft_oaddpre(char **str, t_print *module,\
							unsigned long long int nb);
void						ft_oaddflagg(char **nw, t_print *module, int i);
void						ft_oaddfla(char **str, t_print *module);
/*
** P
*/

int							ft_printf(char *str, ...);
int							ft_power(int nb, int pozer);
/*
** R
*/

void						ft_replace(char **str, char *ne);

/*
** S
*/

void						ft_star(t_print **module, va_list ap);
char						*ft_pstrcat(char *dest, char *str);
int							ft_pstrcmp(const char *s1, const char *s2);
char						*ft_pstrdup(char *str);
size_t						ft_pstrlen(char *str);
void						ft_strlowcase(char **ne);
char						*ft_pstrmalloc(size_t size);
t_print						*ft_structcrea(char *chain);
t_print						*ft_structini(void);
char						*ft_structrecup(char *chain);
char						*ft_pstrstr(const char *str, const char *tofind);

/*
** T
*/

t_len						*ft_t_lencrea(void);
void						ft_typeb(va_list ap, t_print *module, char **print);
void						ft_typec(va_list ap, t_print *module, char **print,\
							t_len **t);
void						ft_typed(va_list ap, t_print *module, char **print);
void						ft_typek(va_list ap, t_print *module, char **print);
void						ft_typeo(va_list ap, t_print *module, char **print);
void						ft_types(va_list ap, t_print *module, char **print);
void						ft_typeu(va_list ap, t_print *module, char **print);
void						ft_typew(va_list ap, t_print *module, char **print,\
							t_len **t);
void						ft_typex(va_list ap, t_print *module, char **print);
void						ft_typeint(va_list ap, t_print *module,\
							char **print);

/*
** U
*/

char						*ft_utoa(unsigned long long int n);
int							ft_ulen_base(unsigned long long int n, int base);
char						*ft_utoa_base(unsigned long long int nb, int base);
void						ft_uprecisize(char **str, t_print *module, char *n);
void						ft_uaddwid(char **str, t_print *module);
void						ft_uaddpre(char **str, t_print *module,\
							unsigned long long int nb);
void						ft_ureplace(char *str, char toreplace, char by);
/*
** V
*/

void						ft_verif(char *chain, t_len **t, char **print);
void						ft_verifbuff(char **str, t_len **t);
long long int				va_to_n(t_print *module, va_list ap);
unsigned long long int		va_to_u(t_print *module, va_list ap);

/*
** W
*/

void						ft_chresize(char **str, int i);
void						ft_wcharc(va_list ap, t_print *module,\
							char **print, t_len **t);
void						ft_unico(char **nw, char *str, t_len **t);
void						ft_wchars(va_list ap, t_print *module,\
							char **print, t_len **t);
char						*ft_wputchar(wchar_t u);
void						ft_wtoc(wchar_t **str, char **c, t_len **t,\
							t_print *module);
void						ft_addwid(char **str, t_print *module);
void						ft_addpre(char **str, t_print *module,\
							long long int nb);
void						ft_precisize(char **str, t_print *module, char *ne);

/*
** X
*/

void						ft_xaddpre(char **str, t_print *module,\
							unsigned long long int nb);
void						ft_xcreafl(char **str, t_print *module,\
							int *k, int *j);
void						ft_xfilfla(char **ne, int *j);
void						ft_xputfla(char **nw, int *k, int *j, char **str);
void						ft_xaddfla(char **str, t_print *module);

/*
********************************************************************************
**                                                               Mes Fonctions *
********************************************************************************
*/

#endif
