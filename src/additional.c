/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:26:59 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/08 22:42:57 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		pr_refresh(t_print *aq)
{
	aq->size += write(1, aq->out, (unsigned int)aq->i);
	ft_bzero(aq->out, sizeof(aq->i));
	aq->i = 0;
}

size_t		pr_overflow_str(t_print *aq, unsigned char *s, size_t *n)
{
	const size_t	t = *n > BUFS ? *n - BUFS : *n;

	if (*n > BUFS)
		pr_join_str(aq, s, t);
	pr_refresh(aq);
	if (*n <= BUFS)
		pr_join_str(aq, s, t);
	*n -= t;
	return (t);
}

size_t		pr_overflow(t_print *aq, unsigned char c, size_t *n)
{
	const size_t	t = *n > BUFS ? *n - BUFS : *n;

	if (*n > BUFS)
		pr_join(aq, c, t);
	pr_refresh(aq);
	if (*n <= BUFS)
		pr_join(aq, c, t);
	*n -= t;
	return (t);
}

static void	set_null_value(t_print *aq)
{
	if (DEC && (S.prec || (S.plus && S.prec < 0)))
		aq->out[aq->i ++] = '0';
	else if (!DEC && !S.hash)
	{
		if (S.prec)
			aq->out[aq->i ++] = '0';
		else if (S.minus && S.wi && !S.prec && S.wi)
			aq->out[aq->i ++] = '0';
	}
	else if (!DEC && S.hash)
	{
		if (S.prec > 0)
			aq->out[aq->i ++] = '0';
//		else if (S.minus && S.wi && !S.prec && S.wi)
//			aq->out[aq->i ++] = '0';
	}
}

void		pr_itoa(t_print *aq, uintmax_t value)
{
	size_t		len;
	size_t		len_p;
	short		left;
	const char	c = (char)(S.ty == 'X' ? 'A' : 'a');

	len = S.ln - 1;
	len_p = len;
	if (!value)
		set_null_value(aq);
	while (value)
	{
		left = (short)(value % S.base);
		value /= S.base;
		aq->out[aq->i + len--] =
			(unsigned char)(left + (left < 10 ? '0' : c - 10));
		if (S.apost && (len_p - len == 3))
		{
			aq->out[aq->i + len--] = ',';
			len_p = len;
			S.apost--;
		}
	}
	S.v && (aq->i += S.ln);
}
