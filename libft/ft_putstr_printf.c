/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:07:25 by gde-sa            #+#    #+#             */
/*   Updated: 2024/01/11 19:14:39 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_printf(char *str, int *count)
{
	int	index;

	index = 0;
	if (!str)
		str = "(null)";
	while (str[index])
	{
		ft_putchar_printf((char) str[index], count);
		index++;
	}
}
