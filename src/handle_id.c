//
// Created by norb on 15.10.2018.
//

#include "../inc/ft_printf.h"

intmax_t	extract_i(t_print *aq)
{
	if (S.length == l || S.ty == 'D')
		return (va_arg(aq->va, long int));
	else if (!S.length)
		return (va_arg(aq->va, int));
	else if (S.length == h)
		return (short)(va_arg(aq->va, void*));
	else if (S.length == hh)
		return (signed char)(va_arg(aq->va, void*));
	else if (S.length == ll)
		return (va_arg(aq->va, long long int));
	else if (S.length == j)
		return (va_arg(aq->va, intmax_t));
	else if (S.length == z)
		return (size_t)(va_arg(aq->va, void*));
	else
		return (0);
}

static void	setting(t_print *aq, intmax_t t)
{
	if (S.prec && S.prv > (int)S.ln)
		S.free = S.wi - S.prv;
	else
		S.free = S.wi - (int)S.ln;
	(t < 0 || S.plus || S.spc) && (S.free--);
	S.free < 0 && (S.free &= 0);
	if (S.apost && S.ln)
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
	if (t < 0)
		pr_join(aq, '-', 1);
	else if (S.plus)
		pr_join(aq, '+', 1);
	else if (S.spc)
		pr_join(aq, ' ', 1);
}

void		handle_id(t_print *aq, intmax_t t)
{
	if (!(!t && S.prec && (S.minus || !(S.minus && S.prv))))
		S.ln = ft_nbrlen(t < 0 ? -t : t, 10);
	setting(aq, t);
	if (S.zero && !S.prec && S.free && !S.minus)
		pr_join(aq, '0', (size_t)S.free);
	else if ((S.zero = (short)(S.prv - S.ln)) > 0)
		pr_join(aq, '0', (size_t)(S.zero));
	t < 0 && (t = -t);
	if (!t && S.ln)
		pr_join(aq, '0', S.ln);
	else if (t)
		pr_utoa(aq, t, 10);
	if (S.minus && S.free > 0)
		pr_join(aq, ' ', (size_t)S.free);
}
