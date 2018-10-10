/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_specification.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 22:07:41 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/10 02:25:48 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	set_type(char **line, t_sp *mark)
{
	char c;

	c = **line;
	if (c == '%' || c == 'p' || c == 's' || c == 'S' || c == 'c' || c == 'C'
		|| c == 'i' || c == 'd' || c == 'D' || c == 'o' || c == 'O' || c == 'b'
		|| c == 'u' || c == 'U' || c == 'x' || c == 'X')
	{
		mark->ty = c;
		(*line)++;
	}
	else
		mark->ty = 's';
}

void	set_length(char **line, t_sp *mark)
{
	char *s;

	s = *line;
	if ((*s == 'h' && (mark->length = h))
		|| (*s == 'l' && (mark->length = l)))
		if ((*(s + 1) == *s) && (mark->length++))
			(*line)++;
	(*s == 'j') && (mark->length = j);
	(*s == 'z') && (mark->length = z);
	if (*s == 'h' || *s == 'l' || *s == 'j' || *s == 'z')
		(*line)++;
	set_type(line, mark);
}

void	set_num(char **line, t_sp *mark)
{
	if ((**line >= '1' && **line <= '9') || **line == '*')
	{
		mark->wi = (short)(**line == '*' ? -1 : ft_atoi(*line));
		while ((**line >= '0' && **line <= '9') || **line == '*')
			(*line)++;
	}
	if (**line == '.')
	{
		(*line)++;
		if (**line == '*')
			mark->prec = -1;
		else if (**line >= '1' && **line <= '9')
			mark->prec = (short)ft_atoi(*line);
		else if (**line >= '0' || !ft_isdigit(*(*line + 1)))
			mark->prec = 0;
		while ((**line >= '0' && **line <= '9') || **line == '*')
			(*line)++;
	}
	else
		mark->prec = -2;
	set_length(line, mark);
}

void	set_color(char **line, t_sp *mark, t_print *aq, size_t n)
{
	mark->color = 1;
	aq->out[aq->i++] = '\e';
	aq->out[aq->i++] = '[';
	if (*(++(*line)) == '1')
		pr_join_str(aq, "1;", 2);
	if (*(++(*line)) == '0')
		(*line)++;
	else if (**line >= '1' && **line <= '8')
	{
		n = (size_t)(*((*line)++) - 19);
		if (**line == 'b' && (n += 60))
			(*line)++;
		pr_itoa(aq, n);
		aq->out[aq->i++] = ';';
	}
	if (**line >= '1' && **line <= '8')
	{
		n = (size_t)(**line - 9);
		if (*(*line + 1) == 'b' && (n += 60))
			(*line)++;
		pr_itoa(aq, n);
	}
	aq->out[aq->i++] = 'm';
}

void	set_flag(char **line, t_sp *mark, t_print *aq)
{
	mark->base = 10;
	while (**line == '#' || **line == '0' || **line == '-' || **line == '!'
		|| **line == '+' || **line == ' ' || **line == '`')
	{
		(**line == '#') && (mark->hash = 1);
		(**line == '0') && (mark->zero = 1);
		(**line == '-') && (mark->minus = 1);
		(**line == '+') && (mark->plus = 1);
		(**line == ' ') && (mark->spc = 1);
		(**line == '`') && (mark->apost = 1);
		if (**line == '!')
		{
			if (aq->i + 12 >= BUFS)
				pr_refresh(aq);
			set_color(line, mark, aq, 0);
		}
		(*line)++;
	}
	set_num(line, mark);
}