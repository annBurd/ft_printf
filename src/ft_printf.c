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

static void		start_handle(t_print *aq, va_list va)
{
	if (S.ty == 'i' || S.ty == 'd' || S.ty == 'D')
		handle_id(aq, extract_i(aq, va));
	else if (S.ty == 'o' || S.ty == 'u' || S.ty == 'b')
		handle_oub(aq, extract_ui(aq, va));
	else if (S.ty == 'p' || S.ty == 'x' || S.ty == 'X')
		handle_xp(aq, extract_ui(aq, va));
	else if (S.ty == 'c' || S.ty == 'C')
		handle_c(aq, (wchar_t)va_arg(va, int));
	else if (S.ty == '%')
		handle_c(aq, '%');
	else if (S.ty == 's' && !S.length)
		handle_s(aq, va_arg(va, char*));
	else if (S.ty == 's' || S.ty == 'S')
		handle_ws(aq, va_arg(va, wchar_t*));
	if (S.color)
		pr_join_str(aq, "\e[0m", 4);
}

static void		explore(t_print *aq, va_list va,
						const char *line, const char *point)
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
			define_flags(aq, va, &line);
			start_handle(aq, va);
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
	va_list			va;

	aq.i = 0;
	aq.size = 0;
	ft_bzero(&aq.out, PR_BUF_SIZE);
	if (format)
	{
		va_start(va, format);
		explore(&aq, va, format, format);
		va_end(va);
	}
	return (aq.size + write(1, aq.out, aq.i));
}
