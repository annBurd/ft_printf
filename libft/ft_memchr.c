/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:40:25 by aburdeni          #+#    #+#             */
/*   Updated: 2017/11/21 18:40:06 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *ss;

	ss = (const unsigned char*)s;
	while (n--)
	{
		if (*ss == (unsigned char)c)
			return ((void*)ss);
		ss++;
	}
	return (NULL);
}
