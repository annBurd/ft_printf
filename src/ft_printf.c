/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:26:16 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/13 19:10:02 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		start_handle(t_print *aq)
{
	(S.wi == -1) && (S.wi = (short)va_arg(aq->va, int));
	(S.prec == -1) && (S.prec = (short)va_arg(aq->va, int));
	if (S.ty == 'i' || S.ty == 'd' || S.ty == 'D' || S.ty == 'b' ||
		S.ty == 'o' || S.ty == 'O' || S.ty == 'u' || S.ty == 'U' ||
		S.ty == 'x' || S.ty == 'X' || S.ty == 'p')
		handle_i(aq);
	else if (S.ty == 'c' || S.ty == 'C' || S.ty == '%')
		!S.length ? handle_c(aq) : handle_wc(aq);
	else if (S.ty == 's' || S.ty == 'S')
		!S.length ? handle_str(aq) : handle_wstr(aq);
	if (S.color)
		pr_join_str(aq, "\e[0m", 4);
}

void		explore(t_print *aq, const char *line, const char *point)
{
	while (*line)
	{
		if ((*line == '<' || *line == '>') && *(line + 1) == '!')
		{
			if (line - point > 0)
				pr_join_str(aq, (char*)point, line - point);
			*(line++) == '<' ? set_color(&line, aq)
							: pr_join_str(aq, "\e[0m", 4);
			point = ++line;
		}
		if (*line == '%')
		{
			if (*point != '%' && line - point > 0)
				pr_join_str(aq, (char*)point, line - point);
			line++;
			set_flag(&line, aq);
			start_handle(aq);
			point = line;
		}
		*line != '%' && line++;
	}
	if (line - point > 0)
		pr_join_str(aq, (char*)point, line - point);
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
	return (aq.size + write(1, aq.out, aq.i));
}
