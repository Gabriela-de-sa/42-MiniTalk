/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:45:21 by gde-sa            #+#    #+#             */
/*   Updated: 2024/01/05 16:16:54 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_source_n(char *s)
{
	int	index;

	if (!s)
		return (-1);
	index = 0;
	while (s[index])
	{
		if (s[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

size_t	ft_strlen_gnl(char *s)
{
	int		count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_strdup_gnl(char *s)
{
	char	*str_dup;
	int		count_bytes;
	int		index;

	count_bytes = ft_strlen_gnl(s);
	str_dup = ft_calloc_gnl(count_bytes + 1, sizeof(char));
	if (str_dup == NULL)
		return (NULL);
	str_dup[count_bytes] = '\0';
	index = 0;
	while (s[index])
	{
		str_dup[index] = s[index];
		index++;
	}
	return (str_dup);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*new_string;
	int		len_s1;
	int		len_s2;
	int		index;

	len_s1 = ft_strlen_gnl(s1);
	len_s2 = ft_strlen_gnl(s2);
	new_string = (char *)malloc((len_s1 + len_s2) * sizeof(char) + 1);
	if (new_string == NULL)
		return (new_string);
	index = -1;
	while (s1[++index])
		new_string[index] = s1[index];
	index = -1;
	while (s2[++index])
		new_string[len_s1 + index] = s2[index];
	new_string[len_s1 + index] = '\0';
	free(s1);
	return (new_string);
}

void	*ft_calloc_gnl(size_t nitems, size_t size)
{
	int		*p;
	size_t	overflow;
	size_t	index;
	char	*ptr;

	overflow = nitems * size;
	if (nitems != 0 && (overflow / nitems) != size)
		return (NULL);
	p = malloc(nitems * size);
	if (p == NULL)
		return (p);
	index = 0;
	ptr = (char *)p;
	while (index < overflow)
	{
		*ptr = '\0';
		ptr++;
		index++;
	}
	return (p);
}
