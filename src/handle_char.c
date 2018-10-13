/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:45:03 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/13 19:51:44 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	handle_c(t_print *aq)
{
	char	arg;

	arg = 0;
	if (S.ty == '%')
		arg = '%';
	else if (S.ty == 'c')
		arg =(char)va_arg(aq->va, int);
	S.ln = 1;
	S.free = (short)(S.wi - (short)S.ln < 0 ? 0 : S.wi - S.ln);
	if (!S.minus && S.free)
		pr_join(aq, (char)(S.zero ? '0' : ' '), (size_t)S.free);
	pr_join(aq, arg, S.ln);
	if (S.minus && S.free)
		pr_join(aq, ' ', (size_t)S.free);
}

void	handle_str(t_print *aq)
{
	char	*arg;

	arg = va_arg(aq->va, char*);
	if (!arg)
		arg = "(null)\0";
	if (!*arg)
		S.ln = 1;
	else
		S.ln = ft_strlen(arg);
	if (S.prec >= 0 && (size_t)S.prec < S.ln)
		S.ln = (size_t)S.prec;
	S.free = (short)(S.wi - (short)S.ln < 0 ? 0 : S.wi - S.ln);
	!*arg && S.wi && S.free++;
	if (!S.minus && S.free)
		pr_join(aq, (char)(S.zero ? '0' : ' '), (size_t)S.free);
	pr_join_str(aq, arg, S.ln);
	if (S.minus && S.free)
		pr_join(aq, ' ', (size_t)S.free);
}
