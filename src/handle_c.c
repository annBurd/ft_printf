/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:45:03 by aburdeni          #+#    #+#             */
/*   Updated: 2018/09/27 22:57:31 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	handle_c(t_print *aq)
{
	char	c;
	char	*arg;

	if ((S.ty == '%' && (c = S.ty)) ||
		(S.ty == 'c' && (c = (char)va_arg(aq->va, int))))
		arg = &c;
	S.ty == 's' && (arg = va_arg(aq->va, char*));
	S.ty != 's' && (S.ln = 1);
	S.ty == 's' && (S.ln = PREC >= 0 ? PREC : ft_strlen(arg));
	if ((size_t)WIDTH <= S.ln)
		return (pr_join(aq, arg, S.ln));
	S.free = (short)(WIDTH - S.ln < 0 ? 0 : WIDTH - S.ln);
	if (!S.minus && S.free)
		pr_set(aq, (char)(S.ty == '%' && S.zero ? '0' : ' '), (size_t)S.free);
	pr_join(aq, arg, S.ln);
	if (S.minus && S.free)
		pr_set(aq, ' ', (size_t)S.free);
}
