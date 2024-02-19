/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:54:38 by gde-sa            #+#    #+#             */
/*   Updated: 2024/01/16 13:19:09 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	unsigned int	i;
	int				counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != '\0')
			counter++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (counter);
}

void	*clear_memory(char **peace)
{
	char	**tmp;

	tmp = peace;
	while (*peace)
		free(*peace++);
	free(tmp);
	return (NULL);
}

char	*string_split(char const *s, int start, int len, char **split)
{
	char	*current_word;
	int		index;

	current_word = malloc((len + 1) * sizeof(char));
	if (current_word == NULL)
		return (clear_memory(split));
	index = 0;
	while (index < len)
	{
		current_word[index] = s[start++];
		index++;
	}
	current_word[index] = '\0';
	return (current_word);
}

char	**put_word(char const *s, char c, char **split)
{
	int		i;
	int		start;
	int		len;
	int		split_index;

	i = 0;
	split_index = -1;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			len = 1;
			while (s[++i] && s[i] != c)
				len++;
			split[++split_index] = string_split(s, start, len, split);
		}
		if (s[i] != '\0')
			i++;
	}
	split[split_index + 1] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**split;

	words = count_words(s, c);
	split = malloc((words + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	put_word(s, c, split);
	return (split);
}
