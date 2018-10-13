/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_color_me.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:37:22 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/11 17:57:58 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
** ___ Format in str
** >>> in string
** ft_printf("<![modify];[foreground color];[background color]!koko>!\n");
** >>> w/ %
** ft_printf("%![modify];[foreground color];[background color]!s\n", "koko");
** ___ Modes
** m - set modify
** M - reset modify
** f - usual foreground
** F - bright version of foreground
** b - usual background
** B - bright version of background
** ___ Modifies
** [m/M]0 - Turn off all modifies
** [m/M]b - set/reset Bold
** [m/M]d - set/reset Dim
** [m/M]i - set/reset Italic
** [m/M]u - set/reset Underline
** [m/M]r - set/reset Reverse/Invert
** ___ Colors
** [f/b]B - black
** [f/b]r - red
** [f/b]g - green
** [f/b]y - yellow
** [f/b]b - blue
** [f/b]p - purple
** [f/b]c - cyan
** [f/b]w - white
** [F/B]B - dark gray
** [F/B]r - bright red
** [F/B]g - bright green
** [F/B]y - bright yellow
** [F/B]b - bright blue
** [F/B]p - bright purple
** [F/B]c - bright cyan
** [F/B]w - bright white
** ___ Examples
**	<!m1;Fr;bB!koko & other text will have the same color>!
**	%!m1;Fr;bB!koko will be the only colored word
**	<!mb!koko>!
**	<!fR;Bw!koko>!
**	<!mi;fg!koko>!
**	<!mu;Fr;bw;koko>!
**	<!md;Fr;bB!koko>!
*/

static void	set_mod_code(t_print *aq, char mod, char value)
{
	size_t code;

	if (!value)
		code = 0;
	else if (value == 'b')
		code = 1;
	else if (value == 'd')
		code = 2;
	else if (value == 'i')
		code = 3;
	else if (value == 'u')
		code = 4;
	else if (value == 'r')
		code = 7;
	else
		code = 0;
	if (mod == 'M' && value)
		code += 20;
	pr_utoa(aq, code, 10);
	aq->out[aq->i++] = ';';
}

static void	set_color_code(t_print *aq, char mod, char value)
{
	size_t code;

	code = 30;
	if (mod == 'F')
		code = 90;
	else if (mod == 'b' || mod == 'B')
		code = mod == 'b' ? 40 : 100;
	if (value == 'r')
		code += 1;
	else if (value == 'g')
		code += 2;
	else if (value == 'y')
		code += 3;
	else if (value == 'b')
		code += 4;
	else if (value == 'p')
		code += 5;
	else if (value == 'c')
		code += 6;
	else if (value == 'w')
		code += 7;
	pr_utoa(aq, code, 10);
	aq->out[aq->i++] = ';';
}

void		set_color(const char **line, t_print *aq)
{
	aq->out[aq->i++] = 033;
	aq->out[aq->i++] = '[';
	(*line)++;
	if (**line == 'm')
	{
		set_mod_code(aq, **line, *(++(*line)));
		if (*(++(*line)) == '!' && (aq->out[aq->i++] = 'm'))
			return ;
		(*line)++;
	}
	if (**line == 'f' || **line == 'F')
	{
		set_color_code(aq, **line, *(++(*line)));
		if (*(++(*line)) == '!' && (aq->out[aq->i++] = 'm'))
			return ;
		(*line)++;
	}
	if (**line == 'b' || **line == 'B')
	{
		set_color_code(aq, **line, *(++(*line)));
		if (**line == '!' && (aq->out[aq->i++] = 'm'))
			return ;
	}
}
