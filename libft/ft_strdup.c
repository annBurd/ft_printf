/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:48:21 by aburdeni          #+#    #+#             */
/*   Updated: 2017/11/21 19:57:47 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;

	if (!(d = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	ft_strcpy(d, s);
	return (d);
}
