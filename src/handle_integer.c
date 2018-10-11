/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 20:10:04 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/11 22:21:41 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	set_flag_1(t_print *aq)
{
	if (S.ty == 'D' || S.ty == 'O' || S.ty == 'U')
	{
		S.length = l;
		S.ty = (char)ft_tolower(S.ty);
	}
	if (S.ty == 'b')
		S.base = 2;
	else if (S.ty == 'o')
		S.base = 8;
	else if (DEC || S.ty == 'u')
		S.base = 10;
	else
		S.base = 16;
}

static void	get_i(t_print *aq, uintmax_t *ut)
{
	if (S.ty == 'i' || S.ty == 'd')
		extract_i(aq, 0, ut);
	else
		extract_ui(aq, ut);
	if (!S.v && ((!S.prec && S.ty != 'o') ||
			(S.hash || (!S.prec && (!S.hash || !S.minus)))))
		S.ln = 0;
	else
		S.ln = ft_nbrulen(*ut, S.base);
	if (S.apost && DEC)
	{
		S.apost = (short)(S.ln / 3 - (S.ln % 3 ? 0 : 1));
		S.ln += S.apost;
	}
	else
		S.apost = 0;
}

static void	set_flag_2(t_print *aq)
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

static void	set_format_i(t_print *aq)
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
	if (S.zero && S.prec == -2 && S.free
		&& !((HEX || S.ty == 'o' || DEC) && S.minus))
		pr_join(aq, '0', (size_t)S.free);
	else if (!(HEX && S.minus) && (S.zero =
			(short)(S.prec - S.ln - (!S.v || S.ty == 'o' ? S.hash : 0))) > 0)
		pr_join(aq, '0', (size_t)(S.zero));
}

void		handle_i(t_print *aq)
{
	uintmax_t	ut;

	set_flag_1(aq);
	get_i(aq, &ut);
	set_flag_2(aq);
	set_format_i(aq);
	if (aq->i + S.ln >= BUFS)
		pr_refresh(aq);
	if (!S.v && S.ln)
		pr_join(aq, '0', S.ln);
	else if (S.v)
		pr_utoa(aq, ut, S.base);
	if (S.minus && S.free > 0)
		pr_join(aq, ' ', (size_t)S.free);
}
