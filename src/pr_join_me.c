/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:28:23 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/09 21:03:23 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
** 0xxxxxxx
** 110xxxxx 10xxxxxx
** 1110xxxx 10xxxxxx 10xxxxxx
** 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
*/

void	pr_join_str(t_print *aq, char *s, size_t n)
{
	if (!n || !s)
		return ;
	if (aq->i + n >= BUFS)
		s += pr_overflow_str(aq, s, &n);
	while (*s && n-- > 0)
		aq->out[aq->i++] = *(s++);
}

void	pr_join(t_print *aq, char c, size_t n)
{
	if (!n || !c)
		return ;
	if (aq->i + n >= BUFS)
		pr_overflow(aq, c, &n);
	while (n--)
		aq->out[aq->i++] = c;
}

void	pr_join_2b(t_print *aq, unsigned int c)
{
	const unsigned int		o2 = (c << 26) >> 26;
	const unsigned int		o1 = ((c >> 6) << 27) >> 27;
	const unsigned int		m2 = 49280;

	pr_join(aq, (unsigned char)((m2 >> 8) | o1), 1);
	pr_join(aq, (unsigned char)(((m2 << 24) >> 24) | o2), 1);
}

void	pr_join_3b(t_print *aq, unsigned int c)
{
	const unsigned int		o3 = (c << 26) >> 26;
	const unsigned int		o2 = ((c >> 6) << 26) >> 26;
	const unsigned int		o1 = ((c >> 12) << 28) >> 28;
	const unsigned int		m3 = 14712960;

	pr_join(aq, (unsigned char)((m3 >> 16) | o1), 1);
	pr_join(aq, (unsigned char)(((m3 << 16) >> 24) | o2), 1);
	pr_join(aq, (unsigned char)(((m3 << 24) >> 24) | o3), 1);
}

void	pr_join_4b(t_print *aq, unsigned int c)
{
	const unsigned int		o4 = (c << 26) >> 26;
	const unsigned int		o3 = ((c >> 6) << 26) >> 26;
	const unsigned int		o2 = ((c >> 12) << 26) >> 26;
	const unsigned int		o1 = ((c >> 18) << 29) >> 29;
	const unsigned int		m4 = 4034953344;

	pr_join(aq, (unsigned char)((m4 >> 24) | o1), 1);
	pr_join(aq, (unsigned char)(((m4 << 8) >> 24) | o2), 1);
	pr_join(aq, (unsigned char)(((m4 << 16) >> 24) | o3), 1);
	pr_join(aq, (unsigned char)(((m4 << 24) >> 24) | o4), 1);
}
