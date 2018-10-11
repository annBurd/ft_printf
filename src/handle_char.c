/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:45:03 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/11 21:59:27 by aburdeni         ###   ########.fr       */
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
	S.ty != 's' && (arg = &c);
	S.ty == 's' && (arg = va_arg(aq->va, char*));
	!arg && (arg = "(null)\0");
	if (S.ty != 's' || !*arg)
		S.ln = 1;
	else if (S.prec >= 0)
		S.ln = (size_t)S.prec;
	else
		S.ln = ft_strlen(arg);
	S.free = (short)(S.wi - (short)S.ln < 0 ? 0 : S.wi - S.ln);
	!*arg && (S.wi || S.ty != 's') && S.free++;
	if (!S.minus && S.free)
		pr_join(aq, (S.zero ? '0' : ' '), (size_t)S.free);
	pr_join_str(aq, arg, S.ln);
	if (S.minus && S.free)
		pr_join(aq, ' ', (size_t)S.free);
}

//
//void	handle_c(t_print *aq)
//{
//	char	arg;
//
//	if (S.ty == '%')
//		arg = '%';
//	else if (S.ty == 'c')
//		arg =(char)va_arg(aq->va, int);
////	if (arg == NULL)
////		arg = ft_strcpy(arg, "(null)\0");
//	if (S.ty != 's' || !*arg)
//	S.ln = 1;
//	S.free = (short)(S.wi - (short)S.ln < 0 ? 0 : S.wi - S.ln);
//	!arg && S.wi && S.free++;
//	if (!S.minus && S.free)
//		pr_join(aq, (S.zero ? '0' : ' '), (size_t)S.free);
//	pr_join_str(aq, arg, S.ln);
//	if (S.minus && S.free)
//		pr_join(aq, ' ', (size_t)S.free);
//}

//void	handle_str(t_print *aq)
//{
//	char	*arg;
//
//	arg = va_arg(aq->va, char*);
//	if (!arg)
//		arg = "(null)\0";
//	if (!*arg)
//		S.ln = 1;
//	else if (S.prec >= 0)
//		S.ln = (size_t)S.prec;
//	else
//		S.ln = ft_strlen(arg);
//	S.free = (short)(S.wi - (short)S.ln < 0 ? 0 : S.wi - S.ln);
//	!*arg && S.wi && S.free++;
//	if (!S.minus && S.free)
//		pr_join(aq, (S.zero ? '0' : ' '), (size_t)S.free);
//	pr_join_str(aq, arg, S.ln);
//	if (S.minus && S.free)
//		pr_join(aq, ' ', (size_t)S.free);
//}
