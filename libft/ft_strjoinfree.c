/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 20:10:19 by aburdeni          #+#    #+#             */
/*   Updated: 2018/09/24 19:31:02 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*fresh;
	char	*ss1;
	char	*ss2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	ss1 = s1;
	ss2 = s2;
	while ((*ss1 || *ss2) && ++i)
		*ss1 ? ss1++ : ss2++;
	if (!(fresh = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	ss1 = s1;
	while (*ss1)
		fresh[i++] = *(ss1++);
	free(s1);
	ss2 = s2;
	while (*ss2)
		fresh[i++] = *(ss2++);
	fresh[i] = 0;
	free(s2);
	return (fresh);
}
