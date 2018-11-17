/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:28:23 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/17 15:31:31 by aburdeni         ###   ########.fr       */
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
	const size_t	t = *n > PRF_BUF_SIZE ? *n - PRF_BUF_SIZE : *n;

	if (*n > PRF_BUF_SIZE)
		pr_join_str(aq, s, t);
	pr_refresh(aq);
	if (*n <= PRF_BUF_SIZE)
		pr_join_str(aq, s, t);
	*n -= t;
	return (t);
}

static void		pr_overflow(t_print *aq, char c, size_t *n)
{
	const size_t	t = *n > PRF_BUF_SIZE ? *n - PRF_BUF_SIZE : *n;

	if (*n > PRF_BUF_SIZE)
		pr_join(aq, c, t);
	pr_refresh(aq);
	if (*n <= PRF_BUF_SIZE)
		pr_join(aq, c, t);
	*n -= t;
}

void			pr_join_str(t_print *aq, char *s, size_t n)
{
	if (aq->i + n >= PRF_BUF_SIZE)
		s += pr_overflow_str(aq, s, &n);
	while (*s && n--)
		aq->out[aq->i++] = *(s++);
}

void			pr_join(t_print *aq, char c, size_t n)
{
	if (aq->i + n >= PRF_BUF_SIZE)
		pr_overflow(aq, c, &n);
	while (n--)
		aq->out[aq->i++] = c;
}
