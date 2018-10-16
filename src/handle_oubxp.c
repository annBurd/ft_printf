//
// Created by norb on 15.10.2018.
//

#include "../inc/ft_printf.h"

uintmax_t	extract_ui(t_print *aq)
{
	if (S.ty == 'p' || S.length == j)
		return (va_arg(aq->va, uintmax_t));
	else if (!S.length)
		return (unsigned int)(va_arg(aq->va, void*));
	else if (S.length == h)
		return (unsigned short)(va_arg(aq->va, void*));
	else if (S.length == hh)
		return (unsigned char)(va_arg(aq->va, void*));
	else if (S.length == l)
		return (unsigned long int)(va_arg(aq->va, void*));
	else if (S.length == ll)
		return (unsigned long long int)(va_arg(aq->va, void*));
	else if (S.length == z)
		return (size_t)(va_arg(aq->va, void*));
}

static void	setting(t_print *aq, uintmax_t ut)
{
	if (!ut && ((S.prec && !S.prv && S.ty != 'o') || ((S.hash && S.ty != 'p')
			|| (S.prec && !S.prv && (!S.hash || !S.minus)))))
		S.ln &= 0;
	S.apost &= 0;
	if (!(S.ty == 'o' && ut && S.prv > (int)(S.ln)))
		S.free = S.wi - S.hash;
	else
		S.free = S.wi;
	S.free -= S.prec && S.prv > (int)S.ln ? S.prv : S.ln;
	S.hash && !ut && S.prec > 0 && S.free++;
	S.free < 0 && (S.free = 0);
	if (!S.minus && S.free && !(S.zero && !S.prec))
	{
		pr_join(aq, ' ', (size_t)S.free);
		S.free &= 0;
	}
}

void		handle_oub(t_print *aq, uintmax_t ut)
{
	S.ln = ft_nbrulen(ut, S.base);
	S.hash && S.ty != 'o' && (S.hash &= 0);
	setting(aq, ut);
	if (S.hash)
		pr_join(aq, '0', 1);
	if (S.zero && !S.prec && S.free && !S.minus)
		pr_join(aq, '0', (size_t)S.free);
	else if ((S.zero = (short)(S.prv - S.ln -
			(!ut || S.ty == 'o' ? S.hash : 0))) > 0)
		pr_join(aq, '0', (size_t)(S.zero));
	if (!ut && S.ln)
		pr_join(aq, '0', S.ln);
	else if (ut)
		pr_utoa(aq, ut, S.base);
	if (S.minus && S.free > 0)
		pr_join(aq, ' ', (size_t)S.free);
}

void		handle_xp(t_print *aq, uintmax_t ut)
{
	S.ln = ft_nbrulen(ut, 16);
	if (S.ty == 'p' || (S.hash && ut))
		S.hash = 2;
	else if (!(S.hash && !ut && S.prec && S.prv))
		S.hash &= 0;
	setting(aq, ut);
	if (S.hash == 1)
		pr_join(aq, '0', 1);
	else if (S.hash == 2)
		pr_join_str(aq, (char*)(S.ty == 'X' ? "0X" : "0x"), 2);
	if (S.zero && !S.prec && S.free && !S.minus)
		pr_join(aq, '0', (size_t)S.free);
	else if ((S.zero = (short)(S.prv - S.ln - (!ut ? S.hash : 0))) > 0)
		pr_join(aq, '0', (size_t)(S.zero));
	if (!ut && S.ln)
		pr_join(aq, '0', S.ln);
	else if (ut)
		pr_utoa(aq, ut, 16);
	if (S.minus && S.free > 0)
		pr_join(aq, ' ', (size_t)S.free);
}
