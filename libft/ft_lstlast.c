/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:24:32 by gabriela          #+#    #+#             */
/*   Updated: 2023/08/16 10:20:26 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	count;

	if (lst == NULL)
		return (lst);
	count = ft_lstsize(lst);
	while (count > 1)
	{
		lst = lst->next;
		count--;
	}
	return (lst);
}
