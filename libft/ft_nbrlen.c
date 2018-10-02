/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 20:26:51 by aburdeni          #+#    #+#             */
/*   Updated: 2018/07/17 20:26:56 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(intmax_t value, int base)
{
	size_t	size;

	size = 1;
	while (value / base)
	{
		value /= base;
		size++;
	}
	return (value < 0) ? size + 1 : size;
}
