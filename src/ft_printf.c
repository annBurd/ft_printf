/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:26:16 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/14 00:35:14 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		start_handle(t_print *aq)
{
	if (S.star[0])
	{
		S.wi = va_arg(aq->va, int);
		S.wi < 0 && (S.minus = 1);
		S.wi < 0 && (S.wi *= -1);
	}
	if (S.star[1])
	{
		S.prv = va_arg(aq->va, int);
		S.prv < 0 && S.zero && !S.minus && (S.prv *= -1);
	}
	if (S.ty == 'i' || S.ty == 'd' || S.ty == 'b' || S.ty == 'p'
		S.ty == 'o' || S.ty == 'u' || S.ty == 'x' || S.ty == 'X')
		handle_nbr(aq);
	else if (S.ty == 'c' || S.ty == 'C' || S.ty == '%')
		!S.length && S.ty != 'C' ? handle_c(aq) : handle_wc(aq);
	else if (S.ty == 's' || S.ty == 'S')
		!S.length && S.ty != 'S' ? handle_str(aq) : handle_wstr(aq);
	if (S.color)
		pr_join_str(aq, "\e[0m", 4);
}

static void		explore(t_print *aq, const char *line, const char *point)
{
	while (*line)
	{
		if ((*line == '<' || *line == '>') && *(line + 1) == '!')
		{
			if (line - point > 0)
				pr_join_str(aq, (char*)point, line - point);
			*(line++) == '<' ? pr_color(&line, aq)
							: pr_join_str(aq, "\e[0m", 4);
			point = ++line;
		}
		if (*line == '%')
		{
			if (*point != '%' && line - point > 0)
				pr_join_str(aq, (char*)point, line - point);
			line++;
			define_flags(&line, aq);
			start_handle(aq);
			point = line;
		}
		*line != '%' && line++;
	}
	if (line - point > 0)
		pr_join_str(aq, (char*)point, line - point);
}

int				ft_printf(const char *format, ...)
{
	static t_print	aq;

	ft_bzero(&aq, sizeof(t_print));
	if (format)
	{
		va_start(aq.va, format);
		explore(&aq, format, format);
		va_end(aq.va);
	}
	return (aq.size + write(1, aq.out, aq.i));
}
