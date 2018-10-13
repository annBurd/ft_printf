/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 21:39:53 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/13 21:47:47 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static size_t	get_bytes(unsigned int arg)
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

static void		set_wln(t_print *aq, wchar_t *arg)
{
	size_t	i;

	i = 0;
	if (!S.prec)
		S.ln = 0;
	else if (S.prec == -2)
		while (arg[i])
			S.ln += get_bytes(arg[i++]);
	else if (S.prec > 0)
		while (arg[i] && S.ln < (size_t)S.prec)
		{
			S.ln += get_bytes(arg[i++]);
			if (S.ln > (size_t)S.prec)
				S.ln -= get_bytes(arg[--i]) - S.ln + S.prec;
		}
}

static void		set_flag_wc(t_print *aq, wchar_t *arg)
{
	if (S.ty == 'c' || S.ty == 'C')
		S.ln = get_bytes(*arg);
	else
		set_wln(aq, arg);
	S.free = (short)((S.wi - (short)S.ln) < 0 ? 0 : S.wi - (short)S.ln);
	if (!S.minus && S.free)
		pr_join(aq, (char)(S.zero ? '0' : ' '), (size_t)S.free);
}

void			handle_wc(t_print *aq)
{
	wchar_t	arg;

	arg = (wchar_t)va_arg(aq->va, int);
	set_flag_wc(aq, &arg);
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

void			handle_wstr(t_print *aq)
{
	wchar_t	*arg;
	size_t	size;
	size_t	i;

	arg = va_arg(aq->va, wchar_t*);
	if (!arg)
		arg = L"(null)\0";
	set_flag_wc(aq, arg);
	i = 0;
	while (arg[i] && S.ln)
	{
		size = get_bytes(arg[i]);
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
