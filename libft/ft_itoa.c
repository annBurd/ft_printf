/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:57:42 by aburdeni          #+#    #+#             */
/*   Updated: 2017/11/04 17:02:04 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*pn(char *s, int n, int t)
{
	unsigned int	ui;

	ui = (n < 0) ? -n : n;
	s[t--] = '\0';
	if (ui == 0)
		s[t] = '0';
	while (ui > 0)
	{
		s[t--] = ui % 10 + 48;
		ui /= 10;
		if (n < 0 && t == 0)
			s[t] = '-';
	}
	return (s);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*res;

	i = ft_nbrlen(n, 10);
	if (!(res = ft_strnew(i)))
		return (NULL);
	res = pn(res, n, i);
	return (res);
}
