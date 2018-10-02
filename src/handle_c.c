///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   handle_c.c                                         :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2018/08/28 17:45:03 by aburdeni          #+#    #+#             */
///*   Updated: 2018/09/27 22:57:31 by aburdeni         ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "../inc/ft_printf.h"
// /* type % doesn't exist !!!11!1 */
//char	*handle_c(va_list aq, t_sp *mark, char *out)
//{
//	char	*s;
//	char	c;
//	char	*arg;
//
//	if ((TY == '%' && (c = TY)) ||
//		(TY == 'c' && (c = (char)va_arg(aq, int))))
//		arg = &c;
//	TY == 's' && (arg = va_arg(aq, char*));
//	TY != 's' && (NLEN = 1);
//	TY == 's' && (NLEN = PREC >= 0 ? PREC : ft_strlen(arg));
//	if ((TY != 's' && WIDTH <= 1) || (TY == 's' && !WIDTH && PREC < 0))
//		return (printf_joinfree(out, arg, NLEN));
//	SIZE = NLEN > (size_t)WIDTH ? NLEN : WIDTH;
//	s = (char*)malloc(sizeof(char) + (SIZE + 1));
//	s[SIZE] = 0;
//	SPC = (short)((WIDTH - (short)NLEN) < 0 ? 0 : (WIDTH - (short)NLEN));
//	if (!MINUS && SPC)
//		ft_memset(s, (TY == '%' && ZERO) ? '0' : ' ', (size_t)SPC);
//	ft_memcpy(s + (MINUS ? 0 : (size_t)SPC), arg, NLEN);
//	if (MINUS && SPC)
//		ft_memset(s + NLEN, ' ', (size_t)SPC);
//	return (ft_strjoinfree(out, s));
//}
