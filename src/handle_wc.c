///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   handle_wc.c                                        :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2018/09/25 21:39:53 by aburdeni          #+#    #+#             */
///*   Updated: 2018/09/28 05:09:03 by aburdeni         ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "../inc/ft_printf.h"
//
//void	get_bytes(t_sp *mark, wchar_t *arg)
//{
//	while (*arg)
//	{
//		if (WS && !PREC)
//			break;
//		if (*arg < 0x80) //128) //2^7 - 1
//			NLEN += 1;
//		else if (*arg < 0x8000) //32767) //2^15 - 1
//			NLEN += 2;
//		else if (*arg < 0x800000) //8388607) //2^23 - 1
//			NLEN += 3;
//		else
//			NLEN += 4;
//		if WC
//			break;
//		arg++;
//	}
//}
//
//void	set_wc(t_sp *mark, char *s, wchar_t arg)
//{
//	int i;
//	short by;
//
//	by = HASH;
//	if (HASH == 4 && (i = arg) && HASH--)
//	{
//		i = i >> 18;
//		i = i | 0xf0;
//		*(s++) = (char)i;
//	}
//	if (HASH == 3 && (i = arg) && HASH--)
//	{
//		by == 4 && (i = i & 0x3f000);
//		i = i >> 12;
//		i = i | (by == 3 ? 0xe0 : 0x80);
//		*(s++) = (char)i;
//	}
//	if (HASH == 2 && (i = arg))
//	{
//		by == 3 && (i = i & 0xfff);
//		by == 4 && (i = i & 0xfc0);
//		i = i >> 6;
//		i = i | (by == 2 ? 0xc0 : 0x80);
//		*(s++) = (char)i;
//		i = arg;
//		i = i & 0x3f;
//		i = i | 0x80;
//		*(s++) = (char)i;
//	}
//}
//
//void	set_bytes(t_sp *mark, char *s, wchar_t *arg)
//{
//	while (*arg)
//	{
//		if (*arg < 0x80)
//			*(s++) = (char)*arg;
//		else if (*arg < 0x8000 && (HASH = 2))
//		{
//			set_wc(mark, s, *arg);
//			s += 2;
//		}
//		else if (*arg < 0x800000 && (HASH = 3))
//		{
//			set_wc(mark, s, *arg);
//			s += 3;
//		}
//		else if (*arg >= 0x800000 && (HASH = 4))
//		{
//			set_wc(mark, s, *arg);
//			s += 4;
//		}
//		if WC
//			break;
//		arg++;
//	}
//}
//
//char	*handle_wc(va_list aq, t_sp *mark, char *out)
//{
//	char	*s;
//	wchar_t wc;
//	wchar_t *arg;
//
//	if (WC && (wc = va_arg(aq, wchar_t)))
//		arg = &wc;
//	WS && (arg = va_arg(aq, wchar_t*));
//	get_bytes(mark, arg);
//	SIZE = NLEN > (size_t)WIDTH ? NLEN : WIDTH;
//	s = (char*)malloc(sizeof(char) + (SIZE + 1));
//	s[SIZE] = 0;
//	SPC = (short)((WIDTH - (short)NLEN) < 0 ? 0 : (WIDTH - (short)NLEN));
//	if (!MINUS && SPC)
//		ft_memset(s, ' ', (size_t)SPC);
//	if (NLEN)
//		set_bytes(mark, s + (MINUS ? 0 : (size_t)SPC), arg);
//	if (MINUS && SPC)
//		ft_memset(s + NLEN, ' ', (size_t)SPC);
//	return (ft_strjoinfree(out, s));
//}
