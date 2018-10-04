/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:26:59 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/02 18:39:06 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

size_t	pr_overflow_str(t_print *aq, unsigned char *s, size_t *n)
{
	const size_t	t = *n > BUFS ? *n - BUFS : *n;

	if (*n > BUFS)
		pr_join_str(aq, s, t);
	aq->size += write(1, aq->out, (unsigned int)aq->i);
	ft_bzero(aq->out, sizeof(aq->i));
	aq->i = 0;
	if (*n <= BUFS)
		pr_join_str(aq, s, t);
	*n -= t;
	return (t);
}

size_t	pr_overflow(t_print *aq, unsigned char c, size_t *n)
{
	const size_t	t = *n > BUFS ? *n - BUFS : *n;

	if (*n > BUFS)
		pr_join(aq, c, t);
	aq->size += write(1, aq->out, (unsigned int)aq->i);
	ft_bzero(aq->out, sizeof(aq->i));
	aq->i = 0;
	if (*n <= BUFS)
		pr_join(aq, c, t);
	*n -= t;
	return (t);
}

void	pr_refresh(t_print *aq)
{
	aq->size += write(1, aq->out, aq->i);
	ft_bzero(aq->out, sizeof(aq->i));
	aq->i = 0;
}

void	pr_itoa(t_print *aq, uintmax_t value)
{
	size_t	len;
	size_t	len_p;
	short	left;
	const char	c = (char)(S.ty == 'X' ? 'A' : 'a');

	len = S.ln - 1;
	len_p = len;
	if (!value && ((!DEC && S.hash)	|| PREC || (S.plus && PREC < 0)))
		aq->out[aq->i++] = '0';
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
