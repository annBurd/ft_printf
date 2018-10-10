/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 20:10:04 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/10 02:21:59 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	extract_i(t_print *aq, intmax_t t, uintmax_t *ut)
{
	if (DEC)
	{
		!S.length && (t = va_arg(aq->va, int));
		S.length == h && (t = (short)va_arg(aq->va, void*));
		S.length == hh && (t = (signed char)va_arg(aq->va, void*));
		S.length == l && (t = va_arg(aq->va, long int));
		S.length == ll && (t = va_arg(aq->va, long long int));
		S.length == j && (t = va_arg(aq->va, intmax_t));
		S.length == z && (t = (size_t)va_arg(aq->va, size_t));
		*ut = (uintmax_t)(t < 0 ? t * -1 : t);
		*ut && (S.v = (short)(t < 0 ? -1 : 1));
	}
	else
	{
		!S.length && (*ut = va_arg(aq->va, unsigned int));
		S.length == h && (*ut = (unsigned short)va_arg(aq->va, void*));
		S.length == hh && (*ut = (unsigned char)va_arg(aq->va, void*));
		S.length == l && (*ut = va_arg(aq->va, unsigned long int));
		S.length == ll && (*ut = va_arg(aq->va, unsigned long long int));
		S.length == j && (*ut = va_arg(aq->va, uintmax_t));
		S.length == z && (*ut = (size_t)va_arg(aq->va, size_t));
		*ut && (S.v = 1);
	}
}

void		get_i(t_print *aq, uintmax_t *ut)
{
	if (S.ty == 'p')
		S.length = 0;
	extract_i(aq, 0, ut);
	if (!S.v && ((!S.prec && S.ty != 'o') ||
				(S.hash || (!S.prec && (!S.hash || !S.minus)))))
		S.ln = 0;
	else
		S.ln = ft_nbrulen(*ut, S.base);
	if (S.apost)
		S.apost = (short)(S.ln / 3 - (S.ln % 3 ? 0 : 1));
	S.ln += S.apost;
}

void		set_flag_i(t_print *aq)
{
	if (!DEC)
	{
		S.plus = 0;
		S.spc = 0;
		if (S.hash &&
		(S.ty == 'o' || (!HEX && S.prec) || (HEX && !S.v && S.prec)))
			S.hash = 1;
		else if (S.ty == 'p' || (S.hash && HEX && S.v))
			S.hash = 2;
		else
			S.hash = 0;
	}
	else
		S.hash = 0;
	S.free = S.wi;
	!(S.ty == 'o' && S.v && S.prec > (short)(S.ln)) && (S.free -= S.hash);
	(S.v < 0 || S.plus || S.spc) && (S.free--);
	S.free -= S.prec > (short)(S.ln) ? S.prec : S.ln;
	S.hash && !S.v && S.prec && (S.free++);
	S.free < 0 && (S.free = 0);
}

void		set_format_i(t_print *aq)
{
	if (!S.minus && S.free && !(S.zero && S.prec == -2))
	{
		pr_join(aq, ' ', (size_t)S.free);
		S.free = 0;
	}
	if (aq->i + 2 >= BUFS)
		pr_refresh(aq);
	if (S.v < 0)
		aq->out[aq->i++] = '-';
	else if (S.plus || S.spc)
		aq->out[aq->i++] = (char)(S.plus ? '+' : ' ');
	else if (S.ty == 'p')
		pr_join_str(aq, "0x", 2);
	else if (S.hash)
	{
		aq->out[aq->i++] = '0';
		S.hash == 2 && (aq->out[aq->i++] = (char)(S.ty == 'X' ? 'X' : 'x'));
	}
	if (S.zero && S.prec == -2 && S.free)
		pr_join(aq, '0', (size_t)S.free);
	else if ((S.zero =
		(short)(S.prec - S.ln - (!S.v || S.ty == 'o' ? S.hash : 0))) > 0)
		pr_join(aq, '0', (size_t)(S.zero));
}

void		handle_i(t_print *aq)
{
	uintmax_t	ut;

	if (S.ty == 'D' || S.ty == 'O' || S.ty == 'U')
	{
		S.length = l;
		S.ty = (char)ft_tolower(S.ty);
	}
	S.ty == 'b' && (S.base = 2);
	S.ty == 'o' && (S.base = 8);
	(DEC || S.ty == 'u') && (S.base = 10);
	(HEX || S.ty == 'p') && (S.base = 16);
	get_i(aq, &ut);
	set_flag_i(aq);
	set_format_i(aq);
	if (aq->i + S.ln >= BUFS)
		pr_refresh(aq);
	!S.v && S.ln ? pr_join(aq, '0', S.ln) : pr_itoa(aq, ut, S.base);
	if (S.minus && S.free > 0)
		pr_join(aq, ' ', (size_t)S.free);
}
