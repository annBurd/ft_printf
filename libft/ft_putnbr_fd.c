/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:04:01 by aburdeni          #+#    #+#             */
/*   Updated: 2017/11/01 17:04:05 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int i;

	i = (n < 0) ? -n : n;
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (i > 9)
		ft_putnbr_fd(i / 10, fd);
	ft_putchar_fd(i % 10 + 48, fd);
}
