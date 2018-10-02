/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 22:37:16 by aburdeni          #+#    #+#             */
/*   Updated: 2018/07/31 20:18:50 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_range(int start, int end)
{
	int *tab;
	int size;

	size = start > end ? start - end + 1 : end - start + 1;
	tab = (int*)malloc(sizeof(int) * size);
	if (start > end)
		while (size)
			tab[--size] = start--;
	else
		while (size)
			tab[--size] = start++;
	return (tab);
}
