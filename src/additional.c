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

void	pr_itoa(t_print *aq, uintmax_t value)
{
	size_t	len;
	size_t	len_p;
	short	left;
	char	c;

	c = (char)(TY == 'X' ? 'A' : 'a');
	len = NLEN - 1;
	len_p = len;
	if (!value && ((!DEC && HASH) || PREC || (PLUS && PREC < 0)))
		aq->out[aq->i++] = '0';
	while (value)
	{
		left = (short)(value % BASE);
		value /= BASE;
		aq->out[aq->i + len--] = (char)(left + (left < 10 ? '0' : c - 10));
		if (APOST && (len_p - len == 3))
		{
			aq->out[aq->i + len--] = ',';
			len_p = len;
			APOST--;
		}
	}
	SIGN &&	(aq->i += NLEN);
}

static void	pr_refresh(t_print *aq)
{
	aq->out[aq->i] = 0;
	write(1, aq->out, aq->i);
	ft_bzero(aq->out, sizeof(aq->i));
	aq->size += aq->i;
	aq->i = 0;
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

//size_t printf_wclen(wchar_t *s)
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

//char 	*printf_setcolor(char *out, char *s, t_sp *mark)
//{
//	char *fresh;
//	size_t	i;
//
//	i = 0;
//
//	return (fresh);
//}

//char	*printf_joinfree(char *s1, char *s2, size_t n)
//{
//	char	*fresh;
//	char	*s;
//	size_t	i;
//
//	if (!n || !s1 || !s2)
//		return (!n) ? s1 : NULL;
//	i = 0;
//	s = s1;
//	while (*(s++) && ++i)
//		;
//	if (!(fresh = (char*)malloc(sizeof(char) * (i + n + 1))))
//		return (NULL);
//	i = 0;
//	s = s1;
//	while (*s)
//		fresh[i++] = *(s++);
//	free(s1);
//	s = s2;
//	while (*s && n-- > 0)
//		fresh[i++] = *(s++);
//	fresh[i] = 0;
//	return (fresh);
//}
