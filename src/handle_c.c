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
	unsigned char	c;
	unsigned char	*arg;

	c = 0;
	if (S.ty == '%' || S.ty == 'c')
		c = (unsigned char)(S.ty == '%' ? '%' : va_arg(aq->va, int));
	c && (arg = &c);
	S.ty == 's' && (arg = va_arg(aq->va, char*));
	S.ty != 's' && (S.ln = 1);
	S.ty == 's' && (S.ln = PREC >= 0 ? PREC : ft_strlen((char*)arg));
	if ((size_t)WIDTH <= S.ln)
		return (pr_join_str(aq, arg, S.ln));
	S.free = (short)(WIDTH - S.ln < 0 ? 0 : WIDTH - S.ln);
	if (!S.minus && S.free)
		pr_join(aq, (unsigned char)
			(S.ty == '%' && S.zero ? '0' : ' '), (size_t)S.free);
	pr_join_str(aq, arg, S.ln);
	if (S.minus && S.free)
		pr_join(aq, ' ', (size_t)S.free);
}
