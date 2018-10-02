/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:44:00 by aburdeni          #+#    #+#             */
/*   Updated: 2017/11/21 17:45:06 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *str1;
	const unsigned char *str2;

	if (s1 == s2 || n == 0)
		return (0);
	str1 = (const unsigned char*)s1;
	str2 = (const unsigned char*)s2;
	while (n--)
	{
		if (*(str1++) != *(str2++))
			return (*(str1 - 1) - *(str2 - 1));
	}
	return (0);
}
