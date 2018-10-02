/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:16:44 by aburdeni          #+#    #+#             */
/*   Updated: 2017/12/15 22:16:46 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	char *fresh;

	fresh = dst;
	while (*dst)
		dst++;
	while (*src)
		*(dst++) = *(src++);
	*dst = 0;
	return (fresh);
}
