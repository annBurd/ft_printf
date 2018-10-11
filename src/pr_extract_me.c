/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_extract_me.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 19:27:37 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/11 19:28:20 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	extract_i(t_print *aq, intmax_t t, uintmax_t *ut)
{
	if (!S.length)
		t = va_arg(aq->va, int);
	else if (S.length == h)
		t = (short)va_arg(aq->va, void*);
	else if (S.length == hh)
		t = (signed char)va_arg(aq->va, void*);
	else if (S.length == l)
		t = va_arg(aq->va, long int);
	else if (S.length == ll)
		t = va_arg(aq->va, long long int);
	else if (S.length == j)
		t = va_arg(aq->va, intmax_t);
	else if (S.length == z)
		t = (size_t)va_arg(aq->va, size_t);
	*ut = (uintmax_t)(t < 0 ? t * -1 : t);
	*ut && (S.v = (short)(t < 0 ? -1 : 1));
}

void	extract_ui(t_print *aq, uintmax_t *ut)
{
	if (S.ty == 'p')
		*ut = (uintmax_t)va_arg(aq->va, void*);
	else if (!S.length)
		*ut = va_arg(aq->va, unsigned int);
	else if (S.length == h)
		*ut = (unsigned short)va_arg(aq->va, void*);
	else if (S.length == hh)
		*ut = (unsigned char)va_arg(aq->va, void*);
	else if (S.length == l)
		*ut = va_arg(aq->va, unsigned long int);
	else if (S.length == ll)
		*ut = va_arg(aq->va, unsigned long long int);
	else if (S.length == j)
		*ut = va_arg(aq->va, uintmax_t);
	else if (S.length == z)
		*ut = (size_t)va_arg(aq->va, size_t);
	*ut && (S.v = 1);
}
