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
	if (DEC && LEN == 0)
		*t = (va_arg(aq->va, int));
	else if (DEC && LEN == h)
		*t = (short)va_arg(aq->va, int);
	else if (DEC && LEN == hh)
		*t = (signed char)va_arg(aq->va, int);
	else if (DEC && LEN == l)
		*t = (va_arg(aq->va, long int));
	else if (DEC && LEN == ll)
		*t = (va_arg(aq->va, long long int));
	else if (DEC && LEN == j)
		*t = (va_arg(aq->va, intmax_t));
	else if (LEN == 0)
		*ut = va_arg(aq->va, unsigned int);
	else if (LEN == h)
		*ut = (unsigned short)va_arg(aq->va, unsigned int);
	else if (LEN == hh)
		*ut = (unsigned char)va_arg(aq->va, unsigned int);
	else if (LEN == l)
		*ut = (va_arg(aq->va, unsigned long int));
	else if (LEN == ll)
		*ut = (va_arg(aq->va, unsigned long long int));
	else if (LEN == j)
		*ut = (va_arg(aq->va, uintmax_t));
}

void		get_i(t_print *aq, intmax_t *t, uintmax_t *ut)
{
	*t = 0;
	if (LEN == z)
		*ut = (uintmax_t)va_arg(aq->va, size_t);
	else if (DEC && LEN != z)
	{
		extract_i(aq, t, ut);
		*ut = (uintmax_t)(*t < 0 ? *t * -1 : *t);
	}
	else if (TY == 'p')
		*ut = (uintmax_t)va_arg(aq->va, void*);
	else
		extract_i(aq, t, ut);
	*ut && (SIGN = (short)(*t < 0 ? -1 : 1));
	NLEN = ft_nbrulen(*ut, BASE);
	APOST && (APOST = (short)(NLEN / 3 - (NLEN % 3 ? 0 : 1)));
	NLEN += APOST;
}

void		set_flag_i(t_print *aq)
{
	!DEC && (PLUS = 0);
	!DEC && (SPC = 0);
	if (HASH && SIGN && TY == 'o')
		HASH = 1;
	else if ((HASH && SIGN && HEX) || TY == 'p')
		HASH = 2;
	else
		HASH = 0;
	FREE = WIDTH;
	FREE -= PREC > (short)(NLEN + HASH) ? PREC : NLEN + /*(!SIGN ? 0 :*/ HASH;
	(SIGN < 0 || PLUS || SPC) && (FREE--);
	!SIGN && !PREC && (FREE++);
	FREE < 0 && (FREE = 0);
}

void		set_format_i(t_print *aq, uintmax_t *ut)
{
	if (!MINUS && FREE && !(ZERO && PREC == -2))
	{
		pr_set(aq, ' ', (size_t)FREE);
		FREE = 0;
	}
	if (SIGN < 0)
		aq->out[aq->i++] = '-';
	else if (PLUS)
		aq->out[aq->i++] = '+';
	else if (SPC)
		aq->out[aq->i++] = ' ';
	else if (HASH)
	{
		aq->out[aq->i++] = '0';
		(TY == 'x' || TY == 'p') && (aq->out[aq->i++] = 'x');
		(TY == 'X') && (aq->out[aq->i++] = 'X');
	}
	if (ZERO && PREC == -2 && FREE)
		pr_set(aq, '0', (size_t)(FREE));
	else if (PREC > (short)(NLEN + /*(!SIGN ? 0 :*/ HASH/*)*/))
		pr_set(aq, '0', (size_t)(PREC - NLEN /*- *//*(!SIGN ? 0 :*//* HASH*/));
	pr_itoa(aq, *ut);
	if (MINUS && FREE > 0)
		pr_set(aq, ' ', (size_t)FREE);
}

void		handle_i(t_print *aq)
{
	uintmax_t	ut;
	intmax_t	t;

	if (TY == 'D' || TY == 'O' || TY == 'U')
	{
		LEN = l;
		TY = (char)ft_tolower(TY);
	}
	get_i(aq, &t, &ut);
	set_flag_i(aq);
	set_format_i(aq, &ut);
}
