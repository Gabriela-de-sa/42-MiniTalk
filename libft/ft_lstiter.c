/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 00:02:39 by gabriela          #+#    #+#             */
/*   Updated: 2023/08/16 10:20:24 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	int	count;

	count = ft_lstsize(lst);
	while (count > 0)
	{
		f(lst->content);
		lst = lst->next;
		count--;
	}
}
