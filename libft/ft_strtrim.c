/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:15:07 by aburdeni          #+#    #+#             */
/*   Updated: 2017/12/15 22:15:10 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	length(char const *s)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if (!s[i])
		return (0);
	len = i;
	while (s[i])
		i++;
	while ((s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t'))
		i--;
	return (i - len);
}

char			*ft_strtrim(char const *s)
{
	char	*result;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = length(s);
	if (len == 0)
	{
		if (!(result = ft_strnew(1)))
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	if (!(result = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	ft_strncpy(result, s + i, len);
	result[len] = '\0';
	return (result);
}
