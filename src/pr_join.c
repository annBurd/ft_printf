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
** xxxxxxxx xxxxxxxx xxxxxxxx 0xxxxxxx - 0
** xxxxxxxx xxxxxxxx 110xxxxx 10xxxxxx - 49280 / c080
** xxxxxxxx 1110xxxx 10xxxxxx 10xxxxxx - 14712960 / e08080
** 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx - 4034953344 / f0808080
**
** oooooooo oooooooo oooooooo oo111111 - 63 / 0x3F
** oooooooo oooooooo oooooooo 1ooooooo - 128 / 0x80
** oooooooo oooooooo oooooooo 11oooooo - 192 / 0xC0
** oooooooo oooooooo oooooooo 111ooooo - 224 / 0xC0
** oooooooo oooooooo oooooooo 1111oooo - 240 / 0xF0
*/

void	pr_join_2b(t_print *aq, unsigned int c)
{
	const unsigned int		o2 = (c << 26) >> 26;
	const unsigned int		o1 = ((c >> 6) << 27) >> 27;
	const unsigned int		m2 = 49280;

	if (aq->i + 2 >= PR_BUF_SIZE)
		pr_refresh(aq);
	aq->out[aq->i++] = (m2 >> 8) | o1;
	aq->out[aq->i++] = ((m2 << 24) >> 24) | o2;

//	 aq->out[aq->i++] = 192 | (((c >> 6) << 27) >> 27);
//	 aq->out[aq->i++] = 49280 | ((c << 26) >> 26);
}

void	pr_join_3b(t_print *aq, unsigned int c)
{
	const unsigned int		o3 = (c << 26) >> 26;
	const unsigned int		o2 = ((c >> 6) << 26) >> 26;
	const unsigned int		o1 = ((c >> 12) << 28) >> 28;
	const unsigned int		m3 = 14712960;

	if (aq->i + 3 >= PR_BUF_SIZE)
		pr_refresh(aq);
	aq->out[aq->i++] = (m3 >> 16) | o1;
	aq->out[aq->i++] = ((m3 << 16) >> 24) | o2;
	aq->out[aq->i++] = ((m3 << 24) >> 24) | o3;

//	 aq->out[aq->i++] = 224 | (((c >> 12) << 28) >> 28);
//	 aq->out[aq->i++] = 57472 | (((c >> 6) << 26) >> 26);
//	 aq->out[aq->i++] = 14712960 | ((c << 26) >> 26);
}

void	pr_join_4b(t_print *aq, unsigned int c)
{
	const unsigned int		o4 = (c << 26) >> 26;
	const unsigned int		o3 = ((c >> 6) << 26) >> 26;
	const unsigned int		o2 = ((c >> 12) << 26) >> 26;
	const unsigned int		o1 = ((c >> 18) << 29) >> 29;
	const unsigned int		m4 = 4034953344;

	if (aq->i + 4 >= PR_BUF_SIZE)
		pr_refresh(aq);
	aq->out[aq->i++] = (m4 >> 24) | o1;
	aq->out[aq->i++] = ((m4 << 8) >> 24) | o2;
	aq->out[aq->i++] = ((m4 << 16) >> 24) | o3;
	aq->out[aq->i++] = ((m4 << 24) >> 24) | o4;

//	 aq->out[aq->i++] = 240 | (((c >> 18) << 29) >> 29);
//	 aq->out[aq->i++] = 61568 | (((c >> 12) << 26) >> 26);
//	 aq->out[aq->i++] = 15761536 | (((c >> 6) << 26) >> 26);
//	 aq->out[aq->i++] = 4034953344 | ((c << 26) >> 26);
}

 void	pr_join_byte(t_print *aq, unsigned int c)
 {
 	if (aq->i + 4 >= PR_BUF_SIZE)
 		pr_refresh(aq);
 	if (c < 128)
 		aq->out[aq->i++] = c;
 	else if (c < 2048)
 	{
// 		aq->out[aq->i++] = 192 | ((c >> 6) & 31); /**/
 		aq->out[aq->i++] = 192 | (c >> 6);
 		aq->out[aq->i++] = 128 | (c & 63);
 	}
 	else if (c < 65536)
 	{
// 		aq->out[aq->i++] = 224 | ((c >> 12) & 15); /**/
 		aq->out[aq->i++] = 224 | (c >> 12);
 		aq->out[aq->i++] = 128 | ((c >> 6) & 63);
 		aq->out[aq->i++] = 128 | (c & 63);
 	}
 	else
 	{
// 		aq->out[aq->i++] = 240 | ((c >> 18) & 7); /**/
 		aq->out[aq->i++] = 240 | ((c >> 18) | 240);
 		aq->out[aq->i++] = 128 | ((c >> 12) & 63);
 		aq->out[aq->i++] = 128 | ((c >> 6) & 63);
 		aq->out[aq->i++] = 128 | (c & 63);
 	}
 }
