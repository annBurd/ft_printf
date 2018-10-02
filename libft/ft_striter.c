/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omashkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:49:01 by omashkov          #+#    #+#             */
/*   Updated: 2017/11/06 20:39:04 by omashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
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
			f(&s[i]);
			i++;
		}
	}
}
