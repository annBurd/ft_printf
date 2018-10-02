/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:12:37 by aburdeni          #+#    #+#             */
/*   Updated: 2017/11/27 17:12:39 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (n)
	{
		if (*str1 != *str2 || *str1 == 0 || *str2 == 0)
			return (*str1 - *str2);
		str1++;
		str2++;
		n--;
	}
	return (0);
}
