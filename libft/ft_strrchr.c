/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 18:43:55 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/31 18:44:03 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long	i;
	long	n;
	char	*str;

	str = (char*)s;
	i = 0;
	n = -1;
	if (c == '\0')
		return (&str[ft_strlen(s)]);
	while (1)
	{
		if (str[i] == c || str[i])
		{
			if (str[i] == c)
				n = i;
		}
		else
			break ;
		i++;
	}
	if (n != -1)
		return (&str[n]);
	return (NULL);
}
