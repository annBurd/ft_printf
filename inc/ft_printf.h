/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:32:45 by aburdeni          #+#    #+#             */
/*   Updated: 2018/09/30 21:24:46 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include <stdint.h>

#include <stdio.h>

// #define RED		"\x1B[31m"
// #define GREEN	"\x1B[32m"
// #define YELLOW	"\x1B[33m"
// #define BLUE		"\x1B[34m"
// #define MAGENTA	"\x1B[35m"
// #define CYAN		"\x1B[36m"
// #define WHITE	"\x1B[37m"
// #define NORMAL	"\x1B[0m"	//standart

# define S		aq->sp

# define WIDTH	S.width
# define PREC	S.prec
# define FREE	S.free
# define DEC	(S.ty == 'i' || S.ty == 'd')
# define HEX	(S.ty == 'x' || S.ty == 'X')
# define WC		(S.ty == 'C' || (S.ty == 'c' && S.ty == l))
# define WS		(S.ty == 'S' || (S.ty == 's' && S.ty == l))

# define BUFS	20

typedef struct	s_sp
{
	short		hash;
	short		zero;
	short		minus;
	short		plus;
	short		spc;
	short		apost;
	short		width;
	short		prec;
	enum
	{
		none, h, hh, l, ll, j, z
	}			length;
	short		v;
	short		base;
	short		free;
	size_t 		ln;
	char		ty;
}				t_sp;

typedef struct	s_print
{
	va_list 	va;
	t_sp		sp;
	char		out[BUFS];
	size_t		i;
	int			size;
}				t_print;

int				ft_printf(const char *format, ...);
void			explore(t_print *aq, const char *format);
void			start_handle(t_print *aq);

void			set_flag(char **line, t_sp *mark);
void			set_num(char **line, t_sp *mark);
void			set_length(char **line, t_sp *mark);
void			set_type(char **line, t_sp *mark);

//size_t			pr_wlen(wchar_t *s);
void			pr_itoa(t_print *aq, uintmax_t value);
void			pr_join(t_print *aq, char *s, size_t n);
void			pr_set(t_print *aq, char c, size_t n);
void			pr_refresh(t_print *aq);

void			handle_i(t_print *aq);
void			get_i(t_print *aq, intmax_t *t, uintmax_t *ut);
void			extract_i(t_print *aq, intmax_t *t, uintmax_t *ut);
void			set_flag_i(t_print *aq);
void			set_format_i(t_print *aq);

void			handle_c(t_print *aq, t_sp *mark);

void			handle_wc(t_print *pr, t_sp *mark);
void			get_bytes(t_sp *mark, wchar_t *arg);
void			set_bytes(t_sp *mark, char *s, wchar_t *arg);
void			set_wc(t_sp *mark, char *s, wchar_t arg);

#endif
