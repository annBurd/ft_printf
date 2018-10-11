/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_define_my_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 22:07:41 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/11 17:43:53 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	set_type(const char **line, t_sp *mark)
{
	char	q;

	q = **line;
	if (q == '%' || q == 'p' || q == 's' || q == 'S' || q == 'c' || q == 'C' ||
		q == 'i' || q == 'd' || q == 'D' || q == 'o' || q == 'O' || q == 'b' ||
		q == 'u' || q == 'U' || q == 'x' || q == 'X')
	{
		mark->ty = q;
		(*line)++;
	}
	else
		mark->ty = 's';
}

void	set_length(const char **line, t_sp *mark)
{
	const char	*s;

	s = *line;
	if ((*s == 'h' && (mark->length = h)) ||
		(*s == 'l' && (mark->length = l)))
		if ((*(s + 1) == *s) && (mark->length++))
			(*line)++;
	(*s == 'j') && (mark->length = j);
	(*s == 'z') && (mark->length = z);
	if (*s == 'h' || *s == 'l' || *s == 'j' || *s == 'z')
		(*line)++;
	set_type(line, mark);
}

void	set_num(const char **line, t_sp *mark)
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
		while ((**line >= '0' && **line <= '9') || **line == '*')
			(*line)++;
	}
	else
		mark->prec = -2;
	set_length(line, mark);
}

void	set_flag(const char **line, t_print *aq)
{
	ft_bzero(&aq->sp, sizeof(t_sp));
	while (**line == '#' || **line == '0' || **line == '-' || **line == '!'
		|| **line == '+' || **line == ' ' || **line == '`')
	{
		(**line == '#') && (S.hash = 1);
		(**line == '0') && (S.zero = 1);
		(**line == '-') && (S.minus = 1);
		(**line == '+') && (S.plus = 1);
		(**line == ' ') && (S.spc = 1);
		(**line == '`') && (S.apost = 1);
		if (**line == '!')
		{
			if (aq->i + 12 >= BUFS)
				pr_refresh(aq);
			S.color = 1;
			set_color(line, aq);
		}
		(*line)++;
	}
	set_num(line, &aq->sp);
}
