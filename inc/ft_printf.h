/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:32:45 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/05 15:30:22 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include <stdint.h>

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

# define BUFS	1777

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
	size_t		ln;
	char		ty;
}				t_sp;

typedef struct	s_print
{
	va_list		va;
	t_sp		sp;
	unsigned char		out[BUFS];
	size_t		i;
	int			size;
}				t_print;

/*
** ft_printf.c
*/
int				ft_printf(const char *format, ...);
void			explore(t_print *aq, const char *format);
void			start_handle(t_print *aq);

/*
** specification_define.c
*/
void			set_flag(char **line, t_sp *mark);
void			set_num(char **line, t_sp *mark);
void			set_length(char **line, t_sp *mark);
void			set_type(char **line, t_sp *mark);

/*
** additional.c
*/
void			pr_itoa(t_print *aq, uintmax_t value);
void			pr_refresh(t_print *aq);
size_t			pr_overflow_str(t_print *aq, unsigned char *s, size_t *n);
size_t			pr_overflow(t_print *aq, unsigned char c, size_t *n);

/*
** handle_i.c
*/
void			handle_i(t_print *aq);
void			get_i(t_print *aq, intmax_t *t, uintmax_t *ut);
void			extract_i(t_print *aq, intmax_t *t, uintmax_t *ut);
void			set_flag_i(t_print *aq);
void			set_format_i(t_print *aq);

/*
** handle_c.c
*/
void			handle_c(t_print *aq);

/*
** handle_wc.c
*/
void			handle_wc(t_print *aq);
size_t			set_wln(t_print *aq, wchar_t *arg);
size_t			get_bytes(unsigned int arg);
void			set_wchar(t_print *aq, wchar_t *arg, size_t n);

/*
** pr_join.c
*/
void			pr_join_str(t_print *aq, unsigned char *s, size_t n);
void			pr_join(t_print *aq, unsigned char c, size_t n);
void			pr_join_4b(t_print *aq, unsigned int c);
void			pr_join_3b(t_print *aq, unsigned int c);
void			pr_join_2b(t_print *aq, unsigned int c);
#endif
