/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:13:30 by aburdeni          #+#    #+#             */
/*   Updated: 2017/12/15 22:13:33 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	char *fresh;

	fresh = dst;
	if (n == 0)
		return (dst);
	while (*dst)
		dst++;
	while (*src && n > 0)
	{
		*(dst++) = *(src++);
		n--;
	}
	*dst = 0;
	return (fresh);
}
