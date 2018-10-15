/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 20:10:04 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/14 01:06:11 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	setting_1(t_print *aq)
{
	if (!DEC)
	{
		S.plus = 0;
		S.spc = 0;
		if (S.hash && (S.ty == 'o' || (HEX && !S.v && S.prec && S.prv)))
			S.hash = 1;
		else if (S.ty == 'p' || (S.hash && HEX && S.v))
			S.hash = 2;
		else
			S.hash = 0;
	}
	else
		S.hash = 0;
	if (!S.v && (((S.prec && !S.prv) && S.ty != 'o')
		|| ((S.hash && S.ty != 'p')
		|| ((S.prec && !S.prv) && (!S.hash || !S.minus)))))
		S.ln = 0;
	S.free = S.wi;
	!(S.ty == 'o' && S.v && S.prv > (int)(S.ln)) && (S.free -= S.hash);
	S.free -= S.prec && S.prv > (int)S.ln ? S.prv : S.ln;
	(S.v < 0 || S.plus || S.spc) && (S.free--);
	S.hash && !S.v && S.prec > 0 && S.free++;
	S.free < 0 && (S.free = 0);
}

static void	setting_2(t_print *aq)
{
	if (S.apost && S.ln && (S.ty == 'i' || S.ty == 'd' || S.ty == 'u'))
	{
		S.apost = (short)(S.ln / 3 - (S.ln % 3 ? 0 : 1));
		S.ln += S.apost;
	}
	else
		S.apost = 0;
	if (!S.minus && S.free && !(S.zero && !S.prec))
	{
		pr_join(aq, ' ', (size_t)S.free);
		S.free = 0;
	}
	if (S.v < 0)
		pr_join(aq, '-', 1);
	else if (S.plus || S.spc)
		pr_join(aq, (char)(S.plus ? '+' : ' '), 1);
	else if (S.hash == 1)
		pr_join(aq, '0', 1);
	else if (S.hash == 2)
		pr_join_str(aq, (char*)(S.ty == 'X' ? "0X" : "0x"), 2);
	if (S.zero && !S.prec && S.free && !S.minus)
		pr_join(aq, '0', (size_t)S.free);
	else if ((S.zero = (short)(S.prv - S.ln -
			(!S.v || S.ty == 'o' ? S.hash : 0))) > 0)
		pr_join(aq, '0', (size_t)(S.zero));
}

void		handle_nbr(t_print *aq)
{
	uintmax_t	ut;

	if (S.ty == 'i' || S.ty == 'd')
		extract_i(aq, 0, &ut);
	else
		extract_ui(aq, &ut);
	S.ln = ft_nbrulen(ut, S.base);
	setting_1(aq);
	setting_2(aq);
	if (!S.v && S.ln)
		pr_join(aq, '0', S.ln);
	else if (S.v)
		pr_utoa(aq, ut, S.base);
	if (S.minus && S.free > 0)
		pr_join(aq, ' ', (size_t)S.free);
}

/*
**	if (!(!S.v && (((S.prec && !S.prv) && S.ty != 'o')
**		|| ((S.hash && S.ty != 'p')
**		|| ((S.prec && !S.prv) && (!S.hash || !S.minus))))))
**		S.ln = ft_nbrulen(*ut, S.base);
*/
