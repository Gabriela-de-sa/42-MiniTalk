/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:55:14 by gde-sa            #+#    #+#             */
/*   Updated: 2023/08/16 10:45:16 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return ((int *)1);
		set++;
	}
	return ((int *)0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (s1 == 0 || set == 0)
		return (NULL);
	while (*s1 && ft_set(*s1, set))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_set(s1[i - 1], set))
		i--;
	return (ft_substr(s1, 0, i));
}
