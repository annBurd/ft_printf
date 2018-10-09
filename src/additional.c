/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:26:59 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/10 00:07:32 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	pr_refresh(t_print *aq)
{
	aq->size += write(1, aq->out, (unsigned int)aq->i);
	ft_bzero(aq->out, sizeof(aq->i));
	aq->i = 0;
}

size_t	pr_overflow_str(t_print *aq, char *s, size_t *n)
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

size_t	pr_overflow(t_print *aq, char c, size_t *n)
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

void	pr_itoa(t_print *aq, uintmax_t value)
{
	size_t		len;
	size_t		len_p;
	short		left;
	const char	c = (char)(S.ty == 'X' ? 'A' : 'a');

	len = S.ln ? S.ln : ft_nbrulen(value, S.base);
	len_p = --len;
	while (value)
	{
		left = (short)(value % S.base);
		value /= S.base;
		aq->out[aq->i + len--] = (char)(left + (left < 10 ? '0' : c - 10));
		if (S.apost && (len_p - len == 3))
		{
			aq->out[aq->i + len--] = ',';
			len_p = len;
			S.apost--;
		}
	}
	aq->i += S.ln ? S.ln : len_p + 1;
}

void	pr_colorme(t_print *aq, short start)
{
	if (aq->i + 12 >= BUFS)
		pr_refresh(aq);
	if (start)
	{
		pr_join_str(aq, "\e[", 2);
		if (S.color[1])
		{
			aq->out[aq->i++] = '1';
			aq->out[aq->i++] = ';';
		}
		if (S.color[2])
			pr_itoa(aq, S.color[2]);
		if (S.color[3])
		{
			S.color[2] && (aq->out[aq->i++] = ';');
			pr_itoa(aq, S.color[3]);
		}
		aq->out[aq->i++] = 'm';
	}
	else
		pr_join_str(aq, "\e[0m", 4);
}
