/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoinfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 18:05:00 by aburdeni          #+#    #+#             */
/*   Updated: 2018/09/08 22:01:40 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*delret(char *s1, char *s2)
{
	free(s2);
	return (s1);
}

char		*ft_strnjoinfree(char *s1, char *s2, size_t n)
{
	char	*fresh;
	char	*s;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	if (!n)
		return (delret(s1, s2));
	i = 0;
	s = s1;
	while (*(s++) && ++i)
		;
	if (!(fresh = (char*)malloc(sizeof(char) * (i + n + 1))))
		return (NULL);
	i = 0;
	s = s1;
	while (*s)
		fresh[i++] = *(s++);
	free(s1);
	s = s2;
	while (*s && n-- > 0)
		fresh[i++] = *(s++);
	fresh[i] = 0;
	free(s2);
	return (fresh);
}
