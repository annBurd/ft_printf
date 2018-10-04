/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 21:39:53 by aburdeni          #+#    #+#             */
/*   Updated: 2018/09/28 05:09:03 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

size_t			get_bytes(unsigned int arg)
{
	if (!arg)
		return (0);
	else if (arg < 128) //2^7
		return (1);
	else if (arg < 2048) //2^12
		return (2);
	else if (arg < 65536) //2^16
		return (3);
	else if (arg < 4294967296) //2^32
		return (4);
	return (0);
}

void			set_wchar(t_print *aq, wchar_t *arg, size_t n)
{
	size_t	i;
	size_t	size;

	i = 0;
	while (i < n)
	{
		size = get_bytes(arg[i]);
		if (size == 1)
			pr_join(aq, (unsigned char)arg[i], 1);
		else if (size == 2)
			pr_join_2b(aq, arg[i]);
		else if (size == 3)
			pr_join_3b(aq, arg[i]);
		else if (size == 4)
			pr_join_4b(aq, arg[i]);
		else
			break;
		i++;
	}
}

void			handle_wc(t_print *aq)
{
	wint_t	wc;
	wchar_t	*arg;
	size_t	i;

	if (S.ty == 'c' && (wc = (wint_t)va_arg(aq->va, int)))
		arg = &wc;
	S.ty == 's' && (arg = va_arg(aq->va, wchar_t*));
	i = 0;
	if (S.ty == 'c')
		S.ln = get_bytes(arg[i++]);
	else if (S.ty == 's' && PREC >= 0)
//		S.ln = (size_t)PREC; //****
		while (arg[i] && S.ln <= PREC)
			S.ln += get_bytes(arg[i++]);
	else
		while (arg[i])
			S.ln += get_bytes(arg[i++]);
	S.free = (short)((WIDTH - (short)S.ln) < 0 ? 0 : WIDTH - (short)S.ln);
	if (!S.minus && S.free)
		pr_join(aq, ' ', (size_t)S.free);
	if (S.ln)
		set_wchar(aq, arg, i);
	if (S.minus && S.free)
		pr_join(aq, ' ', (size_t)S.free);
}
