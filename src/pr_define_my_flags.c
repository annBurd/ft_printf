/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_define_my_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 22:07:41 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/14 02:10:02 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	define_type(const char **line, t_print *aq, char q)
{
	(*line)++;
	if ((q == 'i' || q == 'd' || q == 'u') && (S.ty = q))
		S.base = 10;
	else if (q == 'o' && (S.ty = q))
		S.base = 8;
	if (q == 'D' || q == 'U' || q == 'O')
	{
		S.base = q == 'O' ? 8 : 10;
		(l > S.length) && (S.length = l);
		S.ty = (char)ft_tolower(q);
	}
	else if ((q == 'p' || q == 'x' || q == 'X') && (S.ty = q))
		S.base = 16;
	else if (q == 'b' && (S.ty = q))
		S.base = 2;
	else if (q == '%' || q == 'c' || q == 'C' || q == 's' || q == 'S')
		S.ty = q;
	else
	{
		S.ty = 's';
		(*line)--;
	}
}

static void	define_length(const char **line, t_print *aq)
{
	const char	*s;

	s = *line;
	if ((*s == 'h' && (S.length = h)) ||
		(*s == 'l' && (S.length = l)))
	{
		if ((*(s + 1) == *s) && (S.length++))
			(*line)++;
	}
	else if (*s == 'j')
		S.length = j;
	else if (*s == 'z')
		S.length = z;
	if (*s == 'h' || *s == 'l' || *s == 'j' || *s == 'z')
		(*line)++;
	define_type(line, aq, **line);
}

static void	define_num(const char **line, t_print *aq)
{
	if ((**line >= '1' && **line <= '9') || **line == '*')
	{
		if (**line == '*')
			S.star[0] = 1;
		else
			S.wi = ft_atoi(*line);
		while ((**line >= '0' && **line <= '9') || **line == '*')
			(*line)++;
	}
	if (**line == '.')
	{
		S.prec = 1;
		(*line)++;
		if (**line == '*')
			S.star[1] = 1;
		else if (**line >= '1' && **line <= '9')
			S.prv = ft_atoi(*line);
		while ((**line >= '0' && **line <= '9') || **line == '*')
			(*line)++;
	}
	define_length(line, aq);
}

void		define_flags(const char **line, t_print *aq)
{
	ft_bzero(&aq->sp, sizeof(t_sp));
	while (**line == '#' || **line == '0' || **line == '-' || **line == '!'
		|| **line == '+' || **line == ' ' || **line == '\'')
	{
		(**line == '#') && (S.hash = 1);
		(**line == '0') && (S.zero = 1);
		(**line == '-') && (S.minus = 1);
		(**line == '+') && (S.plus = 1);
		(**line == ' ') && (S.spc = 1);
		(**line == '\'') && (S.apost = 1);
		if (**line == '!')
		{
			if (aq->i + 12 >= BUFSIZE)
				pr_refresh(aq);
			S.color = 1;
			pr_color(line, aq);
		}
		(*line)++;
	}
	define_num(line, aq);
}
