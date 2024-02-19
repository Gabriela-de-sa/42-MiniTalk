/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:40:14 by gabriela          #+#    #+#             */
/*   Updated: 2023/08/16 10:20:11 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

size_t	len_digit(size_t number)
{
	unsigned int	count;

	if (number == 0)
		return (1);
	count = 0;
	while (number > 0)
	{
		count++;
		number /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	unsigned int	neg;
	long int		number;
	unsigned int	len_n;
	char			*str;

	neg = negative(n);
	number = n;
	if (neg == 1)
		number *= -1;
	len_n = len_digit(number);
	str = (char *) malloc(len_n + neg + 1);
	if (str == NULL)
		return (NULL);
	if (neg == 1)
		str[0] = '-';
	str[len_n + neg] = '\0';
	while (len_n > 0)
	{
		str[(len_n - 1) + neg] = (number % 10) + '0';
		number /= 10;
		len_n--;
	}
	return (str);
}
