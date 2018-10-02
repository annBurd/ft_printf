/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 19:27:19 by aburdeni          #+#    #+#             */
/*   Updated: 2017/12/19 19:27:22 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*this;
	t_list	*next;

	if (alst && *alst)
	{
		this = *alst;
		while (this)
		{
			next = this->next;
			del(this->content, this->content_size);
			free(this);
			this = next;
		}
		*alst = NULL;
	}
}
