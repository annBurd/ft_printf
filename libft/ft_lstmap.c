/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 20:18:55 by aburdeni          #+#    #+#             */
/*   Updated: 2017/12/19 20:18:57 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	lstfree(t_list *start)
{
	while (start)
	{
		free(start);
		start = start->next;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*l;
	t_list	*start;
	t_list	*fresh;

	if (lst && f)
	{
		if (!(start = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		start = f(lst);
		fresh = start;
		l = lst->next;
		while (l)
		{
			if (!(fresh->next = (t_list*)malloc(sizeof(t_list))))
			{
				lstfree(start);
				return (NULL);
			}
			fresh->next = f(l);
			fresh = fresh->next;
			l = l->next;
		}
		return (start);
	}
	return (NULL);
}
