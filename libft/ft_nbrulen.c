/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrulen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 19:45:23 by aburdeni          #+#    #+#             */
/*   Updated: 2018/09/04 19:45:26 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrulen(uintmax_t value, int base)
{
	size_t	size;

	size = 1;
	while (value / base)
	{
		value /= base;
		size++;
	}
	return (size);
}
