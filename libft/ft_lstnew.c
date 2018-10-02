/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:23:37 by aburdeni          #+#    #+#             */
/*   Updated: 2017/12/19 18:24:26 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *fresh;

	if (!(fresh = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		fresh->content = NULL;
		fresh->content_size = 0;
	}
	else
	{
		if (!(fresh->content = malloc(content_size)))
		{
			ft_memdel((void**)&fresh);
			return (NULL);
		}
		ft_memcpy(fresh->content, content, content_size);
		fresh->content_size = content_size;
	}
	fresh->next = NULL;
	return (fresh);
}
