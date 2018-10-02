/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omashkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:28:52 by omashkov          #+#    #+#             */
/*   Updated: 2017/11/02 14:23:57 by omashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long	i;
	long	n;
	char	*str;
	int		flag;

	flag = 0;
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
