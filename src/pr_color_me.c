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
** ___Format
** in str	<![modify];[font color];[background color]! koko >?
** w/ %		%![modify];[font color];[background color]!s
** ___Modifies
** m0 - Turn off current modify
** mb - Bold
** md - Dim
** mi - Italic
** mu - Underline
** mr - Reverse/Invert
** ___Font & Background
** Use upper case for bright version
** f - simple font
** F - bright version
** b - simple bg
** B - bright version
** ___Colors
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
** ___Examples
** 	<!m1;Fr;bB!koko & other text will have the same color>!
**	<!m1;Fr;bB!koko & other text will have the same color>!
**	%!m1;Fr;bB!koko will be the only colored word
**	<!mb!koko>!
**	<!fR;Bw!koko>!
**	<!mifg!koko>!
**	<!mu;Fr;bw;koko>!
**	<!md;Fr;bB!koko>!
*/

static void	set_mod_code(t_print *aq, char mod)
{
	if (mod == '0')
		aq->out[aq->i++] = '0';
	else if (mod == 'b')
		aq->out[aq->i++] = '1';
	else if (mod == 'd')
		aq->out[aq->i++] = '2';
	else if (mod == 'i')
		aq->out[aq->i++] = '3';
	else if (mod == 'u')
		aq->out[aq->i++] = '4';
	else if (mod == 'r')
		aq->out[aq->i++] = '7';
	else
		aq->out[aq->i++] = '0';
	aq->out[aq->i++] = ';';
}

static void	set_color_code(t_print *aq, char br, char clr)
{
	size_t code;

	code = 30;
	if (br == 'F')
		code = 90;
	else if (br == 'b' || br == 'B')
		code = br == 'b' ? 40 : 100;
	if (clr == 'r')
		code += 1;
	else if (clr == 'g')
		code += 2;
	else if (clr == 'y')
		code += 3;
	else if (clr == 'b')
		code += 4;
	else if (clr == 'p')
		code += 5;
	else if (clr == 'c')
		code += 6;
	else if (clr == 'w')
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
		set_mod_code(aq, *(++(*line)));
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
