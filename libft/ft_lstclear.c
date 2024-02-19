/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 20:27:41 by gabriela          #+#    #+#             */
/*   Updated: 2023/08/16 10:20:19 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*clear;
	int		count;

	temp = *lst;
	count = ft_lstsize(temp);
	while (count > 0)
	{
		del(temp->content);
		clear = temp;
		temp = temp->next;
		free(clear);
		count--;
	}
	*lst = NULL;
}
