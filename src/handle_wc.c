/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 21:39:53 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/10 00:59:38 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

size_t	get_bytes(unsigned int arg)
{
	if (!arg)
		return (0);
	else if (arg < 128)
		return (1);
	else if (arg < 2048)
		return (2);
	else if (arg < 65536)
		return (3);
	else
		return (4);
}

void	set_wchar(t_print *aq, wchar_t *arg, size_t n)
{
	size_t	i;
	size_t	size;

	i = 0;
	while (i < n)
	{
		size = get_bytes(arg[i]);
		if (size == 1)
			pr_join(aq, arg[i], 1);
		else if (size == 2)
			pr_join_2b(aq, arg[i]);
		else if (size == 3)
			pr_join_3b(aq, arg[i]);
		else if (size == 4)
			pr_join_4b(aq, arg[i]);
		else
			break ;
		i++;
	}
}

size_t	set_wln(t_print *aq, wchar_t *arg)
{
	size_t	i;

	i = 0;
	if (S.ty == 'c')
		S.ln = get_bytes(arg[i++]);
	else if (S.ty == 's')
	{
		if (!S.prec)
			S.ln = 0;
		else if (S.prec == -2)
			while (arg[i])
				S.ln += get_bytes(arg[i++]);
		else if (S.prec > 0)
			while (arg[i] && S.ln < (size_t)S.prec)
			{
				S.ln += get_bytes(arg[i++]);
				S.ln > (size_t)S.prec &&
				(S.ln -= get_bytes(arg[--i]) - S.ln + S.prec);
			}
	}
	return (i);
}

void	handle_wc(t_print *aq)
{
	wint_t	wc;
	wchar_t	*arg;
	size_t	i;

	if (S.color[0])
		pr_colorme(aq, 1);
	if (S.ty == 'C' || S.ty == 'S')
		S.ty = (char)ft_tolower(S.ty);
	if (S.ty == 'c' && (wc = (wint_t)va_arg(aq->va, int)))
		arg = &wc;
	S.ty == 's' && (arg = va_arg(aq->va, wchar_t*));
	i = set_wln(aq, arg);
	S.free = (short)((S.wi - (short)S.ln) < 0 ? 0 : S.wi - (short)S.ln);
	if (!S.minus && S.free)
		pr_join(aq, ' ', (size_t)S.free);
	if (S.ln)
		set_wchar(aq, arg, i);
	if (S.minus && S.free)
		pr_join(aq, ' ', (size_t)S.free);
	if (S.color[0])
		pr_colorme(aq, 0);
}
