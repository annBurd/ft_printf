/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omashkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:34:17 by omashkov          #+#    #+#             */
/*   Updated: 2017/11/06 20:44:39 by omashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	size;
	size_t	i;

	i = 0;
	if (!s || !f)
		return ;
	if (s)
	{
		size = ft_strlen(s);
		while (i < size)
		{
			f(i, s++);
			i++;
		}
	}
}
