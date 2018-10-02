/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:37:51 by aburdeni          #+#    #+#             */
/*   Updated: 2017/12/05 19:37:54 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *fresh;

	if (!(fresh = (char*)malloc(size + 1)))
		return (NULL);
	return (ft_memset(fresh, 0, size + 1));
}
