/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:32:45 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/17 15:53:15 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include "color.h"
# include <stdarg.h>
# include <wchar.h>

# define S aq->sp
# define PRF_BUF_SIZE 666

/*
** EVALUATED BY MOULINETTE 70%
** test_c: [ko]
** test_i: [ko]
** test_d: [ko]
** test_D: [ko]
** test_o: [ko]
** test_u: [ko]
** test_x: [ko]
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
	t_sp		sp;
	char		out[PRF_BUF_SIZE];
	short		i;
	int			size;
}				t_print;

int				ft_printf(const char *format, ...);
void			define_flags(t_print *aq, va_list va, const char **line);

void			handle_id(t_print *aq, intmax_t t);
void			handle_oub(t_print *aq, uintmax_t ut);
void			handle_xp(t_print *aq, uintmax_t ut);
void			handle_c(t_print *aq, wchar_t arg);
void			handle_s(t_print *aq, char *arg);
void			handle_ws(t_print *aq, wchar_t *arg);

intmax_t		extract_i(t_print *aq, va_list va);
uintmax_t		extract_ui(t_print *aq, va_list va);

void			pr_color(t_print *aq, const char **line);
void			pr_utoa(t_print *aq, uintmax_t value, short base);
void			pr_refresh(t_print *aq);
void			pr_join(t_print *aq, char c, size_t n);
void			pr_join_str(t_print *aq, char *s, size_t n);
#endif
