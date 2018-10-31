/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 18:43:18 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/31 18:43:28 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	long	j;
	long	n;
	size_t	sum;

	j = 0;
	i = ft_strlen(dst);
	if (dstsize <= ft_strlen(dst))
		sum = dstsize + ft_strlen(src);
	else
		sum = ft_strlen(dst) + ft_strlen(src);
	n = dstsize - ft_strlen(dst);
	while ((j < (n - 1)) && src[j])
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = 0;
	return (sum);
}
