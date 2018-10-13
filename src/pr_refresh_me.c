/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_refresh_me.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:26:59 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/11 17:00:27 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	pr_refresh(t_print *aq)
{
	aq->size += write(1, aq->out, (unsigned int)aq->i);
	ft_bzero(aq->out, sizeof(aq->i));
	aq->i = 0;
}

size_t	pr_overflow_str(t_print *aq, char *s, size_t *n)
{
	const size_t	t = *n > BUFS ? *n - BUFS : *n;

	if (*n > BUFS)
		pr_join_str(aq, s, t);
	pr_refresh(aq);
	if (*n <= BUFS)
		pr_join_str(aq, s, t);
	*n -= t;
	return (t);
}

void	pr_overflow(t_print *aq, char c, size_t *n)
{
	const size_t	t = *n > BUFS ? *n - BUFS : *n;

	if (*n > BUFS)
		pr_join(aq, c, t);
	pr_refresh(aq);
	if (*n <= BUFS)
		pr_join(aq, c, t);
	*n -= t;
}
