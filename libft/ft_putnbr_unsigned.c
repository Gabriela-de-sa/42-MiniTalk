/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:57:27 by gabriela          #+#    #+#             */
/*   Updated: 2024/01/11 19:14:48 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_unsigned(unsigned int n, int *count)
{
	unsigned int	number;

	number = n;
	if (number > 9)
		ft_putnbr_unsigned(number / 10, count);
	ft_putchar_printf(number % 10 + (char )48, count);
}
