/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 18:44:55 by aburdeni          #+#    #+#             */
/*   Updated: 2018/08/28 18:44:58 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_base(const char *s, short base)
{
	int		res;
	int		minus;
	int		size;
	char	ch;

	minus = 1;
	while (*s < 33)
		s++;
	if (*s == '-' || *s == '+')
		(*s++ == '-') && (minus = -1);
	size = ft_strlen(s);
	res = 0;
	while (*s && size--)
	{
		if (((*s >= '0' && *s <= '9') && (ch = '0'))
		|| ((*s >= 'a' && *s <= 'f') && (ch = 87))
		|| ((*s >= 'A' && *s <= 'F') && (ch = 55)))
			res += (*s - ch) * ft_pow(base, size);
		else
			return (res * minus);
		s++;
	}
	return (res * minus);
}
