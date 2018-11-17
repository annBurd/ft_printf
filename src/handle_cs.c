/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 21:39:53 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/17 15:43:15 by aburdeni         ###   ########.fr       */
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

static void		pr_join_bytes(t_print *aq, unsigned int c)
{
	if (aq->i + 4 >= PRF_BUF_SIZE)
		pr_refresh(aq);
	if (c < 128)
		aq->out[aq->i++] = c;
	else if (c < 2048)
	{
		aq->out[aq->i++] = 192 | (c >> 6);
		aq->out[aq->i++] = 128 | (c & 63);
	}
	else if (c < 65536)
	{
		aq->out[aq->i++] = 224 | (c >> 12);
		aq->out[aq->i++] = 128 | ((c >> 6) & 63);
		aq->out[aq->i++] = 128 | (c & 63);
	}
	else
	{
		aq->out[aq->i++] = 240 | ((c >> 18) | 240);
		aq->out[aq->i++] = 128 | ((c >> 12) & 63);
		aq->out[aq->i++] = 128 | ((c >> 6) & 63);
		aq->out[aq->i++] = 128 | (c & 63);
	}
}

static size_t	count_bytes(unsigned int arg)
{
	if (arg < 128)
		return (size_t)(1 > MB_CUR_MAX ? MB_CUR_MAX : 1);
	else if (arg < 2048)
		return (size_t)(2 > MB_CUR_MAX ? MB_CUR_MAX : 2);
	else if (arg < 65536)
		return (size_t)(3 > MB_CUR_MAX ? MB_CUR_MAX : 3);
	else
		return (size_t)(4 > MB_CUR_MAX ? MB_CUR_MAX : 4);
}

void			handle_c(t_print *aq, wchar_t arg)
{
	S.ln = count_bytes(arg);
	S.free = ((S.wi - (int)S.ln) < 0 ? 0 : S.wi - (int)S.ln);
	if (!S.minus && S.free)
		pr_join(aq, (char)(S.zero ? '0' : ' '), (size_t)S.free);
	pr_join_bytes(aq, arg);
	if (S.minus && S.free)
		pr_join(aq, ' ', (size_t)S.free);
}

void			handle_s(t_print *aq, char *arg)
{
	if (!arg)
		arg = "(null)\0";
	if (!*arg)
		S.ln |= 1;
	else
		S.ln = ft_strlen(arg);
	if (S.prec && S.prv >= 0 && (size_t)S.prv < S.ln)
		S.ln = (size_t)S.prv;
	S.free = (int)(S.wi - (int)S.ln < 0 ? 0 : S.wi - S.ln);
	!*arg && S.wi && S.free++;
	if (!S.minus && S.free)
		pr_join(aq, (char)(S.zero ? '0' : ' '), (size_t)S.free);
	pr_join_str(aq, arg, S.ln);
	if (S.minus && S.free)
		pr_join(aq, ' ', (size_t)S.free);
}

void			handle_ws(t_print *aq, wchar_t *arg)
{
	if (!arg)
		arg = L"(null)\0";
	S.apost = 0;
	if (!S.prec)
		while (arg[S.apost])
			S.ln += count_bytes(arg[S.apost++]);
	else if (S.prec && S.prv > 0)
		while (arg[S.apost] && S.ln < (size_t)S.prv)
		{
			S.ln += count_bytes(arg[S.apost++]);
			if (S.ln > (size_t)S.prv)
				S.ln -= count_bytes(arg[--S.apost]) - S.ln + S.prv;
		}
	S.free = ((S.wi - (int)S.ln) <= 0 ? 0 : S.wi - (int)S.ln);
	if (!S.minus && S.free)
		pr_join(aq, (char)(S.zero ? '0' : ' '), (size_t)S.free);
	while (*arg && S.ln)
	{
		pr_join_bytes(aq, *arg);
		S.ln -= count_bytes(*(arg++));
	}
	if (S.minus && S.free)
		pr_join(aq, ' ', (size_t)S.free);
}
