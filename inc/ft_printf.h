/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:32:45 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/11 19:41:34 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include <stdint.h>

# define S		aq->sp
# define DEC	(S.ty == 'i' || S.ty == 'd')
# define HEX	(S.ty == 'x' || S.ty == 'X')

# define BUFS	777

/*
** v		for vendetta or value sign [-1, 0, 1]
** free		for free space
** color	for using detalies see pe_color_me.c
*/

typedef struct	s_sp
{
	short		hash;
	short		zero;
	short		minus;
	short		plus;
	short		spc;
	short		apost;
	short		wi;
	short		prec;
	enum
	{
		none, h, hh, l, ll, j, z
	}			length;
	short		v;
	short		base;
	short		free;
	size_t		ln;
	char		ty;
	short		color;
}				t_sp;

typedef struct	s_print
{
	va_list		va;
	t_sp		sp;
	char		out[BUFS];
	size_t		i;
	int			size;
}				t_print;

int				ft_printf(const char *format, ...);
void			explore(t_print *aq, const char *line, const char *point);
void			start_handle(t_print *aq);

void			set_flag(const char **line, t_print *aq);
void			set_num(const char **line, t_sp *mark);
void			set_length(const char **line, t_sp *mark);
void			set_type(const char **line, t_sp *mark);

void			set_color(const char **line, t_print *aq);

void			handle_i(t_print *aq);
void			handle_c(t_print *aq);
void			handle_wc(t_print *aq);

void			pr_utoa(t_print *aq, uintmax_t value, short base);

void			extract_i(t_print *aq, intmax_t t, uintmax_t *ut);
void			extract_ui(t_print *aq, uintmax_t *ut);

void			pr_refresh(t_print *aq);
size_t			pr_overflow_str(t_print *aq, char *s, size_t *n);
size_t			pr_overflow(t_print *aq, char c, size_t *n);

void			pr_join_str(t_print *aq, char *s, size_t n);
void			pr_join(t_print *aq, char c, size_t n);
void			pr_join_4b(t_print *aq, unsigned int c);
void			pr_join_3b(t_print *aq, unsigned int c);
void			pr_join_2b(t_print *aq, unsigned int c);
#endif
