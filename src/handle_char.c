/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:45:03 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/10 03:01:51 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	handle_c(t_print *aq)
{
	char	arg;

	if (S.ty == '%')
		arg = '%';
	else
		arg = (char)va_arg(aq->va, int);
	S.ln = 1;
	S.free = (short)(S.wi - (short)S.ln < 0 ? 0 : S.wi - S.ln);
	if (!S.minus && S.free)
		pr_join(aq, (char)(S.ty == '%' && S.zero ? '0' : ' '), (size_t)S.free);
	pr_join(aq, arg, S.ln);
	if (S.minus && S.free)
		pr_join(aq, ' ', (size_t)S.free);
	if (S.color)
		pr_join_str(aq, "\e[0m", 4);
}

void	handle_str(t_print *aq)
{
	char	*arg;

	arg = va_arg(aq->va, char*);
	S.ln = S.prec >= 0 ? S.prec : ft_strlen(arg);
	S.free = (short)(S.wi - (short)S.ln < 0 ? 0 : S.wi - S.ln);
	if (!S.minus && S.free)
		pr_join(aq, ' ', (size_t)S.free);
	pr_join_str(aq, arg, S.ln);
	if (S.minus && S.free)
		pr_join(aq, ' ', (size_t)S.free);
	if (S.color)
		pr_join_str(aq, "\e[0m", 4);
}
