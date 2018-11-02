/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_refresh_me.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:26:59 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/14 01:23:47 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			pr_refresh(t_print *aq)
{
	aq->size += write(1, aq->out, (unsigned int)aq->i);
	ft_bzero(aq->out, sizeof(aq->i));
	aq->i = 0;
}

static size_t	pr_overflow_str(t_print *aq, char *s, size_t *n)
{
	const size_t	t = *n > BUFSIZE ? *n - BUFSIZE : *n;

	if (*n > BUFSIZE)
		pr_join_str(aq, s, t);
	pr_refresh(aq);
	if (*n <= BUFSIZE)
		pr_join_str(aq, s, t);
	*n -= t;
	return (t);
}

static void		pr_overflow(t_print *aq, char c, size_t *n)
{
	const size_t	t = *n > BUFSIZE ? *n - BUFSIZE : *n;

	if (*n > BUFSIZE)
		pr_join(aq, c, t);
	pr_refresh(aq);
	if (*n <= BUFSIZE)
		pr_join(aq, c, t);
	*n -= t;
}

void			pr_join_str(t_print *aq, char *s, size_t n)
{
	if (aq->i + n >= BUFSIZE)
		s += pr_overflow_str(aq, s, &n);
	while (*s && n--)
		aq->out[aq->i++] = *(s++);
}

void			pr_join(t_print *aq, char c, size_t n)
{
	if (aq->i + n >= BUFSIZE)
		pr_overflow(aq, c, &n);
	while (n--)
		aq->out[aq->i++] = c;
}
