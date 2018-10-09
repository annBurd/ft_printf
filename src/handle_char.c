/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:45:03 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/09 21:00:22 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	handle_c(t_print *aq)
{
	char	c;
	char	*arg;

	c = 0;
	if (S.ty == '%' || S.ty == 'c')
		c = (char)(S.ty == '%' ? '%' : va_arg(aq->va, int));
	c && (arg = &c);
	S.ty == 's' && (arg = va_arg(aq->va, char*));
	S.ty != 's' && (S.ln = 1);
	S.ty == 's' && (S.ln = S.prec >= 0 ? S.prec : ft_strlen(arg));
	if ((size_t)S.wi <= S.ln)
		return (pr_join_str(aq, arg, S.ln));
	S.free = (short)(S.wi - (short)S.ln < 0 ? 0 : S.wi - S.ln);
	if (!S.minus && S.free)
		pr_join(aq, (char)(S.ty == '%' && S.zero ? '0' : ' '), (size_t)S.free);
	pr_join_str(aq, arg, S.ln);
	if (S.minus && S.free)
		pr_join(aq, ' ', (size_t)S.free);
}
