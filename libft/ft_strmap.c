/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omashkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:44:49 by omashkov          #+#    #+#             */
/*   Updated: 2017/11/24 18:13:23 by omashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	if (f)
	{
		if (s != NULL)
			size = ft_strlen(s);
		if ((str = ft_strnew(size)))
		{
			while (i < size)
			{
				if ((str[i] = f((char)s[i])))
					i++;
			}
			return (str);
		}
	}
	return (NULL);
}
