/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_join_me.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:28:23 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/13 20:04:16 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
** 0xxxxxxx
** 110xxxxx 10xxxxxx
** 1110xxxx 10xxxxxx 10xxxxxx
** 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
*/

void	pr_join_2b(t_print *aq, unsigned int c)
{
	const unsigned int		o2 = (c << 26) >> 26;
	const unsigned int		o1 = ((c >> 6) << 27) >> 27;
	const unsigned int		m2 = 49280;

	if (aq->i + 2 >= BUFSIZE)
		pr_refresh(aq);
	aq->out[aq->i++] = (m2 >> 8) | o1;
	aq->out[aq->i++] = ((m2 << 24) >> 24) | o2;
}

void	pr_join_3b(t_print *aq, unsigned int c)
{
	const unsigned int		o3 = (c << 26) >> 26;
	const unsigned int		o2 = ((c >> 6) << 26) >> 26;
	const unsigned int		o1 = ((c >> 12) << 28) >> 28;
	const unsigned int		m3 = 14712960;

	if (aq->i + 3 >= BUFSIZE)
		pr_refresh(aq);
	aq->out[aq->i++] = (m3 >> 16) | o1;
	aq->out[aq->i++] = ((m3 << 16) >> 24) | o2;
	aq->out[aq->i++] = ((m3 << 24) >> 24) | o3;
}

void	pr_join_4b(t_print *aq, unsigned int c)
{
	const unsigned int		o4 = (c << 26) >> 26;
	const unsigned int		o3 = ((c >> 6) << 26) >> 26;
	const unsigned int		o2 = ((c >> 12) << 26) >> 26;
	const unsigned int		o1 = ((c >> 18) << 29) >> 29;
	const unsigned int		m4 = 4034953344;

	if (aq->i + 4 >= BUFSIZE)
		pr_refresh(aq);
	aq->out[aq->i++] = (m4 >> 24) | o1;
	aq->out[aq->i++] = ((m4 << 8) >> 24) | o2;
	aq->out[aq->i++] = ((m4 << 16) >> 24) | o3;
	aq->out[aq->i++] = ((m4 << 24) >> 24) | o4;
}
