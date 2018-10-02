/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:11:44 by aburdeni          #+#    #+#             */
/*   Updated: 2017/11/27 17:11:47 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	lens2;

	if (*s2 == 0)
		return ((char *)s1);
	lens2 = ft_strlen(s2);
	while (*s1 && n-- >= lens2)
	{
		if (*s1 == *s2 && ft_memcmp(s1, s2, lens2) == 0)
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
