/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 20:10:04 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/02 18:34:09 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	extract_i(t_print *aq, intmax_t *t, uintmax_t *ut)
{
	if (DEC && S.length == 0)
		*t = (va_arg(aq->va, int));
	else if (DEC && S.length == h)
		*t = (short)va_arg(aq->va, int);
	else if (DEC && S.length == hh)
		*t = (signed char)va_arg(aq->va, int);
	else if (DEC && S.length == l)
		*t = (va_arg(aq->va, long int));
	else if (DEC && S.length == ll)
		*t = (va_arg(aq->va, long long int));
	else if (DEC && S.length == j)
		*t = (va_arg(aq->va, intmax_t));
	else if (S.length == 0)
		*ut = va_arg(aq->va, unsigned int);
	else if (S.length == h)
		*ut = (unsigned short)va_arg(aq->va, unsigned int);
	else if (S.length == hh)
		*ut = (unsigned char)va_arg(aq->va, unsigned int);
	else if (S.length == l)
		*ut = (va_arg(aq->va, unsigned long int));
	else if (S.length == ll)
		*ut = (va_arg(aq->va, unsigned long long int));
	else if (S.length == j)
		*ut = (va_arg(aq->va, uintmax_t));
}

void		get_i(t_print *aq, intmax_t *t, uintmax_t *ut)
{
	*t = 0;
	if (S.length == z)
		*ut = (uintmax_t)va_arg(aq->va, size_t);
	else if (DEC && S.length != z)
	{
		extract_i(aq, t, ut);
		*ut = (uintmax_t)(*t < 0 ? *t * -1 : *t);
	}
	else if (S.ty == 'p')
		*ut = (uintmax_t)va_arg(aq->va, void*);
	else
		extract_i(aq, t, ut);
	*ut && (S.v = (short)(*t < 0 ? -1 : 1));
	S.ln = ft_nbrulen(*ut, S.base);
	if (S.apost)
		S.apost = (short)(S.ln / 3 - (S.ln % 3 ? 0 : 1));
	S.ln += S.apost;
}

void		set_flag_i(t_print *aq)
{
	if (S.ty != 'i' && S.ty != 'd')
	{
		S.plus = 0;
		S.spc = 0;
	}
	if (S.hash && S.v && S.ty == 'o')
		S.hash = 1;
	else if ((S.hash && S.v && HEX) || S.ty == 'p')
		S.hash = 2;
	else
		S.hash = 0;
	FREE = WIDTH;
	FREE -= PREC > (short)(S.ln + S.hash) ? PREC : S.ln + /*(!SIGN ? 0 :*/ S.hash;
	(S.v < 0 || S.plus || S.spc) && (FREE--);
	!S.v && !PREC && (FREE++);
	FREE < 0 && (FREE = 0);
}

void		set_format_i(t_print *aq)
{
	if (!S.minus && FREE && !(S.zero && PREC == -2))
	{
		pr_set(aq, ' ', (size_t)FREE);
		FREE = 0;
	}
	if (aq->i + 2 >= BUFS)
		pr_refresh(aq);
	if (S.v < 0)
		aq->out[aq->i++] = '-';
	else if (S.plus)
		aq->out[aq->i++] = '+';
	else if (S.spc)
		aq->out[aq->i++] = ' ';
	else if (S.hash)
	{
		aq->out[aq->i++] = '0';
		(S.ty == 'x' || S.ty == 'p') && (aq->out[aq->i++] = 'x');
		(S.ty == 'X') && (aq->out[aq->i++] = 'X');
	}
	if (S.zero && PREC == -2 && FREE)
		pr_set(aq, '0', (size_t)(FREE));
	else if (PREC > (short)(S.ln + /*(!SIGN ? 0 :*/ S.hash/*)*/))
		pr_set(aq, '0', (size_t)(PREC - S.ln /*- *//*(!SIGN ? 0 :*//* S.hash*/));
}

void		handle_i(t_print *aq)
{
	uintmax_t	ut;
	intmax_t	t;

	if (S.ty == 'D' || S.ty == 'O' || S.ty == 'U')
	{
		S.length = l;
		S.ty = (char)ft_tolower(S.ty);
	}
	get_i(aq, &t, &ut);
	set_flag_i(aq);
	set_format_i(aq);
	pr_itoa(aq, ut);
	if (S.minus && FREE > 0)
		pr_set(aq, ' ', (size_t)FREE);
}
