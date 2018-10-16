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
	if (S.ty == 'i' || S.ty == 'd' || S.ty == 'D')
		handle_id(aq, extract_i(aq));
	else if (S.ty == 'o' || S.ty == 'u' || S.ty == 'b')
		handle_oub(aq, extract_ui(aq));
	else if (S.ty == 'p' || S.ty == 'x' || S.ty == 'X')
		handle_xp(aq, extract_ui(aq));
	else if (S.ty == 'c' || S.ty == 'C')
		handle_c(aq, (wchar_t)va_arg(aq->va, int));
	else if (S.ty == '%')
		handle_c(aq, '%');
	else if (S.ty == 's')
		handle_s(aq, va_arg(aq->va, char*));
	else if (S.ty == 'S')
		handle_ws(aq, va_arg(aq->va, wchar_t*));
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
			*(line++) == '<' ? pr_color(aq, &line)
							: pr_join_str(aq, "\e[0m", 4);
			point = ++line;
		}
		if (*line == '%')
		{
			if (*point != '%' && line - point > 0)
				pr_join_str(aq, (char*)point, line - point);
			line++;
			define_flags(aq, &line);
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

	aq.i = 0;
	aq.size = 0;
	ft_bzero(&aq.out, BUFSIZE);
	if (format)
	{
		va_start(aq.va, format);
		explore(&aq, format, format);
		va_end(aq.va);
	}
	return (aq.size + write(1, aq.out, aq.i));
}
