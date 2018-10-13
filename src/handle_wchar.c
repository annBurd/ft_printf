/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 21:39:53 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/14 01:36:13 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

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

void			handle_wc(t_print *aq)
{
	wchar_t	arg;

	arg = (wchar_t)va_arg(aq->va, int);
	S.ln = count_bytes(arg);
	S.free = ((S.wi - (int)S.ln) < 0 ? 0 : S.wi - (int)S.ln);
	if (!S.minus && S.free)
		pr_join(aq, (char)(S.zero ? '0' : ' '), (size_t)S.free);
	if (S.ln)
	{
		if (S.ln == 1)
			pr_join(aq, arg, 1);
		else if (S.ln == 2)
			pr_join_2b(aq, arg);
		else if (S.ln == 3)
			pr_join_3b(aq, arg);
		else if (S.ln == 4)
			pr_join_4b(aq, arg);
	}
	if (S.minus && S.free)
		pr_join(aq, ' ', (size_t)S.free);
}

static void		setting_wstr(t_print *aq, wchar_t *arg, size_t i)
{
	if (S.prec && !S.prv)
		S.ln = 0;
	else if (!S.prec)
		while (arg[i])
			S.ln += count_bytes(arg[i++]);
	else if (S.prec && S.prv > 0)
		while (arg[i] && S.ln < (size_t)S.prv)
		{
			S.ln += count_bytes(arg[i++]);
			if (S.ln > (size_t)S.prv)
				S.ln -= count_bytes(arg[--i]) - S.ln + S.prv;
		}
	S.free = ((S.wi - (int)S.ln) < 0 ? 0 : S.wi - (int)S.ln);
	if (!S.minus && S.free)
		pr_join(aq, (char)(S.zero ? '0' : ' '), (size_t)S.free);
}

void			handle_wstr(t_print *aq)
{
	wchar_t	*arg;
	size_t	size;
	size_t	i;

	arg = va_arg(aq->va, wchar_t*);
	if (!arg)
		arg = L"(null)\0";
	setting_wstr(aq, arg, 0);
	i = 0;
	while (arg[i] && S.ln)
	{
		size = count_bytes(arg[i]);
		if (size == 1)
			pr_join(aq, arg[i++], 1);
		else if (size == 2)
			pr_join_2b(aq, arg[i++]);
		else if (size == 3)
			pr_join_3b(aq, arg[i++]);
		else if (size == 4)
			pr_join_4b(aq, arg[i++]);
		S.ln -= size;
	}
	if (S.minus && S.free)
		pr_join(aq, ' ', (size_t)S.free);
}
