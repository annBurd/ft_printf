/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omashkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:23:54 by omashkov          #+#    #+#             */
/*   Updated: 2017/11/07 13:32:26 by omashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	if (s != NULL)
		size = ft_strlen(s);
	if ((str = ft_strnew(size)))
	{
		while (i < size)
		{
			if ((str[i] = f(i, (char)s[i])))
				i++;
		}
		return (str);
	}
	return (NULL);
}
