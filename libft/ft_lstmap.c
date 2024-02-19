/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 00:15:45 by gabriela          #+#    #+#             */
/*   Updated: 2023/08/16 10:20:29 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*elem;

	if (lst == NULL)
		return (NULL);
	elem = ft_lstnew((*f)(lst->content));
	if (elem == NULL)
	{
		free(elem);
		return (NULL);
	}
	new_list = elem;
	lst = lst->next;
	while (lst != NULL)
	{
		elem->next = ft_lstnew((*f)(lst->content));
		if (elem == NULL)
		{
			ft_lstclear(&elem, del);
			return (NULL);
		}
		elem = elem->next;
		lst = lst->next;
	}
	return (new_list);
}
