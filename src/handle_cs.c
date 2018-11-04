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

void			handle_c(t_print *aq, wchar_t arg)
{
	S.ln = count_bytes(arg);
	S.free = ((S.wi - (int)S.ln) < 0 ? 0 : S.wi - (int)S.ln);
	if (!S.minus && S.free)
		pr_join(aq, (char)(S.zero ? '0' : ' '), (size_t)S.free);
	if (S.ln == 1)
		pr_join(aq, (char)arg, 1);
	else if (S.ln == 2)
		pr_join_2b(aq, arg);
	else if (S.ln == 3)
		pr_join_3b(aq, arg);
	else if (S.ln == 4)
		pr_join_4b(aq, arg);
//	pr_join_bytes(aq, arg);
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

static void		setting_ws(t_print *aq, wchar_t *arg, size_t i)
{
	if (!S.prec)
		while (arg[i])
			S.ln += count_bytes(arg[i++]);
	else if (S.prec && S.prv > 0)
		while (arg[i] && S.ln < (size_t)S.prv)
		{
			S.ln += count_bytes(arg[i++]);
			if (S.ln > (size_t)S.prv)
				S.ln -= count_bytes(arg[--i]) - S.ln + S.prv;
		}
	S.free = ((S.wi - (int)S.ln) <= 0 ? 0 : S.wi - (int)S.ln);
	if (!S.minus && S.free)
		pr_join(aq, (char)(S.zero ? '0' : ' '), (size_t)S.free);
}

void			handle_ws(t_print *aq, wchar_t *arg)
{
//	size_t	size;

	if (!arg)
		arg = L"(null)\0";
	setting_ws(aq, arg, 0);
	while (*arg && S.ln)
	{
//		size = count_bytes(*arg);
//		if (size == 1)
//			pr_join(aq, *(arg++), 1);
//		else if (size == 2)
//			pr_join_2b(aq, *(arg++));
//		else if (size == 3)
//			pr_join_3b(aq, *(arg++));
//		else
//			pr_join_4b(aq, *(arg++));
//		S.ln -= size;

		pr_join_bytes(aq, *arg);
		S.ln -= count_bytes(*(arg++));
	}
	if (S.minus && S.free)
		pr_join(aq, ' ', (size_t)S.free);
}
