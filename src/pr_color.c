/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_color_me.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:37:22 by aburdeni          #+#    #+#             */
/*   Updated: 2018/10/14 01:49:43 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
** ___ Format
** ft_printf("<![modify];[foreground color];[background color]!koko>!\n");
** ft_printf("%![modify];[foreground color];[background color]!s\n", "koko");
** ___ Modes
** > You can use few modifies which don't contradict each other
** > But only one foreground or background
** m - set modify
** M - reset modify
** f - usual foreground
** F - bright version of foreground
** b - usual background
** B - bright version of background
** ___ Modifies
** [m/M]0 - Turn off all modifies
** [m/M]b - set/reset Bold
** [m/M]d - set/reset Dim //doesn't work in CLion
** [m/M]i - set/reset Italic //doesn't work in CLion
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
**	<!m1;Fr;bB!koko & other text will have the same color>! but not this text
**	%!m1;Fr;bB!koko will be the only colored word
**	<!mb!koko>!
**	<!fR;Bw!koko>!
**	<!mi;fg!koko>!
**	<!mu;Fr;bw;koko>!
**	<!md;Fr;bB!koko>!
*/

static void	set_modify(t_print *aq, char mod, char value)
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

static void	set_color(t_print *aq, char mod, char value)
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

void		pr_color(t_print *aq, const char **line)
{
	if (aq->i + 12 >= PRF_BUF_SIZE)
		pr_refresh(aq);
	aq->out[aq->i++] = 033;
	aq->out[aq->i++] = '[';
	(*line)++;
	while (**line == 'm' || **line == 'M')
	{
		set_modify(aq, **line, *(++(*line)));
		if (*(++(*line)) == '!' && (aq->out[aq->i++] = 'm'))
			return ;
		(*line)++;
	}
	if (**line == 'f' || **line == 'F')
	{
		set_color(aq, **line, *(++(*line)));
		if (*(++(*line)) == '!' && (aq->out[aq->i++] = 'm'))
			return ;
		(*line)++;
	}
	if (**line == 'b' || **line == 'B')
	{
		set_color(aq, **line, *(++(*line)));
		if (*(++(*line)) == '!' && (aq->out[aq->i++] = 'm'))
			return ;
	}
}
