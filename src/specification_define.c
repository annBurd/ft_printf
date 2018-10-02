/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specification_define.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 22:07:41 by aburdeni          #+#    #+#             */
/*   Updated: 2018/09/28 08:12:01 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	set_type(char **line, t_sp *mark)
{
	char c;

	c = **line;
	if (c == 'b' || c == '%' || c == 's' || c == 'S' || c == 'c' || c == 'C'
		|| c == 'd' || c == 'D'	|| c == 'p' || c == 'i' || c == 'o' || c == 'O'
		|| c == 'u' || c == 'U'	|| c == 'x' || c == 'X')
//		|| c == 'e' || c == 'E' || c == 'f' || c == 'F' || c == 'a' || c == 'A'
//		|| c == 'g' || c == 'G' || c == 'n' || c == 'k')
	{
		mark->type = (char) (c == '%' ? 'c' : c);
		(*line)++;
	}
	else
		mark->type = 's';
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
	// (*s == 'L') && (LEN = L);
	if (*s == 'h' || *s == 'l' || *s == 'j' || *s == 'z')	// || *s == 'L')
		(*line)++;
	set_type(line, mark);
}

void	set_num(char **line, t_sp *mark)
{
	if ((**line >= '1' && **line <= '9') || **line == '*')
	{
		mark->width = (short)(**line == '*' ? -1 : ft_atoi(*line));
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

// void	set_color(char **line, t_sp *mark)
// {
// 	char	c;

// 	(*line)++;
// 	c = **line;

// }

void	set_flag(char **line, t_sp *mark)
{
	while (**line == '#' || **line == '0' || **line == '-'
		|| **line == '+' || **line == ' ' || **line == '`')
	{
		(**line == '#') && (mark->hash = 1);
		(**line == '0') && (mark->zero = 1);
		(**line == '-') && (mark->minus = 1);
		(**line == '+') && (mark->plus = 1);
		(**line == ' ') && (mark->spc = 1);
		(**line == '`') && (mark->apost = 1);
		// (**line == '$') && (set_color(line, mark));
		(*line)++;
	}
	set_num(line, mark);
}
