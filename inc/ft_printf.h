/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:32:45 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/10 00:58:47 by aburdeni         ###   ########.fr       */
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

# define BUFS	1777

/*
** v		for vendetta or value sign // -1, 0, 1
** free		for free space // 0-...
** color[4]	for output color
** //color[0] set active
** //color[1] bold // 0, 1
** //color[2] font
** //color[3] background
** //1 - black
** //2 - red
** //3 - green
** //4 - yellow
** //5 - blue
** //6 - purple
** //7 - cyan
** //8 - white
** // add 'b' after num for bright version
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
	size_t		color[4];
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
void			explore(t_print *aq, const char *format);
void			start_handle(t_print *aq);

void			set_flag(char **line, t_sp *mark);
void			set_color(char **line, t_sp *mark);
void			set_num(char **line, t_sp *mark);
void			set_length(char **line, t_sp *mark);
void			set_type(char **line, t_sp *mark);

void			handle_i(t_print *aq);
void			get_i(t_print *aq, intmax_t *t, uintmax_t *ut);
void			set_flag_i(t_print *aq);
void			set_format_i(t_print *aq);

void			handle_c(t_print *aq);

void			handle_wc(t_print *aq);
size_t			set_wln(t_print *aq, wchar_t *arg);
size_t			get_bytes(unsigned int arg);
void			set_wchar(t_print *aq, wchar_t *arg, size_t n);

void			pr_itoa(t_print *aq, uintmax_t value);
void			pr_refresh(t_print *aq);
void			pr_colorme(t_print *aq, short start);
size_t			pr_overflow_str(t_print *aq, char *s, size_t *n);
size_t			pr_overflow(t_print *aq, char c, size_t *n);
void			pr_join_str(t_print *aq, char *s, size_t n);
void			pr_join(t_print *aq, char c, size_t n);
void			pr_join_4b(t_print *aq, unsigned int c);
void			pr_join_3b(t_print *aq, unsigned int c);
void			pr_join_2b(t_print *aq, unsigned int c);
#endif
