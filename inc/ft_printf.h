/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:32:45 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/14 19:30:46 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include <stdint.h>

# define S aq->sp
# define BUFSIZE 666

/*
** v >>> for ̶ ̶v̶e̶n̶d̶e̶t̶t̶a̶  value sign [-1, 0, 1]
** free >>> for counting free space when length > width
** color >>> usage details see pr_color_me.c
**
** pr_refresh			| for strange & mystic cases
** pr_overflow		>>>	| when buf is full
** pr_overflow_str		| ̶ ̶̶o̶f̶ ̶d̶a̶r̶k̶n̶e̶s̶s̶
**
**
**
**
** EVALUATED BY MOULINETTE 70%
**
** test_c: [ko] **
** test_i: [ko] **
** test_d: [ko] **
** test_D: [ko] **
** test_o: [ko] **
** test_u: [ko] **
** test_x: [ko] **
**
** test_C: [ok]
** test_s: [ok]
** test_S: [ok]
** test_p: [ok]
** test_hhhllljz: [ok]
** test_sharp: [ok]
** test_precision: [ok]
** test_zero: [ok]
** test_minus: [ok]
** test_plus: [ok]
** test_space: [ok]
**
**
*/

typedef struct	s_sp
{
	short		hash;
	short		zero;
	short		minus;
	short		plus;
	short		spc;
	short		apost;
	short		base;
	int			wi;
	short		prec;
	int			prv;
	enum
	{
		none, h, hh, l, ll, j, z
	}			length;
	int			free;
	size_t		ln;
	char		ty;
	short		color;
}				t_sp;

typedef struct	s_print
{
	va_list		va; //separate
	t_sp		sp;
	char		out[BUFSIZE];
	short		i;
	short		size;
}				t_print;

int				ft_printf(const char *format, ...);
void			define_flags(t_print *aq, const char **line);

void			handle_id(t_print *aq, intmax_t t);
void			handle_oub(t_print *aq, uintmax_t ut);
void			handle_xp(t_print *aq, uintmax_t ut);
void			handle_c(t_print *aq, wchar_t arg);
void			handle_s(t_print *aq, char *arg);
void			handle_ws(t_print *aq, wchar_t *arg);

intmax_t		extract_i(t_print *aq);
uintmax_t		extract_ui(t_print *aq);

void			pr_color(t_print *aq, const char **line);

void			pr_utoa(t_print *aq, uintmax_t value, short base);

void			pr_refresh(t_print *aq);
size_t			pr_overflow_str(t_print *aq, char *s, size_t *n);
void			pr_overflow(t_print *aq, char c, size_t *n);

void			pr_join_str(t_print *aq, char *s, size_t n);
void			pr_join(t_print *aq, char c, size_t n);
void			pr_join_2b(t_print *aq, unsigned int c);
void			pr_join_3b(t_print *aq, unsigned int c);
void			pr_join_4b(t_print *aq, unsigned int c);
#endif
