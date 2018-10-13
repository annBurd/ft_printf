/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_utoa_me.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 17:34:16 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/14 01:23:47 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
** Hello itoa, my old friend
** I've come to write some nbrs again
*/

void	pr_utoa(t_print *aq, uintmax_t value, short base)
{
	size_t		len;
	size_t		len_p;
	short		left;
	const char	c = (char)(S.ty == 'X' ? 'A' : 'a');

	len = S.ln ? S.ln : ft_nbrulen(value, base);
	len_p = --len;
	if (aq->i + len + 1 >= BUFSIZE)
		pr_refresh(aq);
	while (value)
	{
		left = (short)(value % base);
		value /= base;
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
