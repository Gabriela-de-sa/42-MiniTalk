/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:23:32 by gde-sa            #+#    #+#             */
/*   Updated: 2023/08/16 10:44:56 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			len_src;
	size_t			len_dst;
	size_t			i;

	i = 0;
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (size == 0)
		return (len_src);
	if (size > len_dst)
	{
		while (src[i] != '\0' && i < size - len_dst - 1)
		{
			dst[i + len_dst] = src[i];
			i++;
		}
		dst[len_dst + i] = '\0';
		len_dst = len_dst + len_src;
	}
	else
		len_dst = len_src + size;
	return (len_dst);
}
