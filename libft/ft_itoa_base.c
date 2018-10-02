/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 21:09:56 by aburdeni          #+#    #+#             */
/*   Updated: 2018/07/17 21:10:05 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		*ft_itoa_base(intmax_t value, short base)
{
	char	*str;
	size_t	len;
	short	minus;
	short	left;

	if (value < 0 && base != 10)
		return (0);
	minus = 1;
	if ((value < 0 && base == 10) && !(minus = 0))
		value *= -1;
	len = ft_nbrlen(value, base);
	str = (char*)malloc(sizeof(char) * (len + 1));
	str[len--] = 0;
	while (value != 0)
	{
		left = value % base;
		value /= base;
		str[len--] = left + (left < 10 ? '0' : 'A' - 10);
		if (minus == 0 && len == 0)
			str[len] = '-';
	}
	return (str);
}
