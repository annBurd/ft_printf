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
	char	c;

	c = (char)(S.ty == 'X' ? 'A' : 'a');
	len = S.ln - 1;
	len_p = len;
	if (aq->i + S.ln >= BUFS)
		pr_refresh(aq);
	if (!value && ((!DEC && S.hash)
		|| PREC || (S.plus && PREC < 0)))
		aq->out[aq->i++] = '0';
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
	S.v && (aq->i += S.ln);
}

void	pr_join(t_print *aq, char *s, size_t n)
{
	if (!n || !s)
		return;
	if (aq->i + n >= BUFS)
		pr_refresh(aq);
	while (*s && n-- > 0)
		aq->out[aq->i++] = *(s++);
}
void	pr_set(t_print *aq, char c, size_t n)
{
	if (!n || !c)
		return;
	if (aq->i + n >= BUFS)
		pr_refresh(aq);
	while (n--)
		aq->out[aq->i++] = c;
}

//size_t pr_wlen(wchar_t *s)
//{
//	size_t size;
//
//	size = 0;
//	while (*s)
//	{
//		if (*s < 0x80) //128) //2^7 - 1
//			size += 1;
//		else if (*s < 0x8000) //32767) //2^15 - 1
//			size += 2;
//		else if (*s < 0x800000) //8388607) //2^23 - 1
//			size += 3;
//		else
//			size += 4;
//		s++;
//	}
//	return (size);
//}
