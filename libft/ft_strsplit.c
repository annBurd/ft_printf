/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:20:36 by aburdeni          #+#    #+#             */
/*   Updated: 2017/11/28 20:20:39 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*arrfree(char **array)
{
	while (*array)
	{
		ft_memdel((void**)&array);
		array++;
	}
	ft_memdel((void**)array);
	return (NULL);
}

static size_t	linecount(char const *s, char c)
{
	size_t	line;

	line = 0;
	while (*(s++))
		if (*(s - 1) != c && (*s == c || *s == 0))
			line++;
	return (line);
}

static char		**koko(size_t *line, char **array, char const *s, char c)
{
	size_t	n;

	n = 0;
	while (*(s++))
	{
		if (*(s - 1) != c)
			n++;
		if (*(s - 1) != c && (*s == c || *s == 0))
		{
			if (!(array[(*line)] = ft_strnew(n + 1)))
				return (arrfree(array));
			array[(*line)] = ft_strncpy(array[(*line)], (s - n), n);
			n = 0;
			(*line)++;
		}
	}
	array[(*line)] = (char*)0;
	return (array);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	size_t	line;

	if (!s || !c)
		return (NULL);
	line = linecount(s, c);
	if (!(array = (char**)malloc(sizeof(char*) * (line + 1))))
		return (NULL);
	line = 0;
	return (koko(&line, array, s, c));
}
