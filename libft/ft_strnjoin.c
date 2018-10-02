/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 19:11:50 by aburdeni          #+#    #+#             */
/*   Updated: 2018/08/13 19:11:52 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*fresh;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s2) < n ? ft_strlen(s2) : n;
	if (!(fresh = (char*)malloc(ft_strlen(s1) + i + 1)))
		return (NULL);
	i = 0;
	while (*s1)
		fresh[i++] = *(s1++);
	while (*s2 && n-- > 0)
		fresh[i++] = *(s2++);
	fresh[i] = 0;
	return (fresh);
}
