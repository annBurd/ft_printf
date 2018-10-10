/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:26:16 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/10 05:31:33 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		start_handle(t_print *aq)
{
	(S.wi == -1) && (S.wi = (short)va_arg(aq->va, int));
	(S.prec == -1) && (S.prec = (short)va_arg(aq->va, int));
	if (S.ty == 'D' || DEC || HEX ||
		S.ty == 'o' || S.ty == 'O' || S.ty == 'b' ||
		S.ty == 'u' || S.ty == 'U' || S.ty == 'p')
		handle_i(aq);
	else if (S.ty == '%' || (!S.length && (S.ty == 'c' || S.ty == 's')))
		handle_c(aq);
	else if (S.ty == 'C' || S.ty == 'S' ||
		(S.length == l && (S.ty == 'c' || S.ty == 's')))
		handle_wc(aq);
}

void		explore(t_print *aq, const char *line, const char *point)
{
	while (*line)
	{
		if (*line == '<' || *line == '>')
		{
			if (line - point > 0)
				pr_join_str(aq, (char*)point, line - point);
			*line == '<' ? set_color(&line, aq) : pr_join_str(aq, "\e[0m", 4);
			point = ++line;
		}
		if (*line == '%')
		{
			if (line - point > 0)
				pr_join_str(aq, (char*)point, line - point);
			line++;
			set_flag(&line, &aq->sp, aq);
			start_handle(aq);
			point = line;
		}
		if (!*(line + 1) && line - point > 0)
			pr_join_str(aq, (char*)point, line - point);
		if (!*line)
			break ;
		line++;
	}
}

int			ft_printf(const char *format, ...)
{
	static t_print	aq;

	ft_bzero(&aq, sizeof(t_print));
	if (format)
	{
		va_start(aq.va, format);
		explore(&aq, format, format);
		va_end(aq.va);
	}
	aq.size += write(1, aq.out, aq.i) + write(1, "\n", 1);
	return (aq.size);
}
