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

static void	define_type(t_print *aq, const char **line, char q)
{
	(*line)++;
	if (q == '%' || q == 'c' || q == 'C' || q == 's' || q == 'S' ||
		q == 'i' || q == 'd' || q == 'D' || q == 'p' || q == 'x' || q == 'X')
		S.ty = q;
	else if ((q == 'u') && (S.ty = q))
		S.base = 10;
	else if (q == 'o' && (S.ty = q))
		S.base = 8;
	else if (q == 'U' || q == 'O')
	{
		S.base = q == 'O' ? 8 : 10;
		(l > S.length) && (S.length = l);
		S.ty = (char)ft_tolower(q);
	}
	else if (q == 'b' && (S.ty = q))
		S.base = 2;
	else
	{
		S.ty = 's';
		(*line)--;
	}
}

static void	define_length(t_print *aq, const char **line, char *s)
{
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
	define_type(aq, line, **line);
}

static void	define_num(t_print *aq, va_list va, const char **line)
{
	if ((**line >= '1' && **line <= '9') || **line == '*')
	{
		if (**line == '*')
			S.wi = va_arg(va, int);
		else
			S.wi = ft_atoi(*line);
		S.wi < 0 && (S.minus = 1);
		S.wi < 0 && (S.wi *= -1);
		while ((**line >= '0' && **line <= '9') || **line == '*')
			(*line)++;
	}
	if (**line == '.')
	{
		S.prec |= 1;
		(*line)++;
		if (**line == '*')
			S.prv = va_arg(va, int);
		else if (**line >= '1' && **line <= '9')
			S.prv = ft_atoi(*line);
		S.prv < 0 && S.zero && !S.minus && (S.prv *= -1);
		while ((**line >= '0' && **line <= '9') || **line == '*')
			(*line)++;
	}
	define_length(aq, line, (char*)*line);
}

void		define_flags(t_print *aq, va_list va, const char **line)
{
	ft_bzero(&aq->sp, sizeof(t_sp));
	while (**line == '#' || **line == '0' || **line == '-' || **line == '!'
		|| **line == '+' || **line == ' ' || **line == '\'')
	{
		if (**line == '#')
			S.hash |= 1;
		else if (**line == '0')
			S.zero |= 1;
		else if (**line == '-')
			S.minus |= 1;
		else if (**line == '+')
			S.plus |= 1;
		else if (**line == ' ')
			S.spc |= 1;
		else if (**line == '\'')
			S.apost |= 1;
		else if (**line == '!')
		{
			S.color |= 1;
			pr_color(aq, line);
		}
		(*line)++;
	}
	define_num(aq, va, line);
}
